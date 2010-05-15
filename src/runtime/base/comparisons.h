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

#ifndef __HPHP_COMPARISONS_H__
#define __HPHP_COMPARISONS_H__

#include <runtime/base/builtin_functions.h>
#include <runtime/base/type_string.h>
#include <runtime/base/type_array.h>
#include <runtime/base/type_variant.h>
#include <runtime/base/type_object.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
// Variant

inline bool same(CVarRef v1, bool    v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, char    v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, short   v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, int     v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, int64   v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, double  v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, CStrRef v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, litstr  v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, CArrRef v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, CObjRef v2)  { return v1.same(v2);}
inline bool same(CVarRef v1, CVarRef v2)  { return v1.same(v2);}

inline bool same_rev(CVarRef v2, CVarRef v1)  { return v1.same(v2);}

inline bool equal(CVarRef v1, bool    v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, char    v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, short   v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, int     v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, int64   v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, double  v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, CStrRef v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, litstr  v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, CArrRef v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, CObjRef v2) { return v1.equal(v2);}
inline bool equal(CVarRef v1, CVarRef v2) { return v1.equal(v2);}

inline bool equal_rev(CVarRef v2, CVarRef v1) { return v1.equal(v2);}

inline bool less(CVarRef v1, bool    v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, char    v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, short   v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, int     v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, int64   v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, double  v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, CStrRef v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, litstr  v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, CArrRef v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, CObjRef v2)  { return v1.less(v2);}
inline bool less(CVarRef v1, CVarRef v2)  { return v1.less(v2);}

inline bool less_rev(CVarRef v2, CVarRef v1)  { return v1.less(v2);}

inline bool more(CVarRef v1, bool    v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, char    v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, short   v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, int     v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, int64   v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, double  v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, CStrRef v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, litstr  v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, CArrRef v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, CObjRef v2)  { return v1.more(v2);}
inline bool more(CVarRef v1, CVarRef v2)  { return v1.more(v2);}

inline bool more_rev(CVarRef v2, CVarRef v1)  { return v1.more(v2);}

///////////////////////////////////////////////////////////////////////////////
// bool

inline bool same(bool v1, bool    v2)  { return v1 == v2;}
inline bool same(bool v1, char    v2)  { return false;}
inline bool same(bool v1, short   v2)  { return false;}
inline bool same(bool v1, int     v2)  { return false;}
inline bool same(bool v1, int64   v2)  { return false;}
inline bool same(bool v1, double  v2)  { return false;}
inline bool same(bool v1, CStrRef v2)  { return false;}
inline bool same(bool v1, litstr  v2)  { return false;}
inline bool same(bool v1, CArrRef v2)  { return false;}
inline bool same(bool v1, CObjRef v2)  { return false;}
inline bool same(bool v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(bool v1, bool    v2) { return v1 == v2;}
inline bool equal(bool v1, char    v2) { return v1 == (v2 != 0);}
inline bool equal(bool v1, short   v2) { return v1 == (v2 != 0);}
inline bool equal(bool v1, int     v2) { return v1 == (v2 != 0);}
inline bool equal(bool v1, int64   v2) { return v1 == (v2 != 0);}
inline bool equal(bool v1, double  v2) { return v1 == (v2 != 0.0);}
inline bool equal(bool v1, CStrRef v2) { return v1 == v2.toBoolean();}
inline bool equal(bool v1, litstr  v2) { return equal(v1, String(v2));}
inline bool equal(bool v1, CArrRef v2) { return v1 == v2.toBoolean();}
inline bool equal(bool v1, CObjRef v2) { return v1 == v2.toBoolean();}
inline bool equal(bool v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(bool v1, bool    v2)  { return (v1?1:0) < (v2?1:0);}
inline bool less(bool v1, char    v2)  { return less(v1,(v2 != 0));}
inline bool less(bool v1, short   v2)  { return less(v1,(v2 != 0));}
inline bool less(bool v1, int     v2)  { return less(v1,(v2 != 0));}
inline bool less(bool v1, int64   v2)  { return less(v1,(v2 != 0));}
inline bool less(bool v1, double  v2)  { return less(v1,(v2 != 0.0));}
inline bool less(bool v1, CStrRef v2)  { return less(v1,v2.toBoolean());}
inline bool less(bool v1, litstr  v2)  { return less(v1,String(v2));}
inline bool less(bool v1, CArrRef v2)  { return less(v1,v2.toBoolean());}
inline bool less(bool v1, CObjRef v2)  { return less(v1,v2.toBoolean());}
inline bool less(bool v1, CVarRef v2)  { return more(v2,v1);}

inline bool more(bool v1, bool    v2)  { return (v1?1:0) > (v2?1:0);}
inline bool more(bool v1, char    v2)  { return more(v1,(v2 != 0));}
inline bool more(bool v1, short   v2)  { return more(v1,(v2 != 0));}
inline bool more(bool v1, int     v2)  { return more(v1,(v2 != 0));}
inline bool more(bool v1, int64   v2)  { return more(v1,(v2 != 0));}
inline bool more(bool v1, double  v2)  { return more(v1,(v2 != 0.0));}
inline bool more(bool v1, CStrRef v2)  { return more(v1,v2.toBoolean());}
inline bool more(bool v1, litstr  v2)  { return more(v1,String(v2));}
inline bool more(bool v1, CArrRef v2)  { return more(v1,v2.toBoolean());}
inline bool more(bool v1, CObjRef v2)  { return more(v1,v2.toBoolean());}
inline bool more(bool v1, CVarRef v2)  { return less(v2,v1);}

///////////////////////////////////////////////////////////////////////////////
// char

inline bool same(char v1, bool    v2)  { return same(v2, v1);}
inline bool same(char v1, char    v2)  { return v1 == v2;}
inline bool same(char v1, short   v2)  { return v1 == v2;}
inline bool same(char v1, int     v2)  { return v1 == v2;}
inline bool same(char v1, int64   v2)  { return v1 == v2;}
inline bool same(char v1, double  v2)  { return (double)v1 == v2;}
inline bool same(char v1, CStrRef v2)  { return false;}
inline bool same(char v1, litstr  v2)  { return false;}
inline bool same(char v1, CArrRef v2)  { return false;}
inline bool same(char v1, CObjRef v2)  { return false;}
inline bool same(char v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(char v1, bool    v2) { return equal(v2, v1);}
inline bool equal(char v1, char    v2) { return v1 == v2;}
inline bool equal(char v1, short   v2) { return v1 == v2;}
inline bool equal(char v1, int     v2) { return v1 == v2;}
inline bool equal(char v1, int64   v2) { return v1 == v2;}
inline bool equal(char v1, double  v2) { return (double)v1 == v2;}
bool equal(char v1, CStrRef v2);
inline bool equal(char v1, litstr  v2) { return equal(v1, String(v2));}
inline bool equal(char v1, CArrRef v2) { return false;}
inline bool equal(char v1, CObjRef v2) { return false;}
inline bool equal(char v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(char v1, bool    v2)  { return more(v2, v1);}
inline bool less(char v1, char    v2)  { return v1 < v2;}
inline bool less(char v1, short   v2)  { return v1 < v2;}
inline bool less(char v1, int     v2)  { return v1 < v2;}
inline bool less(char v1, int64   v2)  { return v1 < v2;}
inline bool less(char v1, double  v2)  { return v1 < v2;}
bool less(char v1, CStrRef v2);
inline bool less(char v1, litstr  v2)  { return less(v1, String(v2));}
inline bool less(char v1, CArrRef v2)  { return true;}
inline bool less(char v1, CObjRef v2)  { return true;}
inline bool less(char v1, CVarRef v2)  { return more(v2, v1);}

inline bool more(char v1, bool    v2)  { return less(v2, v1);}
inline bool more(char v1, char    v2)  { return v1 > v2;}
inline bool more(char v1, short   v2)  { return v1 > v2;}
inline bool more(char v1, int     v2)  { return v1 > v2;}
inline bool more(char v1, int64   v2)  { return v1 > v2;}
inline bool more(char v1, double  v2)  { return v1 > v2;}
bool more(char v1, CStrRef v2);
inline bool more(char v1, litstr  v2)  { return more(v1, String(v2));}
inline bool more(char v1, CArrRef v2)  { return false;}
inline bool more(char v1, CObjRef v2)  { return false;}
inline bool more(char v1, CVarRef v2)  { return less(v2, v1);}

///////////////////////////////////////////////////////////////////////////////
// short

inline bool same(short v1, bool    v2)  { return same(v2, v1);}
inline bool same(short v1, char    v2)  { return same(v2, v1);}
inline bool same(short v1, short   v2)  { return v1 == v2;}
inline bool same(short v1, int     v2)  { return v1 == v2;}
inline bool same(short v1, int64   v2)  { return v1 == v2;}
inline bool same(short v1, double  v2)  { return (double)v1 == v2;}
inline bool same(short v1, CStrRef v2)  { return false;}
inline bool same(short v1, litstr  v2)  { return false;}
inline bool same(short v1, CArrRef v2)  { return false;}
inline bool same(short v1, CObjRef v2)  { return false;}
inline bool same(short v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(short v1, bool    v2) { return equal(v2, v1);}
inline bool equal(short v1, char    v2) { return equal(v2, v1);}
inline bool equal(short v1, short   v2) { return v1 == v2;}
inline bool equal(short v1, int     v2) { return v1 == v2;}
inline bool equal(short v1, int64   v2) { return v1 == v2;}
inline bool equal(short v1, double  v2) { return (double)v1 == v2;}
bool equal(short v1, CStrRef v2);
inline bool equal(short v1, litstr  v2) { return equal(v1, String(v2));}
inline bool equal(short v1, CArrRef v2) { return false;}
inline bool equal(short v1, CObjRef v2) { return false;}
inline bool equal(short v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(short v1, bool    v2)  { return more(v2, v1);}
inline bool less(short v1, char    v2)  { return more(v2, v1);}
inline bool less(short v1, short   v2)  { return v1 < v2;}
inline bool less(short v1, int     v2)  { return v1 < v2;}
inline bool less(short v1, int64   v2)  { return v1 < v2;}
inline bool less(short v1, double  v2)  { return v1 < v2;}
bool less(short v1, CStrRef v2);
inline bool less(short v1, litstr  v2)  { return less(v1, String(v2));}
inline bool less(short v1, CArrRef v2)  { return true;}
inline bool less(short v1, CObjRef v2)  { return true;}
inline bool less(short v1, CVarRef v2)  { return more(v2, v1);}

inline bool more(short v1, bool    v2)  { return less(v2, v1);}
inline bool more(short v1, char    v2)  { return less(v2, v1);}
inline bool more(short v1, short   v2)  { return v1 > v2;}
inline bool more(short v1, int     v2)  { return v1 > v2;}
inline bool more(short v1, int64   v2)  { return v1 > v2;}
inline bool more(short v1, double  v2)  { return v1 > v2;}
bool more(short v1, CStrRef v2);
inline bool more(short v1, litstr  v2)  { return more(v1, String(v2));}
inline bool more(short v1, CArrRef v2)  { return false;}
inline bool more(short v1, CObjRef v2)  { return false;}
inline bool more(short v1, CVarRef v2)  { return less(v2, v1);}

///////////////////////////////////////////////////////////////////////////////
// int

inline bool same(int v1, bool    v2)  { return same(v2, v1);}
inline bool same(int v1, char    v2)  { return same(v2, v1);}
inline bool same(int v1, short   v2)  { return same(v2, v1);}
inline bool same(int v1, int     v2)  { return v1 == v2;}
inline bool same(int v1, int64   v2)  { return v1 == v2;}
inline bool same(int v1, double  v2)  { return (double)v1 == v2;}
inline bool same(int v1, CStrRef v2)  { return false;}
inline bool same(int v1, litstr  v2)  { return false;}
inline bool same(int v1, CArrRef v2)  { return false;}
inline bool same(int v1, CObjRef v2)  { return false;}
inline bool same(int v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(int v1, bool    v2) { return equal(v2, v1);}
inline bool equal(int v1, char    v2) { return equal(v2, v1);}
inline bool equal(int v1, short   v2) { return equal(v2, v1);}
inline bool equal(int v1, int     v2) { return v1 == v2;}
inline bool equal(int v1, int64   v2) { return v1 == v2;}
inline bool equal(int v1, double  v2) { return (double)v1 == v2;}
bool equal(int v1, CStrRef v2);
inline bool equal(int v1, litstr  v2) { return equal(v1, String(v2));}
inline bool equal(int v1, CArrRef v2) { return false;}
inline bool equal(int v1, CObjRef v2) { return false;}
inline bool equal(int v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(int v1, bool    v2)  { return more(v2, v1);}
inline bool less(int v1, char    v2)  { return more(v2, v1);}
inline bool less(int v1, short   v2)  { return more(v2, v1);}
inline bool less(int v1, int     v2)  { return v1 < v2;}
inline bool less(int v1, int64   v2)  { return v1 < v2;}
inline bool less(int v1, double  v2)  { return v1 < v2;}
bool less(int v1, CStrRef v2);
inline bool less(int v1, litstr  v2)  { return less(v1, String(v2));}
inline bool less(int v1, CArrRef v2)  { return true;}
inline bool less(int v1, CObjRef v2)  { return true;}
inline bool less(int v1, CVarRef v2)  { return more(v2, v1);}

inline bool more(int v1, bool    v2)  { return less(v2, v1);}
inline bool more(int v1, char    v2)  { return less(v2, v1);}
inline bool more(int v1, short   v2)  { return less(v2, v1);}
inline bool more(int v1, int     v2)  { return v1 > v2;}
inline bool more(int v1, int64   v2)  { return v1 > v2;}
inline bool more(int v1, double  v2)  { return v1 > v2;}
bool more(int v1, CStrRef v2);
inline bool more(int v1, litstr  v2)  { return more(v1, String(v2));}
inline bool more(int v1, CArrRef v2)  { return false;}
inline bool more(int v1, CObjRef v2)  { return false;}
inline bool more(int v1, CVarRef v2)  { return less(v2, v1);}

///////////////////////////////////////////////////////////////////////////////
// int64

inline bool same(int64 v1, bool    v2)  { return same(v2, v1);}
inline bool same(int64 v1, char    v2)  { return same(v2, v1);}
inline bool same(int64 v1, short   v2)  { return same(v2, v1);}
inline bool same(int64 v1, int     v2)  { return same(v2, v1);}
inline bool same(int64 v1, int64   v2)  { return v1 == v2;}
inline bool same(int64 v1, double  v2)  { return (double)v1 == v2;}
inline bool same(int64 v1, CStrRef v2)  { return false;}
inline bool same(int64 v1, litstr  v2)  { return false;}
inline bool same(int64 v1, CArrRef v2)  { return false;}
inline bool same(int64 v1, CObjRef v2)  { return false;}
inline bool same(int64 v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(int64 v1, bool    v2) { return equal(v2, v1);}
inline bool equal(int64 v1, char    v2) { return equal(v2, v1);}
inline bool equal(int64 v1, short   v2) { return equal(v2, v1);}
inline bool equal(int64 v1, int     v2) { return equal(v2, v1);}
inline bool equal(int64 v1, int64   v2) { return v1 == v2;}
inline bool equal(int64 v1, double  v2) { return (double)v1 == v2;}
bool equal(int64 v1, CStrRef v2);
inline bool equal(int64 v1, litstr  v2) { return equal(v1, String(v2));}
inline bool equal(int64 v1, CArrRef v2) { return false;}
inline bool equal(int64 v1, CObjRef v2) { return false;}
inline bool equal(int64 v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(int64 v1, bool    v2)  { return more(v2, v1);}
inline bool less(int64 v1, char    v2)  { return more(v2, v1);}
inline bool less(int64 v1, short   v2)  { return more(v2, v1);}
inline bool less(int64 v1, int     v2)  { return more(v2, v1);}
inline bool less(int64 v1, int64   v2)  { return v1 < v2;}
inline bool less(int64 v1, double  v2)  { return v1 < v2;}
bool less(int64 v1, CStrRef v2);
inline bool less(int64 v1, litstr  v2)  { return less(v1, String(v2));}
inline bool less(int64 v1, CArrRef v2)  { return true;}
inline bool less(int64 v1, CObjRef v2)  { return true;}
inline bool less(int64 v1, CVarRef v2)  { return more(v2, v1);}

inline bool more(int64 v1, bool    v2)  { return less(v2, v1);}
inline bool more(int64 v1, char    v2)  { return less(v2, v1);}
inline bool more(int64 v1, short   v2)  { return less(v2, v1);}
inline bool more(int64 v1, int     v2)  { return less(v2, v1);}
inline bool more(int64 v1, int64   v2)  { return v1 > v2;}
inline bool more(int64 v1, double  v2)  { return v1 > v2;}
bool more(int64 v1, CStrRef v2);
inline bool more(int64 v1, litstr  v2)  { return more(v1, String(v2));}
inline bool more(int64 v1, CArrRef v2)  { return false;}
inline bool more(int64 v1, CObjRef v2)  { return false;}
inline bool more(int64 v1, CVarRef v2)  { return less(v2, v1);}

///////////////////////////////////////////////////////////////////////////////
// double

inline bool same(double v1, bool    v2)  { return same(v2, v1);}
inline bool same(double v1, char    v2)  { return same(v2, v1);}
inline bool same(double v1, short   v2)  { return same(v2, v1);}
inline bool same(double v1, int     v2)  { return same(v2, v1);}
inline bool same(double v1, int64   v2)  { return same(v2, v1);}
inline bool same(double v1, double  v2)  { return v1 == v2;}
inline bool same(double v1, CStrRef v2)  { return false;}
inline bool same(double v1, litstr  v2)  { return false;}
inline bool same(double v1, CArrRef v2)  { return false;}
inline bool same(double v1, CObjRef v2)  { return false;}
inline bool same(double v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(double v1, bool    v2) { return equal(v2, v1);}
inline bool equal(double v1, char    v2) { return equal(v2, v1);}
inline bool equal(double v1, short   v2) { return equal(v2, v1);}
inline bool equal(double v1, int     v2) { return equal(v2, v1);}
inline bool equal(double v1, int64   v2) { return equal(v2, v1);}
inline bool equal(double v1, double  v2) { return v1 == v2;}
inline bool equal(double v1, CStrRef v2) { return v1 == v2.toDouble();}
inline bool equal(double v1, litstr  v2) { return equal(v1,String(v2));}
inline bool equal(double v1, CArrRef v2) { return false;}
inline bool equal(double v1, CObjRef v2) { return false;}
inline bool equal(double v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(double v1, bool    v2)  { return more(v2, v1);}
inline bool less(double v1, char    v2)  { return more(v2, v1);}
inline bool less(double v1, short   v2)  { return more(v2, v1);}
inline bool less(double v1, int     v2)  { return more(v2, v1);}
inline bool less(double v1, int64   v2)  { return more(v2, v1);}
inline bool less(double v1, double  v2)  { return v1 < v2;}
inline bool less(double v1, CStrRef v2)  { return less(v1,v2.toDouble());}
inline bool less(double v1, litstr  v2)  { return less(v1,String(v2));}
inline bool less(double v1, CArrRef v2)  { return true;}
inline bool less(double v1, CObjRef v2)  { return true;}
inline bool less(double v1, CVarRef v2)  { return more(v2, v1);}

inline bool more(double v1, bool    v2)  { return less(v2, v1);}
inline bool more(double v1, char    v2)  { return less(v2, v1);}
inline bool more(double v1, short   v2)  { return less(v2, v1);}
inline bool more(double v1, int     v2)  { return less(v2, v1);}
inline bool more(double v1, int64   v2)  { return less(v2, v1);}
inline bool more(double v1, double  v2)  { return v1 > v2;}
inline bool more(double v1, CStrRef v2)  { return more(v1,v2.toDouble());}
inline bool more(double v1, litstr  v2)  { return more(v1,String(v2));}
inline bool more(double v1, CArrRef v2)  { return false;}
inline bool more(double v1, CObjRef v2)  { return false;}
inline bool more(double v1, CVarRef v2)  { return less(v2, v1);}

///////////////////////////////////////////////////////////////////////////////
// String

inline bool same(CStrRef v1, bool    v2)  { return same(v2, v1);}
inline bool same(CStrRef v1, char    v2)  { return same(v2, v1);}
inline bool same(CStrRef v1, short   v2)  { return same(v2, v1);}
inline bool same(CStrRef v1, int     v2)  { return same(v2, v1);}
inline bool same(CStrRef v1, int64   v2)  { return same(v2, v1);}
inline bool same(CStrRef v1, double  v2)  { return same(v2, v1);}
inline bool same(CStrRef v1, CStrRef v2)  { return v1.same(v2);}
inline bool same(CStrRef v1, litstr  v2)  { return v1.same(v2);}
inline bool same(CStrRef v1, CArrRef v2)  { return v1.same(v2);}
inline bool same(CStrRef v1, CObjRef v2)  { return v1.same(v2);}
inline bool same(CStrRef v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(CStrRef v1, bool    v2) { return equal(v2, v1);}
inline bool equal(CStrRef v1, char    v2) { return equal(v2, v1);}
inline bool equal(CStrRef v1, short   v2) { return equal(v2, v1);}
inline bool equal(CStrRef v1, int     v2) { return equal(v2, v1);}
inline bool equal(CStrRef v1, int64   v2) { return equal(v2, v1);}
inline bool equal(CStrRef v1, double  v2) { return equal(v2, v1);}
inline bool equal(CStrRef v1, CStrRef v2) { return v1.equal(v2);}
inline bool equal(CStrRef v1, litstr  v2) { return v1.equal(v2);}
inline bool equal(CStrRef v1, CArrRef v2) { return v1.equal(v2);}
inline bool equal(CStrRef v1, CObjRef v2) { return v1.equal(v2);}
inline bool equal(CStrRef v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(CStrRef v1, bool    v2)  { return more(v2, v1);}
inline bool less(CStrRef v1, char    v2)  { return more(v2, v1);}
inline bool less(CStrRef v1, short   v2)  { return more(v2, v1);}
inline bool less(CStrRef v1, int     v2)  { return more(v2, v1);}
inline bool less(CStrRef v1, int64   v2)  { return more(v2, v1);}
inline bool less(CStrRef v1, double  v2)  { return more(v2, v1);}
inline bool less(CStrRef v1, CStrRef v2)  { return v1.less(v2);}
inline bool less(CStrRef v1, litstr  v2)  { return v1.less(v2);}
inline bool less(CStrRef v1, CArrRef v2)  { return v1.less(v2);}
inline bool less(CStrRef v1, CObjRef v2)  { return v1.less(v2);}
inline bool less(CStrRef v1, CVarRef v2)  { return more(v2, v1);}

inline bool more(CStrRef v1, bool    v2)  { return less(v2, v1);}
inline bool more(CStrRef v1, char    v2)  { return less(v2, v1);}
inline bool more(CStrRef v1, short   v2)  { return less(v2, v1);}
inline bool more(CStrRef v1, int     v2)  { return less(v2, v1);}
inline bool more(CStrRef v1, int64   v2)  { return less(v2, v1);}
inline bool more(CStrRef v1, double  v2)  { return less(v2, v1);}
inline bool more(CStrRef v1, CStrRef v2)  { return v1.more(v2);}
inline bool more(CStrRef v1, litstr  v2)  { return v1.more(v2);}
inline bool more(CStrRef v1, CArrRef v2)  { return v1.more(v2);}
inline bool more(CStrRef v1, CObjRef v2)  { return v1.more(v2);}
inline bool more(CStrRef v1, CVarRef v2)  { return less(v2, v1);}

///////////////////////////////////////////////////////////////////////////////
// litstr

inline bool same(litstr v1, bool    v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, char    v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, short   v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, int     v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, int64   v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, double  v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, CStrRef v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, litstr  v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, CArrRef v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, CObjRef v2)  { return same(String(v1), v2);}
inline bool same(litstr v1, CVarRef v2)  { return same(String(v1), v2);}

inline bool equal(litstr v1, bool    v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, char    v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, short   v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, int     v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, int64   v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, double  v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, CStrRef v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, litstr  v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, CArrRef v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, CObjRef v2) { return equal(String(v1),v2);}
inline bool equal(litstr v1, CVarRef v2) { return equal(String(v1),v2);}

inline bool less(litstr v1, bool    v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, char    v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, short   v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, int     v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, int64   v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, double  v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, CStrRef v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, litstr  v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, CArrRef v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, CObjRef v2)  { return less(String(v1), v2);}
inline bool less(litstr v1, CVarRef v2)  { return less(String(v1), v2);}

inline bool more(litstr v1, bool    v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, char    v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, short   v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, int     v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, int64   v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, double  v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, CStrRef v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, litstr  v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, CArrRef v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, CObjRef v2)  { return more(String(v1), v2);}
inline bool more(litstr v1, CVarRef v2)  { return more(String(v1), v2);}

///////////////////////////////////////////////////////////////////////////////
// Array

inline bool same(CArrRef v1, bool    v2)  { return same(v2, v1);}
inline bool same(CArrRef v1, char    v2)  { return same(v2, v1);}
inline bool same(CArrRef v1, short   v2)  { return same(v2, v1);}
inline bool same(CArrRef v1, int     v2)  { return same(v2, v1);}
inline bool same(CArrRef v1, int64   v2)  { return same(v2, v1);}
inline bool same(CArrRef v1, double  v2)  { return same(v2, v1);}
inline bool same(CArrRef v1, CStrRef v2)  { return same(v2, v1);}
inline bool same(CArrRef v1, litstr  v2)  { return same(v2, v1);}
inline bool same(CArrRef v1, CArrRef v2)  { return v1.same(v2);}
inline bool same(CArrRef v1, CObjRef v2)  { return v1.same(v2);}
inline bool same(CArrRef v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(CArrRef v1, bool    v2) { return equal(v2, v1);}
inline bool equal(CArrRef v1, char    v2) { return equal(v2, v1);}
inline bool equal(CArrRef v1, short   v2) { return equal(v2, v1);}
inline bool equal(CArrRef v1, int     v2) { return equal(v2, v1);}
inline bool equal(CArrRef v1, int64   v2) { return equal(v2, v1);}
inline bool equal(CArrRef v1, double  v2) { return equal(v2, v1);}
inline bool equal(CArrRef v1, CStrRef v2) { return equal(v2, v1);}
inline bool equal(CArrRef v1, litstr  v2) { return equal(v2, v1);}
inline bool equal(CArrRef v1, CArrRef v2) { return v1.equal(v2);}
inline bool equal(CArrRef v1, CObjRef v2) { return v1.equal(v2);}
inline bool equal(CArrRef v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(CArrRef v1, bool    v2)  { return more(v2, v1);}
inline bool less(CArrRef v1, char    v2)  { return more(v2, v1);}
inline bool less(CArrRef v1, short   v2)  { return more(v2, v1);}
inline bool less(CArrRef v1, int     v2)  { return more(v2, v1);}
inline bool less(CArrRef v1, int64   v2)  { return more(v2, v1);}
inline bool less(CArrRef v1, double  v2)  { return more(v2, v1);}
inline bool less(CArrRef v1, CStrRef v2)  { return more(v2, v1);}
inline bool less(CArrRef v1, litstr  v2)  { return more(v2, v1);}
inline bool less(CArrRef v1, CArrRef v2)  { return v1.less(v2);}
inline bool less(CArrRef v1, CObjRef v2)  { return v1.less(v2);}
inline bool less(CArrRef v1, CVarRef v2)  { return v1.less(v2);}

inline bool more(CArrRef v1, bool    v2)  { return less(v2, v1);}
inline bool more(CArrRef v1, char    v2)  { return less(v2, v1);}
inline bool more(CArrRef v1, short   v2)  { return less(v2, v1);}
inline bool more(CArrRef v1, int     v2)  { return less(v2, v1);}
inline bool more(CArrRef v1, int64   v2)  { return less(v2, v1);}
inline bool more(CArrRef v1, double  v2)  { return less(v2, v1);}
inline bool more(CArrRef v1, CStrRef v2)  { return less(v2, v1);}
inline bool more(CArrRef v1, litstr  v2)  { return less(v2, v1);}
inline bool more(CArrRef v1, CArrRef v2)  { return v1.more(v2);}
inline bool more(CArrRef v1, CObjRef v2)  { return v1.more(v2);}
inline bool more(CArrRef v1, CVarRef v2)  { return v1.more(v2);}

///////////////////////////////////////////////////////////////////////////////
// Object

inline bool same(CObjRef v1, bool    v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, char    v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, short   v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, int     v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, int64   v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, double  v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, CStrRef v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, litstr  v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, CArrRef v2)  { return same(v2, v1);}
inline bool same(CObjRef v1, CObjRef v2)  { return v1.same(v2);}
inline bool same(CObjRef v1, CVarRef v2)  { return same(v2, v1);}

inline bool equal(CObjRef v1, bool    v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, char    v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, short   v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, int     v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, int64   v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, double  v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, CStrRef v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, litstr  v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, CArrRef v2) { return equal(v2, v1);}
inline bool equal(CObjRef v1, CObjRef v2) { return v1.equal(v2);}
inline bool equal(CObjRef v1, CVarRef v2) { return equal(v2, v1);}

inline bool less(CObjRef v1, bool    v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, char    v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, short   v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, int     v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, int64   v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, double  v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, CStrRef v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, litstr  v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, CArrRef v2)  { return more(v2, v1);}
inline bool less(CObjRef v1, CObjRef v2)  { return v1.less(v2);}
inline bool less(CObjRef v1, CVarRef v2)  { return more(v2, v1);}

inline bool more(CObjRef v1, bool    v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, char    v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, short   v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, int     v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, int64   v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, double  v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, CStrRef v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, litstr  v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, CArrRef v2)  { return less(v2, v1);}
inline bool more(CObjRef v1, CObjRef v2)  { return v1.more(v2);}
inline bool more(CObjRef v1, CVarRef v2)  { return less(v2, v1);}

///////////////////////////////////////////////////////////////////////////////
/**
 * Special-casing comparisons between arrays to get the same results from
 * comparisons between uncomparable arrays.
 */
bool not_more(CVarRef v1, CVarRef v2);

inline bool not_more_rev(CVarRef v2, CVarRef v1) {
  return not_more(v1, v2);
}

bool not_less(CVarRef v1, CVarRef v2);

inline bool not_less_rev(CVarRef v2, CVarRef v1) {
  return not_less(v1, v2);
}

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_COMPARISONS_H__
