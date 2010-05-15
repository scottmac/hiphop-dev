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

#include <runtime/eval/ast/echo_statement.h>
#include <runtime/eval/ast/expression.h>
#include <runtime/eval/bytecode/bytecode.h>

using namespace std;

namespace HPHP {
namespace Eval {
///////////////////////////////////////////////////////////////////////////////

EchoStatement::EchoStatement(STATEMENT_ARGS,
                             const std::vector<ExpressionPtr> &args)
  : Statement(STATEMENT_PASS), m_args(args) {}

void EchoStatement::eval(VariableEnvironment &env) const {
  ENTER_STMT;
  for (vector<ExpressionPtr>::const_iterator it = m_args.begin();
       it != m_args.end(); ++it) {
    echo((*it)->eval(env));
  }
}

void EchoStatement::dump() const {
  printf("echo(");
  dumpVector(m_args, ", ");
  printf(");");
}

void EchoStatement::byteCode(ByteCodeProgram &code) const {
  for (vector<ExpressionPtr>::const_iterator it = m_args.begin();
       it != m_args.end(); ++it) {
    (*it)->byteCodeEval(code);
    code.add(ByteCode::Echo);
  }
}


///////////////////////////////////////////////////////////////////////////////
}
}

