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

#ifndef __STATIC_MEMBER_EXPRESSION_H__
#define __STATIC_MEMBER_EXPRESSION_H__

#include <compiler/expression/expression.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

DECLARE_BOOST_TYPES(StaticMemberExpression);

class StaticMemberExpression : public Expression {
public:
  StaticMemberExpression(EXPRESSION_CONSTRUCTOR_PARAMETERS,
                         const std::string &className, ExpressionPtr exp);

  DECLARE_EXPRESSION_VIRTUAL_FUNCTIONS;
  virtual int getLocalEffects() const { return NoEffect; }
  virtual bool isRefable(bool checkError = false) const { return true;}

  virtual unsigned getCanonHash() const;
  virtual bool canonCompare(ExpressionPtr e) const;
  void preOutputStash(CodeGenerator &cg, AnalysisResultPtr ar,
                      int state);
private:
  std::string m_origClassName;
  std::string m_className;
  ExpressionPtr m_exp;

  bool m_valid;
  std::string m_resolvedClassName;

  bool m_dynamicClass;
  bool m_redeclared;
};

///////////////////////////////////////////////////////////////////////////////
}
#endif // __STATIC_MEMBER_EXPRESSION_H__
