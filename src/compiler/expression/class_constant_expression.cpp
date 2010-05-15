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

#include <compiler/expression/class_constant_expression.h>
#include <compiler/analysis/class_scope.h>
#include <compiler/analysis/constant_table.h>
#include <compiler/analysis/code_error.h>
#include <compiler/analysis/dependency_graph.h>
#include <util/hash.h>
#include <util/util.h>
#include <compiler/option.h>
#include <compiler/analysis/variable_table.h>
#include <compiler/expression/scalar_expression.h>
#include <compiler/expression/constant_expression.h>

using namespace HPHP;
using namespace std;
using namespace boost;

///////////////////////////////////////////////////////////////////////////////

// constructors/destructors

ClassConstantExpression::ClassConstantExpression
(EXPRESSION_CONSTRUCTOR_PARAMETERS,
 const std::string &className, const std::string &varName)
  : Expression(EXPRESSION_CONSTRUCTOR_PARAMETER_VALUES),
    m_origClassName(className), m_varName(varName), m_valid(false),
    m_redeclared(false), m_visited(false) {
  m_className = Util::toLower(className);
}

ExpressionPtr ClassConstantExpression::clone() {
  ClassConstantExpressionPtr exp(new ClassConstantExpression(*this));
  Expression::deepCopy(exp);
  return exp;
}

///////////////////////////////////////////////////////////////////////////////
// parser functions

///////////////////////////////////////////////////////////////////////////////
// static analysis functions

bool ClassConstantExpression::containsDynamicConstant(AnalysisResultPtr ar)
  const {
  ClassScopePtr cls = ar->findClass(m_className);
  return !cls || cls->isVolatile();
}

void ClassConstantExpression::analyzeProgram(AnalysisResultPtr ar) {
  addUserClass(ar, m_className);
}

ExpressionPtr ClassConstantExpression::preOptimize(AnalysisResultPtr ar) {
  if (ar->getPhase() < AnalysisResult::FirstPreOptimize) {
    return ExpressionPtr();
  }
  string currentClsName;
  ClassScopePtr currentCls = ar->getClassScope();
  if (currentCls) currentClsName = currentCls->getName();
  bool inCurrentClass = currentClsName == m_className;
  ClassScopePtr cls =
    inCurrentClass ? currentCls : ar->resolveClass(m_className);
  if (!cls) return ExpressionPtr();
  if (!inCurrentClass) {
    if (m_redeclared) return ExpressionPtr();
    if (cls->isVolatile() || cls->isRedeclaring()) return ExpressionPtr();
  }
  ConstantTablePtr constants = cls->getConstants();
  if (constants->isExplicitlyDeclared(m_varName)) {
    ConstructPtr decl = constants->getValue(m_varName);
    if (decl) {
      ExpressionPtr value = dynamic_pointer_cast<Expression>(decl);
      if (!m_visited) {
        m_visited = true;
        ar->pushScope(cls);
        ExpressionPtr optExp = value->preOptimize(ar);
        ar->popScope();
        m_visited = false;
        if (optExp) value = optExp;
      }
      if (value->isScalar()) {
        // inline the value
        if (value->is(Expression::KindOfScalarExpression)) {
          ScalarExpressionPtr exp =
            dynamic_pointer_cast<ScalarExpression>(Clone(value));
          exp->setComment(getText());
          exp->setLocation(getLocation());
          return exp;
        } else if (value->is(Expression::KindOfConstantExpression)) {
          // inline the value
          ConstantExpressionPtr exp =
            dynamic_pointer_cast<ConstantExpression>(Clone(value));
          exp->setComment(getText());
          exp->setLocation(getLocation());
          return exp;
        }
      }
    }
  }
  return ExpressionPtr();
}

ExpressionPtr ClassConstantExpression::postOptimize(AnalysisResultPtr ar) {
  return ExpressionPtr();
}

TypePtr ClassConstantExpression::inferTypes(AnalysisResultPtr ar,
                                            TypePtr type, bool coerce) {
  m_valid = false;
  ConstructPtr self = shared_from_this();
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
    return Type::Variant;
  }
  if (cls->getConstants()->isDynamic(m_varName) || cls->isVolatile()) {
    ar->getScope()->getVariables()->
      setAttribute(VariableTable::NeedGlobalPointer);
  }
  if (cls->getConstants()->isExplicitlyDeclared(m_varName)) {
    string name = m_className + "::" + m_varName;
    ConstructPtr decl = cls->getConstants()->getDeclaration(m_varName);
    if (decl) { // No decl means an extension class.
      ar->getDependencyGraph()->add(DependencyGraph::KindOfConstant,
                                    ar->getName(),
                                    name, shared_from_this(), name, decl);
    }
    m_valid = true;
  }
  BlockScope *defScope;
  TypePtr t = cls->checkConst(m_varName, type, coerce, ar,
                              shared_from_this(),
                              cls->getBases(), defScope);
  if (defScope) {
    m_valid = true;
    m_defScope = defScope;
  }

  return t;
}

unsigned ClassConstantExpression::getCanonHash() const {
  int64 val =
    hash_string(Util::toLower(m_varName).c_str(), m_varName.size()) -
    hash_string(Util::toLower(m_className).c_str(), m_className.size());
  return ~unsigned(val) ^ unsigned(val >> 32);
}

bool ClassConstantExpression::canonCompare(ExpressionPtr e) const {
  return Expression::canonCompare(e) &&
    m_varName == static_cast<ClassConstantExpression*>(e.get())->m_varName &&
    m_className == static_cast<ClassConstantExpression*>(e.get())->m_className;
}


///////////////////////////////////////////////////////////////////////////////
// code generation functions

void ClassConstantExpression::outputPHP(CodeGenerator &cg,
                                        AnalysisResultPtr ar) {
  cg.printf("%s::%s", m_className.c_str(), m_varName.c_str());
}

void ClassConstantExpression::outputCPPImpl(CodeGenerator &cg,
                                            AnalysisResultPtr ar) {
  bool outsideClass = !ar->checkClassPresent(m_origClassName);
  if (m_valid) {
    string trueClassName;

    ASSERT(m_defScope);
    ClassScope *cls = dynamic_cast<ClassScope*>(m_defScope);
    trueClassName = cls->getName();
    ASSERT(!trueClassName.empty());
    if (outsideClass) {
      cls->outputVolatileCheckBegin(cg, ar, m_origClassName);
    }
    ConstructPtr decl = m_defScope->getConstants()->getValue(m_varName);
    if (decl) {
      decl->outputCPP(cg, ar);
      if (cg.getContext() == CodeGenerator::CppImplementation ||
          cg.getContext() == CodeGenerator::CppParameterDefaultValueImpl) {
        cg.printf("(%s::%s)", m_className.c_str(), m_varName.c_str());
      } else {
        cg.printf("/* %s::%s */", m_className.c_str(), m_varName.c_str());
      }
    } else {
      if (cls->getConstants()->isDynamic(m_varName)) {
        cg.printf("%s%s::lazy_initializer(%s)->", Option::ClassPrefix,
                  trueClassName.c_str(), cg.getGlobals(ar));
      }
      cg.printf("%s%s_%s", Option::ClassConstantPrefix, trueClassName.c_str(),
                m_varName.c_str());
    }
    if (outsideClass) {
      cls->outputVolatileCheckEnd(cg);
    }
  } else if (m_redeclared) {
    if (outsideClass) {
      ClassScope::OutputVolatileCheckBegin(cg, ar, m_origClassName);
    }
    cg.printf("%s->%s%s->os_constant(\"%s\")", cg.getGlobals(ar),
              Option::ClassStaticsObjectPrefix,
              m_className.c_str(), m_varName.c_str());
    if (outsideClass) {
      ClassScope::OutputVolatileCheckEnd(cg);
    }
  } else {
    cg.printf("throw_fatal(\"unknown class constant %s::%s\")",
              m_className.c_str(), m_varName.c_str());
  }
}
