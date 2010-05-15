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

#include <runtime/base/class_info.h>
#include <runtime/base/type_object.h>
#include <runtime/base/type_variant.h>
#include <runtime/ext/ext_string.h>
#include <runtime/ext/ext_network.h>
#include <runtime/ext/ext_soap.h>
#include <runtime/base/program_functions.h>
#include <system/gen/sys/system_globals.h>

///////////////////////////////////////////////////////////////////////////////
// These are normally code-generated and we are implementing them here
// purely for unit testing.

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

// Used by test_ext_preg
static String test_preg_rep(CStrRef a, CStrRef b, CStrRef c) {
  return concat(f_strtoupper(c), a);
}

const char *g_class_map[] = {
  /* header */ (const char *)ClassInfo::IsSystem, NULL, "",
  /* interfaces */
  NULL,
  /* methods    */
  (const char *)ClassInfo::IsPublic, "xbox_process_message",
  NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "test", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "lower", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "sumlen_step", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "sumlen_fini", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "hello", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "sub", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "add", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "sum", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "fault", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPublic, "strlen", NULL, NULL, NULL, NULL,
  NULL,
  /* properties */
  NULL,
  /* constants */
  NULL,

  /* header */ (const char *)ClassInfo::IsNothing, NULL, "",
  /* interfaces */
  NULL,
  /* methods    */
  NULL,
  /* properties */
  NULL,
  /* constants */
  NULL,

  /* header */ (const char *)ClassInfo::IsSystem, "test", "",
  /* interfaces */
  "itestable", NULL,
  /* methods    */
  (const char *)ClassInfo::IsPublic, "foo", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsProtected, "func", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPrivate, "bar", NULL, NULL, NULL, NULL,
  NULL,
  /* properties */
  (const char *)ClassInfo::IsPublic, "foo",
  (const char *)ClassInfo::IsProtected, "prop",
  (const char *)ClassInfo::IsPrivate, "bar",
  NULL,
  /* constants */
  NULL,

  /* header */ (const char *)ClassInfo::IsInterface, "itestable", "",
  /* interfaces */
  NULL,
  /* methods    */
  (const char *)ClassInfo::IsPublic, "foo", NULL, NULL, NULL, NULL,
  (const char *)ClassInfo::IsPrivate, "bar", NULL, NULL, NULL, NULL,
  NULL,
  /* properties */
  NULL,
  /* constants */
  NULL,

  NULL
};

const char *g_source_root = "";
const char *g_source_info[] = { NULL};
const char *g_source_cls2file[] = { "test", "test_file", NULL};
const char *g_source_func2file[] = { NULL};
const char *g_paramrtti_map[] = { NULL};

Variant get_class_var_init(const char *s, const char *var) {
  return null;
}

Object create_object(const char *s, const Array &params, bool init,
                     ObjectData *root) {
  return create_builtin_object(s, params, init, root);
}

Variant invoke(const char *function, CArrRef params, int64 hash,
               bool tryinterp, bool fatal) {
  // for TestExtFunction
  if (strcasecmp(function, "test") == 0) {
    return params[0];
  }

  // for TestExtPreg::test_preg_replace_callback
  if (strcasecmp(function, "next_year") == 0) {
    Array matches = params[0].toArray();
    return matches[1].toString() + String(matches[2].toInt32() + 1);
  }

  // for TestExtArray::test_array_filter
  if (strcasecmp(function, "odd") == 0) {
    return params[0].toInt32() & 1;
  }
  if (strcasecmp(function, "even") == 0) {
    return !(params[0].toInt32() & 1);
  }

  // for TestExtArray::test_array_map
  if (strcasecmp(function, "cube") == 0) {
    int n = params[0].toInt32();
    return n * n * n;
  }

  // for TestExtArray::test_array_multisort
  if (strcasecmp(function, "strtolower") == 0) {
    return f_strtolower(params[0]);
  }

  // for TestExtArray::test_array_reduce
  if (strcasecmp(function, "rsum") == 0) {
    int v = params[0].toInt32();
    int w = params[1].toInt32();
    v += w;
    return v;
  }
  if (strcasecmp(function, "rmul") == 0) {
    int v = params[0].toInt32();
    int w = params[1].toInt32();
    v *= w;
    return v;
  }

  // for TestExtArray::test_array_walk_recursive
  if (strcasecmp(function, "test_print") == 0) {
    String item = params[0].toString();
    String key = params[1].toString();
    echo(key + ": " + item + "\n");
  }

  // for TestExtArray::test_array_walk
  if (strcasecmp(function, "test_alter") == 0) {
    Variant &item1 = lval(((Array&)params).lvalAt(0));
    String key = params[1];
    String prefix = params[2];
    item1 = prefix + ": " + item1;
  }

  // for TestExtArray::test_array_udiff
  if (strcasecmp(function, "comp_func") == 0) {
    int n1 = params[0].toInt32();
    int n2 = params[1].toInt32();
    if (n1 == n2) return 0;
    return n1 > n2 ? 1 : -1;
  }

  // for TestExtArray::test_usort
  if (strcasecmp(function, "reverse_comp_func") == 0) {
    int n1 = params[0].toInt32();
    int n2 = params[1].toInt32();
    if (n1 == n2) return 0;
    return n1 > n2 ? -1 : 1;
  }

  // for TestExtArray::test_array_uintersect
  if (strcasecmp(function, "strcasecmp") == 0) {
    String s1 = params[0].toString();
    String s2 = params[1].toString();
    return strcasecmp(s1.data(), s2.data());
  }

  // for TestExtArray::test_uasort
  if (strcasecmp(function, "reverse_strcasecmp") == 0) {
    String s1 = params[0].toString();
    String s2 = params[1].toString();
    return strcasecmp(s2.data(), s1.data());
  }

  // for TestExtFbml
  if (strcasecmp(function, "urltr") == 0) {
    String s1 = params[0].toString();
    String s2 = params[1].toString();
    return String("url:") + s1 + "=" + s2;
  }

  // for TestExtCurl::test_curl_exec
  if (strcasecmp(function, "curl_write_func") == 0) {
    f_print("curl_write_func called with ");
    f_print(params[1]);
    return params[1].toString().size();
  }

  // for TestExtPreg::test_preg_replace
  if (strcasecmp(function, "strtoupper") == 0) {
    return f_strtoupper(params[0].toString());
  }
  if (strcasecmp(function, "test_preg_rep") == 0) {
    return test_preg_rep(params[0].toString(), params[1].toString(),
                       params[2].toString());
  }
  if (strcasecmp(function, "sprintf") == 0) {
    return f_sprintf(params.size(), params[0],
                     params.slice(1, params.size() - 1, false));
  }

  // for TestExtSqlite3::test_sqlite3
  if (strcasecmp(function, "lower") == 0) {
    return f_strtolower(params[0]);
  }
  if (strcasecmp(function, "sumlen_step") == 0) {
    return params[0].toInt64() + f_strlen(params[2]);
  }
  if (strcasecmp(function, "sumlen_fini") == 0) {
    return params[0].toInt64();
  }

  // for TestExtSoap
  if (strcasecmp(function, "hello") == 0) {
    return "Hello World";
  }
  if (strcasecmp(function, "add") == 0) {
    return params[0].toInt32() + params[1].toInt32();
  }
  if (strcasecmp(function, "sub") == 0) {
    return params[0].toInt32() - params[1].toInt32();
  }
  if (strcasecmp(function, "sum") == 0) {
    int sum = 0;
    for (ArrayIter iter(params[0]); iter; ++iter) {
      sum += iter.second().toInt32();
    }
    return sum;
  }
  if (strcasecmp(function, "strlen") == 0) {
    return f_strlen(params[0]);
  }
  if (strcasecmp(function, "fault") == 0) {
    return Object((NEW(c_soapfault)())->create("MyFault","My fault string"));
  }

  // for TestExtServer
  if (strcasecmp(function, "xbox_process_message") == 0) {
    return StringUtil::Reverse(params[0]);
  }

  return true;
}

Variant invoke_static_method(const char* cls, const char *function,
                             CArrRef params, bool fatal) {
  return null;
}

void init_static_variables() { SystemScalarArrays::initialize();}

class GlobalVariables : public SystemGlobals {};
static IMPLEMENT_THREAD_LOCAL(GlobalVariables, g_variables);
GlobalVariables *get_global_variables() { return g_variables.get();}
LVariableTable *get_variable_table() { return g_variables.get(); }
Globals *get_globals() { return g_variables.get(); }
SystemGlobals *get_system_globals() { return g_variables.get(); }
void init_global_variables() { GlobalVariables::initialize();}
void free_global_variables() { g_variables.reset();}

Variant invoke_file(CStrRef path, bool once /* = false */,
                    LVariableTable* variables /* = NULL */,
                    const char *currentDir /* = NULL */) {
  String cmd = canonicalize_path(path, "", 0);
  if (path == "string") {
    echo("Hello, world!");
    return true;
  }
  if (cmd == "pageletserver") {
    SystemGlobals *g = (SystemGlobals*)get_global_variables();

    echo("pagelet postparam: ");
    echo(g->gv__POST["postparam"]);
    echo("pagelet getparam: ");
    echo(g->gv__GET["getparam"]);
    echo("pagelet header: ");
    echo(g->gv__SERVER["HTTP_MYHEADER"]);
    f_header("ResponseHeader: okay");

    sleep(1); // give status check time to happen
    return true;
  }
  return false;
}

Variant get_static_property(const char *s, const char *prop) {
  return null;
}
Variant get_constant(CStrRef name) {
  return name;
}
Variant get_class_constant(const char *s, const char *prop,
                           bool fatal /* = true */) {
  return null;
}

Array get_global_array_wrapper() {
  return Array();
}

Variant *get_static_property_lv(const char *s, const char *prop) {
  return NULL;
}

namespace Eval {
Variant invoke_from_eval(const char *function, VariableEnvironment &env,
                         const FunctionCallExpression *caller,
                         int64 hash /* = -1 */, bool fatal /* = true */) {
  return Variant();
}
}


///////////////////////////////////////////////////////////////////////////////
}
