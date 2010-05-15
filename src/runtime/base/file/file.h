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

#ifndef __HPHP_FILE_H__
#define __HPHP_FILE_H__

#include <runtime/base/types.h>
#include <runtime/base/resource_data.h>
#include <runtime/base/type_array.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/**
 * This is PHP's "stream", base class of plain file, gzipped file, directory
 * and sockets. We are not going to structure directories this way at all,
 * but we will have PlainFile, ZipFile and Socket derive from this base class,
 * so they can share some minimal functionalities.
 */
class File : public SweepableResourceData {
public:
  static String TranslatePath(CStrRef filename, bool useFileCache = false);
  static String TranslateCommand(CStrRef cmd);
  static Variant Open(CStrRef filename, CStrRef mode,
                      CArrRef options = null_array);

  static bool IsVirtualDirectory(CStrRef filename);

public:
  File(bool pipe = false);
  virtual ~File();

  // overriding ResourceData
  const char *o_getClassName() const { return "File";}
  const char *o_getResourceName() const { return "stream";}
  int o_getResourceId() const {
    // This is different from Zend where each resource is assigned a unique id.
    return o_id;
  }

  int fd() const { return m_fd;}
  bool valid() const { return m_fd >= 0;}

  /**
   * How to open this type of file.
   */
  virtual bool open(CStrRef filename, CStrRef mode) = 0;

  /**
   * How to close this type of file.
   */
  virtual bool close() = 0;

  /**
   * Read one chunk of input. Returns a null string on failure or eof.
   */
  virtual int readImpl(char *buffer, int length) = 0;
  virtual int getc();
  virtual String read(int length = 0);

  /**
   * Write one chunk of output. Returns bytes written.
   */
  virtual int writeImpl(const char *buffer, int length) = 0;
  virtual int write(CStrRef str, int length = 0);
  int putc(char c);

  /**
   * Optional virtual functions to implement.
   */
  virtual bool seek(int offset, int whence = SEEK_SET);
  virtual int tell();
  virtual bool eof();
  virtual bool rewind();
  virtual bool flush();
  virtual bool truncate(int size);
  virtual bool lock(int operation);
  virtual bool lock(int operation, bool &wouldblock);
  virtual Array getMetaData();

  /**
   * Read one line a time. Returns a null string on failure or eof.
   */
  String readLine(int maxlen = 0);

  /**
   * Read one record a time. Returns a null string on failure or eof.
   */
  String readRecord(CStrRef delimiter, int maxlen = 0);

  /**
   * Read entire file and print it out.
   */
  int print();

  /**
   * Write to file with specified format and arguments.
   */
  int printf(CStrRef format, CArrRef args);

  /**
   * Write one line of csv record.
   */
  int writeCSV(CArrRef fields, char delimiter = ',', char enclosure = '"');

  /**
   * Read one line of csv record.
   */
  Array readCSV(int length = 0, char delimiter = ',', char enclosure = '"');

protected:
  int m_fd;      // file descriptor
  bool m_closed; // whether close() was called
  bool m_pipe;

  // fields only useful for buffered reads
  int m_writepos; // where we have read from lower level
  int m_readpos;  // where we have given to upper level
  int m_position; // the current cursor position

  void closeImpl();

private:
  static const int CHUNK_SIZE = 8192;
  char *m_buffer;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __HPHP_FILE_H__
