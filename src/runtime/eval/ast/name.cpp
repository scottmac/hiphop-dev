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

#include <runtime/eval/ast/name.h>
#include <runtime/eval/ast/expression.h>
#include <runtime/base/type_string.h>
#include <util/util.h>
#include <runtime/eval/bytecode/bytecode.h>

namespace HPHP {
namespace Eval {
using namespace std;
///////////////////////////////////////////////////////////////////////////////

Name::Name(CONSTRUCT_ARGS) : Construct(CONSTRUCT_PASS) {}

int64 Name::hash() const {
  return -1;
}
int64 Name::hashLwr() const {
  return -1;
}

NamePtr Name::fromString(CONSTRUCT_ARGS, const string &name) {
  return NamePtr(new StringName(CONSTRUCT_PASS, name));
}

NamePtr Name::fromExp(CONSTRUCT_ARGS, ExpressionPtr e) {
  return NamePtr(new ExprName(CONSTRUCT_PASS, e));
}

StringName::StringName(CONSTRUCT_ARGS, const string &name)
  : Name(CONSTRUCT_PASS), m_name(name),
    m_hash(hash_string(m_name.c_str(), m_name.size())),
    m_hashLwr(hash_string_i(m_name.c_str(), m_name.size())),
    m_sname(m_name.c_str(), m_name.size()) {}

String StringName::get(VariableEnvironment &env) const {
  return getStatic();
}

String StringName::getStatic() const {
  return m_sname;
}

int64 StringName::hash() const {
  return m_hash;
}
int64 StringName::hashLwr() const {
  return m_hashLwr;
}


void StringName::dump() const {
  printf("%s", m_name.c_str());
}

void StringName::byteCode(ByteCodeProgram &code) const {
  code.add(ByteCode::String, (void*)m_sname.get());
}

ExprName::ExprName(CONSTRUCT_ARGS, ExpressionPtr name)
  : Name(CONSTRUCT_PASS), m_name(name) {}

String ExprName::get(VariableEnvironment &env) const {
  return m_name->eval(env).toString();
}

void ExprName::dump() const {
  printf("${");
  m_name->dump();
  printf("}");
}

void ExprName::byteCode(ByteCodeProgram &code) const {
  m_name->byteCodeEval(code);
}

///////////////////////////////////////////////////////////////////////////////
}
}

