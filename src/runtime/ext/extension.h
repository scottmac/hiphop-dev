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

#ifndef __EXTENSION_H__
#define __EXTENSION_H__

#include <runtime/base/type_array.h>
#include <runtime/base/type_variant.h>
#include <util/hdf.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/**
 * Base class of extension modules. See ext_session.cpp for an example. It is
 * NOT required to have an extention class to derive from this base class,
 * unless one of these is needed:
 *
 *   - register an extension's name so extension_loaded() can work;
 *   - register extension's detailed information;
 *   - implement moduleInit() and moduleShutdown() logics that static
 *     initialization is too early.
 *
 * If only "name" is needed to register, use IMPLEMENT_DEFAULT_EXTENSION.
 */

#define IMPLEMENT_DEFAULT_EXTENSION(name)               \
  class name ## Extension : public Extension {          \
  public:                                               \
    name ## Extension() : Extension(#name) {}           \
  };                                                    \
  static name ## Extension s_ ## name ## _extension;    \

///////////////////////////////////////////////////////////////////////////////

class Extension {
public:
  static bool IsLoaded(CStrRef name);
  static Array GetLoadedExtensions();

  // called by RuntimeOption to initialize all configurations of extension
  static void LoadModules(Hdf hdf);

  // called by hphp_process_init/exit
  static void InitModules();
  static void ShutdownModules();

public:
  Extension(litstr name);
  virtual ~Extension() {}

  // override these functions to implement module specific init/shutdown
  // sequences and information display.
  virtual void moduleLoad(Hdf hdf) {}
  virtual void moduleInfo(Array &info) { info.set(m_name, true);}
  virtual void moduleInit() {}
  virtual void moduleShutdown() {}

private:
  const char *m_name;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXTENSION_H__
