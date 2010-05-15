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

#include <compiler/expression/static_member_expression.h>
#include <compiler/expression/simple_variable.h>
#include <compiler/expression/dynamic_variable.h>
#include <compiler/expression/scalar_expression.h>
#include <compiler/analysis/class_scope.h>
#include <compiler/analysis/variable_table.h>
#include <compiler/analysis/code_error.h>
#include <util/util.h>
#include <util/hash.h>
#include <compiler/parser/hphp.tab.hpp>
#include <compiler/analysis/dependency_graph.h>
#include <compiler/option.h>

using namespace HPHP;
using namespace std;
using namespace boost;

///////////////////////////////////////////////////////////////////////////////
// constructors/destructors

StaticMemberExpression::StaticMemberExpression
(EXPRESSION_CONSTRUCTOR_PARAMETERS,
 const std::string &className, ExpressionPtr exp)
  : Expression(EXPRESSION_CONSTRUCTOR_PARAMETER_VALUES),
    m_origClassName(className), m_exp(exp), m_valid(false),
    m_dynamicClass(false), m_redeclared(false) {
  if (exp->is(KindOfSimpleVariable)) {
    SimpleVariablePtr s(dynamic_pointer_cast<SimpleVariable>(exp));
    m_exp = ExpressionPtr
      (new ScalarExpression(getLocation(),
                            KindOfScalarExpression,
                            T_STRING, s->getName(), true));

  } else {
    assert(exp->is(KindOfDynamicVariable));
    m_exp = dynamic_pointer_cast<DynamicVariable>(exp)->getSubExpression();
  }
  m_className = Util::toLower(className);
}

ExpressionPtr StaticMemberExpression::clone() {
  StaticMemberExpressionPtr exp(new StaticMemberExpression(*this));
  Expression::deepCopy(exp);
  return exp;
}

///////////////////////////////////////////////////////////////////////////////
// parser functions

///////////////////////////////////////////////////////////////////////////////
// static analysis functions

void StaticMemberExpression::analyzeProgram(AnalysisResultPtr ar) {
  addUserClass(ar, m_className);
  m_exp->analyzeProgram(ar);
}

ConstructPtr StaticMemberExpression::getNthKid(int n) const {
  switch (n) {
    case 0:
      return m_exp;
    default:
      ASSERT(false);
      break;
  }
  return ConstructPtr();
}

int StaticMemberExpression::getKidCount() const {
  return 1;
}

void StaticMemberExpression::setNthKid(int n, ConstructPtr cp) {
  switch (n) {
    case 0:
      m_exp = boost::dynamic_pointer_cast<Expression>(cp);
      break;
    default:
      ASSERT(false);
      break;
  }
}

ExpressionPtr StaticMemberExpression::preOptimize(AnalysisResultPtr ar) {
  ar->preOptimize(m_exp);
  return ExpressionPtr();
}

ExpressionPtr StaticMemberExpression::postOptimize(AnalysisResultPtr ar) {
  ar->postOptimize(m_exp);
  return ExpressionPtr();
}

/**
 * static_member can only be one of these two forms:
 *
 *   T::$member
 *   T::$$member or T::${$member}, where $member can be an arbitrary expression
 *   The former is represented by a ScalarExpression with value "member",
 *   the latter by the expression $member.
 */
TypePtr StaticMemberExpression::inferTypes(AnalysisResultPtr ar,
                                           TypePtr type, bool coerce) {
  ConstructPtr self = shared_from_this();

  ClassScopePtr cls = ar->resolveClass(m_className);
  m_valid = true;

  if (!cls) {
    if (ar->isFirstPass()) {
      ar->getCodeError()->record(self, CodeError::UnknownClass, self);
    }
    m_valid = false;
  }

  VariableTablePtr variables = ar->getScope()->getVariables();
  variables->setAttribute(VariableTable::NeedGlobalPointer);
  if (cls) {
    if (cls->isRedeclaring()) {
      m_redeclared = true;
    }
    if (cls->derivesFromRedeclaring()) {
      m_dynamicClass = true;
    }
  }

  if (m_exp->is(Expression::KindOfScalarExpression)) {
    if (!cls) {
      m_implementedType.reset();
      return Type::Variant;
    }
    ScalarExpressionPtr var = dynamic_pointer_cast<ScalarExpression>(m_exp);
    const std::string &name = var->getString();
    int p;
    TypePtr tp;
    if (m_redeclared) {
      p = 0;
      BOOST_FOREACH(ClassScopePtr clsr, ar->findClasses(m_className)) {
        int p1;
        clsr->checkStatic(name, type, coerce, ar, self, p1);
        p |= p1;
      }
      tp = Type::Variant;
    } else {
      tp = cls->checkStatic(name, type, coerce, ar, self, p);
    }
    if (ar->isFirstPass() && p && !(p & VariableTable::VariableStatic)) {
      ar->getCodeError()->record(self, CodeError::MissingObjectContext, self);
    }

    m_valid = !p || (p & VariableTable::VariableStatic) ||
      m_redeclared || m_dynamicClass;
    if (cls->hasProperty(name) || m_redeclared) {
      m_resolvedClassName = m_className;
    } else {
      ClassScopePtr parent = cls->getVariables()->findParent(ar, name);
      ASSERT(parent);
      m_resolvedClassName = parent->getName();
    }
    return m_implementedType = tp;
  } else if (cls) {
    cls->getVariables()->forceVariants(ar);
  }

  m_exp->inferAndCheck(ar, Type::String, false);

  // we have to use a variant to hold dynamic value
  return m_implementedType = Type::Variant;
}

unsigned StaticMemberExpression::getCanonHash() const {
  int64 val = Expression::getCanonHash() +
    hash_string(Util::toLower(m_className).c_str(), m_className.size());
  return ~unsigned(val) ^ unsigned(val >> 32);
}

bool StaticMemberExpression::canonCompare(ExpressionPtr e) const {
  if (!Expression::canonCompare(e)) return false;
  StaticMemberExpressionPtr s =
    static_pointer_cast<StaticMemberExpression>(e);
  return m_className == s->m_className;
}


///////////////////////////////////////////////////////////////////////////////
// code generation functions

void StaticMemberExpression::outputPHP(CodeGenerator &cg,
                                       AnalysisResultPtr ar) {
  cg.printf("%s::$", m_className.c_str());
  bool needsClose = false;
  switch (m_exp->getKindOf()) {
  case KindOfScalarExpression:
    {
      ScalarExpressionPtr var = dynamic_pointer_cast<ScalarExpression>(m_exp);
      cg.printf("%s", var->getString().c_str());
      return;
    }
  case KindOfSimpleVariable:
  case KindOfDynamicVariable:
    break;
  default:
    cg.printf("{");
    needsClose = true;
  }
  m_exp->outputPHP(cg, ar);
  if (needsClose) {
    cg.printf("}");
  }
}

void StaticMemberExpression::preOutputStash(CodeGenerator &cg,
                                            AnalysisResultPtr ar,
                                            int state)
{
  if (getContext() & (LValue|RefValue|RefParameter)) return;
  Expression::preOutputStash(cg, ar, state);
}

void StaticMemberExpression::outputCPPImpl(CodeGenerator &cg,
                                           AnalysisResultPtr ar) {
  if (!m_valid) {
    if (m_resolvedClassName.empty()) {
      cg.printf("throw_fatal(\"unknown class %s\")", m_origClassName.c_str());
    } else {
      cg.printf("throw_fatal(\"Access to undeclared static property: ");
      outputPHP(cg, ar);
      cg.printf("\")");
    }
    return;
  }

  bool volatileCheck = false;
  bool outsideClass = !ar->checkClassPresent(m_origClassName);
  ClassScopePtr cls = ClassScopePtr();
  if (!m_resolvedClassName.empty()) {
    cls = ar->findClass(m_resolvedClassName);
    if (cls && outsideClass) {
      volatileCheck = cls->isVolatile();
      if (volatileCheck) {
        ClassScope::OutputVolatileCheckBegin(cg, ar, m_origClassName);
      }
    }
  }

  if (m_exp->is(Expression::KindOfScalarExpression) && !m_redeclared &&
      !m_dynamicClass) {

    ASSERT(cls);
    ScalarExpressionPtr var = dynamic_pointer_cast<ScalarExpression>(m_exp);
    if (cls->needLazyStaticInitializer()) {
      cg.printf("%s%s::lazy_initializer(g)->%s%s%s%s",
                Option::ClassPrefix, m_resolvedClassName.c_str(),
                Option::StaticPropertyPrefix, m_resolvedClassName.c_str(),
                Option::IdPrefix.c_str(), var->getString().c_str());
    } else {
      cg.printf("g->%s%s%s%s", Option::StaticPropertyPrefix,
                m_resolvedClassName.c_str(), Option::IdPrefix.c_str(),
                var->getString().c_str());
    }
  } else {
    if (m_context & (LValue | RefValue)) {
      if (m_redeclared) {
        cg.printf("g->%s%s->%slval(", Option::ClassStaticsObjectPrefix,
                  m_className.c_str(),Option::ObjectStaticPrefix);
      } else {
        cg.printf("%s%s::%slval(", Option::ClassPrefix, m_className.c_str(),
                  Option::ObjectStaticPrefix);
      }
    } else {
      if (m_redeclared) {
        cg.printf("g->%s%s->%sget(", Option::ClassStaticsObjectPrefix,
                  m_className.c_str(), Option::ObjectStaticPrefix);
      } else {
        cg.printf("%s%s::%sget(", Option::ClassPrefix, m_className.c_str(),
                  Option::ObjectStaticPrefix);
      }
    }
    m_exp->outputCPP(cg, ar);
    cg.printf(", -1)");
  }

  if (volatileCheck) {
    ClassScope::OutputVolatileCheckEnd(cg);
  }
}
