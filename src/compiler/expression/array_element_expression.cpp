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

#include <compiler/expression/array_element_expression.h>
#include <compiler/expression/simple_variable.h>
#include <compiler/expression/scalar_expression.h>
#include <compiler/analysis/variable_table.h>
#include <compiler/analysis/dependency_graph.h>
#include <compiler/analysis/code_error.h>
#include <compiler/option.h>
#include <compiler/expression/static_member_expression.h>
#include <compiler/analysis/function_scope.h>
#include <compiler/parser/hphp.tab.hpp>
#include <runtime/base/type_string.h>

using namespace HPHP;
using namespace std;
using namespace boost;

///////////////////////////////////////////////////////////////////////////////
// constructors/destructors

ArrayElementExpression::ArrayElementExpression
(EXPRESSION_CONSTRUCTOR_PARAMETERS,
 ExpressionPtr variable, ExpressionPtr offset)
  : Expression(EXPRESSION_CONSTRUCTOR_PARAMETER_VALUES),
    m_variable(variable), m_offset(offset), m_global(false),
    m_dynamicGlobal(false) {
}

ExpressionPtr ArrayElementExpression::clone() {
  ArrayElementExpressionPtr exp(new ArrayElementExpression(*this));
  Expression::deepCopy(exp);
  exp->m_variable = Clone(m_variable);
  exp->m_offset = Clone(m_offset);
  return exp;
}

void ArrayElementExpression::setContext(Context context) {
  m_context |= context;
  if (context == Expression::LValue) {
    m_variable->setContext(Expression::LValue);
    if (m_variable->is(Expression::KindOfObjectPropertyExpression)) {
      m_variable->clearContext(Expression::NoLValueWrapper);
    }
    // special case for $GLOBALS[], see the if (m_global) check in
    // ArrayElementExpression::outputCPPImpl, we do not need lvalue wrapper
    if (m_variable->is(Expression::KindOfSimpleVariable)) {
      SimpleVariablePtr var =
        dynamic_pointer_cast<SimpleVariable>(m_variable);
      if (var->getName() == "GLOBALS") {
        m_context |= Expression::NoLValueWrapper;
      }
    }
  } else if (context == Expression::DeepAssignmentLHS ||
             context == Expression::ExistContext ||
             context == Expression::UnsetContext) {
    m_variable->setContext(context);
  }
}

void ArrayElementExpression::clearContext(Context context) {
  m_context &= ~context;
  if (context == Expression::LValue || context == Expression::DeepAssignmentLHS
      || context == Expression::UnsetContext) {
    m_variable->clearContext(Expression::LValue);
  }
}

///////////////////////////////////////////////////////////////////////////////
// parser functions

bool ArrayElementExpression::appendClassName(const std::string &name) {
  if (m_variable->is(Expression::KindOfArrayElementExpression)) {
    return dynamic_pointer_cast<ArrayElementExpression>(m_variable)
      ->appendClassName(name);
  }
  if (m_variable->is(Expression::KindOfSimpleVariable)) {
    m_variable = StaticMemberExpressionPtr
      (new StaticMemberExpression(m_variable->getLocation(),
                                  Expression::KindOfStaticMemberExpression,
                                  name, m_variable));
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////
// static analysis functions

void ArrayElementExpression::analyzeProgram(AnalysisResultPtr ar) {
  m_variable->analyzeProgram(ar);
  if (m_offset) m_offset->analyzeProgram(ar);
}

ConstructPtr ArrayElementExpression::getNthKid(int n) const {
  switch (n) {
    case 0:
      return m_variable;
    case 1:
      return m_offset;
    default:
      ASSERT(false);
      break;
  }
  return ConstructPtr();
}

int ArrayElementExpression::getKidCount() const {
  return 2;
}

void ArrayElementExpression::setNthKid(int n, ConstructPtr cp) {
  switch (n) {
    case 0:
      m_variable = boost::dynamic_pointer_cast<Expression>(cp);
      break;
    case 1:
      m_offset = boost::dynamic_pointer_cast<Expression>(cp);
      break;
    default:
      ASSERT(false);
      break;
  }
}

bool ArrayElementExpression::canonCompare(ExpressionPtr e) const {
  return m_offset && Expression::canonCompare(e);
}

ExpressionPtr ArrayElementExpression::preOptimize(AnalysisResultPtr ar) {
  ar->preOptimize(m_variable);
  ar->preOptimize(m_offset);
  return ExpressionPtr();
}

ExpressionPtr ArrayElementExpression::postOptimize(AnalysisResultPtr ar) {
  ar->postOptimize(m_variable);
  ar->postOptimize(m_offset);
  return ExpressionPtr();
}

/**
 * ArrayElementExpression comes from:
 *
 * reference_variable[|expr]
 * ->object_dim_list[|expr]
 * encaps T_VARIABLE[expr]
 * encaps ${T_STRING[expr]}
 */
TypePtr ArrayElementExpression::inferTypes(AnalysisResultPtr ar,
                                           TypePtr type, bool coerce) {
  ConstructPtr self = shared_from_this();

  // handling $GLOBALS[...]
  if (m_variable->is(Expression::KindOfSimpleVariable)) {
    SimpleVariablePtr var =
      dynamic_pointer_cast<SimpleVariable>(m_variable);
    if (var->getName() == "GLOBALS") {
      m_global = true;
      m_dynamicGlobal = true;
      ar->getScope()->getVariables()->
        setAttribute(VariableTable::NeedGlobalPointer);
      VariableTablePtr vars = ar->getVariables();


      if (m_offset && m_offset->is(Expression::KindOfScalarExpression)) {
        ScalarExpressionPtr offset =
          dynamic_pointer_cast<ScalarExpression>(m_offset);

        if (offset->isLiteralString()) {
          m_globalName = offset->getIdentifier();
          if (!m_globalName.empty()) {
            m_dynamicGlobal = false;
            ar->getScope()->getVariables()->
              setAttribute(VariableTable::NeedGlobalPointer);
            TypePtr ret;
            ConstructPtr decl = vars->getDeclaration(m_globalName);
            if (decl) {
              ar->getDependencyGraph()->
                add(DependencyGraph::KindOfGlobalVariable,
                    ar->getName(),
                    m_globalName, self, m_globalName, decl);
            }
            if (coerce) {
              ret = vars->add(m_globalName, type, true, ar, self,
                              ModifierExpressionPtr());
            } else {
              int p;
              ret =
                vars->checkVariable(m_globalName, type, coerce, ar, self, p);
            }
            ar->getScope()->getVariables()->addSuperGlobal(m_globalName);
            return ret;
          }
        }
      } else {
        vars->setAttribute(VariableTable::ContainsDynamicVariable);
      }


      if (hasContext(LValue) || hasContext(RefValue)) {
        if (ar->isFirstPass()) {
          ar->getCodeError()->record(self, CodeError::UseLDynamicVariable,
                                     self);
        }
        ar->getVariables()->forceVariants(ar);
        ar->getVariables()->
          setAttribute(VariableTable::ContainsLDynamicVariable);
      } else {
        if (ar->isFirstPass()) {
          ar->getCodeError()->record(self, CodeError::UseRDynamicVariable,
                                     self);
        }
      }
      if (m_offset) {
        m_offset->inferAndCheck(ar, NEW_TYPE(Primitive), false);
      }
      return m_implementedType = Type::Variant; // so not to lose values
    }
  }
  if (hasContext(LValue) || hasContext(RefValue)) {
    m_variable->setContext(LValue);
  }

  TypePtr varType;
  if (m_offset) {
    varType = m_variable->inferAndCheck(ar, NEW_TYPE(Sequence), false);
    m_offset->inferAndCheck(ar, NEW_TYPE(Some), false);
  } else {
    if (hasContext(ExistContext) || hasContext(UnsetContext)) {
      if (ar->isFirstPass()) {
        ar->getCodeError()->record(self, CodeError::InvalidArrayElement,
                                   self);
      }
    }
    m_variable->inferAndCheck(ar, Type::Array, true);
  }

  if (varType && Type::SameType(varType, Type::String)) {
    m_implementedType.reset();
    return Type::String;
  }

  TypePtr ret = propagateTypes(ar, Type::Variant);
  m_implementedType = Type::Variant;
  return ret; // so not to lose values
}

///////////////////////////////////////////////////////////////////////////////
// code generation functions

void ArrayElementExpression::outputPHP(CodeGenerator &cg,
                                       AnalysisResultPtr ar) {
  if (Option::ConvertSuperGlobals && m_global && !m_dynamicGlobal &&
      ar && (ar->getScope() == ar || ar->getScope()->
             getVariables()->isConvertibleSuperGlobal(m_globalName))) {
    cg.printf("$%s", m_globalName.c_str());
  } else {
    m_variable->outputPHP(cg, ar);
    cg.printf("[");
    if (m_offset) m_offset->outputPHP(cg, ar);
    cg.printf("]");
  }
}

bool ArrayElementExpression::preOutputCPP(CodeGenerator &cg,
                                          AnalysisResultPtr ar, int state) {
  return preOutputOffsetLHS(cg, ar, state);
}

void ArrayElementExpression::outputCPPImpl(CodeGenerator &cg,
                                           AnalysisResultPtr ar) {
  if (m_global) {
    if (!m_globalName.empty()) {
      VariableTablePtr variables = ar->getScope()->getVariables();
      cg.printf("g->%s",
                variables->getGlobalVariableName(ar, m_globalName).c_str());
    } else {
      cg.printf("get_variable_table()->get(");
      m_offset->outputCPP(cg, ar);
      cg.printf(")");
    }
  } else {
    TypePtr type = m_variable->getActualType();
    if (hasContext(UnsetContext)) {
      cg.printf("unsetLval(");
      m_variable->outputCPP(cg, ar);
      cg.printf(", ");
    } else {
      if (m_variable->is(Expression::KindOfScalarExpression) ||
          (type && (type->isInteger() ||
                    type->is(Type::KindOfDouble) ||
                    type->is(Type::KindOfObject) ||
                    type->is(Type::KindOfBoolean)))) {
        cg.printf(type && type->is(Type::KindOfString) ? "((String)" :
                  "((Variant)");
        m_variable->outputCPP(cg, ar);
        cg.printf(")");
      } else {
        m_variable->outputCPP(cg, ar);
      }
    }
    if (m_offset) {
      bool lvalAt = false;
      bool rvalAt = false;
      if (hasContext(UnsetContext)) {
        // do nothing
      } else if (m_context & InvokeArgument) {
        cg.printf(".refvalAt(");
      } else if (m_context & (LValue|RefValue)) {
        cg.printf(".lvalAt(");
        lvalAt = true;
      } else {
        cg.printf(".rvalAt(");
        rvalAt = true;
      }
      m_offset->outputCPP(cg, ar);
      if (!type || !type->is(Type::KindOfString)) {
        bool prehashed = false;
        ScalarExpressionPtr sc =
          dynamic_pointer_cast<ScalarExpression>(m_offset);
        if (sc) {
          int64 hash = sc->getHash();
          if (hash >= 0) {
            cg.printf(", 0x%016llXLL", hash);
            prehashed = true;
          }
        }
        if (!prehashed) {
          cg.printf(", -1");
        }
        if (rvalAt) {
          if (!hasContext(ExistContext)) {
            cg.printf(", true"); // raise undefined index error
          } else {
            cg.printf(", false");
          }
        } else if (lvalAt) {
          if (hasContext(ObjectContext)) {
            // object target might not trigger an array copy
            cg.printf(", true");
          } else {
            cg.printf(", false");
          }
        }
        if (!hasContext(UnsetContext) && sc && sc->isLiteralString()) {
          String s(sc->getLiteralString());
          int64 n;
          if (!s.get()->isStrictlyInteger(n)) {
            cg.printf(", true"); // skip toKey() at run time
          }
        }
      }
      cg.printf(")");
    } else {
      cg.printf(".lvalAt()");
    }
  }
}

void ArrayElementExpression::outputCPPExistTest(CodeGenerator &cg,
                                                AnalysisResultPtr ar, int op) {
  switch (op) {
  case T_ISSET:  cg.printf("isset("); break;
  case T_EMPTY:  cg.printf("empty("); break;
  default: ASSERT(false);
  }

  if (m_global) {
    if (!m_globalName.empty()) {
      VariableTablePtr variables = ar->getScope()->getVariables();
      cg.printf("g->%s",
                variables->getGlobalVariableName(ar, m_globalName).c_str());
    } else {
      cg.printf("get_variable_table()->get(");
      m_offset->outputCPP(cg, ar);
      cg.printf(")");
    }
  } else {
    m_variable->outputCPP(cg, ar);
    cg.printf(", ");
    m_offset->outputCPP(cg, ar);
    ScalarExpressionPtr sc =
      dynamic_pointer_cast<ScalarExpression>(m_offset);
    if (sc) {
      int64 hash = sc->getHash();
      if (hash >= 0) {
        cg.printf(", 0x%016llXLL", hash);
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
}
void ArrayElementExpression::outputCPPUnset(CodeGenerator &cg,
                                            AnalysisResultPtr ar) {
  if (isSuperGlobal()) {
    Expression::outputCPPUnset(cg, ar);
  } else {
    m_variable->outputCPP(cg, ar);
    cg.printf(".weakRemove(");
    m_offset->outputCPP(cg, ar);
    ScalarExpressionPtr sc =
      dynamic_pointer_cast<ScalarExpression>(m_offset);
    if (sc) {
      int64 hash = sc->getHash();
      if (hash >= 0) {
        cg.printf(", 0x%016llXLL", hash);
      }
    }
    cg.printf(");\n");
  }
}
