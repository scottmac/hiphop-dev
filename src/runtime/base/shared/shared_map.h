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

#ifndef __SHARED_MAP_H__
#define __SHARED_MAP_H__

#include <util/shared_memory_allocator.h>
#include <runtime/base/shared/shared_variant.h>
#include <runtime/base/array/array_data.h>
#include <runtime/base/type_string.h>
#include <runtime/base/type_variant.h>
#include <runtime/base/array/array_funcs.h>
#include <runtime/base/builtin_functions.h>
#include <runtime/base/util/hphp_map.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/**
 * Wrapper for a shared memory map.
 */
class SharedMap : public ArrayData {
public:
  SharedMap(SharedVariant* source);

  ~SharedMap() {
    m_arr->decRef();
  }

  ssize_t size() const {
    return m_arr->arrSize();
  }

  Variant getKey(ssize_t pos) const {
    SharedVariant* k = m_arr->getKey(pos);
    return k ? k->toLocal() : null;
  }

  Variant getValue(ssize_t pos) const {
    SharedVariant* v = m_arr->getValue(pos);
    return v ? v->toLocal() : null;
  }

  bool exists(int64 k, int64 prehash = -1) const {
    return exists(Variant(k), prehash);
  }
  bool exists(litstr k, int64 prehash = -1) const {
    return exists(Variant(k), prehash);
  }
  bool exists(CStrRef k, int64 prehash = -1) const {
    return exists(Variant(k), prehash);
  }
  bool exists(CVarRef k, int64 prehash = -1) const;

  bool idxExists(ssize_t idx) const {
    return idx < size();
  }

  Variant get(int64 k, int64 prehash = -1, bool error = false) const {
    return get(Variant(k), prehash, error);
  }
  Variant get(litstr k, int64 prehash = -1, bool error = false) const {
    return get(Variant(k), prehash, error);
  }
  Variant get(CStrRef k, int64 prehash = -1, bool error = false) const {
    return get(Variant(k), prehash, error);
  }
  Variant get(CVarRef k, int64 prehash = -1, bool error = false) const;

  ssize_t getIndex(int64 k, int64 prehash = -1) const {
    return getIndex(Variant(k), prehash);
  }
  ssize_t getIndex(litstr k, int64 prehash = -1) const {
    return getIndex(Variant(k), prehash);
  }
  ssize_t getIndex(CStrRef k, int64 prehash = -1) const {
    return getIndex(Variant(k), prehash);
  }
  ssize_t getIndex(CVarRef k, int64 prehash = -1) const {
    return m_arr->getIndex(k);
  }

  ArrayData *lval(Variant *&ret, bool copy);
  virtual ArrayData *lval(int64   k, Variant *&ret, bool copy,
                          int64 prehash = -1, bool checkExist = false);
  virtual ArrayData *lval(litstr  k, Variant *&ret, bool copy,
                          int64 prehash = -1, bool checkExist = false);
  virtual ArrayData *lval(CStrRef k, Variant *&ret, bool copy,
                          int64 prehash = -1, bool checkExist = false);
  virtual ArrayData *lval(CVarRef k, Variant *&ret, bool copy,
                          int64 prehash = -1, bool checkExist = false);

  ArrayData *set(int64   k, CVarRef v,
                 bool copy, int64 prehash = -1);
  ArrayData *set(litstr  k, CVarRef v,
                 bool copy, int64 prehash = -1);
  ArrayData *set(CStrRef k, CVarRef v,
                 bool copy, int64 prehash = -1);
  ArrayData *set(CVarRef k, CVarRef v,
                 bool copy, int64 prehash = -1);

  ArrayData *remove(int64   k, bool copy, int64 prehash = -1);
  ArrayData *remove(litstr  k, bool copy, int64 prehash = -1);
  ArrayData *remove(CStrRef k, bool copy, int64 prehash = -1);
  ArrayData *remove(CVarRef k, bool copy, int64 prehash = -1);

  ArrayData *copy() const;

  ArrayData *append(CVarRef v, bool copy);
  ArrayData *append(const ArrayData *elems, ArrayOp op, bool copy);

  ArrayData *insert(ssize_t pos, CVarRef v, bool copy);

  /**
   * Memory allocator methods.
   */
  DECLARE_SMART_ALLOCATION(SharedMap, SmartAllocatorImpl::NeedRestore);
  bool calculate(int &size) { return true;}
  void backup(LinearAllocator &allocator) {
    m_arr->incRef(); // protect it
  }
  void restore(const char *&data) { m_arr->incRef();}
  void sweep() { m_arr->decRef();}

  ArrayData *escalate() const;
  MapVariant *escalateToMapVariant() const;

private:
  SharedVariant *m_arr;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __SHARED_MAP_H__
