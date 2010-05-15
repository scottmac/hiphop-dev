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

#ifndef __HPHP_OBJECT_H__
#define __HPHP_OBJECT_H__

#include <runtime/base/util/smart_ptr.h>
#include <runtime/base/object_data.h>
#include <runtime/base/type_string.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

#define null_object Object::s_nullObject

/**
 * Object type wrapping around ObjectData to implement reference count.
 */
class Object : public SmartPtr<ObjectData> {
 public:
  Object() {}

  static const Object s_nullObject;

  /**
   * Constructors
   */
  Object(ObjectData *data) : SmartPtr<ObjectData>(data) { }
  template <typename T>
  Object(T *data) : SmartPtr<ObjectData>() {
    // Assert that casting does not adjust the 'this' pointer
    ASSERT((void*)dynamic_cast<ObjectData*>(data) == (void*)data);
    // Performs a static_cast from T* to ObjectData*. This statement will
    // cause a compile time failure if T is not a descendent of ObjectData
    // in the inheritance hierarchy
    SmartPtr<ObjectData>::operator=(static_cast<ObjectData*>(data));
  }

  Object(CObjRef src) : SmartPtr<ObjectData>(src.m_px) { }

  /**
   * Informational
   */
  bool isNull() const {
    return m_px == NULL;
  }
  bool isResource() const {
    return m_px && m_px->isResource();
  }
  bool instanceof(const char *s) const {
    return m_px && m_px->o_instanceof(s);
  }

  /**
   * getTyped() and is() are intended for use with classes only. Using
   * these functions with an interface will cause a compile time error.
   * It is also worth noting that these functions have not been tested
   * with redeclared classes or classes that have a redeclared ancestor
   * in the inheritance hierarchy.
   */
  template<typename T>
  T *getTyped(bool nullOkay = false, bool badTypeOkay = false) const {
    CT_ASSERT_DESCENDENT_OF_OBJECTDATA(T);

    if (!m_px) {
      if (!nullOkay) {
        throw NullPointerException();
      }
      return NULL;
    }

    T *px = dynamic_cast<T*>(m_px);
    // Assert that casting does not adjust the 'this' pointer
    ASSERT(px == NULL || (void*)px == (void*)m_px);
    if (!px && !badTypeOkay) {
      throw InvalidObjectTypeException(m_px->o_getClassName());
    }

    return px;
  }
  template<typename T>
  bool is() const {
    return getTyped<T>(true, true) != NULL;
  }

  /**
   * Type conversions
   */
  bool   toBoolean() const { return m_px != NULL;}
  char   toByte   () const { return m_px ? m_px->o_toInt64() : 0;}
  short  toInt16  () const { return m_px ? m_px->o_toInt64() : 0;}
  int    toInt32  () const { return m_px ? m_px->o_toInt64() : 0;}
  int64  toInt64  () const { return m_px ? m_px->o_toInt64() : 0;}
  double toDouble () const { return m_px ? m_px->o_toInt64() : 0;}
  String toString () const { return m_px ? m_px->t___tostring() : String();}
  Array  toArray  () const;
  Variant toKey   () const;

  /**
   * Comparisons
   */
  bool same (CObjRef v2) const { return m_px == v2.get();}
  bool equal(CObjRef v2) const;
  bool less (CObjRef v2) const;
  bool more (CObjRef v2) const;

  /**
   * Unresolved objects will go through these two functions than the ones
   * on SmartObject<T>.
   */
  Variant o_get(CStrRef propName, int64 hash = -1, bool error = true) const;
  ObjectOffset o_lval(CStrRef propName, int64 hash = -1);

  /**
   * Input/Output
   */
  void serialize(VariableSerializer *serializer) const;
  bool unserialize(std::istream &in);
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_OBJECT_H__
