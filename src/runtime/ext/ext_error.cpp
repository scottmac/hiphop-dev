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

#include <runtime/ext/ext_error.h>
#include <runtime/base/util/exceptions.h>
#include <runtime/base/runtime_option.h>
#include <runtime/base/util/string_buffer.h>
#include <runtime/base/source_info.h>
#include <runtime/base/debug/backtrace.h>
#include <runtime/base/frame_injection.h>
#include <system/gen/php/globals/constants.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

Array f_debug_backtrace() {
  if (RuntimeOption::InjectedStackTrace) {
    return FrameInjection::GetBacktrace(true);
  }
  StackTrace st;
  return stackTraceToBackTrace(st);
}

void f_debug_print_backtrace() {
  if (RuntimeOption::InjectedStackTrace) {
    Array bt = FrameInjection::GetBacktrace(true);
    int i = 0;
    for (ArrayIter it = bt.begin(); !it.end(); it.next(), i++) {
      Array frame = it.second().toArray();
      StringBuffer buf;
      buf.append('#');
      buf.append(i);
      if (i < 10) buf.append(' ');
      buf.append(' ');
      if (frame.exists("class")) {
        buf.append(frame->get("class").toString());
        buf.append(frame->get("type").toString());
      }
      buf.append(frame->get("function").toString());
      buf.append("()");
      if (frame.exists("file")) {
        buf.append(" called at [");
        buf.append(frame->get("file").toString());
        buf.append(':');
        buf.append(frame->get("line").toString());
        buf.append(']');
      }
      buf.append('\n');
      echo(buf.detach());
    }
  } else {
    StackTrace st;
    echo(String(st.toString()));
  }
}

Array f_error_get_last() {
  String lastError = g_context->getLastError();
  if (lastError.isNull()) {
    return (ArrayData *)NULL;
  }
  return CREATE_VECTOR1(g_context->getLastError());
}

bool f_error_log(CStrRef message, int message_type /* = 0 */,
                 CStrRef destination /* = null_string */,
                 CStrRef extra_headers /* = null_string */) {
  // error_log() should not invoke the user error handler,
  // so we use Logger::Error() instead of raise_warning()
  std::string line(message.data(),
                   // Truncate to 512k
                   message.size() > (1<<19) ? (1<<19) : message.size());
  Logger::RawError(line);
  return true;
}

int f_error_reporting(CVarRef level /* = null */) {
  int oldErrorReportingLevel = g_context->getErrorReportingLevel();
  if (!level.isNull()) {
    g_context->setErrorReportingLevel(level.toInt32());
  }
  return oldErrorReportingLevel;
}

bool f_restore_error_handler() {
  g_context->popSystemExceptionHandler();
  return true;
}

bool f_restore_exception_handler() {
  g_context->popUserExceptionHandler();
  return false;
}

Variant f_set_error_handler(CVarRef error_handler, int error_types /* = 0 */) {
  return g_context->pushSystemExceptionHandler(error_handler);
}

String f_set_exception_handler(CStrRef exception_handler) {
  return g_context->pushUserExceptionHandler(exception_handler);
}

void f_hphp_set_error_page(CStrRef page) {
  g_context->setErrorPage(page);
}

bool f_trigger_error(CStrRef error_msg,
                     int error_type /* = k_E_USER_NOTICE */) {
  std::string msg = error_msg.data();
  if (error_type == k_E_USER_ERROR) {
    raise_error_ex(msg, error_type, true, ThrowIfUnhandled,
                   "HipHop Recoverable error: ");
  } else if (error_type == k_E_USER_WARNING) {
    raise_error_ex(msg, error_type, true, NeverThrow,
                   "HipHop Warning:  ");
  } else if (error_type == k_E_USER_NOTICE) {
    raise_error_ex(msg, error_type, true, NeverThrow,
                   "HipHop Notice:  ");
  } else {
    return false;
  }
  return true;
}

bool f_user_error(CStrRef error_msg, int error_type /* = k_E_USER_NOTICE */) {
  return f_trigger_error(error_msg, error_type);
}

///////////////////////////////////////////////////////////////////////////////
}
