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

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse eval_parse
#define yylex   eval_lex
#define yyerror eval_error
#define yylval  eval_lval
#define yychar  eval_char
#define yydebug eval_debug
#define yynerrs eval_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_REQUIRE_ONCE = 258,
     T_REQUIRE = 259,
     T_EVAL = 260,
     T_INCLUDE_ONCE = 261,
     T_INCLUDE = 262,
     T_LOGICAL_OR = 263,
     T_LOGICAL_XOR = 264,
     T_LOGICAL_AND = 265,
     T_PRINT = 266,
     T_SR_EQUAL = 267,
     T_SL_EQUAL = 268,
     T_XOR_EQUAL = 269,
     T_OR_EQUAL = 270,
     T_AND_EQUAL = 271,
     T_MOD_EQUAL = 272,
     T_CONCAT_EQUAL = 273,
     T_DIV_EQUAL = 274,
     T_MUL_EQUAL = 275,
     T_MINUS_EQUAL = 276,
     T_PLUS_EQUAL = 277,
     T_BOOLEAN_OR = 278,
     T_BOOLEAN_AND = 279,
     T_IS_NOT_IDENTICAL = 280,
     T_IS_IDENTICAL = 281,
     T_IS_NOT_EQUAL = 282,
     T_IS_EQUAL = 283,
     T_IS_GREATER_OR_EQUAL = 284,
     T_IS_SMALLER_OR_EQUAL = 285,
     T_SR = 286,
     T_SL = 287,
     T_INSTANCEOF = 288,
     T_UNSET_CAST = 289,
     T_BOOL_CAST = 290,
     T_OBJECT_CAST = 291,
     T_ARRAY_CAST = 292,
     T_STRING_CAST = 293,
     T_DOUBLE_CAST = 294,
     T_INT_CAST = 295,
     T_DEC = 296,
     T_INC = 297,
     T_CLONE = 298,
     T_NEW = 299,
     T_EXIT = 300,
     T_IF = 301,
     T_ELSEIF = 302,
     T_ELSE = 303,
     T_ENDIF = 304,
     T_LNUMBER = 305,
     T_DNUMBER = 306,
     T_STRING = 307,
     T_STRING_VARNAME = 308,
     T_VARIABLE = 309,
     T_NUM_STRING = 310,
     T_INLINE_HTML = 311,
     T_CHARACTER = 312,
     T_BAD_CHARACTER = 313,
     T_ENCAPSED_AND_WHITESPACE = 314,
     T_CONSTANT_ENCAPSED_STRING = 315,
     T_ECHO = 316,
     T_DO = 317,
     T_WHILE = 318,
     T_ENDWHILE = 319,
     T_FOR = 320,
     T_ENDFOR = 321,
     T_FOREACH = 322,
     T_ENDFOREACH = 323,
     T_DECLARE = 324,
     T_ENDDECLARE = 325,
     T_AS = 326,
     T_SWITCH = 327,
     T_ENDSWITCH = 328,
     T_CASE = 329,
     T_DEFAULT = 330,
     T_BREAK = 331,
     T_CONTINUE = 332,
     T_FUNCTION = 333,
     T_CONST = 334,
     T_RETURN = 335,
     T_TRY = 336,
     T_CATCH = 337,
     T_THROW = 338,
     T_USE = 339,
     T_GLOBAL = 340,
     T_PUBLIC = 341,
     T_PROTECTED = 342,
     T_PRIVATE = 343,
     T_FINAL = 344,
     T_ABSTRACT = 345,
     T_STATIC = 346,
     T_VAR = 347,
     T_UNSET = 348,
     T_ISSET = 349,
     T_EMPTY = 350,
     T_HALT_COMPILER = 351,
     T_CLASS = 352,
     T_INTERFACE = 353,
     T_EXTENDS = 354,
     T_IMPLEMENTS = 355,
     T_OBJECT_OPERATOR = 356,
     T_DOUBLE_ARROW = 357,
     T_LIST = 358,
     T_ARRAY = 359,
     T_CLASS_C = 360,
     T_METHOD_C = 361,
     T_FUNC_C = 362,
     T_LINE = 363,
     T_FILE = 364,
     T_COMMENT = 365,
     T_DOC_COMMENT = 366,
     T_OPEN_TAG = 367,
     T_OPEN_TAG_WITH_ECHO = 368,
     T_CLOSE_TAG = 369,
     T_WHITESPACE = 370,
     T_START_HEREDOC = 371,
     T_END_HEREDOC = 372,
     T_DOLLAR_OPEN_CURLY_BRACES = 373,
     T_CURLY_OPEN = 374,
     T_PAAMAYIM_NEKUDOTAYIM = 375,
     T_HPHP_NOTE = 376,
     T_HPHP_DECLARE = 377
   };
#endif
/* Tokens.  */
#define T_REQUIRE_ONCE 258
#define T_REQUIRE 259
#define T_EVAL 260
#define T_INCLUDE_ONCE 261
#define T_INCLUDE 262
#define T_LOGICAL_OR 263
#define T_LOGICAL_XOR 264
#define T_LOGICAL_AND 265
#define T_PRINT 266
#define T_SR_EQUAL 267
#define T_SL_EQUAL 268
#define T_XOR_EQUAL 269
#define T_OR_EQUAL 270
#define T_AND_EQUAL 271
#define T_MOD_EQUAL 272
#define T_CONCAT_EQUAL 273
#define T_DIV_EQUAL 274
#define T_MUL_EQUAL 275
#define T_MINUS_EQUAL 276
#define T_PLUS_EQUAL 277
#define T_BOOLEAN_OR 278
#define T_BOOLEAN_AND 279
#define T_IS_NOT_IDENTICAL 280
#define T_IS_IDENTICAL 281
#define T_IS_NOT_EQUAL 282
#define T_IS_EQUAL 283
#define T_IS_GREATER_OR_EQUAL 284
#define T_IS_SMALLER_OR_EQUAL 285
#define T_SR 286
#define T_SL 287
#define T_INSTANCEOF 288
#define T_UNSET_CAST 289
#define T_BOOL_CAST 290
#define T_OBJECT_CAST 291
#define T_ARRAY_CAST 292
#define T_STRING_CAST 293
#define T_DOUBLE_CAST 294
#define T_INT_CAST 295
#define T_DEC 296
#define T_INC 297
#define T_CLONE 298
#define T_NEW 299
#define T_EXIT 300
#define T_IF 301
#define T_ELSEIF 302
#define T_ELSE 303
#define T_ENDIF 304
#define T_LNUMBER 305
#define T_DNUMBER 306
#define T_STRING 307
#define T_STRING_VARNAME 308
#define T_VARIABLE 309
#define T_NUM_STRING 310
#define T_INLINE_HTML 311
#define T_CHARACTER 312
#define T_BAD_CHARACTER 313
#define T_ENCAPSED_AND_WHITESPACE 314
#define T_CONSTANT_ENCAPSED_STRING 315
#define T_ECHO 316
#define T_DO 317
#define T_WHILE 318
#define T_ENDWHILE 319
#define T_FOR 320
#define T_ENDFOR 321
#define T_FOREACH 322
#define T_ENDFOREACH 323
#define T_DECLARE 324
#define T_ENDDECLARE 325
#define T_AS 326
#define T_SWITCH 327
#define T_ENDSWITCH 328
#define T_CASE 329
#define T_DEFAULT 330
#define T_BREAK 331
#define T_CONTINUE 332
#define T_FUNCTION 333
#define T_CONST 334
#define T_RETURN 335
#define T_TRY 336
#define T_CATCH 337
#define T_THROW 338
#define T_USE 339
#define T_GLOBAL 340
#define T_PUBLIC 341
#define T_PROTECTED 342
#define T_PRIVATE 343
#define T_FINAL 344
#define T_ABSTRACT 345
#define T_STATIC 346
#define T_VAR 347
#define T_UNSET 348
#define T_ISSET 349
#define T_EMPTY 350
#define T_HALT_COMPILER 351
#define T_CLASS 352
#define T_INTERFACE 353
#define T_EXTENDS 354
#define T_IMPLEMENTS 355
#define T_OBJECT_OPERATOR 356
#define T_DOUBLE_ARROW 357
#define T_LIST 358
#define T_ARRAY 359
#define T_CLASS_C 360
#define T_METHOD_C 361
#define T_FUNC_C 362
#define T_LINE 363
#define T_FILE 364
#define T_COMMENT 365
#define T_DOC_COMMENT 366
#define T_OPEN_TAG 367
#define T_OPEN_TAG_WITH_ECHO 368
#define T_CLOSE_TAG 369
#define T_WHITESPACE 370
#define T_START_HEREDOC 371
#define T_END_HEREDOC 372
#define T_DOLLAR_OPEN_CURLY_BRACES 373
#define T_CURLY_OPEN 374
#define T_PAAMAYIM_NEKUDOTAYIM 375
#define T_HPHP_NOTE 376
#define T_HPHP_DECLARE 377




/* Copy the first part of user declarations.  */
#line 1 "hphp.y"

#include <runtime/eval/parser/parser.h>

using namespace HPHP;
using namespace HPHP::Eval;

#define YYSTYPE Token
//#define YYSTYPE_IS_TRIVIAL 1
#define YLMM_PARSER_CLASS Parser
#define YLMM_LEX_STATIC
#define YYERROR_VERBOSE
#define YYINITDEPTH 500
#include <util/ylmm/yaccmm.hh>

#define _p _parser
#define BEXP(e...) _parser->onBinaryOpExp(e);
#define UEXP(e...) _parser->onUnaryOpExp(e);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 377 "hphp.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
struct yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (struct yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5680

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  152
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  361
/* YYNRULES -- Number of states.  */
#define YYNSTATES  736

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   377

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,   149,     2,   147,    47,    31,   150,
     142,   143,    45,    42,     8,    43,    44,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,   144,
      36,    13,    37,    25,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,   151,    30,     2,   148,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   145,    29,   146,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     9,    10,    11,    12,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    27,    28,
      32,    33,    34,    35,    38,    39,    40,    41,    49,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    18,
      21,    26,    30,    34,    36,    39,    41,    44,    45,    47,
      49,    51,    54,    57,    60,    62,    65,    69,    77,    88,
      94,   102,   112,   118,   121,   125,   128,   132,   135,   139,
     143,   147,   151,   155,   161,   163,   165,   174,   183,   189,
     203,   207,   217,   218,   220,   224,   226,   228,   229,   230,
     241,   242,   251,   252,   260,   262,   265,   268,   271,   272,
     275,   276,   279,   280,   282,   286,   289,   290,   292,   295,
     297,   302,   304,   309,   311,   316,   318,   323,   327,   333,
     337,   342,   347,   353,   359,   364,   365,   367,   369,   376,
     377,   385,   386,   389,   390,   394,   395,   397,   398,   401,
     405,   411,   416,   421,   427,   435,   442,   444,   446,   447,
     449,   450,   452,   454,   457,   461,   465,   470,   474,   476,
     478,   481,   486,   490,   496,   498,   502,   505,   506,   507,
     512,   515,   516,   526,   527,   538,   540,   544,   546,   548,
     550,   551,   553,   556,   558,   560,   562,   564,   566,   568,
     572,   578,   580,   584,   590,   595,   599,   601,   603,   604,
     608,   610,   617,   621,   626,   633,   637,   640,   644,   648,
     652,   656,   660,   664,   668,   672,   676,   680,   684,   687,
     690,   693,   696,   700,   704,   708,   712,   716,   720,   724,
     728,   732,   736,   740,   744,   748,   752,   756,   760,   763,
     766,   769,   772,   776,   780,   784,   788,   792,   796,   800,
     804,   808,   812,   818,   820,   823,   826,   829,   832,   835,
     838,   841,   844,   847,   849,   854,   858,   861,   864,   869,
     874,   881,   888,   890,   892,   894,   895,   901,   903,   906,
     907,   910,   913,   917,   918,   922,   923,   925,   927,   929,
     931,   933,   935,   937,   939,   941,   943,   946,   949,   954,
     956,   960,   962,   964,   966,   968,   972,   976,   980,   983,
     984,   986,   987,   993,   997,  1001,  1003,  1005,  1007,  1009,
    1011,  1013,  1014,  1015,  1023,  1025,  1028,  1029,  1033,  1037,
    1038,  1040,  1043,  1047,  1049,  1051,  1053,  1056,  1058,  1063,
    1068,  1070,  1072,  1077,  1079,  1080,  1082,  1084,  1089,  1094,
    1096,  1098,  1102,  1104,  1107,  1110,  1114,  1121,  1122,  1124,
    1129,  1132,  1133,  1139,  1143,  1147,  1149,  1156,  1161,  1166,
    1169,  1172,  1175,  1176,  1178,  1183,  1187,  1191,  1198,  1202,
    1204,  1206,  1208,  1213,  1218,  1221,  1224,  1229,  1232,  1235,
    1237,  1241
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     153,     0,    -1,   154,    -1,   154,   155,    -1,    -1,   160,
      -1,   166,    -1,   168,    -1,   140,   166,    -1,   140,   168,
      -1,   115,   142,   143,   144,    -1,   141,   156,   144,    -1,
     156,     8,   157,    -1,   157,    -1,    51,    71,    -1,    71,
      -1,   158,   159,    -1,    -1,   160,    -1,   166,    -1,   168,
      -1,   140,   166,    -1,   140,   168,    -1,   230,   144,    -1,
     161,    -1,   140,   161,    -1,   145,   158,   146,    -1,    65,
     142,   230,   143,   160,   186,   188,    -1,    65,   142,   230,
     143,    26,   158,   187,   189,    68,   144,    -1,    82,   142,
     230,   143,   180,    -1,    81,   160,    82,   142,   230,   143,
     144,    -1,    84,   142,   211,   144,   211,   144,   211,   143,
     178,    -1,    91,   142,   230,   143,   183,    -1,    95,   144,
      -1,    95,   230,   144,    -1,    96,   144,    -1,    96,   230,
     144,    -1,    99,   144,    -1,    99,   213,   144,    -1,    99,
     234,   144,    -1,   104,   195,   144,    -1,   110,   197,   144,
      -1,    80,   210,   144,    -1,   112,   142,   163,   143,   144,
      -1,   144,    -1,    75,    -1,    86,   142,   234,    90,   177,
     176,   143,   179,    -1,    86,   142,   213,    90,   234,   176,
     143,   179,    -1,    88,   142,   182,   143,   181,    -1,   100,
     145,   158,   146,   101,   142,   215,    73,   143,   145,   158,
     146,   162,    -1,   102,   230,   144,    -1,   162,   101,   142,
     215,    73,   143,   145,   158,   146,    -1,    -1,   164,    -1,
     163,     8,   164,    -1,   234,    -1,    31,    -1,    -1,    -1,
      97,   165,    71,   167,   142,   190,   143,   145,   158,   146,
      -1,    -1,   171,    71,   172,   169,   173,   145,   198,   146,
      -1,    -1,   117,    71,   170,   174,   145,   198,   146,    -1,
     116,    -1,   109,   116,    -1,   108,   116,    -1,   118,   215,
      -1,    -1,   119,   175,    -1,    -1,   118,   175,    -1,    -1,
     215,    -1,   175,     8,   215,    -1,   121,   177,    -1,    -1,
     234,    -1,    31,   234,    -1,   160,    -1,    26,   158,    85,
     144,    -1,   160,    -1,    26,   158,    87,   144,    -1,   160,
      -1,    26,   158,    83,   144,    -1,   160,    -1,    26,   158,
      89,   144,    -1,    71,    13,   224,    -1,   182,     8,    71,
      13,   224,    -1,   145,   184,   146,    -1,   145,   144,   184,
     146,    -1,    26,   184,    92,   144,    -1,    26,   144,   184,
      92,   144,    -1,   184,    93,   230,   185,   158,    -1,   184,
      94,   185,   158,    -1,    -1,    26,    -1,   144,    -1,   186,
      66,   142,   230,   143,   160,    -1,    -1,   187,    66,   142,
     230,   143,    26,   158,    -1,    -1,    67,   160,    -1,    -1,
      67,    26,   158,    -1,    -1,   191,    -1,    -1,   192,    73,
      -1,   192,    31,    73,    -1,   192,    31,    73,    13,   224,
      -1,   192,    73,    13,   224,    -1,   191,     8,   192,    73,
      -1,   191,     8,   192,    31,    73,    -1,   191,     8,   192,
      31,    73,    13,   224,    -1,   191,     8,   192,    73,    13,
     224,    -1,    71,    -1,   123,    -1,    -1,   194,    -1,    -1,
     213,    -1,   234,    -1,    31,   232,    -1,   194,     8,   213,
      -1,   194,     8,   234,    -1,   194,     8,    31,   232,    -1,
     195,     8,   196,    -1,   196,    -1,    73,    -1,   147,   231,
      -1,   147,   145,   230,   146,    -1,   197,     8,    73,    -1,
     197,     8,    73,    13,   224,    -1,    73,    -1,    73,    13,
     224,    -1,   198,   199,    -1,    -1,    -1,   204,   200,   208,
     144,    -1,   209,   144,    -1,    -1,   205,    97,   165,    71,
     142,   201,   190,   143,   203,    -1,    -1,   140,   205,    97,
     165,    71,   142,   202,   190,   143,   203,    -1,   144,    -1,
     145,   158,   146,    -1,   206,    -1,   111,    -1,   206,    -1,
      -1,   207,    -1,   206,   207,    -1,   105,    -1,   106,    -1,
     107,    -1,   110,    -1,   109,    -1,   108,    -1,   208,     8,
      73,    -1,   208,     8,    73,    13,   224,    -1,    73,    -1,
      73,    13,   224,    -1,   209,     8,    71,    13,   224,    -1,
      98,    71,    13,   224,    -1,   210,     8,   230,    -1,   230,
      -1,   212,    -1,    -1,   212,     8,   230,    -1,   230,    -1,
     122,   142,   251,   143,    13,   230,    -1,   234,    13,   230,
      -1,   234,    13,    31,   234,    -1,   234,    13,    31,    63,
     216,   222,    -1,    63,   216,   222,    -1,    62,   230,    -1,
     234,    24,   230,    -1,   234,    23,   230,    -1,   234,    22,
     230,    -1,   234,    21,   230,    -1,   234,    20,   230,    -1,
     234,    19,   230,    -1,   234,    18,   230,    -1,   234,    17,
     230,    -1,   234,    16,   230,    -1,   234,    15,   230,    -1,
     234,    14,   230,    -1,   233,    60,    -1,    60,   233,    -1,
     233,    59,    -1,    59,   233,    -1,   230,    27,   230,    -1,
     230,    28,   230,    -1,   230,     9,   230,    -1,   230,    11,
     230,    -1,   230,    10,   230,    -1,   230,    29,   230,    -1,
     230,    31,   230,    -1,   230,    30,   230,    -1,   230,    44,
     230,    -1,   230,    42,   230,    -1,   230,    43,   230,    -1,
     230,    45,   230,    -1,   230,    46,   230,    -1,   230,    47,
     230,    -1,   230,    41,   230,    -1,   230,    40,   230,    -1,
      42,   230,    -1,    43,   230,    -1,    48,   230,    -1,    50,
     230,    -1,   230,    33,   230,    -1,   230,    32,   230,    -1,
     230,    35,   230,    -1,   230,    34,   230,    -1,   230,    36,
     230,    -1,   230,    39,   230,    -1,   230,    37,   230,    -1,
     230,    38,   230,    -1,   230,    49,   216,    -1,   142,   230,
     143,    -1,   230,    25,   230,    26,   230,    -1,   257,    -1,
      58,   230,    -1,    57,   230,    -1,    56,   230,    -1,    55,
     230,    -1,    54,   230,    -1,    53,   230,    -1,    52,   230,
      -1,    64,   221,    -1,    51,   230,    -1,   226,    -1,   123,
     142,   252,   143,    -1,   148,   254,   148,    -1,    12,   230,
      -1,   140,   230,    -1,    71,   142,   193,   143,    -1,   240,
     142,   193,   143,    -1,   215,   139,    71,   142,   193,   143,
      -1,   215,   139,   240,   142,   193,   143,    -1,    71,    -1,
      71,    -1,   217,    -1,    -1,   243,   218,   120,   247,   219,
      -1,   243,    -1,   219,   220,    -1,    -1,   120,   247,    -1,
     142,   143,    -1,   142,   230,   143,    -1,    -1,   142,   193,
     143,    -1,    -1,    69,    -1,    70,    -1,    79,    -1,   127,
      -1,   128,    -1,   124,    -1,   125,    -1,   126,    -1,   223,
      -1,    71,    -1,    42,   224,    -1,    43,   224,    -1,   123,
     142,   227,   143,    -1,   225,    -1,    71,   139,    71,    -1,
      71,    -1,    72,    -1,   259,    -1,   223,    -1,   149,   254,
     149,    -1,   150,   254,   150,    -1,   135,   254,   136,    -1,
     229,   228,    -1,    -1,     8,    -1,    -1,   229,     8,   224,
     121,   224,    -1,   229,     8,   224,    -1,   224,   121,   224,
      -1,   224,    -1,   231,    -1,   213,    -1,   234,    -1,   234,
      -1,   234,    -1,    -1,    -1,   242,   235,   120,   247,   239,
     236,   237,    -1,   242,    -1,   237,   238,    -1,    -1,   120,
     247,   239,    -1,   142,   193,   143,    -1,    -1,   244,    -1,
     250,   244,    -1,   215,   139,   240,    -1,   243,    -1,   214,
      -1,   244,    -1,   250,   244,    -1,   241,    -1,   244,    61,
     246,   151,    -1,   244,   145,   230,   146,    -1,   245,    -1,
      73,    -1,   147,   145,   230,   146,    -1,   230,    -1,    -1,
     248,    -1,   240,    -1,   248,    61,   246,   151,    -1,   248,
     145,   230,   146,    -1,   249,    -1,    71,    -1,   145,   230,
     146,    -1,   147,    -1,   250,   147,    -1,   251,     8,    -1,
     251,     8,   234,    -1,   251,     8,   122,   142,   251,   143,
      -1,    -1,   234,    -1,   122,   142,   251,   143,    -1,   253,
     228,    -1,    -1,   253,     8,   230,   121,   230,    -1,   253,
       8,   230,    -1,   230,   121,   230,    -1,   230,    -1,   253,
       8,   230,   121,    31,   232,    -1,   253,     8,    31,   232,
      -1,   230,   121,    31,   232,    -1,    31,   232,    -1,   254,
     255,    -1,   254,    78,    -1,    -1,    73,    -1,    73,    61,
     256,   151,    -1,    73,   120,    71,    -1,   137,   230,   146,
      -1,   137,    72,    61,   230,   151,   146,    -1,   138,   234,
     146,    -1,    71,    -1,    74,    -1,    73,    -1,   113,   142,
     258,   143,    -1,   114,   142,   234,   143,    -1,     7,   230,
      -1,     6,   230,    -1,     5,   142,   230,   143,    -1,     4,
     230,    -1,     3,   230,    -1,   234,    -1,   258,     8,   234,
      -1,   215,   139,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   129,   131,   134,   135,   136,   137,   139,
     141,   142,   146,   148,   151,   152,   155,   157,   160,   161,
     162,   163,   165,   169,   170,   171,   174,   176,   181,   187,
     190,   193,   197,   200,   201,   203,   204,   206,   207,   208,
     210,   211,   212,   213,   215,   217,   219,   224,   229,   232,
     239,   243,   248,   252,   253,   256,   260,   261,   265,   265,
     272,   271,   276,   276,   281,   282,   283,   286,   288,   291,
     292,   295,   296,   299,   300,   305,   306,   309,   310,   314,
     315,   319,   320,   324,   325,   329,   330,   335,   336,   341,
     342,   343,   344,   347,   350,   352,   355,   356,   360,   362,
     365,   368,   371,   372,   375,   376,   380,   381,   384,   385,
     386,   388,   390,   392,   394,   397,   402,   403,   404,   408,
     409,   412,   413,   414,   415,   417,   419,   424,   425,   428,
     429,   430,   434,   435,   437,   438,   442,   444,   447,   447,
     449,   451,   450,   456,   454,   462,   463,   467,   468,   471,
     472,   475,   476,   480,   481,   482,   483,   484,   485,   488,
     490,   492,   493,   496,   498,   502,   503,   507,   508,   511,
     512,   516,   518,   519,   520,   523,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   568,   569,
     571,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   593,   595,
     597,   601,   607,   610,   611,   614,   614,   617,   620,   622,
     625,   629,   630,   631,   635,   637,   641,   642,   643,   645,
     646,   647,   648,   649,   652,   653,   654,   655,   656,   658,
     661,   665,   666,   667,   668,   669,   670,   671,   676,   678,
     681,   682,   685,   688,   690,   692,   696,   697,   700,   703,
     706,   709,   711,   709,   713,   717,   719,   722,   726,   728,
     732,   733,   737,   743,   744,   747,   748,   750,   753,   755,
     756,   759,   760,   763,   764,   768,   769,   772,   773,   774,
     777,   778,   782,   783,   787,   788,   789,   791,   792,   793,
     798,   800,   803,   805,   806,   807,   808,   811,   813,   814,
     818,   819,   821,   824,   825,   827,   829,   831,   833,   836,
     837,   838,   842,   843,   844,   845,   846,   847,   848,   852,
     853,   857
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_REQUIRE_ONCE", "T_REQUIRE", "T_EVAL",
  "T_INCLUDE_ONCE", "T_INCLUDE", "','", "T_LOGICAL_OR", "T_LOGICAL_XOR",
  "T_LOGICAL_AND", "T_PRINT", "'='", "T_SR_EQUAL", "T_SL_EQUAL",
  "T_XOR_EQUAL", "T_OR_EQUAL", "T_AND_EQUAL", "T_MOD_EQUAL",
  "T_CONCAT_EQUAL", "T_DIV_EQUAL", "T_MUL_EQUAL", "T_MINUS_EQUAL",
  "T_PLUS_EQUAL", "'?'", "':'", "T_BOOLEAN_OR", "T_BOOLEAN_AND", "'|'",
  "'^'", "'&'", "T_IS_NOT_IDENTICAL", "T_IS_IDENTICAL", "T_IS_NOT_EQUAL",
  "T_IS_EQUAL", "'<'", "'>'", "T_IS_GREATER_OR_EQUAL",
  "T_IS_SMALLER_OR_EQUAL", "T_SR", "T_SL", "'+'", "'-'", "'.'", "'*'",
  "'/'", "'%'", "'!'", "T_INSTANCEOF", "'~'", "'@'", "T_UNSET_CAST",
  "T_BOOL_CAST", "T_OBJECT_CAST", "T_ARRAY_CAST", "T_STRING_CAST",
  "T_DOUBLE_CAST", "T_INT_CAST", "T_DEC", "T_INC", "'['", "T_CLONE",
  "T_NEW", "T_EXIT", "T_IF", "T_ELSEIF", "T_ELSE", "T_ENDIF", "T_LNUMBER",
  "T_DNUMBER", "T_STRING", "T_STRING_VARNAME", "T_VARIABLE",
  "T_NUM_STRING", "T_INLINE_HTML", "T_CHARACTER", "T_BAD_CHARACTER",
  "T_ENCAPSED_AND_WHITESPACE", "T_CONSTANT_ENCAPSED_STRING", "T_ECHO",
  "T_DO", "T_WHILE", "T_ENDWHILE", "T_FOR", "T_ENDFOR", "T_FOREACH",
  "T_ENDFOREACH", "T_DECLARE", "T_ENDDECLARE", "T_AS", "T_SWITCH",
  "T_ENDSWITCH", "T_CASE", "T_DEFAULT", "T_BREAK", "T_CONTINUE",
  "T_FUNCTION", "T_CONST", "T_RETURN", "T_TRY", "T_CATCH", "T_THROW",
  "T_USE", "T_GLOBAL", "T_PUBLIC", "T_PROTECTED", "T_PRIVATE", "T_FINAL",
  "T_ABSTRACT", "T_STATIC", "T_VAR", "T_UNSET", "T_ISSET", "T_EMPTY",
  "T_HALT_COMPILER", "T_CLASS", "T_INTERFACE", "T_EXTENDS", "T_IMPLEMENTS",
  "T_OBJECT_OPERATOR", "T_DOUBLE_ARROW", "T_LIST", "T_ARRAY", "T_CLASS_C",
  "T_METHOD_C", "T_FUNC_C", "T_LINE", "T_FILE", "T_COMMENT",
  "T_DOC_COMMENT", "T_OPEN_TAG", "T_OPEN_TAG_WITH_ECHO", "T_CLOSE_TAG",
  "T_WHITESPACE", "T_START_HEREDOC", "T_END_HEREDOC",
  "T_DOLLAR_OPEN_CURLY_BRACES", "T_CURLY_OPEN", "T_PAAMAYIM_NEKUDOTAYIM",
  "T_HPHP_NOTE", "T_HPHP_DECLARE", "'('", "')'", "';'", "'{'", "'}'",
  "'$'", "'`'", "'\"'", "'''", "']'", "$accept", "start",
  "top_statement_list", "top_statement", "hphp_declare_list",
  "hphp_declare", "inner_statement_list", "inner_statement", "statement",
  "statement_without_expr", "additional_catches", "unset_variables",
  "unset_variable", "is_reference", "function_declaration_statement", "@1",
  "class_declaration_statement", "@2", "@3", "class_entry_type",
  "extends_from", "implements_list", "interface_extends_list",
  "interface_list", "foreach_optional_arg", "foreach_variable",
  "for_statement", "foreach_statement", "while_statement",
  "declare_statement", "declare_list", "switch_case_list", "case_list",
  "case_separator", "elseif_list", "new_elseif_list", "else_single",
  "new_else_single", "parameter_list", "non_empty_parameter_list",
  "optional_class_type", "function_call_parameter_list",
  "non_empty_fcall_parameter_list", "global_var_list", "global_var",
  "static_var_list", "class_statement_list", "class_statement", "@4", "@5",
  "@6", "method_body", "variable_modifiers", "method_modifiers",
  "non_empty_member_modifiers", "member_modifier",
  "class_variable_declaration", "class_constant_declaration",
  "echo_expr_list", "for_expr", "non_empty_for_expr",
  "expr_without_variable", "function_call", "fully_qualified_class_name",
  "class_name_reference", "dynamic_class_name_reference", "@7",
  "object_properties", "dynamic_class_name_variable_prop", "exit_expr",
  "ctor_arguments", "common_scalar", "static_scalar",
  "static_class_constant", "scalar", "static_array_pair_list",
  "possible_comma", "non_empty_static_array_pair_list", "expr",
  "r_variable", "w_variable", "rw_variable", "variable", "@8", "@9",
  "variable_properties", "variable_property", "method_or_not",
  "variable_without_objects", "static_member",
  "base_variable_with_function_calls", "base_variable",
  "reference_variable", "compound_variable", "dim_offset",
  "object_property", "object_dim_list", "variable_name",
  "simple_indirect_reference", "assignment_list", "array_pair_list",
  "non_empty_array_pair_list", "encaps_list", "encaps_var",
  "encaps_var_offset", "internal_functions", "isset_variables",
  "class_constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    44,   263,
     264,   265,   266,    61,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    63,    58,   278,   279,   124,
      94,    38,   280,   281,   282,   283,    60,    62,   284,   285,
     286,   287,    43,    45,    46,    42,    47,    37,    33,   288,
     126,    64,   289,   290,   291,   292,   293,   294,   295,   296,
     297,    91,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,    40,    41,    59,   123,   125,    36,    96,    34,
      39,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   152,   153,   154,   154,   155,   155,   155,   155,   155,
     155,   155,   156,   156,   157,   157,   158,   158,   159,   159,
     159,   159,   159,   160,   160,   160,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   162,   162,   163,   163,   164,   165,   165,   167,   166,
     169,   168,   170,   168,   171,   171,   171,   172,   172,   173,
     173,   174,   174,   175,   175,   176,   176,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   183,
     183,   183,   183,   184,   184,   184,   185,   185,   186,   186,
     187,   187,   188,   188,   189,   189,   190,   190,   191,   191,
     191,   191,   191,   191,   191,   191,   192,   192,   192,   193,
     193,   194,   194,   194,   194,   194,   194,   195,   195,   196,
     196,   196,   197,   197,   197,   197,   198,   198,   200,   199,
     199,   201,   199,   202,   199,   203,   203,   204,   204,   205,
     205,   206,   206,   207,   207,   207,   207,   207,   207,   208,
     208,   208,   208,   209,   209,   210,   210,   211,   211,   212,
     212,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   214,   214,
     214,   214,   215,   216,   216,   218,   217,   217,   219,   219,
     220,   221,   221,   221,   222,   222,   223,   223,   223,   223,
     223,   223,   223,   223,   224,   224,   224,   224,   224,   224,
     225,   226,   226,   226,   226,   226,   226,   226,   227,   227,
     228,   228,   229,   229,   229,   229,   230,   230,   231,   232,
     233,   235,   236,   234,   234,   237,   237,   238,   239,   239,
     240,   240,   241,   242,   242,   243,   243,   243,   244,   244,
     244,   245,   245,   246,   246,   247,   247,   248,   248,   248,
     249,   249,   250,   250,   251,   251,   251,   251,   251,   251,
     252,   252,   253,   253,   253,   253,   253,   253,   253,   253,
     254,   254,   254,   255,   255,   255,   255,   255,   255,   256,
     256,   256,   257,   257,   257,   257,   257,   257,   257,   258,
     258,   259
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     2,
       4,     3,     3,     1,     2,     1,     2,     0,     1,     1,
       1,     2,     2,     2,     1,     2,     3,     7,    10,     5,
       7,     9,     5,     2,     3,     2,     3,     2,     3,     3,
       3,     3,     3,     5,     1,     1,     8,     8,     5,    13,
       3,     9,     0,     1,     3,     1,     1,     0,     0,    10,
       0,     8,     0,     7,     1,     2,     2,     2,     0,     2,
       0,     2,     0,     1,     3,     2,     0,     1,     2,     1,
       4,     1,     4,     1,     4,     1,     4,     3,     5,     3,
       4,     4,     5,     5,     4,     0,     1,     1,     6,     0,
       7,     0,     2,     0,     3,     0,     1,     0,     2,     3,
       5,     4,     4,     5,     7,     6,     1,     1,     0,     1,
       0,     1,     1,     2,     3,     3,     4,     3,     1,     1,
       2,     4,     3,     5,     1,     3,     2,     0,     0,     4,
       2,     0,     9,     0,    10,     1,     3,     1,     1,     1,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     3,
       5,     1,     3,     5,     4,     3,     1,     1,     0,     3,
       1,     6,     3,     4,     6,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     4,     3,     2,     2,     4,     4,
       6,     6,     1,     1,     1,     0,     5,     1,     2,     0,
       2,     2,     3,     0,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     1,
       3,     1,     1,     1,     1,     3,     3,     3,     2,     0,
       1,     0,     5,     3,     3,     1,     1,     1,     1,     1,
       1,     0,     0,     7,     1,     2,     0,     3,     3,     0,
       1,     2,     3,     1,     1,     1,     2,     1,     4,     4,
       1,     1,     4,     1,     0,     1,     1,     4,     4,     1,
       1,     3,     1,     2,     2,     3,     6,     0,     1,     4,
       2,     0,     5,     3,     3,     1,     6,     4,     4,     2,
       2,     2,     0,     1,     4,     3,     3,     6,     3,     1,
       1,     1,     4,     4,     2,     2,     4,     2,     2,     1,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,     0,   256,   257,
     271,   272,   311,    45,   258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,     0,     0,     0,
     261,   262,   263,   259,   260,   342,     0,     0,     0,    44,
      17,   322,   342,   342,   342,     3,     5,    24,     6,     7,
       0,   287,   304,     0,   274,   233,     0,   286,     0,   288,
       0,   307,   294,   303,   305,   310,     0,   223,   273,     0,
     358,   357,     0,   355,   354,   236,   208,   209,   210,   211,
     232,   230,   229,   228,   227,   226,   225,   224,   242,     0,
     191,   290,   189,   176,   243,     0,   255,   244,   247,   305,
       0,     0,   231,     0,   120,     0,   166,     0,     0,     0,
     168,     0,     0,     0,    33,     0,    35,     0,    56,     0,
      37,   287,     0,   288,    17,     0,   129,     0,     0,   128,
      66,    65,   134,     0,     0,     0,     0,     0,    62,   327,
     331,     0,    25,     8,     9,   237,     0,    15,     0,    13,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,   190,   188,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
       0,   314,     0,   323,   306,     0,     0,     0,   120,   175,
       0,   306,   251,     0,     0,     0,     0,   119,   287,   288,
       0,    42,     0,     0,     0,   167,   170,   287,   288,     0,
       0,     0,    34,    36,    58,    38,    39,     0,    50,     0,
     130,   288,     0,    40,     0,     0,    41,     0,    53,    55,
     359,     0,     0,     0,    72,     0,   328,     0,     0,   335,
       0,   281,   343,   341,   277,     0,     0,   340,    14,     0,
      11,   221,     0,    26,    16,    18,    19,    20,     0,   235,
     275,   276,     0,    60,   361,   302,   300,     0,   194,   196,
     195,     0,   192,   193,   197,   199,   198,   213,   212,   215,
     214,   216,   218,   219,   217,   207,   206,   201,   202,   200,
     203,   204,   205,   220,     0,   172,   187,   186,   185,   184,
     183,   182,   181,   180,   179,   178,   177,     0,     0,   313,
       0,     0,   356,     0,   302,     0,     0,   252,     0,   123,
     289,   238,     0,   165,     0,     0,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
     265,     0,   264,   135,   269,   132,     0,     0,     0,   352,
     353,    10,     0,     0,   327,   324,     0,   339,     0,   234,
     280,   330,     0,     0,   272,     0,     0,    12,    21,    22,
     312,   242,    67,    70,   120,   120,   301,     0,     0,   173,
     239,   320,     0,   316,   299,   315,   319,   308,   309,   254,
     249,    17,    99,     0,   287,   288,     0,    17,    83,    29,
       0,   169,    76,     0,    76,    77,    87,     0,    17,    85,
      48,    95,    95,    32,   118,     0,   131,   266,   267,     0,
     279,     0,    54,    43,   360,    71,    73,   137,     0,     0,
     325,     0,     0,   334,     0,   333,   349,   351,   350,     0,
     345,     0,   346,   348,     0,     0,     0,     0,   222,   255,
       0,   120,   292,   314,     0,   246,   101,   103,   126,     0,
       0,   168,     0,     0,    78,     0,     0,     0,    95,     0,
      95,     0,   116,   117,     0,   106,     0,     0,   270,   285,
       0,   281,   133,     0,   150,   329,   327,   171,   338,   337,
       0,   344,     0,    69,   137,   240,   241,   174,   321,     0,
     296,     0,     0,     0,   248,   105,     0,     0,    27,    30,
       0,     0,    75,     0,     0,    88,     0,     0,     0,     0,
       0,     0,    89,     0,   118,     0,   108,     0,     0,   268,
     280,   278,    74,     0,   153,   154,   155,   158,   157,   156,
     148,   150,    63,   136,   138,     0,   147,   151,     0,     0,
       0,   332,     0,   150,   298,   293,   317,   318,   250,     0,
       0,     0,     0,   102,    84,     0,    17,    81,    47,    46,
      86,     0,    91,     0,    96,    97,    17,    90,    17,     0,
     109,     0,     0,   284,   283,     0,     0,   149,     0,    57,
     152,     0,   140,   326,   336,   347,    61,     0,   295,     0,
      17,     0,     0,    17,    79,    31,     0,    92,    17,    94,
       0,     0,   112,     0,   111,     0,     0,     0,    57,   161,
       0,     0,     0,   299,     0,   104,    28,     0,     0,     0,
      93,    59,   113,     0,   110,    17,   282,   164,     0,     0,
       0,   139,     0,     0,   297,     0,    98,     0,    82,     0,
     115,     0,     0,   162,   159,   141,   163,    17,    80,   114,
      52,   143,     0,   118,   100,    49,   118,   160,     0,     0,
       0,     0,     0,     0,   145,    17,   142,     0,   144,     0,
       0,   146,     0,    17,     0,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    75,   178,   179,   181,   304,   305,    77,
     715,   277,   278,   149,   306,   384,   307,   423,   284,    80,
     313,   495,   403,   475,   513,   454,   655,   618,   449,   460,
     260,   463,   519,   626,   507,   555,   558,   611,   524,   525,
     526,   246,   247,   158,   159,   163,   534,   593,   638,   713,
     716,   726,   594,   595,   596,   597,   670,   598,   135,   254,
     255,    81,    82,    83,   126,   127,   240,   505,   554,   132,
     239,    84,   393,   394,    85,   530,   411,   531,    86,    87,
     369,    88,    89,   230,   550,   605,   648,   502,    90,    91,
      92,    93,    94,    95,   360,   434,   435,   436,    96,   287,
     290,   291,   171,   297,   489,    97,   281,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -553
static const yytype_int16 yypact[] =
{
    -553,    47,  1084,  -553,  4586,  4586,   -72,  4586,  4586,  4586,
    4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,
    4586,  4586,    34,    34,  4586,    77,   -63,   -58,  -553,  -553,
     -53,  -553,  -553,  -553,  -553,  4586,  3352,   -42,   -24,   -19,
      -1,    45,  3604,  3636,    59,  3762,   -11,  4586,   -48,    64,
      80,    54,    78,    83,    96,   109,  -553,   197,   149,   151,
    -553,  -553,  -553,  -553,  -553,  -553,  2470,    30,  4586,  -553,
    -553,    84,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
     229,  -553,  -553,   162,  -553,  -553,  4898,  -553,   219,   856,
     160,  -553,   183,  -553,   -17,  -553,    -2,  -553,  -553,  4586,
    5526,  5526,  4586,  5526,  5526,  5586,  -553,  -553,   257,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,   163,   168,
    -553,  -553,  -553,  -553,   171,   172,   166,  -553,   193,   -21,
      -2,   784,  -553,  4586,  3865,    11,  5526,  3478,   232,  4586,
    4586,  4586,   245,  4586,  -553,  4939,  -553,  4980,  -553,   246,
    -553,   176,  5526,   480,  -553,  5021,  -553,   -28,    12,  -553,
    -553,  -553,   310,    13,    34,    34,    34,   182,  -553,   -34,
    3968,   158,  -553,  -553,  -553,  -553,   255,  -553,    15,  -553,
    5062,  1210,  4586,   110,   116,    76,   220,   102,  4586,  4586,
    4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,
    4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,
    4586,  4586,  4586,    77,  -553,  -553,  -553,  4071,  4586,  4586,
    4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  4586,  3865,
     221,  4586,  4586,    84,    -9,  5103,   126,   120,  3865,  -553,
     222,   -21,  -553,  5144,  5185,    34,   194,   331,    20,    43,
    4586,  -553,   204,  5226,   201,   339,  5526,   259,   378,   340,
      21,  5267,  -553,  -553,  -553,  -553,  -553,  1336,  -553,  4586,
    -553,  -553,   -48,  -553,   136,   279,  -553,    22,  -553,  -553,
    -553,    23,   212,   214,   241,   225,  -553,    24,    34,   564,
     226,   360,    19,  -553,  -553,  4689,    34,  -553,  -553,    30,
    -553,  -553,  2470,  -553,  -553,  -553,  -553,  -553,  3818,  -553,
    -553,  -553,   304,  -553,   236,   237,   -21,    -2,  1074,  5563,
    5586,  5472,  5631,  3916,  4122,   919,   946,  4325,  4325,  4325,
    4325,  1199,  1199,  1199,  1199,   287,   287,   188,   188,   188,
     257,   257,   257,  -553,    35,  5586,  5586,  5586,  5586,  5586,
    5586,  5586,  5586,  5586,  5586,  5586,  5586,   238,   -25,  5526,
     234,  4024,  -553,   236,  -553,   243,   -25,  -553,  2722,  -553,
    -553,  -553,  4174,  5526,  4586,  2848,  4586,  4586,    34,    38,
     136,   318,  2974,     1,   248,   302,  4230,  -553,   136,   136,
     270,   269,  -553,  -553,  -553,   399,    34,   271,    34,  -553,
    -553,  -553,   304,   272,   -34,     4,   401,  -553,  4277,  -553,
    4380,  -553,   169,   345,   357,  4436,   273,  -553,  -553,  -553,
    -553,  -553,  -553,   301,  3865,  3865,   -21,  4586,    77,  -553,
    -553,  -553,  4586,  -553,   280,    -8,  -553,  -553,  -553,  -553,
    -553,  -553,  -553,    34,    25,   428,  5308,  -553,  -553,  -553,
     281,  5526,   305,    34,   305,  -553,  -553,   410,  -553,  -553,
    -553,   283,   284,  -553,    87,   290,  -553,  -553,  -553,   358,
     136,   136,  -553,  -553,  -553,   425,  -553,  -553,    27,   293,
    -553,  4586,    34,  5526,    34,  5431,  -553,  -553,  -553,   288,
    -553,  4586,  -553,  -553,   304,   309,   312,   313,  5609,   166,
    4642,  3865,  -553,  4586,  4586,   337,  2596,   215,  -553,   314,
    1462,  4586,    38,   316,  -553,   320,   136,  1588,  -553,   152,
    -553,   123,  -553,  -553,   323,   453,    37,   304,  -553,   346,
     326,   462,  -553,   304,   528,  -553,   -34,  5586,  -553,  -553,
    4483,  -553,  1034,   425,  -553,  -553,  -553,  -553,  -553,   328,
    -553,   324,  4816,   -25,  -553,   217,   332,  3352,  -553,  -553,
     333,   335,  -553,  3100,  3100,  -553,   336,   178,   338,  4586,
       8,   134,  -553,   334,   133,   403,   468,   411,   136,  -553,
     136,  -553,  -553,   415,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,   256,  -553,  -553,  -553,   392,   -14,  -553,    16,    28,
      34,  5526,   362,   667,  -553,   371,  -553,  -553,  -553,   350,
     483,   438,  4586,  -553,  -553,  3226,  -553,  -553,  -553,  -553,
    -553,   368,  -553,  4857,  -553,  -553,  -553,  -553,  -553,    41,
     500,   136,   373,  -553,   398,   523,   444,   256,   470,    59,
    -553,   473,  -553,  -553,  -553,  -553,  -553,   -25,  -553,  4586,
    -553,   405,  5349,  -553,  -553,  -553,  1714,  -553,  -553,  2596,
    1840,   472,   537,   136,  -553,   406,   136,   136,    59,   539,
      18,   482,   541,   280,  5390,  2596,  -553,  3352,  1966,   413,
    2596,  -553,   548,   136,  -553,  -553,  -553,  -553,   491,   136,
     490,  -553,   426,   136,  -553,   544,  -553,   423,  -553,   136,
    -553,  2092,   430,  -553,   563,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,   136,    87,  2596,   476,    87,  -553,   437,   441,
     442,   142,   304,   142,  -553,  -553,  -553,   511,  -553,  2218,
     443,  -553,   469,  -553,  2344,  -553
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -553,  -553,  -553,  -553,  -553,   289,  -143,  -553,     2,   -52,
    -553,  -553,   191,  -552,     7,  -553,    10,  -553,  -553,  -553,
    -553,  -553,  -553,   122,   164,   107,  -553,    56,  -553,  -553,
    -553,  -553,  -380,     0,  -553,  -553,  -553,  -553,  -461,  -553,
      48,  -216,  -553,  -553,   349,  -553,    81,  -553,  -553,  -553,
    -553,   -96,  -553,    39,    40,  -522,  -553,  -553,  -553,  -358,
    -553,   -37,  -553,   -22,  -196,  -553,  -553,  -553,  -553,  -553,
     129,  -259,  -339,  -553,  -553,  -553,   111,  -553,   513,   484,
    -282,   266,   524,  -553,  -553,  -553,  -553,   -33,  -182,  -553,
    -553,   -23,   -18,  -553,   140,  -350,  -553,  -553,   -15,  -362,
    -553,  -553,   203,  -553,  -553,  -553,  -553,  -553
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -302
static const yytype_int16 yytable[] =
{
     119,   119,   128,   125,    76,   315,   407,   129,   151,    78,
     130,   267,    79,   357,   172,   392,   440,   343,   450,   250,
     272,   275,   365,   299,   641,   156,   690,   461,  -121,   381,
     396,   398,   405,  -124,   624,   405,   405,   118,   138,    32,
     231,   456,   478,   118,   231,    32,   431,     3,    32,   467,
     468,  -122,   231,   503,   315,   364,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   575,   453,
     102,    32,   661,   173,   640,   118,   174,    32,   234,   131,
     412,   176,   521,  -149,   133,   172,  -242,   671,   285,   134,
     148,   584,   585,   586,   587,   588,   589,   248,   428,   157,
     139,   177,  -290,  -290,   257,   118,   118,    32,    32,   118,
     576,    32,   241,    71,   662,   640,   688,   269,   140,    71,
     432,   392,    71,   141,   232,  -300,   479,   162,   232,   392,
     392,   529,   532,  -301,   154,   119,   232,   504,   567,   413,
     571,   142,   119,   119,   119,   233,   462,   119,   124,   292,
      32,    71,   625,   561,   293,   251,   273,   276,   522,   300,
     642,   508,   691,  -121,   382,   397,   399,   406,  -124,   316,
     535,   643,   317,   314,   599,    32,   433,   565,   388,   389,
     160,    71,    71,   292,   433,    71,  -122,   143,   293,   292,
     128,   125,   248,    32,   293,   129,   161,   363,   130,    32,
     538,   248,   539,   608,   522,    28,    29,   390,   496,   497,
     523,   392,   392,   295,   296,    34,   569,   570,   316,   316,
     164,   317,   317,   119,    71,   165,   311,   569,   570,   182,
    -107,   292,   499,   210,   211,   212,   293,   213,   166,   633,
     486,   634,   487,   488,   568,   569,   570,   295,   296,    71,
     172,   167,   718,   295,   296,   720,   523,   392,   309,   391,
      60,    61,    62,    63,    64,   310,   119,    71,   168,   572,
     621,   569,   570,    71,   119,   183,   184,   185,   215,   216,
     627,   556,   557,   609,   610,   549,   724,   725,   120,   122,
     422,   169,   664,   170,   294,   295,   296,   673,   506,   426,
     186,   187,   229,  -291,   510,   134,   213,   236,   238,   418,
    -242,   237,   419,  -245,   252,   517,   259,   264,   644,   392,
     265,   392,   119,   274,   684,   283,   298,   686,   687,   207,
     208,   209,   210,   211,   212,   444,   213,   371,   312,   372,
     316,   358,   366,   317,   700,   376,   374,   377,   316,   378,
     703,   317,   395,   380,   706,   400,   119,   119,   401,   402,
     709,   584,   585,   586,   587,   588,   589,   404,   410,   409,
     442,   433,   392,   717,   119,   421,   119,   448,   424,   425,
     476,   430,   119,   119,   459,   437,   439,   248,   248,   457,
     464,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   465,   392,   128,   125,   392,   392,   469,
     129,   470,   471,   130,   481,   473,   490,   477,   491,   493,
     494,   119,   501,   516,   392,   511,   512,   518,   520,   528,
     392,   119,   527,   533,   392,   536,  -125,  -290,  -290,   541,
     392,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   392,   544,   545,   546,   553,   559,   563,
     119,   574,   119,   564,   248,   433,   573,   578,   379,   579,
     580,   604,   476,   656,   612,   606,   630,   614,   615,   628,
     620,   631,   622,   659,   632,   660,   635,  -290,  -290,   639,
     119,   647,   649,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   577,   651,   675,   645,   650,
     678,   582,   657,   663,   119,   680,   665,   100,   101,   666,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   316,   667,   123,   317,  -290,
    -290,   668,   701,   669,   672,   682,   121,   121,   136,   676,
     683,   685,   689,   692,   693,   145,   147,   698,   152,   613,
     155,   699,   702,   704,   714,   617,   617,   708,   705,   153,
     707,  -125,   711,   188,   189,   190,   712,   719,   119,   175,
     721,   180,   729,   722,   730,   723,   732,   472,   417,   191,
     734,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   175,   213,   733,   235,   543,   654,   515,   562,
     619,   387,   629,   658,   266,   603,   583,   728,   547,   316,
     636,   637,   317,   584,   585,   586,   587,   588,   589,   590,
     694,   270,   581,   551,   243,     0,   244,   152,     0,     0,
     175,     0,   253,   256,   152,     0,   261,     0,   249,     0,
       0,     0,     0,     0,     0,   258,     0,     0,   591,     0,
       0,     0,     0,     0,   592,     0,     0,     0,     0,   696,
       0,   271,     0,   289,     0,   408,     0,     0,   279,   280,
     282,     0,     0,   286,     0,   308,     0,     0,     0,     0,
     727,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,     0,     0,     0,     0,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   152,     0,   359,   361,     0,     0,     0,     0,
       0,   152,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   249,   373,     0,   583,     0,     0,     0,   370,
       0,     0,   584,   585,   586,   587,   588,   589,   590,     0,
       0,     0,   386,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   591,   415,     0,
       0,     0,   370,   646,     0,   175,     0,     0,     0,     0,
     416,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,     0,
       0,     0,     0,    28,    29,    30,    31,    32,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,   429,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,     0,     0,     0,     0,   152,     0,   446,     0,   256,
     451,     0,     0,     0,     0,     0,   445,    53,    54,     0,
       0,     0,   452,   455,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     0,     0,  -290,  -290,     0,     0,    65,
     279,   483,   474,   485,    99,     0,    68,   242,   286,   480,
       0,    71,    72,    73,    74,     0,     0,   152,   152,     0,
     498,     0,     0,     0,     0,   500,     0,     0,   249,   249,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   370,   213,     0,
       0,     0,     0,     0,     0,     0,     0,   514,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   537,   213,     0,     0,     0,     0,
       0,     0,     0,     0,   542,     0,   370,     0,   370,     0,
       0,     0,     0,     0,   152,     0,   359,   552,     0,     0,
       0,     0,     0,     0,   256,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   455,     0,     0,     0,
       0,     0,     0,   188,   189,   190,     0,     0,     0,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,   191,
     286,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   623,   213,   189,   190,     0,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,   370,   652,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
       0,     0,     0,    28,    29,    30,    31,    32,     0,    33,
       0,     0,   674,    34,    35,    36,    37,     0,    38,     0,
      39,     0,    40,     0,     0,    41,     0,     0,     0,    42,
      43,    44,     0,    45,    46,   602,    47,     0,    48,     0,
       0,     0,    49,    50,    51,     0,    52,    53,    54,    55,
      56,    57,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     4,     5,     6,     7,     8,     0,    65,
       0,     0,     9,     0,    66,    67,    68,     0,    69,    70,
       0,    71,    72,    73,    74,  -302,  -302,  -302,  -302,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,     0,     0,     0,    28,
      29,    30,    31,    32,     0,    33,     0,     0,     0,    34,
      35,    36,    37,     0,    38,     0,    39,     0,    40,     0,
       0,    41,     0,     0,     0,    42,    43,    44,     0,    45,
      46,     0,    47,     0,    48,     0,     0,     0,    49,    50,
      51,     0,    52,    53,    54,     0,    56,    57,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    64,     4,
       5,     6,     7,     8,     0,    65,     0,     0,     9,     0,
     302,     0,    68,     0,    69,    70,   303,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,     0,     0,     0,    28,    29,    30,    31,    32,
       0,    33,     0,     0,     0,    34,    35,    36,    37,     0,
      38,     0,    39,     0,    40,     0,     0,    41,     0,     0,
       0,    42,    43,    44,     0,    45,    46,     0,    47,     0,
      48,     0,     0,     0,    49,    50,    51,     0,    52,    53,
      54,     0,    56,    57,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     4,     5,     6,     7,     8,
       0,    65,     0,     0,     9,     0,   302,     0,    68,     0,
      69,    70,   385,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,     0,     0,
       0,    28,    29,    30,    31,    32,     0,    33,     0,     0,
       0,    34,    35,    36,    37,   560,    38,     0,    39,     0,
      40,     0,     0,    41,     0,     0,     0,    42,    43,    44,
       0,    45,    46,     0,    47,     0,    48,     0,     0,     0,
      49,    50,    51,     0,    52,    53,    54,     0,    56,    57,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      64,     4,     5,     6,     7,     8,     0,    65,     0,     0,
       9,     0,   302,     0,    68,     0,    69,    70,     0,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,     0,     0,     0,    28,    29,    30,
      31,    32,     0,    33,     0,     0,     0,    34,    35,    36,
      37,     0,    38,     0,    39,     0,    40,   566,     0,    41,
       0,     0,     0,    42,    43,    44,     0,    45,    46,     0,
      47,     0,    48,     0,     0,     0,    49,    50,    51,     0,
      52,    53,    54,     0,    56,    57,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    64,     4,     5,     6,
       7,     8,     0,    65,     0,     0,     9,     0,   302,     0,
      68,     0,    69,    70,     0,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
       0,     0,     0,    28,    29,    30,    31,    32,     0,    33,
       0,     0,     0,    34,    35,    36,    37,     0,    38,     0,
      39,   679,    40,     0,     0,    41,     0,     0,     0,    42,
      43,    44,     0,    45,    46,     0,    47,     0,    48,     0,
       0,     0,    49,    50,    51,     0,    52,    53,    54,     0,
      56,    57,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     4,     5,     6,     7,     8,     0,    65,
       0,     0,     9,     0,   302,     0,    68,     0,    69,    70,
       0,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,     0,     0,     0,    28,
      29,    30,    31,    32,     0,    33,     0,     0,     0,    34,
      35,    36,    37,     0,    38,     0,    39,     0,    40,     0,
       0,    41,     0,     0,     0,    42,    43,    44,     0,    45,
      46,     0,    47,     0,    48,     0,     0,     0,    49,    50,
      51,     0,    52,    53,    54,     0,    56,    57,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    64,     4,
       5,     6,     7,     8,     0,    65,     0,     0,     9,     0,
     302,     0,    68,     0,    69,    70,   681,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,     0,     0,     0,    28,    29,    30,    31,    32,
       0,    33,     0,     0,     0,    34,    35,    36,    37,     0,
      38,   697,    39,     0,    40,     0,     0,    41,     0,     0,
       0,    42,    43,    44,     0,    45,    46,     0,    47,     0,
      48,     0,     0,     0,    49,    50,    51,     0,    52,    53,
      54,     0,    56,    57,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     4,     5,     6,     7,     8,
       0,    65,     0,     0,     9,     0,   302,     0,    68,     0,
      69,    70,     0,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,     0,     0,
       0,    28,    29,    30,    31,    32,     0,    33,     0,     0,
       0,    34,    35,    36,    37,     0,    38,     0,    39,     0,
      40,     0,     0,    41,     0,     0,     0,    42,    43,    44,
       0,    45,    46,     0,    47,     0,    48,     0,     0,     0,
      49,    50,    51,     0,    52,    53,    54,     0,    56,    57,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      64,     4,     5,     6,     7,     8,     0,    65,     0,     0,
       9,     0,   302,     0,    68,     0,    69,    70,   710,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,     0,     0,     0,    28,    29,    30,
      31,    32,     0,    33,     0,     0,     0,    34,    35,    36,
      37,     0,    38,     0,    39,     0,    40,     0,     0,    41,
       0,     0,     0,    42,    43,    44,     0,    45,    46,     0,
      47,     0,    48,     0,     0,     0,    49,    50,    51,     0,
      52,    53,    54,     0,    56,    57,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    64,     4,     5,     6,
       7,     8,     0,    65,     0,     0,     9,     0,   302,     0,
      68,     0,    69,    70,   731,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
       0,     0,     0,    28,    29,    30,    31,    32,     0,    33,
       0,     0,     0,    34,    35,    36,    37,     0,    38,     0,
      39,     0,    40,     0,     0,    41,     0,     0,     0,    42,
      43,    44,     0,    45,    46,     0,    47,     0,    48,     0,
       0,     0,    49,    50,    51,     0,    52,    53,    54,     0,
      56,    57,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     4,     5,     6,     7,     8,     0,    65,
       0,     0,     9,     0,   302,     0,    68,     0,    69,    70,
     735,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,     0,     0,     0,    28,
      29,    30,    31,    32,     0,    33,     0,     0,     0,    34,
      35,    36,    37,     0,    38,     0,    39,     0,    40,     0,
       0,    41,     0,     0,     0,    42,    43,    44,     0,    45,
      46,     0,    47,     0,    48,     0,     0,     0,    49,    50,
      51,     0,    52,    53,    54,     0,    56,    57,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    64,     4,
       5,     6,     7,     8,     0,    65,     0,     0,     9,     0,
      99,     0,    68,     0,    69,    70,     0,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,     0,     0,     0,    28,    29,    30,    31,    32,
       0,    33,     0,     0,     0,    34,    35,    36,    37,     0,
      38,     0,    39,     0,    40,     0,     0,    41,     0,     0,
       0,    42,    43,    44,     0,    45,    46,     0,    47,     0,
      48,     0,     0,     0,    49,    50,    51,     0,    52,    53,
      54,     0,    56,    57,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     4,     5,     6,     7,     8,
       0,    65,     0,     0,     9,     0,   302,     0,    68,     0,
      69,    70,     0,    71,    72,    73,    74,     0,   441,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,     0,     0,
       0,    28,    29,    30,    31,    32,     0,    33,     0,     0,
       0,    34,    35,    36,    37,     0,    38,     0,    39,     0,
      40,     0,     0,    41,     0,     0,     0,    42,    43,     0,
       0,    45,    46,     0,    47,     0,    48,     0,     0,     0,
       0,     0,    51,     0,    52,    53,    54,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      64,     4,     5,     6,     7,     8,     0,    65,     0,     0,
       9,     0,   137,     0,    68,     0,    69,    70,     0,    71,
      72,    73,    74,     0,   447,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,     0,     0,     0,    28,    29,    30,
      31,    32,     0,    33,     0,     0,     0,    34,    35,    36,
      37,     0,    38,     0,    39,     0,    40,     0,     0,    41,
       0,     0,     0,    42,    43,     0,     0,    45,    46,     0,
      47,     0,    48,     0,     0,     0,     0,     0,    51,     0,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    64,     4,     5,     6,
       7,     8,     0,    65,     0,     0,     9,     0,   137,     0,
      68,     0,    69,    70,     0,    71,    72,    73,    74,     0,
     458,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,    27,
       0,     0,     0,    28,    29,    30,    31,    32,     0,    33,
       0,     0,     0,    34,    35,    36,    37,     0,    38,     0,
      39,     0,    40,     0,     0,    41,     0,     0,     0,    42,
      43,     0,     0,    45,    46,     0,    47,     0,    48,     0,
       0,     0,     0,     0,    51,     0,    52,    53,    54,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     4,     5,     6,     7,     8,     0,    65,
       0,     0,     9,     0,   137,     0,    68,     0,    69,    70,
       0,    71,    72,    73,    74,     0,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,    27,     0,     0,     0,    28,
      29,    30,    31,    32,     0,    33,     0,     0,     0,    34,
      35,    36,    37,     0,    38,     0,    39,     0,    40,     0,
       0,    41,     0,     0,     0,    42,    43,     0,     0,    45,
      46,     0,    47,     0,    48,     0,     0,     0,     0,     0,
      51,     0,    52,    53,    54,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    64,     4,
       5,     6,     7,     8,     0,    65,     0,     0,     9,     0,
     137,     0,    68,     0,    69,    70,     0,    71,    72,    73,
      74,     0,   653,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,     0,     0,     0,    28,    29,    30,    31,    32,
       0,    33,     0,     0,     0,    34,    35,    36,    37,     0,
      38,     0,    39,     0,    40,     0,     0,    41,     0,     0,
       0,    42,    43,     0,     0,    45,    46,     0,    47,     0,
      48,     0,     0,     0,     0,     0,    51,     0,    52,    53,
      54,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     4,     5,     6,     7,     8,
       0,    65,     0,     0,     9,     0,   137,     0,    68,     0,
      69,    70,     0,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,    27,     0,     0,
       0,    28,    29,    30,    31,    32,     0,    33,     0,     0,
       0,    34,    35,    36,    37,     0,    38,     0,    39,     0,
      40,     0,     0,    41,     0,     0,     0,    42,    43,     0,
       0,    45,    46,     0,    47,     0,    48,     0,     0,     0,
       0,     0,    51,     0,    52,    53,    54,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      64,     4,     5,     6,     7,     8,     0,    65,     0,     0,
       9,     0,   137,     0,    68,     0,    69,    70,     0,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,     0,     0,     0,    28,    29,    30,
      31,    32,     0,    33,     0,     0,     0,    34,    35,    36,
      37,     0,    38,     0,    39,     0,    40,     0,     0,    41,
       0,     0,     0,    42,    43,     0,     0,    45,    46,     0,
      47,     0,    48,     0,     0,     0,     0,     0,    51,     0,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    64,     4,     5,     6,
       7,     8,     0,    65,     0,     0,     9,     0,    99,     0,
      68,     0,    69,    70,     0,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     0,     0,    10,    11,     9,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    10,    11,
       0,     0,     0,    34,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,     0,     0,     0,     0,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    34,     0,    53,    54,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,    99,     0,    68,     0,   144,    53,
      54,    71,    72,    73,    74,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     4,     5,     6,     7,     8,
       0,    65,     0,     0,     9,     0,    99,     0,    68,     0,
     146,     0,     0,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    24,    25,    26,   188,   189,   190,
       0,    28,    29,    30,    31,    32,     0,     0,     0,     0,
       0,    34,     0,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,   213,     4,     5,
       6,     7,     8,     0,     0,    53,    54,     9,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,   245,    65,     0,     0,
       0,     0,    99,     0,    68,     0,   150,    10,    11,    71,
      72,    73,    74,    12,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    24,    25,    26,
       0,     0,     0,     0,    28,    29,    30,    31,    32,     0,
       0,     0,     0,     0,    34,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   420,   213,     0,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     0,     0,    53,    54,
       9,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     0,     0,     0,   288,
      65,     0,     0,     0,     0,    99,     0,    68,     0,     0,
      10,    11,    71,    72,    73,    74,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,   188,   189,   190,     0,    28,    29,    30,
      31,    32,     0,     0,     0,     0,     0,    34,     0,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,     4,     5,     6,     7,     8,     0,
       0,    53,    54,     9,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,   344,    65,     0,     0,     0,     0,    99,     0,
      68,     0,     0,    10,    11,    71,    72,    73,    74,    12,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,    24,    25,    26,     0,     0,     0,     0,
      28,    29,    30,    31,    32,     0,     0,     0,     0,     0,
      34,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     438,   213,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     0,     0,    53,    54,     9,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,   443,    65,     0,     0,     0,
       0,    99,     0,    68,     0,     0,    10,    11,    71,    72,
      73,    74,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    24,    25,    26,   188,
     189,   190,     0,    28,    29,    30,    31,    32,     0,     0,
       0,     0,     0,    34,     0,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,   213,
       4,     5,     6,     7,     8,     0,     0,    53,    54,     9,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     0,     0,     0,     0,     0,   482,    65,
       0,     0,     0,     0,    99,     0,    68,     0,     0,    10,
      11,    71,    72,    73,    74,    12,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,    24,
      25,    26,     0,     0,     0,     0,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,    34,  -302,  -302,  -302,
    -302,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,     0,   466,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     0,     0,
      53,    54,     9,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
       0,   484,    65,     0,     0,     0,     0,    99,     0,    68,
       0,     0,    10,    11,    71,    72,    73,    74,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    24,    25,    26,   188,   189,   190,     0,    28,
      29,    30,    31,    32,     0,     0,     0,     0,     0,    34,
       0,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,   213,     4,     5,     6,     7,
       8,     0,     0,    53,    54,     9,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,     0,     0,   600,    65,     0,     0,     0,     0,
      99,     0,    68,     0,     0,    10,    11,    71,    72,    73,
      74,    12,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,    24,    25,    26,     0,     0,
       0,     0,    28,    29,    30,    31,    32,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   492,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     0,     0,    53,    54,     9,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
      63,    64,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,    99,     0,    68,     0,     0,    10,    11,
      71,    72,    73,    74,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    24,    25,
      26,   188,   189,   190,     0,    28,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    34,     0,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,     4,     5,     6,     7,     8,     0,     0,    53,
      54,     9,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,    99,     0,    68,     0,
       0,    10,    11,    71,    72,    73,    74,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,    24,    25,    26,     0,     0,     0,     0,    28,    29,
      30,   414,    32,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,    65,   188,   189,   190,     0,    99,
       0,    68,     0,     0,     0,     0,    71,    72,    73,    74,
       0,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,   213,   188,   189,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   624,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,     0,   213,   188,   189,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,   213,   188,   189,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   607,     0,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,   188,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   625,     0,     0,     0,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,   213,
     188,   189,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,     0,     0,     0,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
     213,   188,   189,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,   188,   189,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,     0,     0,     0,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,   213,   188,   189,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,     0,     0,     0,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,   188,   189,   190,     0,     0,     0,
       0,     0,     0,     0,     0,   301,     0,     0,     0,     0,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,   188,   189,   190,     0,     0,
       0,     0,     0,     0,     0,     0,   362,     0,     0,     0,
       0,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,   213,   188,   189,   190,     0,
       0,     0,     0,     0,     0,     0,     0,   367,     0,     0,
       0,     0,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,     0,   213,   188,   189,   190,
       0,     0,     0,     0,     0,     0,     0,     0,   368,     0,
       0,     0,     0,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,   213,   188,   189,
     190,     0,     0,     0,     0,     0,     0,     0,     0,   375,
       0,     0,     0,     0,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,   188,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
     383,     0,     0,     0,     0,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,   213,
     188,   189,   190,     0,     0,     0,     0,     0,     0,     0,
       0,   509,     0,     0,     0,     0,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
     213,   188,   189,   190,     0,     0,     0,     0,     0,     0,
       0,     0,   677,     0,     0,     0,     0,   191,   427,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   695,     0,   188,   189,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   540,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   190,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   191,   213,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,   213,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
     213
};

static const yytype_int16 yycheck[] =
{
      22,    23,    25,    25,     2,   187,   288,    25,    45,     2,
      25,   154,     2,   229,    66,   274,   366,   213,   376,     8,
       8,     8,   238,     8,     8,    73,     8,    26,     8,     8,
       8,     8,     8,     8,    26,     8,     8,    71,    36,    73,
      61,   380,   404,    71,    61,    73,    71,     0,    73,   388,
     389,     8,    61,    61,   236,   237,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    31,    31,
     142,    73,    31,    66,   596,    71,    66,    73,    96,   142,
      61,    51,   462,    97,   142,   137,   139,   639,   122,   142,
      31,   105,   106,   107,   108,   109,   110,   134,    63,   147,
     142,    71,    59,    60,   141,    71,    71,    73,    73,    71,
      73,    73,   130,   147,    73,   637,   668,   145,   142,   147,
     145,   380,   147,   142,   145,   142,   122,    73,   145,   388,
     389,   470,   471,   142,   145,   157,   145,   145,   518,   120,
     520,   142,   164,   165,   166,   147,   145,   169,    71,    73,
      73,   147,   144,   511,    78,   144,   144,   144,    71,   144,
     144,   443,   144,   143,   143,   143,   143,   143,   143,   187,
     143,   143,   187,    71,   536,    73,   358,   516,    42,    43,
     116,   147,   147,    73,   366,   147,   143,   142,    78,    73,
     213,   213,   229,    73,    78,   213,   116,    71,   213,    73,
     482,   238,   484,   553,    71,    69,    70,    71,   424,   425,
     123,   470,   471,   137,   138,    79,    93,    94,   236,   237,
     142,   236,   237,   245,   147,   142,   150,    93,    94,   145,
     143,    73,   428,    45,    46,    47,    78,    49,   142,   578,
      71,   580,    73,    74,    92,    93,    94,   137,   138,   147,
     302,   142,   713,   137,   138,   716,   123,   516,   148,   123,
     124,   125,   126,   127,   128,   149,   288,   147,    71,   146,
      92,    93,    94,   147,   296,    72,    73,    74,    59,    60,
     146,    66,    67,    66,    67,   501,   144,   145,    22,    23,
     312,   142,   631,   142,   136,   137,   138,   647,   441,   317,
      71,   139,   142,   120,   447,   142,    49,   139,   142,   302,
     139,   139,   302,   120,    82,   458,    71,    71,   600,   578,
     144,   580,   344,    13,   663,   143,    71,   666,   667,    42,
      43,    44,    45,    46,    47,   372,    49,   143,   118,     8,
     358,   120,   120,   358,   683,   144,   142,     8,   366,    90,
     689,   366,    73,    13,   693,   143,   378,   379,   144,   118,
     699,   105,   106,   107,   108,   109,   110,   142,     8,   143,
     368,   553,   631,   712,   396,    71,   398,   375,   142,   142,
     402,   143,   404,   405,   382,   151,   143,   424,   425,    71,
     142,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   101,   663,   428,   428,   666,   667,   139,
     428,   142,    13,   428,    13,   144,    71,   145,    61,   146,
     119,   443,   142,    13,   683,   144,   121,   144,   144,    71,
     689,   453,   142,     8,   693,   142,     8,    59,    60,   151,
     699,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   712,   145,   143,   143,   120,   144,   143,
     482,     8,   484,   143,   501,   647,   143,   121,    90,   143,
       8,   143,   494,   616,   142,   151,    73,   144,   143,   145,
     144,    13,   144,   626,    73,   628,    71,    59,    60,    97,
     512,   120,   142,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   527,    68,   650,   146,    26,
     653,   533,   144,    13,   536,   658,   143,     4,     5,   121,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   553,    13,    24,   553,    59,
      60,    97,   685,    73,    71,    73,    22,    23,    35,   144,
      13,   145,    13,    71,    13,    42,    43,   144,    45,   557,
      47,    13,    71,    73,   707,   563,   564,   144,   142,    45,
      26,   143,   142,     9,    10,    11,    13,   101,   600,    66,
     143,    68,   725,   142,    73,   143,   143,   396,   299,    25,
     733,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    99,    49,   145,   102,   494,   615,   454,   512,
     564,   272,   574,   623,   144,   544,    98,   723,   499,   647,
     591,   591,   647,   105,   106,   107,   108,   109,   110,   111,
     673,   157,   531,   503,   131,    -1,   133,   134,    -1,    -1,
     137,    -1,   139,   140,   141,    -1,   143,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,   677,
      -1,   157,    -1,   170,    -1,   121,    -1,    -1,   164,   165,
     166,    -1,    -1,   169,    -1,   182,    -1,    -1,    -1,    -1,
     722,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,    -1,   231,   232,    -1,    -1,    -1,    -1,
      -1,   238,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   250,    -1,    98,    -1,    -1,    -1,   245,
      -1,    -1,   105,   106,   107,   108,   109,   110,   111,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   295,    -1,
      -1,    -1,   288,   146,    -1,   302,    -1,    -1,    -1,    -1,
     296,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,   344,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,   372,    -1,   374,    -1,   376,
     377,    -1,    -1,    -1,    -1,    -1,   372,   113,   114,    -1,
      -1,    -1,   378,   379,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    59,    60,    -1,    -1,   135,
     396,   408,   398,   410,   140,    -1,   142,   143,   404,   405,
      -1,   147,   148,   149,   150,    -1,    -1,   424,   425,    -1,
     427,    -1,    -1,    -1,    -1,   432,    -1,    -1,   424,   425,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,   443,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   481,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   491,    -1,   482,    -1,   484,    -1,
      -1,    -1,    -1,    -1,   501,    -1,   503,   504,    -1,    -1,
      -1,    -1,    -1,    -1,   511,   501,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   540,    -1,    -1,    -1,    -1,    -1,    25,
     536,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   569,    49,    10,    11,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,   600,   612,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    75,
      -1,    -1,   649,    79,    80,    81,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    -1,    99,   100,   151,   102,    -1,   104,    -1,
      -1,    -1,   108,   109,   110,    -1,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,     3,     4,     5,     6,     7,    -1,   135,
      -1,    -1,    12,    -1,   140,   141,   142,    -1,   144,   145,
      -1,   147,   148,   149,   150,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    -1,    75,    -1,    -1,    -1,    79,
      80,    81,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    97,    -1,    99,
     100,    -1,   102,    -1,   104,    -1,    -1,    -1,   108,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,     3,
       4,     5,     6,     7,    -1,   135,    -1,    -1,    12,    -1,
     140,    -1,   142,    -1,   144,   145,   146,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      -1,    75,    -1,    -1,    -1,    79,    80,    81,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    95,    96,    97,    -1,    99,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,   108,   109,   110,    -1,   112,   113,
     114,    -1,   116,   117,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,     3,     4,     5,     6,     7,
      -1,   135,    -1,    -1,    12,    -1,   140,    -1,   142,    -1,
     144,   145,   146,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    -1,    75,    -1,    -1,
      -1,    79,    80,    81,    82,    83,    84,    -1,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      -1,    99,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,
     108,   109,   110,    -1,   112,   113,   114,    -1,   116,   117,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,     3,     4,     5,     6,     7,    -1,   135,    -1,    -1,
      12,    -1,   140,    -1,   142,    -1,   144,   145,    -1,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    89,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    -1,    99,   100,    -1,
     102,    -1,   104,    -1,    -1,    -1,   108,   109,   110,    -1,
     112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,     3,     4,     5,
       6,     7,    -1,   135,    -1,    -1,    12,    -1,   140,    -1,
     142,    -1,   144,   145,    -1,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    75,
      -1,    -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,
      86,    87,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    -1,    99,   100,    -1,   102,    -1,   104,    -1,
      -1,    -1,   108,   109,   110,    -1,   112,   113,   114,    -1,
     116,   117,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,     3,     4,     5,     6,     7,    -1,   135,
      -1,    -1,    12,    -1,   140,    -1,   142,    -1,   144,   145,
      -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    -1,    75,    -1,    -1,    -1,    79,
      80,    81,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    97,    -1,    99,
     100,    -1,   102,    -1,   104,    -1,    -1,    -1,   108,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,     3,
       4,     5,     6,     7,    -1,   135,    -1,    -1,    12,    -1,
     140,    -1,   142,    -1,   144,   145,   146,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      -1,    75,    -1,    -1,    -1,    79,    80,    81,    82,    -1,
      84,    85,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    95,    96,    97,    -1,    99,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,   108,   109,   110,    -1,   112,   113,
     114,    -1,   116,   117,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,     3,     4,     5,     6,     7,
      -1,   135,    -1,    -1,    12,    -1,   140,    -1,   142,    -1,
     144,   145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    -1,    75,    -1,    -1,
      -1,    79,    80,    81,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      -1,    99,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,
     108,   109,   110,    -1,   112,   113,   114,    -1,   116,   117,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,     3,     4,     5,     6,     7,    -1,   135,    -1,    -1,
      12,    -1,   140,    -1,   142,    -1,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    97,    -1,    99,   100,    -1,
     102,    -1,   104,    -1,    -1,    -1,   108,   109,   110,    -1,
     112,   113,   114,    -1,   116,   117,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,     3,     4,     5,
       6,     7,    -1,   135,    -1,    -1,    12,    -1,   140,    -1,
     142,    -1,   144,   145,   146,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    75,
      -1,    -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    97,    -1,    99,   100,    -1,   102,    -1,   104,    -1,
      -1,    -1,   108,   109,   110,    -1,   112,   113,   114,    -1,
     116,   117,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,     3,     4,     5,     6,     7,    -1,   135,
      -1,    -1,    12,    -1,   140,    -1,   142,    -1,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    -1,    75,    -1,    -1,    -1,    79,
      80,    81,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    97,    -1,    99,
     100,    -1,   102,    -1,   104,    -1,    -1,    -1,   108,   109,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,     3,
       4,     5,     6,     7,    -1,   135,    -1,    -1,    12,    -1,
     140,    -1,   142,    -1,   144,   145,    -1,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      -1,    75,    -1,    -1,    -1,    79,    80,    81,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    95,    96,    97,    -1,    99,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,   108,   109,   110,    -1,   112,   113,
     114,    -1,   116,   117,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,     3,     4,     5,     6,     7,
      -1,   135,    -1,    -1,    12,    -1,   140,    -1,   142,    -1,
     144,   145,    -1,   147,   148,   149,   150,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    -1,    75,    -1,    -1,
      -1,    79,    80,    81,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    -1,
      -1,    99,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,   110,    -1,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,     3,     4,     5,     6,     7,    -1,   135,    -1,    -1,
      12,    -1,   140,    -1,   142,    -1,   144,   145,    -1,   147,
     148,   149,   150,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    -1,    -1,    99,   100,    -1,
     102,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,    -1,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,     3,     4,     5,
       6,     7,    -1,   135,    -1,    -1,    12,    -1,   140,    -1,
     142,    -1,   144,   145,    -1,   147,   148,   149,   150,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    75,
      -1,    -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,
      86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,
      96,    -1,    -1,    99,   100,    -1,   102,    -1,   104,    -1,
      -1,    -1,    -1,    -1,   110,    -1,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,     3,     4,     5,     6,     7,    -1,   135,
      -1,    -1,    12,    -1,   140,    -1,   142,    -1,   144,   145,
      -1,   147,   148,   149,   150,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    -1,    75,    -1,    -1,    -1,    79,
      80,    81,    82,    -1,    84,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,
     100,    -1,   102,    -1,   104,    -1,    -1,    -1,    -1,    -1,
     110,    -1,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,     3,
       4,     5,     6,     7,    -1,   135,    -1,    -1,    12,    -1,
     140,    -1,   142,    -1,   144,   145,    -1,   147,   148,   149,
     150,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      -1,    75,    -1,    -1,    -1,    79,    80,    81,    82,    -1,
      84,    -1,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,
      -1,    95,    96,    -1,    -1,    99,   100,    -1,   102,    -1,
     104,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,     3,     4,     5,     6,     7,
      -1,   135,    -1,    -1,    12,    -1,   140,    -1,   142,    -1,
     144,   145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    -1,    75,    -1,    -1,
      -1,    79,    80,    81,    82,    -1,    84,    -1,    86,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    -1,
      -1,    99,   100,    -1,   102,    -1,   104,    -1,    -1,    -1,
      -1,    -1,   110,    -1,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,     3,     4,     5,     6,     7,    -1,   135,    -1,    -1,
      12,    -1,   140,    -1,   142,    -1,   144,   145,    -1,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,
      82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    95,    96,    -1,    -1,    99,   100,    -1,
     102,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,    -1,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,     3,     4,     5,
       6,     7,    -1,   135,    -1,    -1,    12,    -1,   140,    -1,
     142,    -1,   144,   145,    -1,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    42,    43,    12,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    42,    43,
      -1,    -1,    -1,    79,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,   140,    -1,   142,    -1,   144,   113,
     114,   147,   148,   149,   150,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,     3,     4,     5,     6,     7,
      -1,   135,    -1,    -1,    12,    -1,   140,    -1,   142,    -1,
     144,    -1,    -1,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,     9,    10,    11,
      -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     3,     4,
       5,     6,     7,    -1,    -1,   113,   114,    12,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    31,   135,    -1,    -1,
      -1,    -1,   140,    -1,   142,    -1,   144,    42,    43,   147,
     148,   149,   150,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   146,    49,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,   113,   114,
      12,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    31,
     135,    -1,    -1,    -1,    -1,   140,    -1,   142,    -1,    -1,
      42,    43,   147,   148,   149,   150,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,     9,    10,    11,    -1,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     3,     4,     5,     6,     7,    -1,
      -1,   113,   114,    12,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    31,   135,    -1,    -1,    -1,    -1,   140,    -1,
     142,    -1,    -1,    42,    43,   147,   148,   149,   150,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     146,    49,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,   113,   114,    12,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    31,   135,    -1,    -1,    -1,
      -1,   140,    -1,   142,    -1,    -1,    42,    43,   147,   148,
     149,   150,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,     9,
      10,    11,    -1,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       3,     4,     5,     6,     7,    -1,    -1,   113,   114,    12,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    31,   135,
      -1,    -1,    -1,    -1,   140,    -1,   142,    -1,    -1,    42,
      43,   147,   148,   149,   150,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,   146,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
     113,   114,    12,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    31,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,
      -1,    -1,    42,    43,   147,   148,   149,   150,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,     9,    10,    11,    -1,    69,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     3,     4,     5,     6,
       7,    -1,    -1,   113,   114,    12,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,    -1,
      -1,    -1,    -1,    -1,    31,   135,    -1,    -1,    -1,    -1,
     140,    -1,   142,    -1,    -1,    42,    43,   147,   148,   149,
     150,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,   113,   114,    12,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   140,    -1,   142,    -1,    -1,    42,    43,
     147,   148,   149,   150,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,     9,    10,    11,    -1,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     3,     4,     5,     6,     7,    -1,    -1,   113,
     114,    12,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,   140,    -1,   142,    -1,
      -1,    42,    43,   147,   148,   149,   150,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,    -1,   135,     9,    10,    11,    -1,   140,
      -1,   142,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   121,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    11,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    25,    49,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   153,   154,     0,     3,     4,     5,     6,     7,    12,
      42,    43,    48,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    62,    63,    64,    65,    69,    70,
      71,    72,    73,    75,    79,    80,    81,    82,    84,    86,
      88,    91,    95,    96,    97,    99,   100,   102,   104,   108,
     109,   110,   112,   113,   114,   115,   116,   117,   122,   123,
     124,   125,   126,   127,   128,   135,   140,   141,   142,   144,
     145,   147,   148,   149,   150,   155,   160,   161,   166,   168,
     171,   213,   214,   215,   223,   226,   230,   231,   233,   234,
     240,   241,   242,   243,   244,   245,   250,   257,   259,   140,
     230,   230,   142,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,    71,   215,
     233,   234,   233,   230,    71,   215,   216,   217,   243,   244,
     250,   142,   221,   142,   142,   210,   230,   140,   160,   142,
     142,   142,   142,   142,   144,   230,   144,   230,    31,   165,
     144,   213,   230,   234,   145,   230,    73,   147,   195,   196,
     116,   116,    73,   197,   142,   142,   142,   142,    71,   142,
     142,   254,   161,   166,   168,   230,    51,    71,   156,   157,
     230,   158,   145,   254,   254,   254,    71,   139,     9,    10,
      11,    25,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    49,   144,    59,    60,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   142,
     235,    61,   145,   147,   244,   230,   139,   139,   142,   222,
     218,   244,   143,   230,   230,    31,   193,   194,   213,   234,
       8,   144,    82,   230,   211,   212,   230,   213,   234,    71,
     182,   230,   144,   144,    71,   144,   144,   158,   144,   145,
     231,   234,     8,   144,    13,     8,   144,   163,   164,   234,
     234,   258,   234,   143,   170,   122,   234,   251,    31,   230,
     252,   253,    73,    78,   136,   137,   138,   255,    71,     8,
     144,   143,   140,   146,   159,   160,   166,   168,   230,   148,
     149,   150,   118,   172,    71,   240,   244,   250,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   216,    31,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   193,   120,   230,
     246,   230,   143,    71,   240,   193,   120,   143,   143,   232,
     234,   143,     8,   230,   142,   143,   144,     8,    90,    90,
      13,     8,   143,   143,   167,   146,   230,   196,    42,    43,
      71,   123,   223,   224,   225,    73,     8,   143,     8,   143,
     143,   144,   118,   174,   142,     8,   143,   232,   121,   143,
       8,   228,    61,   120,    72,   230,   234,   157,   166,   168,
     146,    71,   215,   169,   142,   142,   244,    26,    63,   234,
     143,    71,   145,   240,   247,   248,   249,   151,   146,   143,
     247,    26,   160,    31,   213,   234,   230,    26,   160,   180,
     211,   230,   234,    31,   177,   234,   224,    71,    26,   160,
     181,    26,   145,   183,   142,   101,   146,   224,   224,   139,
     142,    13,   164,   144,   234,   175,   215,   145,   251,   122,
     234,    13,    31,   230,    31,   230,    71,    73,    74,   256,
      71,    61,   146,   146,   119,   173,   193,   193,   230,   216,
     230,   142,   239,    61,   145,   219,   158,   186,   232,   143,
     158,   144,   121,   176,   234,   176,    13,   158,   144,   184,
     144,   184,    71,   123,   190,   191,   192,   142,    71,   224,
     227,   229,   224,     8,   198,   143,   142,   230,   232,   232,
     121,   151,   230,   175,   145,   143,   143,   222,   146,   193,
     236,   246,   230,   120,   220,   187,    66,    67,   188,   144,
      83,   211,   177,   143,   143,   224,    89,   184,    92,    93,
      94,   184,   146,   143,     8,    31,    73,   215,   121,   143,
       8,   228,   215,    98,   105,   106,   107,   108,   109,   110,
     111,   140,   146,   199,   204,   205,   206,   207,   209,   251,
      31,   230,   151,   198,   143,   237,   151,   146,   247,    66,
      67,   189,   142,   160,   144,   143,    26,   160,   179,   179,
     144,    92,   144,   230,    26,   144,   185,   146,   145,   192,
      73,    13,    73,   224,   224,    71,   205,   206,   200,    97,
     207,     8,   144,   143,   232,   146,   146,   120,   238,   142,
      26,    68,   230,    26,   160,   178,   158,   144,   185,   158,
     158,    31,    73,    13,   224,   143,   121,    13,    97,    73,
     208,   165,    71,   247,   230,   158,   144,   143,   158,    87,
     158,   146,    73,    13,   224,   145,   224,   224,   165,    13,
       8,   144,    71,    13,   239,   143,   160,    85,   144,    13,
     224,   158,    71,   224,    73,   142,   224,    26,   144,   224,
     146,   142,    13,   201,   158,   162,   202,   224,   190,   101,
     190,   143,   142,   143,   144,   145,   203,   215,   203,   158,
      73,   146,   143,   145,   158,   146
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	struct yyalloc *yyptr =
	  (struct yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        memset(yyptr, 0, YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 125 "hphp.y"
    { _p->saveParseTree((yyval));;}
    break;

  case 3:
#line 130 "hphp.y"
    { _p->addStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 4:
#line 131 "hphp.y"
    { (yyval).reset();;}
    break;

  case 5:
#line 134 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 6:
#line 135 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 7:
#line 136 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 8:
#line 138 "hphp.y"
    { _p->onHphpNoteStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 9:
#line 140 "hphp.y"
    { _p->onHphpNoteStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 10:
#line 141 "hphp.y"
    { (yyval).reset();;}
    break;

  case 11:
#line 143 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 12:
#line 147 "hphp.y"
    { (yyval).reset();;}
    break;

  case 13:
#line 148 "hphp.y"
    { (yyval).reset();;}
    break;

  case 14:
#line 151 "hphp.y"
    { _p->addHphpSuppressError((yyvsp[(2) - (2)]));;}
    break;

  case 15:
#line 152 "hphp.y"
    { _p->addHphpDeclare((yyvsp[(1) - (1)]));;}
    break;

  case 16:
#line 156 "hphp.y"
    { _p->addStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 17:
#line 157 "hphp.y"
    { (yyval).reset();;}
    break;

  case 18:
#line 160 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 19:
#line 161 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 20:
#line 162 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 21:
#line 164 "hphp.y"
    { _p->onHphpNoteStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 22:
#line 166 "hphp.y"
    { _p->onHphpNoteStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 23:
#line 169 "hphp.y"
    { _p->onExpStatement((yyval), (yyvsp[(1) - (2)]));;}
    break;

  case 24:
#line 170 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 25:
#line 171 "hphp.y"
    { _p->onHphpNoteStatement((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 26:
#line 174 "hphp.y"
    { _p->onBlock((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 27:
#line 179 "hphp.y"
    { _p->onIf((yyval),(yyvsp[(3) - (7)]),(yyvsp[(5) - (7)]),(yyvsp[(6) - (7)]),(yyvsp[(7) - (7)]));;}
    break;

  case 28:
#line 185 "hphp.y"
    { _p->onIf((yyval),(yyvsp[(3) - (10)]),(yyvsp[(6) - (10)]),(yyvsp[(7) - (10)]),(yyvsp[(8) - (10)]));;}
    break;

  case 29:
#line 188 "hphp.y"
    { _p->onWhile((yyval),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 30:
#line 191 "hphp.y"
    { _p->onDo((yyval),(yyvsp[(2) - (7)]),(yyvsp[(5) - (7)]));;}
    break;

  case 31:
#line 195 "hphp.y"
    { _p->onFor((yyval),(yyvsp[(3) - (9)]),(yyvsp[(5) - (9)]),(yyvsp[(7) - (9)]),(yyvsp[(9) - (9)]));;}
    break;

  case 32:
#line 198 "hphp.y"
    { _p->onSwitch((yyval),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 33:
#line 200 "hphp.y"
    { _p->onBreak((yyval), NULL);;}
    break;

  case 34:
#line 201 "hphp.y"
    { _p->onBreak((yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 35:
#line 203 "hphp.y"
    { _p->onContinue((yyval), NULL);;}
    break;

  case 36:
#line 204 "hphp.y"
    { _p->onContinue((yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 37:
#line 206 "hphp.y"
    { _p->onReturn((yyval), NULL);;}
    break;

  case 38:
#line 207 "hphp.y"
    { _p->onReturn((yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 39:
#line 208 "hphp.y"
    { _p->onReturn((yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 40:
#line 210 "hphp.y"
    { _p->onGlobal((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 41:
#line 211 "hphp.y"
    { _p->onStatic((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 42:
#line 212 "hphp.y"
    { _p->onEcho((yyval), (yyvsp[(2) - (3)]), 0);;}
    break;

  case 43:
#line 214 "hphp.y"
    { _p->onUnset((yyval), (yyvsp[(3) - (5)]));;}
    break;

  case 44:
#line 215 "hphp.y"
    { (yyval).reset();;}
    break;

  case 45:
#line 217 "hphp.y"
    { _p->onEcho((yyval), (yyvsp[(1) - (1)]), 1);;}
    break;

  case 46:
#line 222 "hphp.y"
    { _p->onForEach((yyval),(yyvsp[(3) - (8)]),(yyvsp[(5) - (8)]),(yyvsp[(6) - (8)]),(yyvsp[(8) - (8)]));;}
    break;

  case 47:
#line 227 "hphp.y"
    { _p->onForEach((yyval),(yyvsp[(3) - (8)]),(yyvsp[(5) - (8)]),(yyvsp[(6) - (8)]),(yyvsp[(8) - (8)]));;}
    break;

  case 48:
#line 230 "hphp.y"
    { _p->onBlock((yyval), (yyvsp[(5) - (5)]));;}
    break;

  case 49:
#line 237 "hphp.y"
    { _p->onTry((yyval),(yyvsp[(3) - (13)]),(yyvsp[(7) - (13)]),(yyvsp[(8) - (13)]),(yyvsp[(11) - (13)]),(yyvsp[(13) - (13)]));;}
    break;

  case 50:
#line 239 "hphp.y"
    { _p->onThrow((yyval), (yyvsp[(2) - (3)]));;}
    break;

  case 51:
#line 247 "hphp.y"
    { _p->onCatch((yyval), (yyvsp[(1) - (9)]), (yyvsp[(4) - (9)]), (yyvsp[(5) - (9)]), (yyvsp[(8) - (9)]));;}
    break;

  case 52:
#line 248 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 53:
#line 252 "hphp.y"
    { _p->onExprListElem((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 54:
#line 253 "hphp.y"
    { _p->onExprListElem((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 55:
#line 256 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 56:
#line 260 "hphp.y"
    { (yyval) = 1;;}
    break;

  case 57:
#line 261 "hphp.y"
    { (yyval).reset();;}
    break;

  case 58:
#line 265 "hphp.y"
    { _p->onFunctionStart((yyvsp[(3) - (3)]));;}
    break;

  case 59:
#line 267 "hphp.y"
    { _p->onFunction((yyval),(yyvsp[(2) - (10)]),(yyvsp[(3) - (10)]),(yyvsp[(6) - (10)]),(yyvsp[(9) - (10)]));;}
    break;

  case 60:
#line 272 "hphp.y"
    { _p->onClassStart((yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 61:
#line 274 "hphp.y"
    { _p->onClass((yyval),(yyvsp[(1) - (8)]),(yyvsp[(5) - (8)]));;}
    break;

  case 62:
#line 276 "hphp.y"
    { _p->onClassStart((yyvsp[(2) - (2)]), NULL);;}
    break;

  case 63:
#line 278 "hphp.y"
    { _p->onInterface((yyval),(yyvsp[(4) - (7)]));;}
    break;

  case 64:
#line 281 "hphp.y"
    { (yyval) = T_CLASS;;}
    break;

  case 65:
#line 282 "hphp.y"
    { (yyval) = T_ABSTRACT;;}
    break;

  case 66:
#line 283 "hphp.y"
    { (yyval) = T_FINAL;;}
    break;

  case 67:
#line 287 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 68:
#line 288 "hphp.y"
    { (yyval).reset();;}
    break;

  case 69:
#line 291 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 70:
#line 292 "hphp.y"
    { (yyval).reset();;}
    break;

  case 71:
#line 295 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 72:
#line 296 "hphp.y"
    { (yyval).reset();;}
    break;

  case 73:
#line 299 "hphp.y"
    { _p->onInterfaceName((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 74:
#line 301 "hphp.y"
    { _p->onInterfaceName((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 75:
#line 305 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 76:
#line 306 "hphp.y"
    { (yyval).reset();;}
    break;

  case 77:
#line 309 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 78:
#line 310 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = 1;;}
    break;

  case 79:
#line 314 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 80:
#line 316 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 81:
#line 319 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 82:
#line 321 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 83:
#line 324 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 84:
#line 326 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 85:
#line 329 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 86:
#line 331 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 89:
#line 341 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 90:
#line 342 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]);;}
    break;

  case 91:
#line 343 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 92:
#line 344 "hphp.y"
    { (yyval) = (yyvsp[(3) - (5)]);;}
    break;

  case 93:
#line 349 "hphp.y"
    { _p->onCase((yyval),(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 94:
#line 351 "hphp.y"
    { _p->onCase((yyval),(yyvsp[(1) - (4)]),NULL,(yyvsp[(4) - (4)]));;}
    break;

  case 95:
#line 352 "hphp.y"
    { (yyval).reset();;}
    break;

  case 96:
#line 355 "hphp.y"
    { (yyval).reset();;}
    break;

  case 97:
#line 356 "hphp.y"
    { (yyval).reset();;}
    break;

  case 98:
#line 361 "hphp.y"
    { _p->onElseIf((yyval),(yyvsp[(1) - (6)]),(yyvsp[(4) - (6)]),(yyvsp[(6) - (6)]));;}
    break;

  case 99:
#line 362 "hphp.y"
    { (yyval).reset();;}
    break;

  case 100:
#line 367 "hphp.y"
    { _p->onElseIf((yyval),(yyvsp[(1) - (7)]),(yyvsp[(4) - (7)]),(yyvsp[(7) - (7)]));;}
    break;

  case 101:
#line 368 "hphp.y"
    { (yyval).reset();;}
    break;

  case 102:
#line 371 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 103:
#line 372 "hphp.y"
    { (yyval).reset();;}
    break;

  case 104:
#line 375 "hphp.y"
    { (yyval) = (yyvsp[(3) - (3)]);;}
    break;

  case 105:
#line 376 "hphp.y"
    { (yyval).reset();;}
    break;

  case 106:
#line 380 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 107:
#line 381 "hphp.y"
    { (yyval).reset();;}
    break;

  case 108:
#line 384 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),0,NULL);;}
    break;

  case 109:
#line 385 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),1,NULL);;}
    break;

  case 110:
#line 387 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),1,&(yyvsp[(5) - (5)]));;}
    break;

  case 111:
#line 389 "hphp.y"
    { _p->onParam((yyval),NULL,(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),0,&(yyvsp[(4) - (4)]));;}
    break;

  case 112:
#line 391 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]),0,NULL);;}
    break;

  case 113:
#line 393 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),1,NULL);;}
    break;

  case 114:
#line 396 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (7)]),(yyvsp[(3) - (7)]),(yyvsp[(5) - (7)]),1,&(yyvsp[(7) - (7)]));;}
    break;

  case 115:
#line 399 "hphp.y"
    { _p->onParam((yyval),&(yyvsp[(1) - (6)]),(yyvsp[(3) - (6)]),(yyvsp[(4) - (6)]),0,&(yyvsp[(6) - (6)]));;}
    break;

  case 116:
#line 402 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 117:
#line 403 "hphp.y"
    { (yyval).setText("array");;}
    break;

  case 118:
#line 404 "hphp.y"
    { (yyval).reset();;}
    break;

  case 119:
#line 408 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 120:
#line 409 "hphp.y"
    { (yyval).reset();;}
    break;

  case 121:
#line 412 "hphp.y"
    { _p->onCallParam((yyval),NULL,(yyvsp[(1) - (1)]),false);;}
    break;

  case 122:
#line 413 "hphp.y"
    { _p->onCallParam((yyval),NULL,(yyvsp[(1) - (1)]),false);;}
    break;

  case 123:
#line 414 "hphp.y"
    { _p->onCallParam((yyval),NULL,(yyvsp[(2) - (2)]),true);;}
    break;

  case 124:
#line 416 "hphp.y"
    { _p->onCallParam((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),false);;}
    break;

  case 125:
#line 418 "hphp.y"
    { _p->onCallParam((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),false);;}
    break;

  case 126:
#line 420 "hphp.y"
    { _p->onCallParam((yyval),&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),true);;}
    break;

  case 127:
#line 424 "hphp.y"
    { _p->onGlobalVar((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 128:
#line 425 "hphp.y"
    { _p->onGlobalVar((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 129:
#line 428 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 130:
#line 429 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = 1;;}
    break;

  case 131:
#line 430 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]); (yyval) = 1;;}
    break;

  case 132:
#line 434 "hphp.y"
    { _p->onStaticVariable((yyval),&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),NULL);;}
    break;

  case 133:
#line 436 "hphp.y"
    { _p->onStaticVariable((yyval),&(yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 134:
#line 437 "hphp.y"
    { _p->onStaticVariable((yyval),NULL,(yyvsp[(1) - (1)]),NULL);;}
    break;

  case 135:
#line 438 "hphp.y"
    { _p->onStaticVariable((yyval),NULL,(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 136:
#line 443 "hphp.y"
    { ;}
    break;

  case 137:
#line 444 "hphp.y"
    { ;}
    break;

  case 138:
#line 447 "hphp.y"
    { _p->onClassVariableStart((yyvsp[(1) - (1)])); ;}
    break;

  case 140:
#line 449 "hphp.y"
    { ;}
    break;

  case 141:
#line 451 "hphp.y"
    { _p->onMethodStart((yyvsp[(4) - (5)]), (yyvsp[(1) - (5)]));;}
    break;

  case 142:
#line 452 "hphp.y"
    { _p->onMethod((yyvsp[(1) - (9)]),(yyvsp[(3) - (9)]),(yyvsp[(4) - (9)]),(yyvsp[(7) - (9)]),
                                                      (yyvsp[(9) - (9)]));;}
    break;

  case 143:
#line 456 "hphp.y"
    { _p->onMethodStart((yyvsp[(5) - (6)]),(yyvsp[(2) - (6)]));;}
    break;

  case 144:
#line 457 "hphp.y"
    { _p->onMethod((yyvsp[(2) - (10)]),(yyvsp[(4) - (10)]),(yyvsp[(5) - (10)]),(yyvsp[(8) - (10)]),
                                                      (yyvsp[(10) - (10)]));
                                         _p->onHphpNoteStatement((yyval),(yyvsp[(1) - (10)]),(yyval));;}
    break;

  case 145:
#line 462 "hphp.y"
    { (yyval).reset();;}
    break;

  case 146:
#line 463 "hphp.y"
    { _p->finishStatement((yyval), (yyvsp[(2) - (3)]));
                                         (yyval) = 1;;}
    break;

  case 147:
#line 467 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 148:
#line 468 "hphp.y"
    { (yyval).reset();;}
    break;

  case 149:
#line 471 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 150:
#line 472 "hphp.y"
    { (yyval).reset();;}
    break;

  case 151:
#line 475 "hphp.y"
    { _p->onMemberModifier((yyval),NULL,(yyvsp[(1) - (1)]));;}
    break;

  case 152:
#line 477 "hphp.y"
    { _p->onMemberModifier((yyval),&(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 153:
#line 480 "hphp.y"
    { (yyval) = T_PUBLIC;;}
    break;

  case 154:
#line 481 "hphp.y"
    { (yyval) = T_PROTECTED;;}
    break;

  case 155:
#line 482 "hphp.y"
    { (yyval) = T_PRIVATE;;}
    break;

  case 156:
#line 483 "hphp.y"
    { (yyval) = T_STATIC;;}
    break;

  case 157:
#line 484 "hphp.y"
    { (yyval) = T_ABSTRACT;;}
    break;

  case 158:
#line 485 "hphp.y"
    { (yyval) = T_FINAL;;}
    break;

  case 159:
#line 489 "hphp.y"
    { _p->onClassVariable((yyvsp[(3) - (3)]),NULL);;}
    break;

  case 160:
#line 491 "hphp.y"
    { _p->onClassVariable((yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 161:
#line 492 "hphp.y"
    { _p->onClassVariable((yyvsp[(1) - (1)]),NULL);;}
    break;

  case 162:
#line 493 "hphp.y"
    { _p->onClassVariable((yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 163:
#line 497 "hphp.y"
    { _p->onClassConstant((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));;}
    break;

  case 164:
#line 498 "hphp.y"
    { _p->onClassConstant((yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));;}
    break;

  case 165:
#line 502 "hphp.y"
    { _p->onExprListElem((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 166:
#line 503 "hphp.y"
    { _p->onExprListElem((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 167:
#line 507 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 168:
#line 508 "hphp.y"
    { (yyval).reset();;}
    break;

  case 169:
#line 511 "hphp.y"
    { _p->onExprListElem((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 170:
#line 512 "hphp.y"
    { _p->onExprListElem((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 171:
#line 517 "hphp.y"
    { _p->onListAssignment((yyval), (yyvsp[(3) - (6)]), (yyvsp[(6) - (6)]));;}
    break;

  case 172:
#line 518 "hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), 0);;}
    break;

  case 173:
#line 519 "hphp.y"
    { _p->onAssign((yyval), (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]), 1);;}
    break;

  case 174:
#line 522 "hphp.y"
    { _p->onAssignNew((yyval),(yyvsp[(1) - (6)]),(yyvsp[(5) - (6)]),(yyvsp[(6) - (6)]));;}
    break;

  case 175:
#line 524 "hphp.y"
    { _p->onNewObject((yyval), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 176:
#line 525 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_CLONE,1);;}
    break;

  case 177:
#line 526 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_PLUS_EQUAL);;}
    break;

  case 178:
#line 527 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MINUS_EQUAL);;}
    break;

  case 179:
#line 528 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MUL_EQUAL);;}
    break;

  case 180:
#line 529 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_DIV_EQUAL);;}
    break;

  case 181:
#line 530 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_CONCAT_EQUAL);;}
    break;

  case 182:
#line 531 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_MOD_EQUAL);;}
    break;

  case 183:
#line 532 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_AND_EQUAL);;}
    break;

  case 184:
#line 533 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_OR_EQUAL);;}
    break;

  case 185:
#line 534 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_XOR_EQUAL);;}
    break;

  case 186:
#line 535 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SL_EQUAL);;}
    break;

  case 187:
#line 536 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SR_EQUAL);;}
    break;

  case 188:
#line 537 "hphp.y"
    { UEXP((yyval),(yyvsp[(1) - (2)]),T_INC,0);;}
    break;

  case 189:
#line 538 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INC,1);;}
    break;

  case 190:
#line 539 "hphp.y"
    { UEXP((yyval),(yyvsp[(1) - (2)]),T_DEC,0);;}
    break;

  case 191:
#line 540 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_DEC,1);;}
    break;

  case 192:
#line 541 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_BOOLEAN_OR);;}
    break;

  case 193:
#line 542 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_BOOLEAN_AND);;}
    break;

  case 194:
#line 543 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_OR);;}
    break;

  case 195:
#line 544 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_AND);;}
    break;

  case 196:
#line 545 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_LOGICAL_XOR);;}
    break;

  case 197:
#line 546 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'|');;}
    break;

  case 198:
#line 547 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'&');;}
    break;

  case 199:
#line 548 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'^');;}
    break;

  case 200:
#line 549 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'.');;}
    break;

  case 201:
#line 550 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'+');;}
    break;

  case 202:
#line 551 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'-');;}
    break;

  case 203:
#line 552 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'*');;}
    break;

  case 204:
#line 553 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'/');;}
    break;

  case 205:
#line 554 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'%');;}
    break;

  case 206:
#line 555 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SL);;}
    break;

  case 207:
#line 556 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_SR);;}
    break;

  case 208:
#line 557 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 209:
#line 558 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 210:
#line 559 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'!',1);;}
    break;

  case 211:
#line 560 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'~',1);;}
    break;

  case 212:
#line 561 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_IDENTICAL);;}
    break;

  case 213:
#line 562 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_NOT_IDENTICAL);;}
    break;

  case 214:
#line 563 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_EQUAL);;}
    break;

  case 215:
#line 564 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_IS_NOT_EQUAL);;}
    break;

  case 216:
#line 565 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'<');;}
    break;

  case 217:
#line 566 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),
                                              T_IS_SMALLER_OR_EQUAL);;}
    break;

  case 218:
#line 568 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),'>');;}
    break;

  case 219:
#line 569 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),
                                              T_IS_GREATER_OR_EQUAL);;}
    break;

  case 220:
#line 572 "hphp.y"
    { BEXP((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),T_INSTANCEOF);;}
    break;

  case 221:
#line 573 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (3)]),'(',1);;}
    break;

  case 222:
#line 574 "hphp.y"
    { _p->onQOp((yyval), (yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));;}
    break;

  case 223:
#line 575 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 224:
#line 576 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INT_CAST,1);;}
    break;

  case 225:
#line 577 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_DOUBLE_CAST,1);;}
    break;

  case 226:
#line 578 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_STRING_CAST,1);;}
    break;

  case 227:
#line 579 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_ARRAY_CAST,1);;}
    break;

  case 228:
#line 580 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_OBJECT_CAST,1);;}
    break;

  case 229:
#line 581 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_BOOL_CAST,1);;}
    break;

  case 230:
#line 582 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_UNSET_CAST,1);;}
    break;

  case 231:
#line 583 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_EXIT,1);;}
    break;

  case 232:
#line 584 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'@',1);;}
    break;

  case 233:
#line 585 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 234:
#line 586 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]));;}
    break;

  case 235:
#line 587 "hphp.y"
    { _p->onEncapsList((yyval),'`',(yyvsp[(2) - (3)]));;}
    break;

  case 236:
#line 588 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_PRINT,1);;}
    break;

  case 237:
#line 589 "hphp.y"
    { _p->onHphpNoteExpr((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 238:
#line 594 "hphp.y"
    { _p->onCall((yyval),0,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 239:
#line 596 "hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 240:
#line 600 "hphp.y"
    { _p->onCall((yyval),0,(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]),&(yyvsp[(1) - (6)]));;}
    break;

  case 241:
#line 604 "hphp.y"
    { _p->onCall((yyval),1,(yyvsp[(3) - (6)]),(yyvsp[(5) - (6)]),&(yyvsp[(1) - (6)]));;}
    break;

  case 242:
#line 607 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 243:
#line 610 "hphp.y"
    { _p->onName((yyval), (yyvsp[(1) - (1)]), true);;}
    break;

  case 244:
#line 611 "hphp.y"
    { _p->onName((yyval), (yyvsp[(1) - (1)]), false);;}
    break;

  case 245:
#line 614 "hphp.y"
    { _p->pushObject((yyvsp[(1) - (1)]));;}
    break;

  case 246:
#line 616 "hphp.y"
    { _p->popObject((yyval));;}
    break;

  case 247:
#line 617 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 248:
#line 621 "hphp.y"
    { ;}
    break;

  case 249:
#line 622 "hphp.y"
    { ;}
    break;

  case 250:
#line 625 "hphp.y"
    { ;}
    break;

  case 251:
#line 629 "hphp.y"
    { (yyval).reset();;}
    break;

  case 252:
#line 630 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 253:
#line 631 "hphp.y"
    { (yyval).reset();;}
    break;

  case 254:
#line 636 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 255:
#line 637 "hphp.y"
    { (yyval).reset();;}
    break;

  case 256:
#line 641 "hphp.y"
    { _p->onScalar((yyval), T_LNUMBER, (yyvsp[(1) - (1)]));;}
    break;

  case 257:
#line 642 "hphp.y"
    { _p->onScalar((yyval), T_DNUMBER, (yyvsp[(1) - (1)]));;}
    break;

  case 258:
#line 643 "hphp.y"
    { _p->onScalar((yyval),
                                         T_CONSTANT_ENCAPSED_STRING, (yyvsp[(1) - (1)]));;}
    break;

  case 259:
#line 645 "hphp.y"
    { _p->onScalar((yyval), T_LINE, (yyvsp[(1) - (1)]));;}
    break;

  case 260:
#line 646 "hphp.y"
    { _p->onScalar((yyval), T_FILE, (yyvsp[(1) - (1)]));;}
    break;

  case 261:
#line 647 "hphp.y"
    { _p->onScalar((yyval), T_CLASS_C, (yyvsp[(1) - (1)]));;}
    break;

  case 262:
#line 648 "hphp.y"
    { _p->onScalar((yyval), T_METHOD_C, (yyvsp[(1) - (1)]));;}
    break;

  case 263:
#line 649 "hphp.y"
    { _p->onScalar((yyval), T_FUNC_C, (yyvsp[(1) - (1)]));;}
    break;

  case 264:
#line 652 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 265:
#line 653 "hphp.y"
    { _p->onConstant((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 266:
#line 654 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 267:
#line 655 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 268:
#line 657 "hphp.y"
    { _p->onArray((yyval),(yyvsp[(3) - (4)]));;}
    break;

  case 269:
#line 658 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 270:
#line 662 "hphp.y"
    { _p->onClassConst((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 271:
#line 665 "hphp.y"
    { _p->onConstant((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 272:
#line 666 "hphp.y"
    { _p->onConstant((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 273:
#line 667 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 274:
#line 668 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 275:
#line 669 "hphp.y"
    { _p->onEncapsList((yyval),'"',(yyvsp[(2) - (3)]));;}
    break;

  case 276:
#line 670 "hphp.y"
    { _p->onEncapsList((yyval),'\'',(yyvsp[(2) - (3)]));;}
    break;

  case 277:
#line 672 "hphp.y"
    { _p->onEncapsList((yyval),T_START_HEREDOC,
                                                          (yyvsp[(2) - (3)]));;}
    break;

  case 278:
#line 677 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 279:
#line 678 "hphp.y"
    { (yyval).reset();;}
    break;

  case 280:
#line 681 "hphp.y"
    { (yyval).reset();;}
    break;

  case 281:
#line 682 "hphp.y"
    { (yyval).reset();;}
    break;

  case 282:
#line 687 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),false);;}
    break;

  case 283:
#line 689 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),NULL,(yyvsp[(3) - (3)]),false);;}
    break;

  case 284:
#line 691 "hphp.y"
    { _p->onArrayPair((yyval),NULL,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),false);;}
    break;

  case 285:
#line 692 "hphp.y"
    { _p->onArrayPair((yyval),NULL,NULL,(yyvsp[(1) - (1)]),false);;}
    break;

  case 286:
#line 696 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 287:
#line 697 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 288:
#line 700 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 289:
#line 703 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 290:
#line 706 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 291:
#line 709 "hphp.y"
    { _p->pushObject((yyvsp[(1) - (1)]));;}
    break;

  case 292:
#line 711 "hphp.y"
    { _p->appendMethodParams((yyvsp[(5) - (5)]));;}
    break;

  case 293:
#line 712 "hphp.y"
    { _p->popObject((yyval));;}
    break;

  case 294:
#line 713 "hphp.y"
    { _p->pushObject((yyvsp[(1) - (1)]));
                                         _p->popObject((yyval));;}
    break;

  case 295:
#line 718 "hphp.y"
    { ;}
    break;

  case 296:
#line 719 "hphp.y"
    { ;}
    break;

  case 297:
#line 723 "hphp.y"
    { _p->appendMethodParams((yyvsp[(3) - (3)]));;}
    break;

  case 298:
#line 727 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).num = 1;;}
    break;

  case 299:
#line 728 "hphp.y"
    { (yyval).reset();;}
    break;

  case 300:
#line 732 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 301:
#line 734 "hphp.y"
    { _p->onIndirectRef((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 302:
#line 739 "hphp.y"
    { _p->onStaticMember((yyval),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));;}
    break;

  case 303:
#line 743 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 304:
#line 744 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 305:
#line 747 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 306:
#line 749 "hphp.y"
    { _p->onIndirectRef((yyval),(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));;}
    break;

  case 307:
#line 750 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = 2;;}
    break;

  case 308:
#line 754 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 309:
#line 755 "hphp.y"
    { _p->onRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 310:
#line 756 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 311:
#line 759 "hphp.y"
    { _p->onSimpleVariable((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 312:
#line 760 "hphp.y"
    { _p->onDynamicVariable((yyval), (yyvsp[(3) - (4)]), 0);;}
    break;

  case 313:
#line 763 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 314:
#line 764 "hphp.y"
    { (yyval).reset();;}
    break;

  case 315:
#line 768 "hphp.y"
    { ;}
    break;

  case 316:
#line 769 "hphp.y"
    { _p->appendProperty((yyvsp[(1) - (1)]));;}
    break;

  case 317:
#line 772 "hphp.y"
    { _p->appendRefDim((yyvsp[(3) - (4)]));;}
    break;

  case 318:
#line 773 "hphp.y"
    { _p->appendRefDim((yyvsp[(3) - (4)]));;}
    break;

  case 319:
#line 774 "hphp.y"
    { _p->appendProperty((yyvsp[(1) - (1)]));;}
    break;

  case 320:
#line 777 "hphp.y"
    { _p->onName((yyval), (yyvsp[(1) - (1)]), true);;}
    break;

  case 321:
#line 778 "hphp.y"
    { _p->onName((yyval), (yyvsp[(2) - (3)]), false);;}
    break;

  case 322:
#line 782 "hphp.y"
    { (yyval) = 1;;}
    break;

  case 323:
#line 783 "hphp.y"
    { (yyval)++;;}
    break;

  case 324:
#line 787 "hphp.y"
    { _p->onAListVar((yyval),&(yyvsp[(1) - (2)]),NULL);;}
    break;

  case 325:
#line 788 "hphp.y"
    { _p->onAListVar((yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 326:
#line 790 "hphp.y"
    { _p->onAListSub((yyval),&(yyvsp[(1) - (6)]),(yyvsp[(5) - (6)]));;}
    break;

  case 327:
#line 791 "hphp.y"
    { _p->onAListVar((yyval),NULL,NULL);;}
    break;

  case 328:
#line 792 "hphp.y"
    { _p->onAListVar((yyval),NULL,&(yyvsp[(1) - (1)]));;}
    break;

  case 329:
#line 793 "hphp.y"
    { _p->onAListSub((yyval),NULL,(yyvsp[(3) - (4)]));;}
    break;

  case 330:
#line 799 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 331:
#line 800 "hphp.y"
    { (yyval).reset();;}
    break;

  case 332:
#line 804 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]),false);;}
    break;

  case 333:
#line 805 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (3)]),NULL,(yyvsp[(3) - (3)]),false);;}
    break;

  case 334:
#line 806 "hphp.y"
    { _p->onArrayPair((yyval),NULL,&(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]),false);;}
    break;

  case 335:
#line 807 "hphp.y"
    { _p->onArrayPair((yyval),NULL,NULL,(yyvsp[(1) - (1)]),false);;}
    break;

  case 336:
#line 810 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (6)]),&(yyvsp[(3) - (6)]),(yyvsp[(6) - (6)]),true);;}
    break;

  case 337:
#line 812 "hphp.y"
    { _p->onArrayPair((yyval),&(yyvsp[(1) - (4)]),NULL,(yyvsp[(4) - (4)]),true);;}
    break;

  case 338:
#line 813 "hphp.y"
    { _p->onArrayPair((yyval),NULL,&(yyvsp[(1) - (4)]),(yyvsp[(4) - (4)]),true);;}
    break;

  case 339:
#line 814 "hphp.y"
    { _p->onArrayPair((yyval),NULL,NULL,(yyvsp[(2) - (2)]),true);;}
    break;

  case 340:
#line 818 "hphp.y"
    { _p->addEncap((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), -1);;}
    break;

  case 341:
#line 820 "hphp.y"
    { _p->addEncap((yyval), (yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), 0);;}
    break;

  case 342:
#line 821 "hphp.y"
    { (yyval).reset();;}
    break;

  case 343:
#line 824 "hphp.y"
    { _p->onSimpleVariable((yyval), (yyvsp[(1) - (1)]));;}
    break;

  case 344:
#line 826 "hphp.y"
    { _p->encapRefDim((yyval), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));;}
    break;

  case 345:
#line 828 "hphp.y"
    { _p->encapObjProp((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 346:
#line 830 "hphp.y"
    { _p->onDynamicVariable((yyval), (yyvsp[(2) - (3)]), 1);;}
    break;

  case 347:
#line 832 "hphp.y"
    { _p->encapArray((yyval), (yyvsp[(2) - (6)]), (yyvsp[(4) - (6)]));;}
    break;

  case 348:
#line 833 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 349:
#line 836 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_STRING;;}
    break;

  case 350:
#line 837 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_NUM_STRING;;}
    break;

  case 351:
#line 838 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_VARIABLE;;}
    break;

  case 352:
#line 842 "hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_ISSET,1);;}
    break;

  case 353:
#line 843 "hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_EMPTY,1);;}
    break;

  case 354:
#line 844 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INCLUDE,1);;}
    break;

  case 355:
#line 845 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_INCLUDE_ONCE,1);;}
    break;

  case 356:
#line 846 "hphp.y"
    { UEXP((yyval),(yyvsp[(3) - (4)]),T_EVAL,1);;}
    break;

  case 357:
#line 847 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_REQUIRE,1);;}
    break;

  case 358:
#line 848 "hphp.y"
    { UEXP((yyval),(yyvsp[(2) - (2)]),T_REQUIRE_ONCE,1);;}
    break;

  case 359:
#line 852 "hphp.y"
    { _p->onExprListElem((yyval), NULL, (yyvsp[(1) - (1)]));;}
    break;

  case 360:
#line 853 "hphp.y"
    { _p->onExprListElem((yyval), &(yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 361:
#line 858 "hphp.y"
    { _p->onClassConst((yyval), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;


/* Line 1267 of yacc.c.  */
#line 5082 "hphp.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 860 "hphp.y"


static int __attribute__((unused)) suppress_warning = yydebug;

