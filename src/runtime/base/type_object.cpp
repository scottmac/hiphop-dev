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

#include <runtime/base/type_object.h>
#include <runtime/base/object_offset.h>
#include <runtime/base/builtin_functions.h>
#include <runtime/base/variable_serializer.h>
#include <system/gen/php/classes/stdclass.h>

namespace HPHP {

const Object Object::s_nullObject = Object();

///////////////////////////////////////////////////////////////////////////////

Array Object::toArray() const {
  return m_px ? m_px->o_toArray() : Array();
}

Variant Object::toKey() const {
  return m_px ? (isResource() ? m_px->o_toInt64() : m_px->t___tostring())
              : String();
}

bool Object::equal(CObjRef v2) const {
  if (m_px == v2.get())
    return true;
  if (!m_px || !v2.get())
    return false;
  if (isResource() || v2.isResource())
    return false;
  return (v2.get()->o_isClass(m_px->o_getClassName()) &&
          toArray().equal(v2.toArray()));
}

bool Object::less(CObjRef v2) const { return toArray().less(v2.toArray());}
bool Object::more(CObjRef v2) const { return toArray().more(v2.toArray());}

Variant Object::o_get(CStrRef propName, int64 hash /* = -1 */,
    bool error /* = true */) const {
  if (!m_px) throw NullPointerException();
  return m_px->o_get(propName, hash, error);
}

ObjectOffset Object::o_lval(CStrRef propName, int64 hash /* = -1 */) {
  if (!m_px) {
    operator=(NEW(c_stdclass)());
  }
  return ObjectOffset(m_px, propName, hash);
}

///////////////////////////////////////////////////////////////////////////////
// output

void Object::serialize(VariableSerializer *serializer) const {
  if (m_px) {
    m_px->serialize(serializer);
  } else {
    serializer->writeNull();
  }
}

bool Object::unserialize(std::istream &in) {
  throw NotImplementedException(__func__);
}

///////////////////////////////////////////////////////////////////////////////
}
