/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include <compiler/expression/dynamic_function_call.h>
#include <compiler/analysis/code_error.h>
#include <compiler/expression/expression_list.h>
#include <compiler/analysis/function_scope.h>
#include <compiler/analysis/class_scope.h>
#include <util/util.h>
#include <compiler/option.h>
#include <compiler/analysis/variable_table.h>

using namespace HPHP;
using namespace std;
using namespace boost;

///////////////////////////////////////////////////////////////////////////////
// constructors/destructors

DynamicFunctionCall::DynamicFunctionCall
(EXPRESSION_CONSTRUCTOR_PARAMETERS,
 ExpressionPtr name, ExpressionListPtr params, const std::string *classname)
  : FunctionCall(EXPRESSION_CONSTRUCTOR_PARAMETER_VALUES,
                 name, "", params, classname) {
}

ExpressionPtr DynamicFunctionCall::clone() {
  DynamicFunctionCallPtr exp(new DynamicFunctionCall(*this));
  FunctionCall::deepCopy(exp);
  exp->m_params = Clone(m_params);
  return exp;
}

///////////////////////////////////////////////////////////////////////////////
// parser functions

///////////////////////////////////////////////////////////////////////////////
// static analysis functions

void DynamicFunctionCall::analyzeProgram(AnalysisResultPtr ar) {
  addUserClass(ar, m_className);
  m_nameExp->analyzeProgram(ar);
  if (m_params) {
    m_params->markParams(false);
    m_params->analyzeProgram(ar);
  }
}

ExpressionPtr DynamicFunctionCall::preOptimize(AnalysisResultPtr ar) {
  return FunctionCall::preOptimize(ar);
}

ExpressionPtr DynamicFunctionCall::postOptimize(AnalysisResultPtr ar) {
  return FunctionCall::postOptimize(ar);
}

TypePtr DynamicFunctionCall::inferTypes(AnalysisResultPtr ar, TypePtr type,
                                        bool coerce) {
  reset();
  ConstructPtr self = shared_from_this();
  if (!m_className.empty()) {
    ClassScopePtr cls = ar->resolveClass(m_className);
    if (!cls || cls->isRedeclaring()) {
      if (cls) {
        m_redeclared = true;
        ar->getScope()->getVariables()->
          setAttribute(VariableTable::NeedGlobalPointer);
      }
      if (!cls && ar->isFirstPass()) {
        ar->getCodeError()->record(self, CodeError::UnknownClass, self);
      }
    } else {
      m_validClass = true;
    }
  }

  ar->containsDynamicFunctionCall();

  if (ar->isFirstPass()) {
    ar->getCodeError()->record(self, CodeError::UseDynamicFunction, self);
  }
  m_nameExp->inferAndCheck(ar, Type::String, false);
  if (m_params) {
    for (int i = 0; i < m_params->getCount(); i++) {
      (*m_params)[i]->inferAndCheck(ar, Type::Variant, true);
    }
  }
  return Type::Variant;
}

///////////////////////////////////////////////////////////////////////////////
// code generation functions

void DynamicFunctionCall::outputPHP(CodeGenerator &cg, AnalysisResultPtr ar) {
  outputLineMap(cg, ar);

  if (!m_className.empty()) {
    cg.printf("%s::", m_className.c_str());
    m_nameExp->outputPHP(cg, ar);
  } else {
    const char *prefix = Option::IdPrefix.c_str();
    if (cg.getOutput() == CodeGenerator::TrimmedPHP &&
        cg.usingStream(CodeGenerator::PrimaryStream) &&
        !m_nameExp->is(Expression::KindOfScalarExpression)) {
      cg.printf("${%sdynamic_load($%stmp = (", prefix, prefix);
      m_nameExp->outputPHP(cg, ar);
      cg.printf("), '%stmp'", prefix);
      cg.printf(")}");
    } else {
      m_nameExp->outputPHP(cg, ar);
    }
  }

  cg.printf("(");
  if (m_params) m_params->outputPHP(cg, ar);
  cg.printf(")");
}

void DynamicFunctionCall::outputCPPImpl(CodeGenerator &cg,
                                        AnalysisResultPtr ar) {
  bool linemap = outputLineMap(cg, ar, true);
  if (!m_className.empty()) {
    if (m_validClass) {
      cg.printf("%s%s::%sinvoke(\"%s\", ", Option::ClassPrefix,
                m_className.c_str(), Option::ObjectStaticPrefix,
                m_className.c_str());
    } else if (m_redeclared) {
      cg.printf("g->%s%s->%sinvoke(\"%s\", ", Option::ClassStaticsObjectPrefix,
                m_className.c_str(), Option::ObjectStaticPrefix,
                m_className.c_str());
    } else {
      cg.printf("throw_fatal(\"unknown class %s\")", m_className.c_str());
      cg.printf(")");
      return;
    }
  } else {
    cg.printf("invoke(");
  }
  if (m_nameExp->is(Expression::KindOfSimpleVariable)) {
    m_nameExp->outputCPP(cg, ar);
  } else {
    cg.printf("(");
    m_nameExp->outputCPP(cg, ar);
    cg.printf(")");
  }
  cg.printf(", ");
  if (m_params && m_params->getCount() > 0) {
    FunctionScope::outputCPPArguments(m_params, cg, ar, -1, false);
  } else {
    cg.printf("Array()");
  }
  cg.printf(", -1)");
  if (linemap) cg.printf(")");
}
