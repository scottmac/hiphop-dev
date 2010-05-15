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

#include <compiler/analysis/analysis_result.h>
#include <compiler/expression/expression.h>
#include <compiler/expression/assignment_expression.h>
#include <compiler/expression/list_assignment.h>
#include <compiler/expression/binary_op_expression.h>
#include <compiler/expression/unary_op_expression.h>
#include <compiler/expression/simple_variable.h>
#include <compiler/expression/scalar_expression.h>
#include <compiler/expression/array_element_expression.h>
#include <compiler/expression/object_property_expression.h>
#include <compiler/expression/parameter_expression.h>
#include <compiler/expression/expression_list.h>
#include <compiler/expression/expression.h>
#include <compiler/statement/statement.h>
#include <compiler/statement/statement_list.h>
#include <compiler/statement/catch_statement.h>
#include <compiler/statement/method_statement.h>
#include <compiler/analysis/alias_manager.h>
#include <compiler/analysis/variable_table.h>
#include <runtime/eval/parser/hphp.tab.hpp>
#include <util/util.h>

#define spc(T,p) boost::static_pointer_cast<T>(p)
#define dpc(T,p) boost::dynamic_pointer_cast<T>(p)

using namespace HPHP;
using std::string;

bool AliasManager::s_deadCodeElim = true;
bool AliasManager::s_localCopyProp = true;

///////////////////////////////////////////////////////////////////////////////

bool AliasManager::parseOptimizations(const std::string &optimizations,
                                      std::string &errs)
{
  size_t pos = 0;
  while ((pos = optimizations.find_first_not_of(" ,", pos)) !=
         string::npos) {
    size_t end = optimizations.find_first_of(" ,", pos);
    string opt = optimizations.substr(pos, end - pos);
    bool val = true;
    if (opt.substr(0, 3) == "no-") {
      val = false;
      opt = opt.substr(3);
    }

    if (opt == "deadcode") {
      setDeadCodeElim(val);
    } else if (opt == "localcopy") {
      setLocalCopyProp(val);
    } else if (val && (opt == "all" || opt == "none")) {
      val = opt == "all";
      setDeadCodeElim(val);
      setLocalCopyProp(val);
    } else {
      errs = "Unknown optimization: " + opt;
      return false;
    }

    if (end == string::npos) {
      break;
    }
    pos = end;
  }

  return true;
}

ExpressionPtr BucketMapEntry::find(ExpressionPtr e) {
  ExpressionPtrList::iterator it = m_exprs.begin();
  while (it != m_exprs.end()) {
    ExpressionPtr c = *it;
    if (e->canonCompare(c)) {
      return c;
    }
    ++it;
  }

  return ExpressionPtr();
}

void BucketMapEntry::add(ExpressionPtr e) {
  m_exprs.push_back(e);
  m_num++;
}

void BucketMapEntry::clear() {
  m_stack.resize(0);
  m_exprs.resize(0);
  m_num = 0;
}

void BucketMapEntry::beginScope() {
  m_stack.push_back(m_num);
}

void BucketMapEntry::endScope() {
  resetScope();
  if (m_stack.size()) {
    m_stack.pop_back();
  }
}

void BucketMapEntry::resetScope() {
  if (!m_stack.size()) {
    m_exprs.empty();
    m_num = 0;
  } else {
    m_num = m_stack.back();
    m_exprs.resize(m_num);
  }
}

void BucketMapEntry::stash(size_t from, ExpressionPtrList &to) {
  ExpressionPtrList::iterator it = m_exprs.begin(), end = m_exprs.end();
  m_num = from;
  while (from--) {
    assert(it != end);
    ++it;
  }
  while (it != end) {
    ExpressionPtr t = *it;

    to.insert(to.end(), t);
    it = m_exprs.erase(it);
  }
}

void BucketMapEntry::import(ExpressionPtrList &from) {
  m_exprs.splice(m_exprs.end(), from);
}

void AliasManager::add(BucketMapEntry &em, ExpressionPtr e) {
  em.add(e);
  e->setCanonID(m_nextID++);
}

ExpressionPtr AliasManager::getCanonical(ExpressionPtr e) {
  unsigned val = (e->getCanonHash() % MaxBuckets) + 1;

  BucketMapEntry &em = m_bucketMap[val];

  ExpressionPtr c = em.find(e);

  if (!c) {
    add(em, e);
    c = e;
    e->setCanonPtr(ExpressionPtr());
  } else {
    e->setCanonID(c->getCanonID());
    e->setCanonPtr(c);
  }

  return c;
}

void AliasManager::clearHelper(BucketMap::value_type &it) {
  it.second.clear();
}

void AliasManager::clear() {
  m_bucketMap.clear();
  m_stack.resize(0);

  //  std::for_each(m_bucketMap.begin(), m_bucketMap.end(),
  //              clearHelper);
}

void AliasManager::beginScopeHelper(BucketMap::value_type &it) {
  it.second.beginScope();
}

void AliasManager::beginScope() {
  ExpressionPtr e(new ScalarExpression(LocationPtr(),
                                       Expression::KindOfScalarExpression,
                                       T_STRING, string("begin")));
  m_bucketMap[0].add(e);
  m_stack.push_back(m_bucketMap[0].size());
  std::for_each(m_bucketMap.begin(), m_bucketMap.end(),
                beginScopeHelper);
}

void AliasManager::mergeScope() {
  if (m_stack.size()) {
    CondStackElem &cs = m_stack.back();
    BucketMapEntry &bm = m_bucketMap[0];
    bm.stash(cs.m_size, cs.m_exprs);
  }
}

void AliasManager::endScopeHelper(BucketMap::value_type &it) {
  it.second.endScope();
}

void AliasManager::endScope() {
  mergeScope();

  std::for_each(m_bucketMap.begin(), m_bucketMap.end(),
                endScopeHelper);

  if (m_stack.size()) {
    CondStackElem &cs = m_stack.back();
    BucketMapEntry &bm = m_bucketMap[0];
    bm.import(cs.m_exprs);
    ExpressionPtr
      e(new ScalarExpression(LocationPtr(),
                             Expression::KindOfScalarExpression,
                             T_STRING, string("end")));
    bm.add(e);
    m_stack.pop_back();
  }
}

void AliasManager::resetScopeHelper(BucketMap::value_type &it) {
  it.second.resetScope();
}

void AliasManager::resetScope() {
  mergeScope();
  std::for_each(m_bucketMap.begin(), m_bucketMap.end(),
                resetScopeHelper);
}

int AliasManager::testAccesses(ExpressionPtr e1, ExpressionPtr e2) {
  Expression::KindOf k1 = e1->getKindOf(), k2 = e2->getKindOf();
  while (true) {
    switch (k1) {
    case Expression::KindOfConstantExpression:
      if (e1->canonCompare(e2)) return SameAccess;
      switch (k2) {
      case Expression::KindOfObjectMethodExpression:
      case Expression::KindOfDynamicFunctionCall:
      case Expression::KindOfSimpleFunctionCall:
      case Expression::KindOfNewObjectExpression:
        return InterfAccess;
      default:
        return DisjointAccess;
      }
      break;

    case Expression::KindOfArrayElementExpression:
      if (k2 == Expression::KindOfSimpleVariable ||
          k2 == Expression::KindOfDynamicVariable ||
          k2 == Expression::KindOfConstantExpression) {
        break;
      }

      return e1->canonCompare(e2) ?
        SameAccess : InterfAccess;

    case Expression::KindOfStaticMemberExpression:
      if (k2 == Expression::KindOfSimpleVariable ||
          k2 == Expression::KindOfConstantExpression) {
        break;
      }
      return e1->canonCompare(e2) ?
        SameAccess : InterfAccess;

    case Expression::KindOfObjectPropertyExpression:
      if (k2 == Expression::KindOfSimpleVariable ||
          k2 == Expression::KindOfConstantExpression) {
        break;
      }
      return InterfAccess;

    case Expression::KindOfDynamicVariable:
      if (k2 == Expression::KindOfSimpleVariable ||
          k2 == Expression::KindOfConstantExpression) {
        break;
      }

      return e1->canonCompare(e2) ?
        SameAccess : InterfAccess;

    case Expression::KindOfSimpleVariable:
      {
        if (k2 == Expression::KindOfConstantExpression) {
          return DisjointAccess;
        }
        SimpleVariablePtr sv1 = spc(SimpleVariable, e1);
        AliasInfo &ai1 = m_aliasInfo[sv1->getName()];
        switch (k2) {
        case Expression::KindOfSimpleVariable:
          {
            SimpleVariablePtr sv2 = spc(SimpleVariable, e2);
            if (sv1->getName() == sv2->getName()) {
              return SameAccess;
            }
            AliasInfo &ai2 = m_aliasInfo[sv2->getName()];

            if (ai1.getIsRefTo() || ai1.getIsGlobal()) {
              return m_wildRefs || ai2.getIsGlobal() || ai2.checkRefLevel(0) ?
                InterfAccess : DisjointAccess;
            }

            if (ai2.getIsRefTo() || ai2.getIsGlobal()) {
              return m_wildRefs || ai1.getIsGlobal() || ai1.checkRefLevel(0) ?
                InterfAccess : DisjointAccess;
            }
          }
          return DisjointAccess;

        case Expression::KindOfDynamicVariable:
          return InterfAccess;

        case Expression::KindOfArrayElementExpression:
          if (ai1.getIsRefTo() || ai1.getIsGlobal() ||
              m_wildRefs || ai1.checkRefLevel(0)) {
            return InterfAccess;
          } else {
            // $a = "foo"; $a[0] = "x";
            ExpressionPtr var = spc(ArrayElementExpression, e2)->getVariable();
            if (e1->canonCompare(var)) {
              return InterfAccess;
            }
          }
          return DisjointAccess;

        case Expression::KindOfStaticMemberExpression:
        case Expression::KindOfObjectPropertyExpression:
        default:
          if (ai1.getIsRefTo() || ai1.getIsGlobal() || m_wildRefs) {
            return InterfAccess;
          }
          return DisjointAccess;
        }
        // mustnt get here (we would loop forever).
        ASSERT(false);
      }

    default:
      return InterfAccess;
    }

    ExpressionPtr t = e1;
    e1 = e2;
    e2 = t;
    k1 = k2;
    k2 = e2->getKindOf();
  }
}

static bool isReadOnlyAccess(ExpressionPtr e) {
  if (e->getContext() & (Expression::UnsetContext|
                         Expression::RefValue|
                         Expression::LValue)) {
    return false;
  }
  switch (e->getKindOf()) {
  case Expression::KindOfConstantExpression:
  case Expression::KindOfSimpleVariable:
  case Expression::KindOfArrayElementExpression:
  case Expression::KindOfDynamicVariable:
    return true;
  default:
    return false;
  }
}

int AliasManager::findInterf(ExpressionPtr rv, bool isLoad,
                             ExpressionPtr &rep) {
  BucketMapEntry lvs = m_bucketMap[0];

  rep = ExpressionPtr();
  ExpressionPtrList::reverse_iterator it = lvs.rbegin(), end = lvs.rend();
  int a;

  int depth = 0, min_depth = 0, max_depth = 0;
  while (it != end) {
    ExpressionPtr e = *it++;
    switch (e->getKindOf()) {
    case Expression::KindOfScalarExpression:
      {
        ScalarExpressionPtr se = spc(ScalarExpression, e);
        const std::string &s = se->getString();
        if (s == "begin") {
          depth--;
          if (depth < min_depth) min_depth = depth;
        } else if (s == "end") {
          depth++;
          if (depth > max_depth) max_depth = depth;
        } else {
          assert(false);
        }
      }
      break;

    case Expression::KindOfObjectMethodExpression:
    case Expression::KindOfDynamicFunctionCall:
    case Expression::KindOfSimpleFunctionCall:
    case Expression::KindOfNewObjectExpression:
      return testAccesses(rv, e);

    case Expression::KindOfListAssignment: {
      ListAssignmentPtr la = spc(ListAssignment, e);
      ExpressionList &lhs = *la->getVariables().get();
      for (int i = lhs.getCount(); i--; ) {
        ExpressionPtr ep = lhs[i];
        if (ep && testAccesses(ep, rv) != DisjointAccess) {
          return InterfAccess;
        }
      }
      break;
    }

    case Expression::KindOfObjectPropertyExpression:
    case Expression::KindOfConstantExpression:
    case Expression::KindOfSimpleVariable:
    case Expression::KindOfDynamicVariable:
    case Expression::KindOfArrayElementExpression:
    case Expression::KindOfStaticMemberExpression:
      a = testAccesses(e, rv);
      if (a == DisjointAccess) {
        continue;
      }
      if (a == SameAccess) {
        if (isLoad) {
          // The value of an earlier load is available
          // if it dominates this one
          if (depth > min_depth) {
            a = InterfAccess;
          }
        } else {
          // The assignment definitely hits the load
          // if it post-dominates it.
          if (min_depth < 0) {
            a = InterfAccess;
          }
        }
      }
      if (a != SameAccess &&
          isLoad && isReadOnlyAccess(e)) {
        continue;
      }
      rep = e;
      return a;

    case Expression::KindOfUnaryOpExpression:
      a = testAccesses(spc(UnaryOpExpression,e)->getExpression(), rv);
      goto handle_assign;
    case Expression::KindOfBinaryOpExpression:
      a = testAccesses(spc(BinaryOpExpression,e)->getExp1(), rv);
      goto handle_assign;
    case Expression::KindOfAssignmentExpression:
      a = testAccesses(spc(AssignmentExpression,e)->getVariable(), rv);
      goto handle_assign;

    handle_assign:
      if (a == DisjointAccess) {
        continue;
      }
      rep = e;
      if (a == SameAccess) {
        if (isLoad) {
          // we can propagate the value of an assignment
          // to a load, provided the assignment dominates
          // the load.
          if (depth > min_depth) {
            a = InterfAccess;
          }
        } else {
          // a later assignment kills an earlier one
          // provided the later one post-dominates the earlier
          if (min_depth < 0) {
            a = InterfAccess;
          }
        }
      }
      return a;

    default:
      break;
    }
  }
  return DisjointAccess;
}

static int getOpForAssignmentOp(int op) {
  switch (op) {
  case T_PLUS_EQUAL: return '+';
  case T_MINUS_EQUAL: return '-';
  case T_MUL_EQUAL: return '*';
  case T_DIV_EQUAL: return '/';
  case T_CONCAT_EQUAL: return '.';
  case T_MOD_EQUAL: return '%';
  case T_AND_EQUAL: return '&';
  case T_OR_EQUAL: return '|';
  case T_XOR_EQUAL: return '^';
  case T_SL_EQUAL: return T_SL;
  case T_SR_EQUAL: return T_SR;
  default: return 0;
  }
}

ExpressionPtr AliasManager::canonicalizeNonNull(ExpressionPtr e)
{
  ExpressionPtr r = canonicalizeNode(e);
  return r ? r : e;
}

ExpressionPtr AliasManager::canonicalizeNode(ExpressionPtr e) {
  e->setCanonPtr(ExpressionPtr());
  e->setCanonID(0);

  switch (e->getKindOf()) {
  case Expression::KindOfObjectMethodExpression:
  case Expression::KindOfDynamicFunctionCall:
  case Expression::KindOfSimpleFunctionCall:
  case Expression::KindOfNewObjectExpression:
    add(m_bucketMap[0], e);
    break;

  case Expression::KindOfListAssignment:
    add(m_bucketMap[0], e);
    break;

  case Expression::KindOfAssignmentExpression: {
    AssignmentExpressionPtr ae = spc(AssignmentExpression,e);
    if (e->getContext() & Expression::DeadStore) {
      Construct::recomputeEffects();
      return ae->getValue();
    }
    ExpressionPtr rep;
    int interf = findInterf(ae->getVariable(), false, rep);
    if (interf == SameAccess) {
      switch (rep->getKindOf()) {
      default:
        break;
      case Expression::KindOfAssignmentExpression:
        {
          AssignmentExpressionPtr a = spc(AssignmentExpression, rep);
          ExpressionPtr value = a->getValue();
          if (a->getValue()->getContext() & Expression::RefValue) {
            break;
          }
        }
      case Expression::KindOfUnaryOpExpression:
      case Expression::KindOfBinaryOpExpression:
        rep->setContext(Expression::DeadStore);
        break;
      }
    }
    add(m_bucketMap[0], e);
    break;
  }

  case Expression::KindOfConstantExpression:
  case Expression::KindOfSimpleVariable:
  case Expression::KindOfDynamicVariable:
  case Expression::KindOfArrayElementExpression:
  case Expression::KindOfObjectPropertyExpression:
  case Expression::KindOfStaticMemberExpression:
    if (!(e->getContext() & (Expression::AssignmentLHS|
                             Expression::DeepAssignmentLHS|
                             Expression::OprLValue))) {
      if (!(e->getContext() & (Expression::LValue|
                               Expression::RefValue|
                               Expression::RefParameter|
                               Expression::UnsetContext))) {
        ExpressionPtr rep;
        int interf = findInterf(e, true, rep);
        if (interf == SameAccess) {
          if (rep->getKindOf() == e->getKindOf()) {
            e->setCanonID(rep->getCanonID());
            e->setCanonPtr(rep);
            return ExpressionPtr();
          }
          if (rep->getKindOf() == Expression::KindOfAssignmentExpression) {
            ExpressionPtr rhs = spc(AssignmentExpression,rep)->getValue();
            if (rhs->is(Expression::KindOfScalarExpression)) {
              rhs = rhs->clone();
              getCanonical(rhs);
              return rhs;
            }
            e->setCanonPtr(rhs);
          }
        }
      }
      add(m_bucketMap[0], e);
    } else {
      getCanonical(e);
    }
    break;

  case Expression::KindOfBinaryOpExpression: {
    BinaryOpExpressionPtr bop = spc(BinaryOpExpression, e);

    int rop = getOpForAssignmentOp(bop->getOp());
    if (rop) {
      ExpressionPtr lhs = bop->getExp1();
      ExpressionPtr rep;
      if (bop->getContext() & Expression::DeadStore) {
        Construct::recomputeEffects();
        ExpressionPtr rhs = bop->getExp2()->clone();
        lhs = lhs->clone();
        lhs->clearContext(Expression::LValue);
        lhs->clearContext(Expression::NoLValueWrapper);
        lhs->clearContext(Expression::OprLValue);
        rep = ExpressionPtr
          (new BinaryOpExpression(e->getLocation(),
                                  Expression::KindOfBinaryOpExpression,
                                  lhs, rhs, rop));

      } else {
        ExpressionPtr alt;
        int interf = findInterf(lhs, true, alt);
        if (interf == SameAccess &&
            alt->is(Expression::KindOfAssignmentExpression)) {
          ExpressionPtr op0 = spc(AssignmentExpression,alt)->getValue();
          if (op0->is(Expression::KindOfScalarExpression)) {
            ExpressionPtr op1 = bop->getExp2();
            ExpressionPtr rhs
              (new BinaryOpExpression(e->getLocation(),
                                      Expression::KindOfBinaryOpExpression,
                                      op0->clone(), op1->clone(), rop));

            lhs = lhs->clone();
            lhs->clearContext(Expression::OprLValue);
            rep = ExpressionPtr
              (new AssignmentExpression(e->getLocation(),
                                        Expression::KindOfAssignmentExpression,
                                        lhs, rhs, false));
          }
        }
      }
      if (rep) {
        ExpressionPtr c = canonicalizeRecur(rep);
        return c ? c : rep;
      }
      add(m_bucketMap[0], e);
    } else {
      getCanonical(e);
    }
    break;
  }

  case Expression::KindOfUnaryOpExpression:
    {
      UnaryOpExpressionPtr uop = spc(UnaryOpExpression, e);
      switch (uop->getOp()) {
      case T_INC:
      case T_DEC:
        if (uop->getContext() & Expression::DeadStore) {
          Construct::recomputeEffects();
          ExpressionPtr val = uop->getExpression()->clone();
          val->clearContext(Expression::LValue);
          val->clearContext(Expression::NoLValueWrapper);
          val->clearContext(Expression::OprLValue);
          if (uop->getFront()) {
            ExpressionPtr inc
              (new ScalarExpression(uop->getLocation(),
                                    Expression::KindOfScalarExpression,
                                    T_LNUMBER, string("1")));

            val = ExpressionPtr
              (new BinaryOpExpression(uop->getLocation(),
                                      Expression::KindOfBinaryOpExpression,
                                      val, inc,
                                      uop->getOp() == T_INC ? '+' : '-'));

          }

          ExpressionPtr r = canonicalizeRecur(val);
          return r ? r : val;
        }
        add(m_bucketMap[0], e);
        break;
      default:
        getCanonical(e);
        break;
      }
      break;
    }

  default:
    getCanonical(e);
    break;
  }

  return ExpressionPtr();
}

void AliasManager::canonicalizeKid(ConstructPtr e, ExpressionPtr kid, int i) {
  if (kid) {
    kid = canonicalizeRecur(kid);
    if (kid) {
      e->setNthKid(i, kid);
      m_changed = true;
    }
  }
}

ExpressionPtr AliasManager::canonicalizeRecur(ExpressionPtr e) {
  switch (e->getKindOf()) {
  case Expression::KindOfQOpExpression:
    canonicalizeKid(e, e->getNthExpr(0), 0);
    beginScope();
    canonicalizeKid(e, e->getNthExpr(1), 1);
    resetScope();
    canonicalizeKid(e, e->getNthExpr(2), 2);
    endScope();
    return canonicalizeNode(e);

  case Expression::KindOfBinaryOpExpression:
    if (spc(BinaryOpExpression,e)->isShortCircuitOperator()) {
      canonicalizeKid(e, e->getNthExpr(0), 0);
      beginScope();
      canonicalizeKid(e, e->getNthExpr(1), 1);
      endScope();
      return canonicalizeNode(e);
    }
    break;

  default:
    break;
  }

  for (int i = 0, n = e->getKidCount(); i < n; i++) {
    canonicalizeKid(e, e->getNthExpr(i), i);
  }

  return canonicalizeNode(e);
}

int AliasManager::canonicalizeRecur(StatementPtr s) {
  if (!s) return FallThrough;

  Statement::KindOf stype = s->getKindOf();
  int ret = FallThrough;
  int start = 0;

  switch (stype) {
  case Statement::KindOfFunctionStatement:
  case Statement::KindOfMethodStatement:
  case Statement::KindOfClassStatement:
  case Statement::KindOfInterfaceStatement:
    // Dont handle nested functions
    // they will be dealt with by another
    // top level call to optimize
    return ret;
  case Statement::KindOfStaticStatement:
    clear();
    ret = Converge;
    break;
  case Statement::KindOfClassVariable:
    clear();
    ret = Branch;
  case Statement::KindOfClassConstant:
  case Statement::KindOfGlobalStatement:
  case Statement::KindOfEchoStatement:
  case Statement::KindOfUnsetStatement:
  case Statement::KindOfExpStatement:
  case Statement::KindOfStatementList:
  case Statement::KindOfBlockStatement:
  case Statement::KindOfTryStatement:
    // No special action, just execute
    // and fall through
    break;

  case Statement::KindOfIfStatement:
    {
      StatementPtr iflist = spc(Statement, s->getNthKid(0));
      if (iflist) {
        for (int i = 0, n = iflist->getKidCount(); i < n; i++) {
          StatementPtr ifstmt = spc(Statement, iflist->getNthKid(i));
          ExpressionPtr cond = spc(Expression, ifstmt->getNthKid(0));
          canonicalizeKid(ifstmt, cond, 0);
          if (!i) beginScope();
          beginScope();
          canonicalizeRecur(spc(Statement, ifstmt->getNthKid(1)));
          endScope();
          if (i+1 < n) resetScope();
        }
        endScope();
      }
      ret = Converge;
      return FallThrough;
    }
    break;

  case Statement::KindOfIfBranchStatement:
    assert(0);
    break;

  case Statement::KindOfForStatement:
    canonicalizeKid(s, spc(Expression,s->getNthKid(0)), 0);
    clear();
    canonicalizeKid(s, spc(Expression,s->getNthKid(1)), 1);
    canonicalizeRecur(spc(Statement, s->getNthKid(2)));
    clear();
    canonicalizeKid(s, spc(Expression,s->getNthKid(3)), 3);
    return Converge;

  case Statement::KindOfWhileStatement:
  case Statement::KindOfDoStatement:
  case Statement::KindOfForEachStatement:
    clear();
    ret = Converge;
    break;

  case Statement::KindOfSwitchStatement:
    canonicalizeKid(s, spc(Expression,s->getNthKid(0)), 0);
    clear();
    start = 1;
    ret = Converge;
    break;

  case Statement::KindOfCaseStatement:
    clear();
    break;

  case Statement::KindOfBreakStatement:
  case Statement::KindOfContinueStatement:
  case Statement::KindOfReturnStatement:
    ret = Branch;
    break;

  case Statement::KindOfCatchStatement:
    clear();
    ret = Converge;
    break;

  case Statement::KindOfThrowStatement:
    ret = Branch;
    break;
  }

  int nkid = s->getKidCount();
  for (int i = start; i < nkid; i++) {
    ConstructPtr cp = s->getNthKid(i);
    if (!cp) {
      continue;
    }
    if (StatementPtr skid = dpc(Statement, cp)) {
      int action = canonicalizeRecur(skid);
      switch (action) {
      case FallThrough:
      case CondBranch:
        break;
      case Branch:
        clear();
        break;
      case Converge:
        clear();
        break;
      }
    } else {
      canonicalizeKid(s, spc(Expression, cp), i);
    }
  }

  return ret;
}

void AliasManager::collectAliasInfoRecur(ConstructPtr cs) {
  if (!cs) {
    return;
  }

  if (StatementPtr s = dpc(Statement, cs)) {
    switch (s->getKindOf()) {
      case Statement::KindOfFunctionStatement:
      case Statement::KindOfMethodStatement:
      case Statement::KindOfClassStatement:
      case Statement::KindOfInterfaceStatement:
        return;
      default:
        break;
    }
  }

  int nkid = cs->getKidCount();

  for (int i = 0; i < nkid; i++) {
    ConstructPtr kid = cs->getNthKid(i);
    if (kid) {
      collectAliasInfoRecur(kid);
    }
  }

  if (ExpressionPtr e = dpc(Expression, cs)) {
    int context = e->getContext();
    switch (e->getKindOf()) {
    case Expression::KindOfAssignmentExpression:
      {
        AssignmentExpressionPtr ae = spc(AssignmentExpression, e);
        ExpressionPtr var = ae->getVariable();
        ExpressionPtr val = ae->getValue();
        if (var->is(Expression::KindOfSimpleVariable)) {
          const std::string &name = spc(SimpleVariable, var)->getName();
          AliasInfo &ai = m_aliasInfo[name];
          if (val->getContext() & Expression::RefValue) {
            ai.setIsRefTo();
            m_variables->addUsed(name);
          } else {
            Expression::checkUsed(m_arp, var, val);
          }
        }
      }
      break;
    case Expression::KindOfListAssignment:
      {
        ListAssignmentPtr la = spc(ListAssignment, e);
        ExpressionListPtr vars = la->getVariables();
        for (int i = vars->getCount(); i--; ) {
          ExpressionPtr v = (*vars)[i];
          if (v && v->is(Expression::KindOfSimpleVariable)) {
            SimpleVariablePtr sv = spc(SimpleVariable, v);
            m_variables->addUsed(sv->getName());
          }
        }
      }
      break;
    case Expression::KindOfSimpleVariable:
      {
        const std::string &name = spc(SimpleVariable, e)->getName();
        if (context & Expression::RefValue) {
          AliasInfo &ai = m_aliasInfo[name];
          ai.addRefLevel(0);
        }
        if (!(context & (Expression::AssignmentLHS |
                         Expression::UnsetContext))) {
          m_variables->addUsed(name);
        }
      }
      break;
    case Expression::KindOfDynamicVariable:
      if (context & Expression::RefValue) {
        m_wildRefs = true;
      }
      break;
    case Expression::KindOfArrayElementExpression:
      {
        int n = 1;
        while (n < 10 &&
               e->is(Expression::KindOfArrayElementExpression)) {
          e = spc(ArrayElementExpression, e)->getVariable();
        }
        if (e->is(Expression::KindOfSimpleVariable)) {
          const std::string &name = spc(SimpleVariable, e)->getName();
          if (context & Expression::RefValue) {
            AliasInfo &ai = m_aliasInfo[name];
            ai.addRefLevel(n);
          }
          m_variables->addUsed(name); // need this for UnsetContext
        }
      }
      break;
    case Expression::KindOfObjectPropertyExpression:
      {
        e = spc(ObjectPropertyExpression, e)->getObject();
        if (e->is(Expression::KindOfSimpleVariable)) {
          const std::string &name = spc(SimpleVariable, e)->getName();
          if (context & Expression::RefValue) {
            AliasInfo &ai = m_aliasInfo[name];
            ai.addRefLevel(1);
          }
          m_variables->addUsed(name); // need this for UnsetContext
        }
      }
      break;
    default:
      break;
    }
  } else {
    StatementPtr s = spc(Statement, cs);
    switch (s->getKindOf()) {
    case Statement::KindOfCatchStatement:
      {
        const std::string &name = spc(CatchStatement, s)->getVariable();
        m_variables->addUsed(name);
        break;
      }
    default:
      break;
    }
  }
}

bool AliasManager::optimize(AnalysisResultPtr ar, MethodStatementPtr m) {
  m_arp = ar;

  m_variables = ar->getScope()->getVariables();
  if (!m_variables->isPseudoMainTable()) {
    m_variables->clearUsed();
  }

  if (ExpressionListPtr pPtr = m->getParams()) {
    ExpressionList &params = *pPtr;
    for (int i = params.getCount(); i--; ) {
      ParameterExpressionPtr p = spc(ParameterExpression, params[i]);
      AliasInfo &ai = m_aliasInfo[p->getName()];
      if (p->isRef()) {
        ai.setIsRefTo();
      }
    }
  }

  collectAliasInfoRecur(m->getStmts());

  for (AliasInfoMap::iterator it = m_aliasInfo.begin(),
         end = m_aliasInfo.end(); it != end; ++it) {
    if (m_variables->isGlobal(it->first) ||
        m_variables->isStatic(it->first)) {
      it->second.setIsGlobal();
    }
  }

  canonicalizeRecur(m->getStmts());
  return m_changed;
}

