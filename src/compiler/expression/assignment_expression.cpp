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

#include <compiler/expression/assignment_expression.h>
#include <compiler/expression/array_element_expression.h>
#include <compiler/analysis/code_error.h>
#include <compiler/expression/constant_expression.h>
#include <compiler/expression/simple_variable.h>
#include <compiler/analysis/block_scope.h>
#include <compiler/analysis/variable_table.h>
#include <compiler/analysis/constant_table.h>
#include <compiler/analysis/file_scope.h>
#include <compiler/analysis/alias_manager.h>
#include <compiler/expression/unary_op_expression.h>
#include <compiler/parser/hphp.tab.hpp>
#include <compiler/option.h>
#include <compiler/analysis/class_scope.h>
#include <compiler/analysis/function_scope.h>
#include <compiler/analysis/dependency_graph.h>
#include <compiler/expression/scalar_expression.h>
#include <compiler/expression/expression_list.h>
#include <compiler/expression/simple_function_call.h>
#include <runtime/base/type_string.h>

using namespace HPHP;
using namespace std;
using namespace boost;

///////////////////////////////////////////////////////////////////////////////
// constructors/destructors

AssignmentExpression::AssignmentExpression
(EXPRESSION_CONSTRUCTOR_PARAMETERS,
 ExpressionPtr variable, ExpressionPtr value, bool ref)
  : Expression(EXPRESSION_CONSTRUCTOR_PARAMETER_VALUES),
    m_variable(variable), m_value(value), m_ref(ref) {
  m_variable->setContext(Expression::DeepAssignmentLHS);
  m_variable->setContext(Expression::AssignmentLHS);
  m_variable->setContext(Expression::LValue);
  m_variable->setContext(Expression::NoLValueWrapper);
  m_value->setContext(Expression::AssignmentRHS);
  if (ref) {
    m_value->setContext(Expression::RefValue);

    // we have &new special case that's handled in this class
    m_value->setContext(Expression::NoRefWrapper);
  }
}

ExpressionPtr AssignmentExpression::clone() {
  AssignmentExpressionPtr exp(new AssignmentExpression(*this));
  Expression::deepCopy(exp);
  exp->m_variable = Clone(m_variable);
  exp->m_value = Clone(m_value);
  return exp;
}

///////////////////////////////////////////////////////////////////////////////
// parser functions

void AssignmentExpression::onParse(AnalysisResultPtr ar) {
  BlockScopePtr scope = ar->getScope();

  // This is that much we can do during parse phase.
  TypePtr type;
  if (m_value->is(Expression::KindOfScalarExpression)) {
    type = m_value->inferAndCheck(ar, NEW_TYPE(Some), false);
  } else if (m_value->is(Expression::KindOfUnaryOpExpression)) {
    UnaryOpExpressionPtr uexp =
      dynamic_pointer_cast<UnaryOpExpression>(m_value);
    if (uexp->getOp() == T_ARRAY) {
      type = Type::Array;
    }
  }
  if (!type) type = NEW_TYPE(Some);

  if (m_variable->is(Expression::KindOfConstantExpression)) {
    // ...as in ClassConstant statement
    // We are handling this one here, not in ClassConstant, purely because
    // we need "value" to store in constant table.
    ConstantExpressionPtr exp =
      dynamic_pointer_cast<ConstantExpression>(m_variable);
    scope->getConstants()->add(exp->getName(), type, m_value, ar, m_variable);

    string name = ar->getClassScope()->getName() + "::" + exp->getName();
    ar->getDependencyGraph()->
      addParent(DependencyGraph::KindOfConstant, "", name, exp);
  } else if (m_variable->is(Expression::KindOfSimpleVariable)) {
    SimpleVariablePtr var = dynamic_pointer_cast<SimpleVariable>(m_variable);
    scope->getVariables()->add(var->getName(), type, true, ar,
                               shared_from_this(), scope->getModifiers());
    var->clearContext(Declaration); // to avoid wrong CodeError
  } else {
    ASSERT(false); // parse phase shouldn't handle anything else
  }
}

///////////////////////////////////////////////////////////////////////////////
// static analysis functions

int AssignmentExpression::getLocalEffects() const {
  return AssignEffect;
}

void AssignmentExpression::analyzeProgram(AnalysisResultPtr ar) {
  m_variable->analyzeProgram(ar);
  m_value->analyzeProgram(ar);
  if (ar->getPhase() == AnalysisResult::AnalyzeAll) {
    if (m_ref && m_variable->is(Expression::KindOfSimpleVariable)) {
      SimpleVariablePtr var =
        dynamic_pointer_cast<SimpleVariable>(m_variable);
      const std::string &name = var->getName();
      VariableTablePtr variables = ar->getScope()->getVariables();
      variables->addUsed(name);
    }
    if (m_variable->is(Expression::KindOfConstantExpression)) {
      ConstantExpressionPtr exp =
        dynamic_pointer_cast<ConstantExpression>(m_variable);
      if (!m_value->isScalar()) {
        ar->getScope()->getConstants()->setDynamic(ar, exp->getName());
      }
    }
  }
}

ConstructPtr AssignmentExpression::getNthKid(int n) const {
  switch (n) {
    case 0:
      return m_variable;
    case 1:
      return m_value;
    default:
      ASSERT(false);
      break;
  }
  return ConstructPtr();
}

int AssignmentExpression::getKidCount() const {
  return 2;
}

void AssignmentExpression::setNthKid(int n, ConstructPtr cp) {
  switch (n) {
    case 0:
      m_variable = boost::dynamic_pointer_cast<Expression>(cp);
      break;
    case 1:
      m_value = boost::dynamic_pointer_cast<Expression>(cp);
      break;
    default:
      ASSERT(false);
      break;
  }
}

ExpressionPtr AssignmentExpression::preOptimize(AnalysisResultPtr ar) {
  ar->preOptimize(m_variable);
  ar->preOptimize(m_value);
  return ExpressionPtr();
}

ExpressionPtr AssignmentExpression::postOptimize(AnalysisResultPtr ar) {
  ar->postOptimize(m_variable);
  ar->postOptimize(m_value);
  if (m_variable->is(Expression::KindOfSimpleVariable)) {
    SimpleVariablePtr var =
      dynamic_pointer_cast<SimpleVariable>(m_variable);
    const std::string &name = var->getName();
    VariableTablePtr variables = ar->getScope()->getVariables();
    if (variables->checkUnused(name)) {
      variables->addUnused(name);
      if (m_value->getContainedEffects() != getContainedEffects()) {
        s_effectsTag++;
      }
      return m_value;
    }
  }
  return ExpressionPtr();
}

TypePtr AssignmentExpression::inferTypes(AnalysisResultPtr ar, TypePtr type,
                                         bool coerce) {

  if (VariableTable::m_hookHandler) {
    VariableTable::m_hookHandler(ar, ar->getScope()->getVariables().get(),
                                 m_variable,
                                 beforeAssignmentExpressionInferTypes);
  }

  TypePtr ret = inferAssignmentTypes(ar, type, coerce, m_variable, m_value);

  if (VariableTable::m_hookHandler) {
    VariableTable::m_hookHandler(ar, ar->getScope()->getVariables().get(),
                                 m_variable,
                                 afterAssignmentExpressionInferTypes);
  }

  return ret;
}

///////////////////////////////////////////////////////////////////////////////
// code generation functions

void AssignmentExpression::outputPHP(CodeGenerator &cg, AnalysisResultPtr ar) {
  m_variable->outputPHP(cg, ar);
  cg.printf(" = ");
  if (m_ref) cg.printf("&");
  m_value->outputPHP(cg, ar);
}

void AssignmentExpression::outputCPPImpl(CodeGenerator &cg,
                                         AnalysisResultPtr ar) {
  BlockScopePtr scope = ar->getScope();
  bool ref = (m_ref && !m_value->is(Expression::KindOfNewObjectExpression));

  bool setElement = false; // turning $a['elem'] = $b into $a.set('elem', $b);
  bool type_cast = false;
  bool setNull = false;
  TypePtr m_actualType;

  if (m_variable->is(Expression::KindOfArrayElementExpression)) {
    ArrayElementExpressionPtr exp =
      dynamic_pointer_cast<ArrayElementExpression>(m_variable);
    m_actualType = m_variable->getActualType();
    if (m_actualType && m_actualType->getKindOf() == Type::KindOfVariant
        && !ref) {
      //type_cast = true;
    }
    if (!exp->isSuperGlobal() && !exp->isDynamicGlobal()) {
      exp->getVariable()->outputCPP(cg, ar);
      if (exp->getOffset()) {
        cg.printf(".set(");
        exp->getOffset()->outputCPP(cg, ar);
        cg.printf(", (");
      } else {
        cg.printf(".append((");
      }
      if (type_cast) {
        m_actualType->outputCPPCast(cg, ar);
        cg.printf("(");
      }
      if (ref && m_value->isRefable()) cg.printf("ref(");
      m_value->outputCPP(cg, ar);
      if (ref && m_value->isRefable()) cg.printf(")");
      if (type_cast) cg.printf(")");
      cg.printf(")");
      ExpressionPtr off = exp->getOffset();
      if (off) {
        ScalarExpressionPtr sc =
          dynamic_pointer_cast<ScalarExpression>(off);
        if (sc) {
          int64 hash = sc->getHash();
          if (hash >= 0) {
            cg.printf(", 0x%016llXLL", hash);
          } else {
            cg.printf(", -1");
          }
          if (sc->isLiteralString()) {
            String s(sc->getLiteralString());
            int64 n;
            if (!s.get()->isStrictlyInteger(n)) {
              cg.printf(", true"); // skip toKey() at run time
            }
          }
        }
      }
      cg.printf(")");
      setElement = true;
    }
  }
  if (m_variable->is(Expression::KindOfSimpleVariable) &&
      m_value->is(Expression::KindOfConstantExpression)) {
    ConstantExpressionPtr exp =
      dynamic_pointer_cast<ConstantExpression>(m_value);
    if (exp->isNull()) setNull = true;
  }

  if (!setElement) {
    if (setNull) {
      cg.printf("setNull(");
      m_variable->outputCPP(cg, ar);
    } else {
      cg.printf("(");
      m_variable->outputCPP(cg, ar);
      cg.printf(" = ");

      if (type_cast) {
        m_actualType->outputCPPCast(cg, ar);
        cg.printf("(");
      }
      if (ref && m_value->isRefable()) cg.printf("ref(");
      m_value->outputCPP(cg, ar);
      if (ref && m_value->isRefable()) cg.printf(")");
      if (type_cast) cg.printf(")");
    }
    cg.printf(")");
  }
}
