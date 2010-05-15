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

#ifndef __HPHP_SOURCE_ROOT_INFO_H__
#define __HPHP_SOURCE_ROOT_INFO_H__

#include <runtime/base/type_string.h>
#include <runtime/base/type_variant.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

class Transport;

class SourceRootInfo {
public:
  SourceRootInfo(const char *host);
  ~SourceRootInfo();

  void setServerVariables(Variant &server) const;
  std::string path() const;

  bool sandboxOn() const {
    return m_sandboxCond == SandboxOn;
  }

  void clear() {
    m_user.reset();
    m_sandbox.reset();
    m_path.reset();
  }

  bool error() const {
    return m_sandboxCond == SandboxError;
  }
  void handleError(Transport *t);

private:
  String m_user;
  String m_sandbox;
  String m_path;
  enum SandboxCondition {
    SandboxOn,
    SandboxError,
    SandboxOff
  } m_sandboxCond;

  std::string parseSandboxServerVariable(const std::string &format) const;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_SOURCE_ROOT_INFO_H__
