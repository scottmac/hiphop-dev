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

#include <unistd.h>
#include <runtime/base/file/plain_file.h>
#include <runtime/base/type_string.h>
#include <runtime/base/util/request_local.h>

namespace HPHP {

IMPLEMENT_OBJECT_ALLOCATION(PlainFile);

///////////////////////////////////////////////////////////////////////////////
// constructor and destructor

PlainFile::PlainFile(FILE *stream, bool pipe)
  : File(pipe), m_stream(stream), m_eof(false) {
  if (stream) m_fd = fileno(stream);
}

PlainFile::~PlainFile() {
  closeImpl();
}

bool PlainFile::open(CStrRef filename, CStrRef mode) {
  ASSERT(m_stream == NULL);
  ASSERT(m_fd == -1);

  FILE *f = fopen(filename.data(), mode.data());
  if (!f) {
    return false;
  }
  m_stream = f;
  m_fd = fileno(f);
  return true;
}

bool PlainFile::close() {
  return closeImpl();
}

bool PlainFile::closeImpl() {
  bool ret = true;
  if (!m_closed) {
    if (m_stream) {
      ret = (fclose(m_stream) == 0);
    }
    m_closed = true;
    m_stream = NULL;
  }
  File::closeImpl();
  return ret;
}

///////////////////////////////////////////////////////////////////////////////
// virtual functions

int PlainFile::readImpl(char *buffer, int length) {
  ASSERT(m_stream);
  ASSERT(length > 0);
  // use read instead of fread to handle EOL in stdin
  size_t ret = ::read(m_fd, buffer, length);
  if (ret == 0
   || (ret == (size_t)-1
    && errno != EWOULDBLOCK && errno != EINTR && errno != EBADF)) {
    m_eof = true;
  }
  return ret == (size_t)-1 ? 0 : ret;
}

int PlainFile::getc() {
  ASSERT(m_stream);
  return File::getc();
}

int PlainFile::writeImpl(const char *buffer, int length) {
  ASSERT(m_stream);
  ASSERT(length > 0);

  // use write instead of fwrite to be consistent with read
  // o.w., read-and-write files would not work
  int written = ::write(m_fd, buffer, length);
  return written < 0 ? 0 : written;
}

bool PlainFile::seek(int offset, int whence /* = SEEK_SET */) {
  ASSERT(m_stream);

  if (whence == SEEK_CUR) {
    if (offset > 0 && offset < m_writepos - m_readpos) {
      m_readpos += offset;
      m_position += offset;
      return true;
    }
    offset += m_position;
    whence = SEEK_SET;
  }

  // invalidate the current buffer
  m_writepos = 0;
  m_readpos = 0;
  // clear the eof flag
  m_eof = false;
  // lseek instead of seek to be consistent with read
  off_t result = lseek(m_fd, offset, whence);
  m_position = result;
  return result != (off_t)-1;
}

int PlainFile::tell() {
  ASSERT(m_stream);
  return m_position;
}

bool PlainFile::eof() {
  ASSERT(m_stream);
  int avail = m_writepos - m_readpos;
  if (avail > 0) {
    return false;
  }
  return m_eof;
}

bool PlainFile::rewind() {
  ASSERT(m_stream);
  seek(0);
  m_writepos = 0;
  m_readpos = 0;
  m_position = 0;
  return true;
}

bool PlainFile::flush() {
  ASSERT(m_stream);
  return fflush(m_stream) == 0;
}

bool PlainFile::truncate(int size) {
  ASSERT(m_stream);
  return ftruncate(fileno(m_stream), size) == 0;
}

///////////////////////////////////////////////////////////////////////////////
// BuiltinFiles

IMPLEMENT_REQUEST_LOCAL(BuiltinFiles, g_builtin_files);

void BuiltinFiles::requestShutdown() {
  m_stdin.reset();
  m_stdout.reset();
  m_stderr.reset();
}

CVarRef BuiltinFiles::getSTDIN() {
  if (g_builtin_files->m_stdin.isNull()) {
    g_builtin_files->m_stdin = NEW(PlainFile)(stdin);
  }
  return g_builtin_files->m_stdin;
}

CVarRef BuiltinFiles::getSTDOUT() {
  if (g_builtin_files->m_stdout.isNull()) {
    g_builtin_files->m_stdout = NEW(PlainFile)(stdout);
  }
  return g_builtin_files->m_stdout;
}

CVarRef BuiltinFiles::getSTDERR() {
  if (g_builtin_files->m_stderr.isNull()) {
    g_builtin_files->m_stderr = NEW(PlainFile)(stderr);
  }
  return g_builtin_files->m_stderr;
}

///////////////////////////////////////////////////////////////////////////////
}
