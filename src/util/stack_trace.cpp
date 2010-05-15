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

#include "stack_trace.h"
#include "process.h"
#include "base.h"
#include "lock.h"
#include "util.h"

#ifndef MAC_OS_X
#include <execinfo.h>
#include <bfd.h>
#endif

#include <signal.h>

using namespace std;
using namespace boost;

namespace HPHP {

///////////////////////////////////////////////////////////////////////////////

std::string StackTrace::Frame::toString() const {
  string out;
  out = funcname.empty() ? "??" : funcname;
  out += " at ";
  out += filename.empty() ? "??" : filename;
  out += ":";
  out += lexical_cast<string>(lineno);
  return out;
}

///////////////////////////////////////////////////////////////////////////////
// signal handler

bool SegFaulting = false;

static void bt_handler(int sig) {
  // In case we crash again in the signal hander or something
  signal(sig, SIG_DFL);

  // Generating a stack dumps significant time, try to stop threads
  // from flushing bad data or generating more faults meanwhile
  if (sig==SIGQUIT || sig==SIGILL || sig==SIGSEGV || sig==SIGBUS) {
    SegFaulting=true;
    // leave running for SIGTERM SIGFPE SIGABRT
  }

  // Turn on stack traces for coredumps
  StackTrace::Enabled = true;
  StackTraceNoHeap st;

  char pid[sizeof(Process::GetProcessId())*3+2]; // '-' and \0
  sprintf(pid,"%u",Process::GetProcessId());
  char tracefn [strlen("/tmp/stacktrace..log" + strlen(pid) +1 )];
  sprintf(tracefn,"/tmp/stacktrace.%s.log" , pid);
  
  st.log(strsignal(sig), tracefn, pid);

  //cerr << logmessage << endl;
  if (!StackTrace::ReportEmail.empty()) {
    //cerr << "Emailing trace to " << StackTrace::ReportEmail << endl;
    char format [] = "cat %s | mail -s \"Stack Trace from %s\"%s";
    char cmdline[strlen(format)+strlen(tracefn)
                 +strlen(Process::GetAppName().c_str())
                 +strlen(StackTrace::ReportEmail.c_str())+1];
    sprintf(cmdline, format, tracefn, Process::GetAppName().c_str(),  
            StackTrace::ReportEmail.c_str());
    Util::ssystem(cmdline);
  }

  // Calling all of these library functions in a signal handler
  // is completely undefined behavior, but we seem to get away with it.
  // Do it last just in case

  Logger::Error("Core dumped: %s", strsignal(sig));

  // re-raise the signal and pass it to the default handler
  // to terminate the process.
  raise(sig);
}
///////////////////////////////////////////////////////////////////////////////
// statics

bool StackTraceBase::Enabled = true;
string StackTraceBase::ReportEmail;

void StackTraceBase::InstallReportOnSignal(int sig) {
  signal(sig, bt_handler);
}

void StackTraceBase::InstallReportOnErrors() {
  static bool already_set = false;
  if (already_set) return;
  already_set = true;

  // Turn on bt-on-sig for a good default set of error signals
  signal(SIGQUIT, bt_handler);
  signal(SIGTERM, bt_handler);
  signal(SIGILL,  bt_handler);
  signal(SIGFPE,  bt_handler);
  signal(SIGSEGV, bt_handler);
  signal(SIGBUS,  bt_handler);
  signal(SIGABRT, bt_handler);
}

///////////////////////////////////////////////////////////////////////////////
// constructor and destructor

StackTraceBase::StackTraceBase() {
#ifndef MAC_OS_X
  bfd_init();
#endif
}

StackTrace::StackTrace(const StackTrace &bt) {
  assert(this != &bt);

  m_bt_pointers = bt.m_bt_pointers;
  m_bt = bt.m_bt;
}

StackTrace::StackTrace(bool trace) {
  if (trace && Enabled) {
    create();
  }
}

StackTraceNoHeap::StackTraceNoHeap(bool trace) {
  if (trace && Enabled) {
    create();
  }
}

StackTrace::StackTrace(const std::string &hexEncoded) {
  vector<string> frames;
  Util::split(':', hexEncoded.c_str(), frames);
  for (unsigned int i = 0; i < frames.size(); i++) {
    m_bt_pointers.push_back((void*)strtoll(frames[i].c_str(), NULL, 16));
  }
}

void StackTrace::create() {
  void *btpointers[MAXFRAME];
  int framecount = 0;
#ifndef MAC_OS_X
  framecount = backtrace(btpointers, MAXFRAME);
#endif
  if (framecount <= 0 || framecount > (signed) MAXFRAME) {
    m_bt_pointers.clear();
    return;
  }
  m_bt_pointers.resize(framecount);
  for (int i = 0; i < framecount; i++) {
    m_bt_pointers[i] = btpointers[i];
  }
}

void StackTraceNoHeap::create() {
  int unsigned framecount = 0;
#ifndef MAC_OS_X
  framecount = backtrace(m_btpointers, MAXFRAME);
#endif
  if (framecount <= 0 || framecount > MAXFRAME) {
    m_btpointers_cnt = 0; 
    return;
  }
  m_btpointers_cnt = framecount;
}

///////////////////////////////////////////////////////////////////////////////
// reporting functions

const std::string &StackTrace::toString() const {
  if (m_bt.empty()) {
    size_t frame = 0;
    for (vector<void*>::const_iterator btpi = m_bt_pointers.begin();
         btpi != m_bt_pointers.end(); ++btpi) {
      string framename = Translate(*btpi)->toString();
      if (framename.find("StackTrace::") != string::npos) {
        continue; // ignore frames in the StackTrace class
      }
      m_bt += "# ";
      m_bt += lexical_cast<string>(frame);
      if (frame < 10) m_bt += " ";

      m_bt += " ";
      m_bt += framename;
      m_bt += "\n";
      ++frame;
    }
  }
  return m_bt;
}

void StackTraceNoHeap::print(FILE *f) const {
  int frame=0;
  for (unsigned int i=0; i<m_btpointers_cnt; i++) {
    if (!Translate(f, m_btpointers[i], frame)) continue;;
    frame++;
  }
}

void StackTrace::get(FramePtrVec &frames) const {
  frames.clear();
  for (vector<void*>::const_iterator btpi = m_bt_pointers.begin();
       btpi != m_bt_pointers.end(); ++btpi) {
    frames.push_back(Translate(*btpi));
  }
}

std::string StackTrace::hexEncode(int minLevel /* = 0 */,
                                  int maxLevel /* = 999 */) const {
  string bts;
  for (int i = minLevel; i < (int)m_bt_pointers.size() && i < maxLevel; i++) {
    if (i > minLevel) bts += ':';
    char buf[20];
    snprintf(buf, sizeof(buf), "%llx", (int64)m_bt_pointers[i]);
    bts.append(buf);
  }
  return bts;
}

template <class T>
struct DumpGetThreadId {
  void print(FILE *f, const pthread_t& p) { fprintf (f, lexical_cast<string>(p).c_str()); }
};
template <>
struct DumpGetThreadId<unsigned long int> {
  // no heap version, if possible
  void print(FILE *f, const pthread_t& p) { fprintf (f, "%lu", (unsigned long int)(p)); }
};
void StackTraceNoHeap::log(const char *errorType, const char * tracefn, const char * pid) const {
  FILE *f = fopen(tracefn,"w");
  if (!f) return;

  fprintf(f,"Host: %s\n",Process::GetHostName().c_str());
  fprintf(f, "ProcessID: %s\n", pid);
  fprintf(f,"ThreadID: "); 
  { DumpGetThreadId<pthread_t> p; p.print(f,Process::GetThreadId()); }
  fprintf (f,"\nName: %s\n", Process::GetAppName().c_str());
  fprintf (f,"Type: %s\n\n", errorType ? errorType : "(unknown error)" );
  print(f);
  fprintf(f,"\n");
  fclose(f);

  return ;
}


///////////////////////////////////////////////////////////////////////////////
// helpers

struct addr2line_data {
  asymbol **syms;
  bfd_vma pc;
  const char *filename;
  const char *functionname;
  unsigned int line;
  bfd_boolean found;
};


bool StackTraceBase::Translate(void *frame, StackTraceBase::Frame * f, 
                               Dl_info &dlInfo, void* data) {
  char sframe[32];
  snprintf(sframe, sizeof(sframe), "%p", frame);

  if (!dladdr(frame, &dlInfo)) {
    return false;
  }

  // frame pointer offset in previous frame
  f->offset = (char*)frame - (char*)dlInfo.dli_saddr;

  if (dlInfo.dli_fname) {

    // 1st attempt without offsetting base address
    if (!Addr2line(dlInfo.dli_fname, sframe, f, data) &&
        dlInfo.dli_fname && strstr(dlInfo.dli_fname,".so")) {
      // offset shared lib's base address
      frame = (char*)frame - (size_t)dlInfo.dli_fbase;
      snprintf(sframe, sizeof(sframe), "%p", frame);

      // Use addr2line to get line number info.
      Addr2line(dlInfo.dli_fname, sframe, f, data);
    }
  }
  return true;
}

StackTrace::FramePtr StackTrace::Translate(void *frame) {
  Dl_info dlInfo;
  addr2line_data adata;

  Frame * f1 = new Frame(frame);
  FramePtr f(f1);
  if (!StackTraceBase::Translate(frame, f1, dlInfo, &adata)) return f;

  if (adata.filename) {
    f->filename = adata.filename;
  }
  if (adata.functionname) {
    f->funcname = Demangle(adata.functionname);
  }
  if (f->filename.empty() && dlInfo.dli_fname) {
    f->filename = dlInfo.dli_fname;
  }
  if (f->funcname.empty() && dlInfo.dli_sname) {
    f->funcname = Demangle(dlInfo.dli_sname);
  }

  return f;
}

bool StackTraceNoHeap::Translate(FILE *fp, void *frame, int frame_num) {

  // frame pointer offset in previous frame
  Dl_info dlInfo;
  addr2line_data adata;
  Frame f(frame);
  if (!StackTraceBase::Translate(frame, &f, dlInfo, &adata))  {
     return false;
  }

  const char *filename=adata.filename ? adata.filename : dlInfo.dli_fname;
  if (!filename) filename = "??";
  const char *funcname=adata.functionname ? adata.functionname : dlInfo.dli_sname;
  if (!funcname) filename = "??";

  // ignore frames in the StackTrace class
  if (strstr(funcname,"StackTraceNoHeap")) 
      return false ;

  fprintf (fp, "# %d%s ", frame_num, frame_num < 10 ? " " : ""); 
  Demangle(fp, funcname);
  fprintf(fp, " at %s:%u\n", filename, f.lineno);

  return true;
}

///////////////////////////////////////////////////////////////////////////////
// copied and re-factored from addr2line

#ifndef MAC_OS_X

static void find_address_in_section(bfd *abfd, asection *section, void *data) {
  addr2line_data *adata = reinterpret_cast<addr2line_data*>(data);

  bfd_vma vma;
  bfd_size_type size;

  if (adata->found) {
    return;
  }

  if ((bfd_get_section_flags(abfd, section) & SEC_ALLOC) == 0) {
    return;
  }

  vma = bfd_get_section_vma(abfd, section);
  if (adata->pc < vma) {
    return;
  }

  size = bfd_get_section_size(section);
  if (adata->pc >= vma + size) {
    return;
  }

  adata->found = bfd_find_nearest_line(abfd, section, adata->syms,
                                       adata->pc - vma, &adata->filename,
                                       &adata->functionname, &adata->line);
  if (adata->found) {
    const char *file = adata->filename;
    unsigned int line = adata->line;
    bfd_boolean found = TRUE;
    while (found) {
      found = bfd_find_inliner_info(abfd, &file, &adata->functionname, &line);
    }
  }
}

static bool slurp_symtab(asymbol ***syms, bfd *abfd) {
  long symcount;
  unsigned int size;

  symcount = bfd_read_minisymbols(abfd, FALSE, (void **)syms, &size);
  if (symcount == 0) {
    symcount = bfd_read_minisymbols(abfd, TRUE /* dynamic */, (void **)syms,
                                    &size);
  }
  return symcount >= 0;
}

static bool translate_addresses(bfd *abfd, const char *addr,
                                addr2line_data *adata) {
  adata->pc = bfd_scan_vma(addr, NULL, 16);

  adata->found = FALSE;
  bfd_map_over_sections(abfd, find_address_in_section, adata);

  if (!adata->found || !adata->functionname || !*adata->functionname) {
    return false;
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////
// We cache opened bfd file pointers that in turn cached frame pointer lookup
// tables.

struct bfd_cache {
  bfd *abfd;
  asymbol **syms;

  ~bfd_cache() {
    if (abfd) {
      bfd_cache_close(abfd);
      bfd_free_cached_info(abfd);
      bfd_close_all_done(abfd);
    }
  }
};
typedef boost::shared_ptr<bfd_cache> bfd_cache_ptr;
typedef __gnu_cxx::hash_map<std::string, bfd_cache_ptr, string_hash> bfdMap;
static Mutex s_bfdMutex;
static bfdMap s_bfds;

static bfd_cache_ptr get_bfd_cache(const char *filename) {
  bfdMap::const_iterator iter = s_bfds.find(filename);
  if (iter != s_bfds.end()) {
    return iter->second;
  }
  bfd_cache_ptr p(new bfd_cache());
  bfd *abfd = bfd_openr(filename, NULL);
  if (abfd) {
    p->abfd = abfd;
    p->syms = NULL;
    char **match;
    if (bfd_check_format(abfd, bfd_archive) ||
        !bfd_check_format_matches(abfd, bfd_object, &match) ||
        !slurp_symtab(&p->syms, abfd)) {
      bfd_close(abfd);
      p.reset();
    }
  } else {
    p.reset();
  }
  s_bfds[filename] = p;
  return p;
}

#endif

bool StackTraceBase::Addr2line(const char *filename, const char *address,
                           Frame *frame, void *adata) {
#ifndef MAC_OS_X
  Lock lock(s_bfdMutex);
  addr2line_data *data = reinterpret_cast<addr2line_data*>(adata);
  bfd_cache_ptr p = get_bfd_cache(filename);
  if (!p) return false;

  data->filename = NULL;
  data->functionname = NULL;
  data->line = 0;
  data->syms = p->syms;
  bool ret = translate_addresses(p->abfd, address, data);
  if (ret) {
    frame->lineno = data->line;
  }
  return ret;
#else
  return false;
#endif
}

///////////////////////////////////////////////////////////////////////////////
// copied and re-factored from demangle/c++filt

#define DMGL_PARAMS	 (1 << 0)	/* Include function args */
#define DMGL_ANSI	 (1 << 1)	/* Include const, volatile, etc */
#define DMGL_VERBOSE	 (1 << 3)	/* Include implementation details.  */

#ifndef MAC_OS_X

extern "C" {
  extern char *cplus_demangle (const char *mangled, int options);
}

#endif

std::string StackTrace::Demangle(const char *mangled) {
  assert(mangled);
  if (!mangled || !*mangled) {
    return "";
  }

#ifndef MAC_OS_X
  size_t skip_first = 0;
  if (mangled[0] == '.' || mangled[0] == '$') ++skip_first;
  //if (mangled[skip_first] == '_') ++skip_first;

  char *result = cplus_demangle(mangled + skip_first, DMGL_PARAMS | DMGL_ANSI | DMGL_VERBOSE);
  if (result == NULL) return mangled;

  string ret;
  if (mangled[0] == '.') ret += '.';
  ret += result;
  free (result);
  return ret;
#else
  return mangled;
#endif
}

void StackTraceNoHeap::Demangle(FILE *f, const char *mangled) {
  assert(mangled);
  if (!mangled || !*mangled) {
    fprintf(f, "??");
    return ;
  }

#ifndef MAC_OS_X
  size_t skip_first = 0;
  if (mangled[0] == '.' || mangled[0] == '$') ++skip_first;
  //if (mangled[skip_first] == '_') ++skip_first;

  char *result = cplus_demangle(mangled + skip_first, DMGL_PARAMS | DMGL_ANSI | DMGL_VERBOSE);
  if (result == NULL) {
    fprintf (f, "%s", mangled);
    return;
  }
  fprintf (f, "%s%s", mangled[0]=='.' ? "." : "", result);
  return ;
#else
  fprintf (f, "%s", mangled);
  return ;
#endif
}


///////////////////////////////////////////////////////////////////////////////
}
