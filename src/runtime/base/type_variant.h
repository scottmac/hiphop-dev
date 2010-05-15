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

#ifndef __HPHP_VARIANT_H__
#define __HPHP_VARIANT_H__

#include <runtime/base/types.h>
#include <runtime/base/type_string.h>
#include <runtime/base/type_object.h>
#include <runtime/base/type_array.h>
#include <runtime/base/memory/smart_allocator.h>
#include <runtime/base/array/array_data.h>
#include <runtime/base/array/array_iterator.h>
#include <runtime/base/macros.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/**
 * Perhaps the most important class in the entire runtime. When type inference
 * fails to know type of a variable, or when certain coding requires reference
 * or other dynamic-ness, we have to use Variant as a fallback of a specific
 * type. This normally means slower coding. Conceptually, Variant == zval,
 * in terms of tasks it has to perform. Therefore, this class is taking similar
 * switch(type) approach Zend takes, and this class is pretty much the entire
 * Zend re-implementation in a C++ way, whereas other classes in this library
 * represent type-specialized implementation of the language.
 *
 * Variant is also the only way to implement references. A reference is a
 * strong binding between two variables, meaning they both point to the same
 * underlying data. Perhaps "contagious" bit is the hardest to understand, but
 * it's really just a temporary flag to indicate that next assignment should
 * set both variables to be strongly bound together. For example,
 *
 *   a = ref(b);
 *
 * Here, ref() simply sets "contagious" flag on b. Then assignment a = b will
 * check contagious flag. If on, both will be bound together. Then contagious
 * flag will be cleared, so not to affect future assignments. Code generation
 * made sure both "a" and "b" are Variants, otherwise we won't do references.
 *
 * In this class, strong binding is done through "pvar" member variable. All
 * others are for weak bindings. Primitive types can just make copies, but not
 * strings and arrays, which take a copy-on-write approach. This is done by
 * doing reference counting on pstr and parr members.
 *
 * In summary, we have really different approaches handling different types:
 *
 *           binding  copy-by-value copy-on-write  ref-counting
 *   num     weak      x (data)
 *   dbl     weak      x (data)
 *   str     weak      x (pointer)
 *   pstr    weak      x (pointer)        x             x
 *   parr    weak      x (pointer)        x             x
 *   pobj    weak      x (pointer)                      x
 *   pvar    strong    x (pointer)                      x
 */

#define null (Variant())

class Variant {
 public:
  friend class Array;

  /**
   * Variant does not formally derive from Countable, however it has a
   * _count field and implements all of the methods from Countable.
   */
  IMPLEMENT_COUNTABLE_METHODS_NO_STATIC

  Variant() : _count(0), m_type(KindOfNull) {
    // uninitialized
    m_data.num = 1;
  }

  void destruct();

  // g++ does not inline !isPrimitive()
  ~Variant() { if (m_type > LiteralString) destruct(); }

  void reset(); // only for special memory sweeping!

  /**
   * Constructors. We can't really use template<T> here, since that will make
   * Variant being able to take many other external types, messing up those
   * operator overloads.
   */
  Variant(CVarRef v);
  Variant(bool    v) : _count(0), m_type(KindOfBoolean) { m_data.num = (v?1:0);}
  Variant(char    v) : _count(0), m_type(KindOfByte   ) { m_data.num = v;}
  Variant(short   v) : _count(0), m_type(KindOfInt16  ) { m_data.num = v;}
  Variant(int     v) : _count(0), m_type(KindOfInt32  ) { m_data.num = v;}
  Variant(int64   v) : _count(0), m_type(KindOfInt64  ) { m_data.num = v;}
  Variant(uint64  v) : _count(0), m_type(KindOfInt64  ) { m_data.num = v;}
  Variant(ssize_t v) : _count(0), m_type(KindOfInt64  ) { m_data.num = v;}
  Variant(double  v) : _count(0), m_type(KindOfDouble ) { m_data.dbl = v;}
  Variant(litstr  v) : _count(0), m_type(LiteralString) { m_data.str = v;}

  Variant(CStrRef v);
  Variant(CArrRef v);
  Variant(CObjRef v);
  Variant(StringData *v);
  Variant(ArrayData *v);
  Variant(ObjectData *v);
  Variant(Variant *v);

  template<typename T>
  Variant(const SmartObject<T> &v) : _count(0), m_type(KindOfNull) {
    set(v);
  }

  /**
   * Break bindings and set to null.
   */
  void unset() {
    if (m_type > LiteralString) destruct();
    m_data.num = 1;
    m_type = KindOfNull;
  }

  /**
   * set to null without breaking bindings (if any), faster than v_a = null;
   */
  void setNull();

  /**
   * Type testing functions
   */
  DataType getType() const {
    return m_type == KindOfVariant ? m_data.pvar->getType() : m_type;
  }
  DataType getRawType() const {
    return m_type;
  }
  bool is(DataType type) const {
    return getType() == type;
  }
  bool isInitialized() const {
    return m_type != KindOfNull || m_data.num != 1 /* uninitialized */;
  }
  bool isNull() const {
    return getType() == KindOfNull;
  }
  bool isBoolean() const {
    return getType() == KindOfBoolean;
  }
  bool isDouble() const {
    return getType() == KindOfDouble;
  }
  bool isString() const {
    DataType type = getType();
    return type == LiteralString || type == KindOfString;
  }
  bool isInteger() const;
  bool isNumeric(bool checkString = false) const;
  DataType toNumeric(int64 &ival, double &dval, bool checkString = false)
    const;
  bool isScalar() const;
  bool isObject () const {
    return getType() == KindOfObject;
  }
  bool isIntVal() const {
    switch (m_type) {
      case KindOfNull:
      case KindOfBoolean:
      case KindOfByte:
      case KindOfInt16:
      case KindOfInt32:
      case KindOfInt64:
      case KindOfObject:
        return true;
      case KindOfVariant:
        return m_data.pvar->isIntVal();
      default:
        break;
    }
    return false;
  }
  bool isArray() const {
    return getType() == KindOfArray;
  }
  bool isResource() const;
  bool instanceof(const char *s) const;

  /**
   * Borrowing Countable::_count for contagious bit, and this is okay, since
   * outer Variant never uses reference counting.
   */
  void setContagious() const { _count = -1;}
  void clearContagious() const { _count = 0;}
  bool isContagious() const { return _count == -1;}

  /**
   * Whether or not there are at least two variables that are strongly bound.
   */
  bool isReferenced() const {
    return m_type == KindOfVariant && m_data.pvar->getCount() > 1;
  }

  /**
   * Get reference count of weak or strong binding. For debugging purpose.
   */
  int getRefCount() const;

  double getDouble() const {
    ASSERT(m_type == KindOfDouble);
    return m_data.dbl;
  }

  /**
   * Can just swap the data between variants sometimes to avoid inc and decref
   */
  void swap(Variant &other) {
    char tmp[sizeof(Variant)];
    memcpy(tmp, &other, sizeof(Variant));
    memcpy((char*)&other, (char*)this, sizeof(Variant));
    memcpy((char*)this, tmp, sizeof(Variant));
  }

  /**
   * Operators
   */
  Variant &assign(CVarRef v);

  Variant &operator=(CVarRef v) {
    return assign(v);
  }
  template<typename T> Variant &operator=(const T &v) {
    if (m_type != KindOfVariant) {
      set(v);
    } else {
      m_data.pvar->set(v);
    }
    return *this;
  }

  Variant  operator +  ();
  Variant unary_plus() const { return Variant(*this).operator+();}
  Variant  operator +  (CVarRef v) const;
  Variant &operator += (CVarRef v);
  Variant &operator += (char    n) { return operator+=((int64)n);}
  Variant &operator += (short   n) { return operator+=((int64)n);}
  Variant &operator += (int     n) { return operator+=((int64)n);}
  Variant &operator += (int64   n);
  Variant &operator += (double  n);

  Variant negate() const { return Variant(*this).operator-();}
  Variant  operator -  ();
  Variant  operator -  (CVarRef v) const;
  Variant &operator -= (CVarRef v);
  Variant &operator -= (char    n) { return operator-=((int64)n);}
  Variant &operator -= (short   n) { return operator-=((int64)n);}
  Variant &operator -= (int     n) { return operator-=((int64)n);}
  Variant &operator -= (int64   n);
  Variant &operator -= (double  n);

  Variant  operator *  (CVarRef v) const;
  Variant &operator *= (CVarRef v);
  Variant &operator *= (char    n) { return operator*=((int64)n);}
  Variant &operator *= (short   n) { return operator*=((int64)n);}
  Variant &operator *= (int     n) { return operator*=((int64)n);}
  Variant &operator *= (int64   n);
  Variant &operator *= (double  n);

  Variant  operator /  (CVarRef v) const;
  Variant &operator /= (CVarRef v);
  Variant &operator /= (char    n) { return operator/=((int64)n);}
  Variant &operator /= (short   n) { return operator/=((int64)n);}
  Variant &operator /= (int     n) { return operator/=((int64)n);}
  Variant &operator /= (int64   n);
  Variant &operator /= (double  n);

  int64    operator %  (CVarRef v) const;
  Variant &operator %= (CVarRef v);
  Variant &operator %= (char    n) { return operator%=((int64)n);}
  Variant &operator %= (short   n) { return operator%=((int64)n);}
  Variant &operator %= (int     n) { return operator%=((int64)n);}
  Variant &operator %= (int64   n);
  Variant &operator %= (double  n);

  Variant  operator ~  () const;
  Variant  operator |  (CVarRef v) const;
  Variant &operator |= (CVarRef v);
  Variant  operator &  (CVarRef v) const;
  Variant &operator &= (CVarRef v);
  Variant  operator ^  (CVarRef v) const;
  Variant &operator ^= (CVarRef v);
  Variant &operator <<=(int64 n);
  Variant &operator >>=(int64 n);

  Variant &operator ++ ();
  Variant  operator ++ (int);
  Variant &operator -- ();
  Variant  operator -- (int);

  /**
   * These are convenient functions for writing extensions, since code
   * generation always uses explicit functions like same(), less() etc. that
   * are type specialized and unambiguous.
   */
  bool operator == (CVarRef v) const;
  bool operator != (CVarRef v) const;
  bool operator >= (CVarRef v) const;
  bool operator <= (CVarRef v) const;
  bool operator >  (CVarRef v) const;
  bool operator <  (CVarRef v) const;

  /**
   * Iterator functions. See array_iterator.h for end() and next().
   * escalate() will escalate me to become VectorVariant or MapVariant, so that
   * getValueRef() can be called to take a reference to an array element.
   */
  ArrayIterPtr begin(const char *context = NULL) const;
  // used by generated code
  MutableArrayIterPtr begin(Variant *key, Variant &val);
  void escalate();

  /**
   * Implicit type conversions. In general, we prefer explicit type conversion
   * functions. These are needed simply because Variant is a coerced type from
   * other types, and we need implicit type conversions to make our type
   * inference coding simpler (Expression::m_expectedType handling).
   */

  operator bool   () const { return toBoolean();}
  operator char   () const { return toByte();}
  operator short  () const { return toInt16();}
  operator int    () const { return toInt32();}
  operator int64  () const { return toInt64();}
  operator double () const { return toDouble();}
  operator String () const;
  operator Array  () const;
  operator Object () const;
  template<typename T> operator SmartObject<T>() const { return toObject();}

  /**
   * Explicit type conversions
   */
  bool   toBoolean() const {
    if (m_type == KindOfNull) return false;
    if (m_type <= KindOfInt64) return m_data.num;
    return toBooleanHelper();
  }
  char   toByte   () const { return (char)toInt64();}
  short  toInt16  (int base = 10) const { return (short)toInt64(base);}
  int    toInt32  (int base = 10) const { return (int)toInt64(base);}
  int64  toInt64  () const {
    if (m_type == KindOfNull) return 0;
    if (m_type <= KindOfInt64) return m_data.num;
    return toInt64Helper(10);
  }
  int64  toInt64  (int base) const {
    if (m_type == KindOfNull) return 0;
    if (m_type <= KindOfInt64) return m_data.num;
    return toInt64Helper(base);
  }
  double toDouble () const;
  String toString () const;
  Array  toArray  () const;
  Object toObject () const;
  Variant toKey   () const;

  /**
   * Comparisons
   */
  bool same(bool    v2) const;
  bool same(char    v2) const;
  bool same(short   v2) const;
  bool same(int     v2) const;
  bool same(int64   v2) const;
  bool same(double  v2) const;
  bool same(litstr  v2) const;
  bool same(CStrRef v2) const;
  bool same(CArrRef v2) const;
  bool same(CObjRef v2) const;
  bool same(CVarRef v2) const;

  bool equal(bool    v2) const;
  bool equal(char    v2) const;
  bool equal(short   v2) const;
  bool equal(int     v2) const;
  bool equal(int64   v2) const;
  bool equal(double  v2) const;
  bool equal(litstr  v2) const;
  bool equal(CStrRef v2) const;
  bool equal(CArrRef v2) const;
  bool equal(CObjRef v2) const;
  bool equal(CVarRef v2) const;

  bool less(bool    v2) const;
  bool less(char    v2) const;
  bool less(short   v2) const;
  bool less(int     v2) const;
  bool less(int64   v2) const;
  bool less(double  v2) const;
  bool less(litstr  v2) const;
  bool less(CStrRef v2) const;
  bool less(CArrRef v2) const;
  bool less(CObjRef v2) const;
  bool less(CVarRef v2) const;

  bool more(bool    v2) const;
  bool more(char    v2) const;
  bool more(short   v2) const;
  bool more(int     v2) const;
  bool more(int64   v2) const;
  bool more(double  v2) const;
  bool more(litstr  v2) const;
  bool more(CStrRef v2) const;
  bool more(CArrRef v2) const;
  bool more(CObjRef v2) const;
  bool more(CVarRef v2) const;

  /**
   * Output functions
   */
  void serialize(VariableSerializer *serializer,
                 bool isArrayKey = false) const;
  void unserialize(VariableUnserializer *unserializer);

  /**
   * Used by SharedStore to save/restore a variant.
   */
  Variant share(bool save) const;

  /**
   * Debugging functions.
   */
  static const char *getTypeString(DataType type);
  std::string getDebugDump() const;

  /**
   * Memory allocator methods.
   */
  DECLARE_SMART_ALLOCATION_NOCALLBACKS(Variant);
  void dump();

  /**
   * Offset functions
   */
  Variant rvalAt(bool    offset, int64 prehash = -1,
                 bool error = false) const {
    return rvalAt(offset ? 1LL : 0LL, prehash, error);
  }
  Variant rvalAt(char    offset, int64 prehash = -1,
                 bool error = false) const {
    return rvalAt((int64)offset, prehash, error);
  }
  Variant rvalAt(short   offset, int64 prehash = -1,
                 bool error = false) const {
    return rvalAt((int64)offset, prehash, error);
  }
  Variant rvalAt(int     offset, int64 prehash = -1,
                 bool error = false) const {
    return rvalAt((int64)offset, prehash, error);
  }
  Variant rvalAtHelper(int64   offset, int64 prehash = -1,
                       bool error = false) const;
  Variant rvalAt(int64   offset, int64 prehash = -1,
                 bool error = false) const {
    if (m_type == KindOfArray) {
      return m_data.parr->get(offset, prehash, error);
    }
    return rvalAtHelper(offset, prehash, error);
  }
  Variant rvalAt(double  offset, int64 prehash = -1,
                 bool error = false) const {
    return rvalAt((int64)offset, prehash, error);
  }
  Variant rvalAt(litstr  offset, int64 prehash = -1,
                 bool error = false, bool isString = false) const;
  Variant rvalAt(CStrRef offset, int64 prehash = -1,
                 bool error = false, bool isString = false) const;
  Variant rvalAt(CVarRef offset, int64 prehash = -1,
                 bool error = false) const;

  const Variant operator[](bool    key) const { return rvalAt(key);}
  const Variant operator[](char    key) const { return rvalAt(key);}
  const Variant operator[](short   key) const { return rvalAt(key);}
  const Variant operator[](int     key) const { return rvalAt(key);}
  const Variant operator[](int64   key) const { return rvalAt(key);}
  const Variant operator[](double  key) const { return rvalAt(key);}
  const Variant operator[](litstr  key) const { return rvalAt(key);}
  const Variant operator[](CStrRef key) const { return rvalAt(key);}
  const Variant operator[](CArrRef key) const { return rvalAt(key);}
  const Variant operator[](CObjRef key) const { return rvalAt(key);}
  const Variant operator[](CVarRef key) const { return rvalAt(key);}

  /**
   * Called from VariantOffset for taking lval().
   */
  Variant &lval() {
    if (m_type == KindOfVariant) {
      return m_data.pvar->lval();
    }

    ASSERT(m_type == KindOfArray);
    Variant *ret = NULL;
    ArrayData *arr = m_data.parr;
    ArrayData *escalated = arr->lval(ret, arr->getCount() > 1);
    if (escalated) {
      set(escalated);
    }
    ASSERT(ret);
    return *ret;
  }

  template<typename T>
    Variant &lval(const T &key) {
    if (m_type == KindOfVariant) {
      return m_data.pvar->lval(key);
    }

    ASSERT(m_type == KindOfArray);
    Variant *ret = NULL;
    ArrayData *arr = m_data.parr;
    ArrayData *escalated = arr->lval(key, ret, arr->getCount() > 1);
    if (escalated) {
      set(escalated);
    }
    ASSERT(ret);
    return *ret;
  }

  Variant &lvalAt() {
    append(null);
    return lval();
  }

  static Variant &lvalInvalid();
  static Variant &lvalBlackHole();

  Variant &lvalAt(bool    key, int64 prehash = -1, bool checkExist = false);
  Variant &lvalAt(char    key, int64 prehash = -1, bool checkExist = false);
  Variant &lvalAt(short   key, int64 prehash = -1, bool checkExist = false);
  Variant &lvalAt(int     key, int64 prehash = -1, bool checkExist = false);
  Variant &lvalAt(int64   key, int64 prehash = -1, bool checkExist = false);
  Variant &lvalAt(double  key, int64 prehash = -1, bool checkExist = false);
  Variant &lvalAt(litstr  key, int64 prehash = -1, bool checkExist = false,
                  bool    isString = false);
  Variant &lvalAt(CStrRef key, int64 prehash = -1, bool checkExist = false,
                  bool    isString = false);
  Variant &lvalAt(CVarRef key, int64 prehash = -1, bool checkExist = false);

  Variant refvalAt(bool    key, int64 prehash = -1);
  Variant refvalAt(char    key, int64 prehash = -1);
  Variant refvalAt(short   key, int64 prehash = -1);
  Variant refvalAt(int     key, int64 prehash = -1);
  Variant refvalAt(int64   key, int64 prehash = -1);
  Variant refvalAt(double  key, int64 prehash = -1);
  Variant refvalAt(litstr  key, int64 prehash = -1, bool isString = false);
  Variant refvalAt(CStrRef key, int64 prehash = -1, bool isString = false);
  Variant refvalAt(CVarRef key, int64 prehash = -1);

  Variant o_get(CStrRef propName, int64 prehash = -1,
                bool error = true) const;
  ObjectOffset o_lval(CStrRef propName, int64 prehash = -1);

  Variant o_invoke(const char *s, CArrRef params, int64 hash);
  Variant o_root_invoke(const char *s, CArrRef params, int64 hash);
  Variant o_invoke_ex(const char *clsname, const char *s,
                      CArrRef params, int64 hash);

  Variant o_invoke_few_args(const char *s, int64 hash, int count,
                            CVarRef a0 = null_variant,
                            CVarRef a1 = null_variant,
                            CVarRef a2 = null_variant
#if INVOKE_FEW_ARGS_COUNT > 3
                            ,CVarRef a3 = null_variant,
                            CVarRef a4 = null_variant,
                            CVarRef a5 = null_variant
#endif
#if INVOKE_FEW_ARGS_COUNT > 6
                            ,CVarRef a6 = null_variant,
                            CVarRef a7 = null_variant,
                            CVarRef a8 = null_variant,
                            CVarRef a9 = null_variant
#endif
);
  Variant o_root_invoke_few_args(const char *s, int64 hash, int count,
                                 CVarRef a0 = null_variant,
                                 CVarRef a1 = null_variant,
                                 CVarRef a2 = null_variant
#if INVOKE_FEW_ARGS_COUNT > 3
                                 ,CVarRef a3 = null_variant,
                                 CVarRef a4 = null_variant,
                                 CVarRef a5 = null_variant
#endif
#if INVOKE_FEW_ARGS_COUNT > 6
                                 ,CVarRef a6 = null_variant,
                                 CVarRef a7 = null_variant,
                                 CVarRef a8 = null_variant,
                                 CVarRef a9 = null_variant
#endif
);

  /**
   * The whole purpose of VariantOffset is to collect "v" parameter to call
   * this function.
   */
  CVarRef set(bool    key, CVarRef v, int64 prehash = -1) {
    return set(key ? 1LL : 0LL, v, prehash);
  }
  CVarRef set(char    key, CVarRef v, int64 prehash = -1) {
    return set((int64)key, v, prehash);
  }
  CVarRef set(short   key, CVarRef v, int64 prehash = -1) {
    return set((int64)key, v, prehash);
  }
  CVarRef set(int     key, CVarRef v, int64 prehash = -1) {
    return set((int64)key, v, prehash);
  }
  CVarRef set(int64 key, CVarRef v, int64 prehash = -1);
  CVarRef set(double  key, CVarRef v, int64 prehash = -1) {
    return set((int64)key, v, prehash);
  }
  CVarRef set(litstr  key, CVarRef v, int64 prehash = -1,
              bool isString = false);
  CVarRef set(CStrRef key, CVarRef v, int64 prehash = -1,
              bool isString = false);
  CVarRef set(CVarRef key, CVarRef v, int64 prehash = -1);

  CVarRef append(CVarRef v);

  template<typename T>
  void removeImpl(const T &key, int64 prehash) {
    switch (getType()) {
    case KindOfNull:
      break;
    case KindOfArray:
      {
        ArrayData *arr = getArrayData();
        if (arr) {
          ArrayData *escalated = arr->remove(key, (arr->getCount() > 1),
                                             prehash);
          if (escalated) {
            set(escalated);
          }
        }
      }
      break;
    case KindOfObject:
      callOffsetUnset(key);
      break;
    default:
      lvalInvalid();
      break;
    }
  }
  void remove(bool    key, int64 prehash = -1) { remove((int64)key, prehash);}
  void remove(char    key, int64 prehash = -1) { remove((int64)key, prehash);}
  void remove(short   key, int64 prehash = -1) { remove((int64)key, prehash);}
  void remove(int     key, int64 prehash = -1) { remove((int64)key, prehash);}
  void remove(int64   key, int64 prehash = -1) { removeImpl(key, prehash);}
  void remove(double  key, int64 prehash = -1) { remove((int64)key, prehash);}
  void remove(litstr  key, int64 prehash = -1);
  void remove(CStrRef key, int64 prehash = -1);
  void remove(CVarRef key, int64 prehash = -1);

  template<typename T>
  void weakRemove(const T &key, int64 prehash = -1) {
    if (is(KindOfArray) ||
        (is(KindOfObject) && getObjectData()->o_instanceof("arrayaccess"))) {
      remove(key, prehash);
    }
    if (isString()) {
      raise_error("Cannot unset string offsets");
      return;
    }
  }

  /**
   * More array opeartions.
   */
  Variant pop();
  Variant dequeue();
  void insert(int pos, CVarRef v);

  /**
   * Position-based iterations.
   */
  Variant array_iter_reset();
  Variant array_iter_prev();
  Variant array_iter_current() const;
  Variant array_iter_next();
  Variant array_iter_end();
  Variant array_iter_key() const;
  Variant array_iter_value(ssize_t &pos) const;
  Variant array_iter_each();

  /**
   * Low level access that should be restricted to internal use.
   */
  int64 *getInt64Data() const {
    ASSERT(getType() == KindOfInt64);
    return m_type == KindOfVariant ? &m_data.pvar->m_data.num : &m_data.num;
  }
  double *getDoubleData() const {
    ASSERT(getType() == KindOfDouble);
    return m_type == KindOfVariant ? &m_data.pvar->m_data.dbl : &m_data.dbl;
  }
  litstr getLiteralString() const {
    ASSERT(getType() == LiteralString);
    return m_type == KindOfVariant ? m_data.pvar->m_data.str : m_data.str;
  }
  StringData *getStringData() const {
    ASSERT(getType() == KindOfString);
    return m_type == KindOfVariant ? m_data.pvar->m_data.pstr : m_data.pstr;
  }
  ArrayData *getArrayData() const {
    ASSERT(is(KindOfArray));
    return m_type == KindOfVariant ? m_data.pvar->m_data.parr : m_data.parr;
  }
  ObjectData *getObjectData() const {
    ASSERT(is(KindOfObject));
    return m_type == KindOfVariant ? m_data.pvar->m_data.pobj : m_data.pobj;
  }
  Variant *getVariantData() const {
    // Wrap into a referenceable form, if it isn't already.
    if (m_type != KindOfVariant) {
      Variant *shared = NEW(Variant)();
      shared->bind(*this);
      shared->_count = 1;

      _count = 0;
      m_data.pvar = shared;
      m_type = KindOfVariant;
    }
    ASSERT(m_type == KindOfVariant);
    return m_data.pvar;
  }
  ObjectData *getArrayAccess() const;
  void callOffsetUnset(CVarRef key);
  int64 getNumData() const { return m_data.num; }
  bool isStatic() const { return _count == (1 << 30); }
  void setStatic() const;

  /**
   * The order of the data members is significant. The _count field must
   * be exactly FAST_REFCOUNT_OFFSET bytes from the beginning of the object.
   */
 private:
  mutable union {
    int64        num;
    double       dbl;
    litstr       str;
    StringData  *pstr;
    ArrayData   *parr;
    ObjectData  *pobj;
    Variant     *pvar; // shared data between strongly bound Variants
  } m_data;
 protected:
  mutable int _count;
 private:
  mutable DataType m_type;

  bool isPrimitive() const { return m_type <= LiteralString; }

  CVarRef set(bool    v);
  CVarRef set(char    v);
  CVarRef set(short   v);
  CVarRef set(int     v);
  CVarRef set(int64   v);
  CVarRef set(double  v);
  CVarRef set(litstr  v);
  CVarRef set(StringData  *v);
  CVarRef set(ArrayData   *v);
  CVarRef set(ObjectData  *v);
  CVarRef set(const ObjectOffset& v);

  CVarRef set(CStrRef v) { return set(v.get()); }
  CVarRef set(CArrRef v) { return set(v.get()); }
  CVarRef set(CObjRef v) { return set(v.get()); }

  void escalateString() const;

  template<typename T>
  CVarRef set(const SmartObject<T> &v) {
    return set(v.get());
  }

  // Internal helper for weakly binding a variable. m_type should be viewed
  // as KindOfNull and for complex types the old data already released.
  void bind(CVarRef v) {
    if (v.m_type <= LiteralString) {
      m_type = v.m_type;
      /* drop uninitialized flag */
      m_data.num = m_type == KindOfNull ? 0 : v.m_data.num;
      return;
    }
#ifdef FAST_REFCOUNT_FOR_VARIANT
    Variant *var = v.m_data.pvar;
    if (v.m_type != KindOfVariant) {
      if (var) {
        m_type = v.m_type;
        m_data.pvar = var;
        /**
         * This is safe because we have compile time assertions that
         * guarantee that the _count field will always be exactly
         * FAST_REFCOUNT_OFFSET bytes from the beginning of the object
         * for the StringData, ArrayData, ObjectData, and Variant classes.
         */
        var->incRefCount();
      } else {
        m_data.num = 0;
        m_type = KindOfNull;
      }
    } else {
      bind(*var);
    }
#else
    switch (v.m_type) {
    // copy-on-write: ref counting complex types
    case KindOfString: {
      StringData *str = v.m_data.pstr;
      if (str) {
        m_type = KindOfString;
        m_data.pstr = str;
        str->incRefCount();
      } else {
        m_data.num = 0;
        m_type = KindOfNull;
      }
      break;
    }
    case KindOfArray: {
      ArrayData *arr = v.m_data.parr;
      if (arr) {
        m_type = KindOfArray;
        m_data.parr = arr;
        arr->incRefCount();
      } else {
        m_data.num = 0;
        m_type = KindOfNull;
      }
      break;
    }
    case KindOfObject: {
      ObjectData *obj = v.m_data.pobj;
      if (obj) {
        m_type = KindOfObject;
        m_data.pobj = obj;
        obj->incRefCount();
      } else {
        m_data.num = 0;
        m_type = KindOfNull;
      }
      break;
    }
    case KindOfVariant:
      bind(*v.m_data.pvar);
      break;
    default:
      ASSERT(false);
    }
#endif
  }

  // Internal helper for strongly binding a variable
  void strongBind(Variant *v) {
    ASSERT(v != this);
    if (v) {
      v->incRefCount(); // in case destruct() triggers deletion of v
      if (m_type > LiteralString) destruct();
      m_type = KindOfVariant;
      m_data.pvar = v;
    } else {
      unset();
    }
  }

  // Internal helper for handling contagious assignment
  void assignContagious(CVarRef v) {
    ASSERT(v.isContagious());
    // do it early to avoid strongBind() triggers deletion of v
    v.clearContagious();
    // we have to wrap up v into a sharable form
    if (v.m_type != KindOfVariant) {
      Variant *shared = NEW(Variant)();
      shared->bind(v);
      const_cast<Variant&>(v).strongBind(shared);
    }
    // then we can share v.m_data.pvar
    strongBind(v.m_data.pvar);
  }

  bool   toBooleanHelper() const;
  int64  toInt64Helper(int base = 10) const;

  void split();  // breaking weak binding by making a real copy

  template<typename T>
  Variant &lvalAtImpl(const T &key, int64 prehash = -1,
                      bool checkExist = false) {
    if (m_type == KindOfVariant) {
      return m_data.pvar->lvalAtImpl(key, prehash);
    }
    if (isNull() ||
        (m_type == KindOfBoolean && !toBoolean()) ||
        (m_type == LiteralString && !*getLiteralString()) ||
        (m_type == KindOfString && getStringData()->empty())) {
      unset();
      set(toArray());
    }
    if (m_type == KindOfArray) {
      Variant *ret = NULL;
      ArrayData *arr = m_data.parr;
      ArrayData *escalated =
        arr->lval(key, ret, arr->getCount() > 1, prehash, checkExist);
      if (escalated) {
        set(escalated);
      }
      ASSERT(ret);
      return *ret;
    }
    if (m_type == KindOfObject) {
      return getArrayAccess()->___offsetget_lval(key);
    }
    return lvalInvalid();
  }

  template<typename T>
  Variant refvalAtImpl(const T &key, int64 prehash = -1) {
    if (m_type == KindOfVariant) {
      return m_data.pvar->refvalAtImpl(key, prehash);
    }
    if (is(KindOfArray) || isNull() ||
        (is(KindOfBoolean) && !toBoolean()) ||
        (is(LiteralString) && !*getLiteralString()) ||
        (is(KindOfString) && getStringData()->empty())) {
      return ref(lvalAt(key, prehash));
    } else {
      return rvalAt(key, prehash);
    }
  }

  Variant refvalAtImpl(CStrRef key, int64 prehash = -1, bool isString = false);

#ifdef FAST_REFCOUNT_FOR_VARIANT
 private:
  static void compileTimeAssertions() {
    CT_ASSERT(offsetof(Variant, _count) == FAST_REFCOUNT_OFFSET);
  }
#endif
};

///////////////////////////////////////////////////////////////////////////////

inline Variant operator+(char    n, CVarRef v) { return Variant(v) += n;}
inline Variant operator+(short   n, CVarRef v) { return Variant(v) += n;}
inline Variant operator+(int     n, CVarRef v) { return Variant(v) += n;}
inline Variant operator+(int64   n, CVarRef v) { return Variant(v) += n;}
inline Variant operator+(double  n, CVarRef v) { return Variant(v) += n;}
inline Variant operator+(CVarRef v, char    n) { return Variant(v) += n;}
inline Variant operator+(CVarRef v, short   n) { return Variant(v) += n;}
inline Variant operator+(CVarRef v, int     n) { return Variant(v) += n;}
inline Variant operator+(CVarRef v, int64   n) { return Variant(v) += n;}
inline Variant operator+(CVarRef v, double  n) { return Variant(v) += n;}

inline Variant operator-(char    n, CVarRef v) { return v.negate() += n;}
inline Variant operator-(short   n, CVarRef v) { return v.negate() += n;}
inline Variant operator-(int     n, CVarRef v) { return v.negate() += n;}
inline Variant operator-(int64   n, CVarRef v) { return v.negate() += n;}
inline Variant operator-(double  n, CVarRef v) { return v.negate() += n;}
inline Variant operator-(CVarRef v, char    n) { return Variant(v) -= n;}
inline Variant operator-(CVarRef v, short   n) { return Variant(v) -= n;}
inline Variant operator-(CVarRef v, int     n) { return Variant(v) -= n;}
inline Variant operator-(CVarRef v, int64   n) { return Variant(v) -= n;}
inline Variant operator-(CVarRef v, double  n) { return Variant(v) -= n;}

inline Variant operator*(char    n, CVarRef v) { return Variant(v) *= n;}
inline Variant operator*(short   n, CVarRef v) { return Variant(v) *= n;}
inline Variant operator*(int     n, CVarRef v) { return Variant(v) *= n;}
inline Variant operator*(int64   n, CVarRef v) { return Variant(v) *= n;}
inline Variant operator*(double  n, CVarRef v) { return Variant(v) *= n;}
inline Variant operator*(CVarRef v, char    n) { return Variant(v) *= n;}
inline Variant operator*(CVarRef v, short   n) { return Variant(v) *= n;}
inline Variant operator*(CVarRef v, int     n) { return Variant(v) *= n;}
inline Variant operator*(CVarRef v, int64   n) { return Variant(v) *= n;}
inline Variant operator*(CVarRef v, double  n) { return Variant(v) *= n;}

double operator/(double n, CVarRef v);
double operator/(int n, CVarRef v);
inline Variant operator/(CVarRef v, char    n) { return Variant(v) /= n;}
inline Variant operator/(CVarRef v, short   n) { return Variant(v) /= n;}
inline Variant operator/(CVarRef v, int     n) { return Variant(v) /= n;}
inline Variant operator/(CVarRef v, int64   n) { return Variant(v) /= n;}
inline Variant operator/(CVarRef v, double  n) { return Variant(v) /= n;}

///////////////////////////////////////////////////////////////////////////////
// breaking circular dependencies

template<typename T>
CVarRef Array::setImpl(const T &key, CVarRef v, int64 prehash) {
  if (!m_px) {
    ArrayData *data = ArrayData::Create(key, v);
    SmartPtr<ArrayData>::operator=(data);
  } else {
    if (v.isContagious()) {
      escalate();
    }
    ArrayData *escalated =
      m_px->set(key, v, (m_px->getCount() > 1), prehash);
    if (escalated) {
      SmartPtr<ArrayData>::operator=(escalated);
    }
  }
  return v;
}

template<typename T>
Variant Array::refvalAt(const T &key, int64 prehash /* = -1 */) {
  return ref(lvalAt(key, prehash));
}

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_VARIANT_H__
