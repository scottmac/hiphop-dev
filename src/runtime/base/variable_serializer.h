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

#ifndef __HPHP_VARIABLE_SERIALIZER_H__
#define __HPHP_VARIABLE_SERIALIZER_H__

#include <runtime/base/types.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////


class ClassInfo;

/**
 * Maintaining states during serialization of a variable. We use this single
 * class to uniformly serialize variables according to different formats:
 * print_r(), var_export(), var_dump(), debug_zval_dump() or serialize().
 */
class VariableSerializer {
public:
  /**
   * Supported formats.
   */
  enum Type {
    PrintR,
    VarExport,
    VarDump,
    DebugDump,
    Serialize,
    JSON,
  };

  /**
   * Constructor.
   */
  VariableSerializer(Type type, int option = 0);

  /**
   * Top level entry function called by f_ functions.
   */
  Variant serialize(CVarRef v, bool ret);

  /**
   * Type specialized output functions.
   */
  void write(bool    v);
  void write(char    v) { write((int64)v);}
  void write(short   v) { write((int64)v);}
  void write(int     v) { write((int64)v);}
  void write(int64   v);
  void write(double  v);
  void write(litstr  v, int len = -1, bool isArrayKey = false);
  void write(CStrRef v);
  void write(CArrRef v);
  void write(CObjRef v);
  void write(CVarRef v, bool isArrayKey = false);

  void writeNull();
  // what to write if recursive level is over limit?
  void writeOverflow(void* ptr, bool isObject = false);
  void writeRefCount(); // for DebugDump only

  void writeArrayHeader(const ArrayData *arr, int size);
  void writeArrayKey(const ArrayData *arr, Variant key);
  void writeArrayValue(const ArrayData *arr, CVarRef value);
  void writeArrayFooter(const ArrayData *arr);

  /**
   * Helpers.
   */
  void indent();
  void setReferenced(bool referenced) { m_referenced = referenced;}
  void setRefCount(int count) { m_refCount = count;}
  void incMaxCount() { m_maxCount++; }
  bool incNestedLevel(void *ptr, bool isObject = false);
  void decNestedLevel(void *ptr);
  void setObjectInfo(const char *objClass, int objId);
  void setResourceInfo(const char *rsrcName, int rsrcId);
  void getResourceInfo(std::string &rsrcName, int &rsrcId);
  Type getType() const { return m_type; }
private:
  Type m_type;
  int m_option;                  // type specific extra options
  std::ostream *m_out;
  int m_indent;
  std::map<void*, int> m_counts; // counting seen arrays for recursive levels
  std::map<void*, int> m_arrayIds; // reference ids for objs/arrays
  int m_valueCount;              // Current ref index
  bool m_referenced;             // mark current array element as reference
  int m_refCount;                // current variable's reference count
  std::string m_objClass;        // for object serialization
  std::string m_rsrcName;        // for resource serialization
  int m_objId;                   // for object serialization
  int m_rsrcId;                  // for resource serialization
  int m_maxCount;                // for max recursive levels
  std::streampos m_initPos;      // Initial position of the output stream
  int64 m_outputLimit;             // Maximum size of output


  struct ArrayInfo {
    const ClassInfo *class_info; // The class info if an object
    bool is_object;     // nested arrays or objects
    bool is_vector;     // whether current array is a vector
    bool first_element; // whether this is first array element
    int  indent_delta;  // the extra indent to serialize this object
  };
  std::vector<ArrayInfo> m_arrayInfos;

  void writePropertyPrivacy(const char *prop, const ClassInfo *cls);
  void writeSerializedProperty(CStrRef prop, const ClassInfo *cls);
  void checkOutputSize();
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_VARIABLE_SERIALIZER_H__
