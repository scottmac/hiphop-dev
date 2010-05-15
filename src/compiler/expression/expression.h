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

#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include <compiler/construct.h>
#include <compiler/analysis/type.h>
#include <compiler/analysis/analysis_result.h>

#define EXPRESSION_CONSTRUCTOR_PARAMETERS       \
  LocationPtr loc, Expression::KindOf kindOf
#define EXPRESSION_CONSTRUCTOR_PARAMETER_VALUES \
  loc, kindOf
#define DECLARE_BASE_EXPRESSION_VIRTUAL_FUNCTIONS                       \
  virtual void analyzeProgram(AnalysisResultPtr ar);                    \
  virtual ExpressionPtr clone();                                        \
  virtual ExpressionPtr preOptimize(AnalysisResultPtr ar);              \
  virtual ExpressionPtr postOptimize(AnalysisResultPtr ar);             \
  virtual TypePtr inferTypes(AnalysisResultPtr ar, TypePtr type,        \
                             bool coerce);                              \
  virtual void outputPHP(CodeGenerator &cg, AnalysisResultPtr ar);      \
  virtual void outputCPPImpl(CodeGenerator &cg, AnalysisResultPtr ar)
#define DECLARE_EXPRESSION_VIRTUAL_FUNCTIONS                            \
  DECLARE_BASE_EXPRESSION_VIRTUAL_FUNCTIONS;                            \
  virtual ConstructPtr getNthKid(int n) const;                          \
  virtual int getKidCount() const;                                      \
  virtual void setNthKid(int n, ConstructPtr cp)

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

DECLARE_BOOST_TYPES(Statement);
DECLARE_BOOST_TYPES(Expression);
class Variant;

class Expression : public Construct {
public:
  enum KindOf {
    KindOfExpressionList,
    KindOfAssignmentExpression,
    KindOfSimpleVariable,
    KindOfDynamicVariable,
    KindOfStaticMemberExpression,
    KindOfArrayElementExpression,
    KindOfDynamicFunctionCall,
    KindOfSimpleFunctionCall,
    KindOfScalarExpression,
    KindOfObjectPropertyExpression,
    KindOfObjectMethodExpression,
    KindOfListAssignment,
    KindOfNewObjectExpression,
    KindOfUnaryOpExpression,
    KindOfIncludeExpression,
    KindOfBinaryOpExpression,
    KindOfQOpExpression,
    KindOfArrayPairExpression,
    KindOfClassConstantExpression,
    KindOfParameterExpression,
    KindOfModifierExpression,
    KindOfConstantExpression,
    KindOfEncapsListExpression,
    /* KindOfCount = 22 */
  };

  enum Context {
    RValue       = 0,
    LValue       = 1,            // assignment exp; foreach stmt
    Declaration  = LValue | 2,   // global or static stmt
    NoLValueWrapper = 4,         // ok to not have lval() wrapper
    RefValue  = 8,               // &exp
    NoRefWrapper = 0x10,         // ok to not have ref() wrapper
    ObjectContext = 0x20,        // $obj->
    InParameterExpression = 0x40,// for default value expression
    ExistContext = 0x80,         // isset(...) or empty(...) recursively
    UnsetContext = 0x100,        // Within unset(...), arr el recursively
    AssignmentLHS = 0x200,       // LHS in assignment
    DeepAssignmentLHS = 0x400,   // LHS in assignment, deep
    InvokeArgument = 0x800,      // Invoke arguments
    RefParameter   = 0x1000,     // eg f(&$x)
    OprLValue = 0x2000,          // Lhs of op=, or operand of ++,--
    DeadStore = 0x4000,          // This is an assignment, op=, or ++/--
                                 // which can be killed
    CondExpr = 0x8000,           // Used by alias manager to track expressions
                                 // which are conditionally executed
    AssignmentRHS = 0x10000      // RHS in assignment
  };

  enum Order {
    FixOrder  = 1,
    StashVars = 2
  };

  enum Error {
    NoError = 0,
    BadPassByRef = 1,
  };

public:
  Expression(EXPRESSION_CONSTRUCTOR_PARAMETERS);

  /**
   * Set this expression's context.
   */
  virtual void setContext(Context context) { m_context |= context;}
  virtual void clearContext(Context context) { m_context &= ~context;}
  int getContext() const { return m_context;}
  bool hasContext(Context context) const { return m_context & context; }

  /**
   * Set this expression's error flags.
   */
  virtual void setError(Error error) { m_error |= error;}
  virtual void clearError(Error error) { m_error &= ~error;}
  int getError() const { return m_error;}
  bool hasError(Error error) const { return m_error & error; }

  /**
   * Implementing Construct.
   */
  virtual void outputCPP(CodeGenerator &cg, AnalysisResultPtr ar);
  virtual void outputCPPImpl(CodeGenerator &cg, AnalysisResultPtr ar) = 0;
  void outputCPPCast(CodeGenerator &cg, AnalysisResultPtr ar);
  virtual void outputCPPDecl(CodeGenerator &cg, AnalysisResultPtr ar);

  virtual void outputCPPExistTest(CodeGenerator &cg, AnalysisResultPtr ar,
                                  int op);
  virtual void outputCPPUnset(CodeGenerator &cg, AnalysisResultPtr ar);
  virtual void preOutputStash(CodeGenerator &cg, AnalysisResultPtr ar,
                              int state);
  virtual bool outputCPPUnneeded(CodeGenerator &cg, AnalysisResultPtr ar);
  bool outputCPPBegin(CodeGenerator &cg, AnalysisResultPtr ar);
  bool outputCPPEnd(CodeGenerator &cg, AnalysisResultPtr ar);
  virtual bool preOutputCPP(CodeGenerator &cg, AnalysisResultPtr ar,
                            int state);
  bool preOutputOffsetLHS(CodeGenerator &cg, AnalysisResultPtr ar,
                          int state);
  bool hasCPPTemp() const { return !m_cppTemp.empty(); }
  const std::string &cppTemp() const { return m_cppTemp; }
  std::string genCPPTemp(CodeGenerator &cg, AnalysisResultPtr ar);
  void setCPPTemp(const std::string &s) { m_cppTemp = s; }
  /**
    * For generic walks
    */
  virtual int getKidCount() const { return 0; }
  ExpressionPtr getNthExpr(int n) const { return
      boost::static_pointer_cast<Expression>(getNthKid(n)); }

  /**
   * For cse & canonicalization
   */
  virtual unsigned getCanonHash() const;
  virtual bool canonCompare(ExpressionPtr e) const;
  void setCanonID(unsigned id) { m_canon_id = id; }
  unsigned getCanonID() const { return m_canon_id; }
  void setCanonPtr(ExpressionPtr e) { m_canonPtr = e; }
  ExpressionPtr getCanonPtr() const { return m_canonPtr; }

  /**
   * Type checking without RTTI.
   */
  bool is(KindOf kindOf) const { return m_kindOf == kindOf;}
  KindOf getKindOf() const { return m_kindOf;}
  virtual bool isScalar() const { return false;}
  virtual bool isRefable(bool checkError = false) const { return false;}
  virtual bool getScalarValue(Variant &value) { return false;}
  virtual ExpressionPtr clone() {
    ASSERT(false);
    return ExpressionPtr();
  }
  virtual bool isThis() const { return false;}
  virtual bool isLiteralString() const { return false;}
  virtual std::string getLiteralString() const { return "";}
  virtual bool containsDynamicConstant(AnalysisResultPtr ar) const {
    return false;
  }
  void deepCopy(ExpressionPtr exp);
  ExpressionPtr unneeded(AnalysisResultPtr ar);
  virtual ExpressionPtr unneededHelper(AnalysisResultPtr ar);

  /**
   * This is to avoid dynamic casting to ExpressionList in Parser.
   */
  virtual void addElement(ExpressionPtr exp);
  virtual void insertElement(ExpressionPtr exp, int index = 0);

  /**
   * Called before type inference.
   */
  virtual ExpressionPtr preOptimize(AnalysisResultPtr ar) = 0;

  /**
   * Called after type inference.
   */
  virtual ExpressionPtr postOptimize(AnalysisResultPtr ar) = 0;

  /**
   * Find other types that have been inferred for this expression,
   * and apply combine them with inType to form a new, tighter
   * type.
   */
  TypePtr propagateTypes(AnalysisResultPtr ar, TypePtr inType);

  /**
   * Called when types need to be inferred inside this expression.
   *
   * When coerce is true, it means this expression will have to be able to
   * hold that type of data. When it's false, it means as long as this
   * expression can be converted to the type, we are fine.
   *
   * This is the key function to understand in order to understand type
   * inference. Basically, "type" parameter is "expected" type, under
   * either l-value context, when coerce == true, or r-value context, when
   * coerce == false. But it's not always l-value context that "coerce" can
   * be set to true, since for example, there are cases like foreach ($a ...)
   * that we know $a needs to be an Array for sure. Some l-value context
   * cannot set "coerce" to true, for example $a++, which doesn't actually
   * change $a's type to anything new.
   *
   * Return type is ALWAYS an r-value type that this expression is evaluated
   * to. It's always up to this expression's parent to determine whether this
   * returned type is used as a "coerce"-d one or not onto another
   * expression.
   *
   * @param type  This expression is evaluated as this type.
   * @coerce      Whether to force this expression to be that type.
   * @return      What type this expression is evaluated to.
   */
  virtual TypePtr inferTypes(AnalysisResultPtr ar, TypePtr type,
                             bool coerce) = 0;

  /**
   * Call inferTypes() and check to make sure return type is convertible
   * to specified type. If not, raise a CodeError.
   */
  virtual TypePtr inferAndCheck(AnalysisResultPtr ar, TypePtr type,
                                bool coerce);

  /**
   * Check to make sure return type is convertible to specified type.
   * If not, raise a CodeError.
   */
  TypePtr checkTypesImpl(AnalysisResultPtr ar, TypePtr expectedType,
                         TypePtr actualType, bool coerce);

  TypePtr getActualType() { return m_actualType;}
  TypePtr getExpectedType() { return m_expectedType;}
  TypePtr getImplementedType() { return m_implementedType;}
  void setActualType(TypePtr actualType) {
    m_actualType = actualType;
  }
  void setExpectedType(TypePtr expectedType) {
    m_expectedType = expectedType;
  }
  TypePtr getType();

  static ExpressionPtr makeConstant(AnalysisResultPtr ar,
                                    LocationPtr loc,
                                    const std::string &value);
  static void checkPassByReference(AnalysisResultPtr ar,
                                   ExpressionPtr param);

  static void checkUsed(AnalysisResultPtr ar, ExpressionPtr variable,
                        ExpressionPtr value);

protected:
  static bool isIdentifier(const std::string &value);

  KindOf m_kindOf;
  int m_context;
  TypePtr m_actualType;
  TypePtr m_expectedType; // null if the same as m_actualType
  TypePtr m_implementedType; // null if the same as m_actualType
  std::string m_cppTemp;

  TypePtr inferAssignmentTypes(AnalysisResultPtr ar, TypePtr type,
                               bool coerce, ExpressionPtr variable,
                               ExpressionPtr value = ExpressionPtr());
  void setTypes(TypePtr actualType, TypePtr expectedType);
  void setDynamicByIdentifier(AnalysisResultPtr ar,
                              const std::string &value);
  bool outputLineMap(CodeGenerator &cg, AnalysisResultPtr ar,
                     bool force = false);

 private:
  void outputCPPInternal(CodeGenerator &cg, AnalysisResultPtr ar);

  unsigned m_canon_id;
  ExpressionPtr m_canonPtr;
  mutable int m_error;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXPRESSION_H__
