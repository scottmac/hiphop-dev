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

#ifndef __HPHP_EXECUTION_CONTEXT_H__
#define __HPHP_EXECUTION_CONTEXT_H__

#include <runtime/base/type_variant.h>
#include <runtime/base/server/transport.h>
#include <util/thread_local.h>
#include <runtime/base/resource_data.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/**
 * Mainly designed for extensions to perform initialization and shutdown
 * sequences at request scope.
 */
class RequestEventHandler {
public:
  RequestEventHandler() : m_inited(false) {}
  virtual ~RequestEventHandler() {}

  virtual void requestInit() = 0;
  virtual void requestShutdown() = 0;

  void setInited(bool inited) { m_inited = inited;}
  bool getInited() const { return m_inited;}

  // Priority of request shutdown call. Lower priority value means
  // requestShutdown is called earlier than higher priority values.
  virtual int priority() const;

protected:
  bool m_inited;
};

/**
 * Put all global variables here so we can gather them into one thread-local
 * variable for easy access.
 */
class ExecutionContext {
public:
  enum ConnetionStatus {
    Normal,
    Aborted,
    TimedOut,
  };

  enum ShutdownType {
    ShutDown,
    PostSend,
    CleanUp,
  };

public:
  ExecutionContext();
  ~ExecutionContext();

  /**
   * Get current output buffer.
   */
  std::ostream &out() { return *m_out;}
  std::ostream &err() { return *m_err;}

  /**
   * Output buffering.
   */
  void obStart(CVarRef handler = null);
  String obGetContents();
  std::string getContents();
  int obGetContentLength();
  void obClean();
  bool obFlush();
  void obFlushAll();
  bool obEnd();
  void obEndAll();
  int obGetLevel();
  void obSetImplicitFlush(bool on);
  Array obGetHandlers();
  void obProtect(bool on); // making sure obEnd() never passes current level
  void flush();

  /**
   * Program execution hooks.
   */
  void registerShutdownFunction(CVarRef function, Array arguments,
                                ShutdownType type);
  void registerTickFunction(CVarRef function, Array arguments);
  void unregisterTickFunction(CVarRef function);
  Variant pushSystemExceptionHandler(CVarRef function);
  Variant pushUserExceptionHandler(CVarRef function);
  void popSystemExceptionHandler();
  void popUserExceptionHandler();

  /**
   * Request sequences.
   */
  void registerRequestEventHandler(RequestEventHandler *handler);
  void onRequestShutdown();

  void onShutdownPreSend();
  void onShutdownPostSend();
  void onTick();
  bool callUserErrorHandler(const Exception &e, int64 errnum,
                            bool swallowExceptions);
  void recordLastError(const Exception &e);
  void onFatalError(const Exception &e);
  void onUnhandledException(Object e);
  void setInsideRaiseError(bool yes);
  bool isInsideRaiseError();

  String getLastError();
  int getErrorReportingLevel();
  void setErrorReportingLevel(int level);
  String getTimeZone();
  void setTimeZone(CStrRef timezone);
  String getDefaultTimeZone();
  String getCwd();
  void setCwd(CStrRef cwd);
  void setenv(CStrRef name, CStrRef value);
  String getenv(CStrRef name);

  Transport *getTransport() { return m_transport;}
  void setTransport(Transport *transport) { m_transport = transport;}
  String getMimeType();
  void setContentType(CStrRef mimetype, CStrRef charset);
  // TODO: support these features
  ConnetionStatus getConnectionStatus() { return m_connStatus;}

  int64 getRequestMemoryMaxBytes() const { return m_requestMemoryMaxBytes; }
  void setRequestMemoryMaxBytes(int64 max) {
    m_requestMemoryMaxBytes = max;
  }
  int64 getRequestTimeLimit() const { return m_requestTimeLimit; }
  void setRequestTimeLimit(int64 limit) {
    m_requestTimeLimit = limit;
  }

  // invoke which page on 500 errors
  void setErrorPage(const char *page) { m_errorPage = page ? page : "";}
  const std::string &getErrorPage() const { return m_errorPage;}

private:
  struct OutputBuffer {
    std::ostringstream oss;
    Variant handler;
  };

  std::ostream *m_err;                // current error log stream
  std::ostream *m_out;                // current output buffer
  std::list<OutputBuffer*> m_buffers; // a stack of output buffers
  std::ofstream m_null;
  bool m_implicitFlush;
  int m_protectedLevel;
  std::string m_errorPage;

  std::set<RequestEventHandler*> m_requestEventHandlerSet;
  std::vector<RequestEventHandler*> m_requestEventHandlers;
  ConnetionStatus m_connStatus;
  Transport *m_transport;

  int64 m_requestMemoryMaxBytes;
  // Only used for ini_get
  int64 m_requestTimeLimit;
  void resetCurrentBuffer();
  void executeFunctions(CArrRef funcs);
};

class PersistentObjectStore {
public:
  ~PersistentObjectStore();

  int size() const;

  void set(const char *type, const char *name, ResourceData *obj);
  ResourceData *get(const char *type, const char *name);
  void remove(const char *type, const char *name);

  const ResourceMap &getMap(const char *type);

private:
  ResourceMapMap m_objects;

  void removeObject(ResourceData *data);
};

class Silencer {
public:
  Silencer();
  ~Silencer();
  void enable();
  void disable();
  Variant disable(CVarRef v);

private:
  bool m_active;
  int m_errorReportingValue;
};

///////////////////////////////////////////////////////////////////////////////

extern DECLARE_THREAD_LOCAL(ExecutionContext, g_context);
extern DECLARE_THREAD_LOCAL(PersistentObjectStore, g_persistentObjects);

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_EXECUTION_CONTEXT_H__
