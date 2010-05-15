/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   | Copyright (c) 1997-2010 The PHP Group                                |
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

#include <runtime/ext/extension.h>
#include <runtime/base/type_variant.h>

using namespace std;

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

typedef std::map<std::string, Extension*, stdltistr> ExtensionMap;
static ExtensionMap *s_registered_extensions = NULL;

Extension::Extension(litstr name) : m_name(name) {
  if (s_registered_extensions == NULL) {
    s_registered_extensions = new ExtensionMap();
  }
  ASSERT(s_registered_extensions->find(name) ==
         s_registered_extensions->end());
  (*s_registered_extensions)[name] = this;
}

void Extension::LoadModules(Hdf hdf) {
  ASSERT(s_registered_extensions);
  for (ExtensionMap::const_iterator iter = s_registered_extensions->begin();
       iter != s_registered_extensions->end(); ++iter) {
    iter->second->moduleLoad(hdf["Extensions"][iter->second->m_name]);
  }
}

void Extension::InitModules() {
  ASSERT(s_registered_extensions);
  for (ExtensionMap::const_iterator iter = s_registered_extensions->begin();
       iter != s_registered_extensions->end(); ++iter) {
    iter->second->moduleInit();
  }
}

void Extension::ShutdownModules() {
  ASSERT(s_registered_extensions);
  for (ExtensionMap::const_iterator iter = s_registered_extensions->begin();
       iter != s_registered_extensions->end(); ++iter) {
    iter->second->moduleShutdown();
  }
}

bool Extension::IsLoaded(CStrRef name) {
  ASSERT(s_registered_extensions);
  return s_registered_extensions->find(name.data()) !=
    s_registered_extensions->end();
}

Array Extension::GetLoadedExtensions() {
  ASSERT(s_registered_extensions);
  Array ret = Array::Create();
  for (ExtensionMap::const_iterator iter = s_registered_extensions->begin();
       iter != s_registered_extensions->end(); ++iter) {
    ret.append(iter->second->m_name);
  }
  return ret;
}

///////////////////////////////////////////////////////////////////////////////
}
