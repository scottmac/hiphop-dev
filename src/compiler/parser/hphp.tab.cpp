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
     T_HPHP_NOTE = 298,
     T_CLONE = 299,
     T_NEW = 300,
     T_EXIT = 301,
     T_IF = 302,
     T_ELSEIF = 303,
     T_ELSE = 304,
     T_ENDIF = 305,
     T_LNUMBER = 306,
     T_DNUMBER = 307,
     T_STRING = 308,
     T_STRING_VARNAME = 309,
     T_VARIABLE = 310,
     T_NUM_STRING = 311,
     T_INLINE_HTML = 312,
     T_CHARACTER = 313,
     T_BAD_CHARACTER = 314,
     T_ENCAPSED_AND_WHITESPACE = 315,
     T_CONSTANT_ENCAPSED_STRING = 316,
     T_ECHO = 317,
     T_DO = 318,
     T_WHILE = 319,
     T_ENDWHILE = 320,
     T_FOR = 321,
     T_ENDFOR = 322,
     T_FOREACH = 323,
     T_ENDFOREACH = 324,
     T_DECLARE = 325,
     T_ENDDECLARE = 326,
     T_AS = 327,
     T_SWITCH = 328,
     T_ENDSWITCH = 329,
     T_CASE = 330,
     T_DEFAULT = 331,
     T_BREAK = 332,
     T_CONTINUE = 333,
     T_FUNCTION = 334,
     T_CONST = 335,
     T_RETURN = 336,
     T_TRY = 337,
     T_CATCH = 338,
     T_THROW = 339,
     T_USE = 340,
     T_GLOBAL = 341,
     T_PUBLIC = 342,
     T_PROTECTED = 343,
     T_PRIVATE = 344,
     T_FINAL = 345,
     T_ABSTRACT = 346,
     T_STATIC = 347,
     T_VAR = 348,
     T_UNSET = 349,
     T_ISSET = 350,
     T_EMPTY = 351,
     T_HALT_COMPILER = 352,
     T_CLASS = 353,
     T_INTERFACE = 354,
     T_EXTENDS = 355,
     T_IMPLEMENTS = 356,
     T_OBJECT_OPERATOR = 357,
     T_DOUBLE_ARROW = 358,
     T_LIST = 359,
     T_ARRAY = 360,
     T_CLASS_C = 361,
     T_METHOD_C = 362,
     T_FUNC_C = 363,
     T_LINE = 364,
     T_FILE = 365,
     T_COMMENT = 366,
     T_DOC_COMMENT = 367,
     T_OPEN_TAG = 368,
     T_OPEN_TAG_WITH_ECHO = 369,
     T_CLOSE_TAG = 370,
     T_WHITESPACE = 371,
     T_START_HEREDOC = 372,
     T_END_HEREDOC = 373,
     T_DOLLAR_OPEN_CURLY_BRACES = 374,
     T_CURLY_OPEN = 375,
     T_PAAMAYIM_NEKUDOTAYIM = 376,
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
#define T_HPHP_NOTE 298
#define T_CLONE 299
#define T_NEW 300
#define T_EXIT 301
#define T_IF 302
#define T_ELSEIF 303
#define T_ELSE 304
#define T_ENDIF 305
#define T_LNUMBER 306
#define T_DNUMBER 307
#define T_STRING 308
#define T_STRING_VARNAME 309
#define T_VARIABLE 310
#define T_NUM_STRING 311
#define T_INLINE_HTML 312
#define T_CHARACTER 313
#define T_BAD_CHARACTER 314
#define T_ENCAPSED_AND_WHITESPACE 315
#define T_CONSTANT_ENCAPSED_STRING 316
#define T_ECHO 317
#define T_DO 318
#define T_WHILE 319
#define T_ENDWHILE 320
#define T_FOR 321
#define T_ENDFOR 322
#define T_FOREACH 323
#define T_ENDFOREACH 324
#define T_DECLARE 325
#define T_ENDDECLARE 326
#define T_AS 327
#define T_SWITCH 328
#define T_ENDSWITCH 329
#define T_CASE 330
#define T_DEFAULT 331
#define T_BREAK 332
#define T_CONTINUE 333
#define T_FUNCTION 334
#define T_CONST 335
#define T_RETURN 336
#define T_TRY 337
#define T_CATCH 338
#define T_THROW 339
#define T_USE 340
#define T_GLOBAL 341
#define T_PUBLIC 342
#define T_PROTECTED 343
#define T_PRIVATE 344
#define T_FINAL 345
#define T_ABSTRACT 346
#define T_STATIC 347
#define T_VAR 348
#define T_UNSET 349
#define T_ISSET 350
#define T_EMPTY 351
#define T_HALT_COMPILER 352
#define T_CLASS 353
#define T_INTERFACE 354
#define T_EXTENDS 355
#define T_IMPLEMENTS 356
#define T_OBJECT_OPERATOR 357
#define T_DOUBLE_ARROW 358
#define T_LIST 359
#define T_ARRAY 360
#define T_CLASS_C 361
#define T_METHOD_C 362
#define T_FUNC_C 363
#define T_LINE 364
#define T_FILE 365
#define T_COMMENT 366
#define T_DOC_COMMENT 367
#define T_OPEN_TAG 368
#define T_OPEN_TAG_WITH_ECHO 369
#define T_CLOSE_TAG 370
#define T_WHITESPACE 371
#define T_START_HEREDOC 372
#define T_END_HEREDOC 373
#define T_DOLLAR_OPEN_CURLY_BRACES 374
#define T_CURLY_OPEN 375
#define T_PAAMAYIM_NEKUDOTAYIM 376
#define T_HPHP_DECLARE 377




/* Copy the first part of user declarations.  */
#line 1 "hphp.y"

#include <compiler/parser/parser.h>

using namespace HPHP;

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
#line 368 "hphp.tab.cpp"

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
#define YYLAST   5748

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  152
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  362
/* YYNRULES -- Number of states.  */
#define YYNSTATES  735

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
     203,   207,   209,   210,   212,   215,   224,   226,   230,   232,
     234,   235,   236,   247,   248,   257,   258,   266,   268,   271,
     274,   277,   278,   281,   282,   285,   286,   288,   292,   295,
     296,   298,   301,   303,   308,   310,   315,   317,   322,   324,
     329,   333,   339,   343,   348,   353,   359,   365,   370,   371,
     373,   375,   382,   383,   391,   392,   395,   396,   400,   401,
     403,   404,   407,   411,   417,   422,   427,   433,   441,   448,
     450,   452,   453,   455,   456,   458,   460,   463,   467,   471,
     476,   480,   482,   484,   487,   492,   496,   502,   504,   508,
     511,   512,   516,   519,   520,   530,   531,   542,   544,   548,
     550,   552,   554,   555,   557,   560,   562,   564,   566,   568,
     570,   572,   576,   582,   584,   588,   594,   599,   603,   605,
     607,   608,   612,   614,   621,   625,   630,   637,   641,   644,
     648,   652,   656,   660,   664,   668,   672,   676,   680,   684,
     688,   691,   694,   697,   700,   704,   708,   712,   716,   720,
     724,   728,   732,   736,   740,   744,   748,   752,   756,   760,
     764,   767,   770,   773,   776,   780,   784,   788,   792,   796,
     800,   804,   808,   812,   816,   822,   824,   827,   830,   833,
     836,   839,   842,   845,   848,   851,   853,   858,   862,   865,
     868,   873,   878,   885,   892,   894,   896,   898,   899,   905,
     907,   910,   911,   914,   917,   921,   922,   926,   927,   929,
     931,   933,   935,   937,   939,   941,   943,   945,   947,   950,
     953,   958,   960,   964,   966,   968,   970,   972,   976,   980,
     984,   987,   988,   990,   991,   997,  1001,  1005,  1007,  1009,
    1011,  1013,  1015,  1017,  1018,  1019,  1027,  1029,  1032,  1033,
    1037,  1041,  1042,  1044,  1047,  1051,  1053,  1055,  1057,  1060,
    1062,  1067,  1072,  1074,  1076,  1081,  1083,  1084,  1086,  1088,
    1093,  1098,  1100,  1102,  1106,  1108,  1111,  1115,  1117,  1119,
    1124,  1125,  1128,  1129,  1135,  1139,  1143,  1145,  1152,  1157,
    1162,  1165,  1168,  1171,  1172,  1174,  1179,  1183,  1187,  1194,
    1198,  1200,  1202,  1204,  1209,  1214,  1217,  1220,  1225,  1228,
    1231,  1233,  1237
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     153,     0,    -1,   154,    -1,   154,   155,    -1,    -1,   160,
      -1,   168,    -1,   170,    -1,    62,   168,    -1,    62,   170,
      -1,   116,   142,   143,   144,    -1,   141,   156,   144,    -1,
     156,     8,   157,    -1,   157,    -1,    51,    72,    -1,    72,
      -1,   158,   159,    -1,    -1,   160,    -1,   168,    -1,   170,
      -1,    62,   168,    -1,    62,   170,    -1,   231,   144,    -1,
     161,    -1,    62,   161,    -1,   145,   158,   146,    -1,    66,
     142,   231,   143,   160,   188,   190,    -1,    66,   142,   231,
     143,    26,   158,   189,   191,    69,   144,    -1,    83,   142,
     231,   143,   182,    -1,    82,   160,    83,   142,   231,   143,
     144,    -1,    85,   142,   212,   144,   212,   144,   212,   143,
     180,    -1,    92,   142,   231,   143,   185,    -1,    96,   144,
      -1,    96,   231,   144,    -1,    97,   144,    -1,    97,   231,
     144,    -1,   100,   144,    -1,   100,   214,   144,    -1,   100,
     235,   144,    -1,   105,   197,   144,    -1,   111,   199,   144,
      -1,    81,   211,   144,    -1,   113,   142,   165,   143,   144,
      -1,   144,    -1,    76,    -1,    87,   142,   235,    91,   179,
     178,   143,   181,    -1,    87,   142,   214,    91,   235,   178,
     143,   181,    -1,    89,   142,   184,   143,   183,    -1,   101,
     145,   158,   146,   102,   142,   216,    74,   143,   145,   158,
     146,   162,    -1,   103,   231,   144,    -1,   163,    -1,    -1,
     164,    -1,   163,   164,    -1,   102,   142,   216,    74,   143,
     145,   158,   146,    -1,   166,    -1,   165,     8,   166,    -1,
     235,    -1,    31,    -1,    -1,    -1,    98,   167,    72,   169,
     142,   192,   143,   145,   158,   146,    -1,    -1,   173,    72,
     171,   174,   175,   145,   200,   146,    -1,    -1,   118,    72,
     172,   176,   145,   200,   146,    -1,   117,    -1,   110,   117,
      -1,   109,   117,    -1,   119,   216,    -1,    -1,   120,   177,
      -1,    -1,   119,   177,    -1,    -1,   216,    -1,   177,     8,
     216,    -1,   122,   179,    -1,    -1,   235,    -1,    31,   235,
      -1,   160,    -1,    26,   158,    86,   144,    -1,   160,    -1,
      26,   158,    88,   144,    -1,   160,    -1,    26,   158,    84,
     144,    -1,   160,    -1,    26,   158,    90,   144,    -1,    72,
      13,   225,    -1,   184,     8,    72,    13,   225,    -1,   145,
     186,   146,    -1,   145,   144,   186,   146,    -1,    26,   186,
      93,   144,    -1,    26,   144,   186,    93,   144,    -1,   186,
      94,   231,   187,   158,    -1,   186,    95,   187,   158,    -1,
      -1,    26,    -1,   144,    -1,   188,    67,   142,   231,   143,
     160,    -1,    -1,   189,    67,   142,   231,   143,    26,   158,
      -1,    -1,    68,   160,    -1,    -1,    68,    26,   158,    -1,
      -1,   193,    -1,    -1,   194,    74,    -1,   194,    31,    74,
      -1,   194,    31,    74,    13,   225,    -1,   194,    74,    13,
     225,    -1,   193,     8,   194,    74,    -1,   193,     8,   194,
      31,    74,    -1,   193,     8,   194,    31,    74,    13,   225,
      -1,   193,     8,   194,    74,    13,   225,    -1,    72,    -1,
     124,    -1,    -1,   196,    -1,    -1,   214,    -1,   235,    -1,
      31,   233,    -1,   196,     8,   214,    -1,   196,     8,   235,
      -1,   196,     8,    31,   233,    -1,   197,     8,   198,    -1,
     198,    -1,    74,    -1,   147,   232,    -1,   147,   145,   231,
     146,    -1,   199,     8,    74,    -1,   199,     8,    74,    13,
     225,    -1,    74,    -1,    74,    13,   225,    -1,   200,   201,
      -1,    -1,   205,   209,   144,    -1,   210,   144,    -1,    -1,
     206,    98,   167,    72,   142,   202,   192,   143,   204,    -1,
      -1,    62,   206,    98,   167,    72,   142,   203,   192,   143,
     204,    -1,   144,    -1,   145,   158,   146,    -1,   207,    -1,
     112,    -1,   207,    -1,    -1,   208,    -1,   207,   208,    -1,
     106,    -1,   107,    -1,   108,    -1,   111,    -1,   110,    -1,
     109,    -1,   209,     8,    74,    -1,   209,     8,    74,    13,
     225,    -1,    74,    -1,    74,    13,   225,    -1,   210,     8,
      72,    13,   225,    -1,    99,    72,    13,   225,    -1,   211,
       8,   231,    -1,   231,    -1,   213,    -1,    -1,   213,     8,
     231,    -1,   231,    -1,   123,   142,   252,   143,    13,   231,
      -1,   235,    13,   231,    -1,   235,    13,    31,   235,    -1,
     235,    13,    31,    64,   217,   223,    -1,    64,   217,   223,
      -1,    63,   231,    -1,   235,    24,   231,    -1,   235,    23,
     231,    -1,   235,    22,   231,    -1,   235,    21,   231,    -1,
     235,    20,   231,    -1,   235,    19,   231,    -1,   235,    18,
     231,    -1,   235,    17,   231,    -1,   235,    16,   231,    -1,
     235,    15,   231,    -1,   235,    14,   231,    -1,   234,    60,
      -1,    60,   234,    -1,   234,    59,    -1,    59,   234,    -1,
     231,    27,   231,    -1,   231,    28,   231,    -1,   231,     9,
     231,    -1,   231,    11,   231,    -1,   231,    10,   231,    -1,
     231,    29,   231,    -1,   231,    31,   231,    -1,   231,    30,
     231,    -1,   231,    44,   231,    -1,   231,    42,   231,    -1,
     231,    43,   231,    -1,   231,    45,   231,    -1,   231,    46,
     231,    -1,   231,    47,   231,    -1,   231,    41,   231,    -1,
     231,    40,   231,    -1,    42,   231,    -1,    43,   231,    -1,
      48,   231,    -1,    50,   231,    -1,   231,    33,   231,    -1,
     231,    32,   231,    -1,   231,    35,   231,    -1,   231,    34,
     231,    -1,   231,    36,   231,    -1,   231,    39,   231,    -1,
     231,    37,   231,    -1,   231,    38,   231,    -1,   231,    49,
     217,    -1,   142,   231,   143,    -1,   231,    25,   231,    26,
     231,    -1,   259,    -1,    58,   231,    -1,    57,   231,    -1,
      56,   231,    -1,    55,   231,    -1,    54,   231,    -1,    53,
     231,    -1,    52,   231,    -1,    65,   222,    -1,    51,   231,
      -1,   227,    -1,   124,   142,   254,   143,    -1,   148,   256,
     148,    -1,    12,   231,    -1,    62,   231,    -1,    72,   142,
     195,   143,    -1,   241,   142,   195,   143,    -1,   216,   140,
      72,   142,   195,   143,    -1,   216,   140,   241,   142,   195,
     143,    -1,    72,    -1,    72,    -1,   218,    -1,    -1,   244,
     219,   121,   248,   220,    -1,   244,    -1,   220,   221,    -1,
      -1,   121,   248,    -1,   142,   143,    -1,   142,   231,   143,
      -1,    -1,   142,   195,   143,    -1,    -1,    70,    -1,    71,
      -1,    80,    -1,   128,    -1,   129,    -1,   125,    -1,   126,
      -1,   127,    -1,   224,    -1,    72,    -1,    42,   225,    -1,
      43,   225,    -1,   124,   142,   228,   143,    -1,   226,    -1,
      72,   140,    72,    -1,    72,    -1,    73,    -1,   261,    -1,
     224,    -1,   149,   256,   149,    -1,   150,   256,   150,    -1,
     136,   256,   137,    -1,   230,   229,    -1,    -1,     8,    -1,
      -1,   230,     8,   225,   122,   225,    -1,   230,     8,   225,
      -1,   225,   122,   225,    -1,   225,    -1,   232,    -1,   214,
      -1,   235,    -1,   235,    -1,   235,    -1,    -1,    -1,   243,
     236,   121,   248,   240,   237,   238,    -1,   243,    -1,   238,
     239,    -1,    -1,   121,   248,   240,    -1,   142,   195,   143,
      -1,    -1,   245,    -1,   251,   245,    -1,   216,   140,   241,
      -1,   244,    -1,   215,    -1,   245,    -1,   251,   245,    -1,
     242,    -1,   245,    61,   247,   151,    -1,   245,   145,   231,
     146,    -1,   246,    -1,    74,    -1,   147,   145,   231,   146,
      -1,   231,    -1,    -1,   249,    -1,   241,    -1,   249,    61,
     247,   151,    -1,   249,   145,   231,   146,    -1,   250,    -1,
      72,    -1,   145,   231,   146,    -1,   147,    -1,   251,   147,
      -1,   252,     8,   253,    -1,   253,    -1,   235,    -1,   123,
     142,   252,   143,    -1,    -1,   255,   229,    -1,    -1,   255,
       8,   231,   122,   231,    -1,   255,     8,   231,    -1,   231,
     122,   231,    -1,   231,    -1,   255,     8,   231,   122,    31,
     233,    -1,   255,     8,    31,   233,    -1,   231,   122,    31,
     233,    -1,    31,   233,    -1,   256,   257,    -1,   256,    79,
      -1,    -1,    74,    -1,    74,    61,   258,   151,    -1,    74,
     121,    72,    -1,   138,   231,   146,    -1,   138,    73,    61,
     231,   151,   146,    -1,   139,   235,   146,    -1,    72,    -1,
      75,    -1,    74,    -1,   114,   142,   260,   143,    -1,   115,
     142,   235,   143,    -1,     7,   231,    -1,     6,   231,    -1,
       5,   142,   231,   143,    -1,     4,   231,    -1,     3,   231,
      -1,   235,    -1,   260,     8,   235,    -1,   216,   140,    72,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   128,   130,   133,   134,   135,   136,   138,
     140,   141,   145,   147,   150,   151,   154,   156,   159,   160,
     161,   162,   164,   168,   169,   170,   173,   175,   180,   186,
     189,   192,   196,   199,   200,   202,   203,   205,   206,   207,
     209,   210,   211,   212,   214,   216,   218,   223,   228,   231,
     238,   242,   243,   246,   247,   251,   258,   259,   262,   266,
     267,   271,   271,   277,   277,   282,   282,   287,   288,   289,
     292,   294,   297,   298,   301,   302,   305,   306,   311,   312,
     315,   316,   320,   321,   325,   326,   330,   331,   335,   336,
     341,   342,   347,   348,   349,   350,   353,   356,   358,   361,
     362,   366,   368,   371,   374,   377,   378,   381,   382,   386,
     387,   390,   391,   392,   394,   396,   398,   400,   403,   408,
     409,   410,   414,   415,   418,   419,   420,   421,   423,   425,
     430,   431,   434,   435,   436,   440,   441,   443,   444,   448,
     450,   453,   455,   457,   456,   462,   460,   468,   469,   473,
     474,   477,   478,   481,   482,   486,   487,   488,   489,   490,
     491,   494,   496,   498,   499,   502,   504,   508,   509,   513,
     514,   517,   518,   522,   524,   525,   526,   529,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     574,   575,   577,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     599,   601,   603,   607,   613,   616,   617,   620,   620,   623,
     627,   629,   632,   636,   637,   638,   642,   644,   648,   649,
     650,   652,   653,   654,   655,   656,   659,   660,   661,   662,
     663,   665,   668,   672,   673,   674,   675,   676,   677,   678,
     683,   685,   688,   689,   692,   695,   697,   699,   703,   704,
     707,   710,   713,   716,   718,   716,   720,   724,   726,   729,
     733,   735,   739,   740,   744,   750,   751,   754,   755,   757,
     760,   762,   763,   766,   767,   770,   771,   775,   776,   779,
     780,   781,   784,   785,   789,   790,   794,   795,   798,   799,
     800,   804,   806,   809,   811,   812,   813,   814,   817,   819,
     820,   824,   825,   827,   830,   831,   833,   835,   837,   839,
     842,   843,   844,   848,   849,   850,   851,   852,   853,   854,
     858,   859,   863
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
  "T_DOUBLE_CAST", "T_INT_CAST", "T_DEC", "T_INC", "'['", "T_HPHP_NOTE",
  "T_CLONE", "T_NEW", "T_EXIT", "T_IF", "T_ELSEIF", "T_ELSE", "T_ENDIF",
  "T_LNUMBER", "T_DNUMBER", "T_STRING", "T_STRING_VARNAME", "T_VARIABLE",
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
  "T_HPHP_DECLARE", "'('", "')'", "';'", "'{'", "'}'", "'$'", "'`'",
  "'\"'", "'''", "']'", "$accept", "start", "top_statement_list",
  "top_statement", "hphp_declare_list", "hphp_declare",
  "inner_statement_list", "inner_statement", "statement",
  "statement_without_expr", "additional_catches",
  "non_empty_additional_catches", "additional_catch", "unset_variables",
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
  "method_body", "variable_modifiers", "method_modifiers",
  "non_empty_member_modifiers", "member_modifier",
  "class_variable_declaration", "class_constant_declaration",
  "echo_expr_list", "for_expr", "non_empty_for_expr",
  "expr_without_variable", "function_call", "fully_qualified_class_name",
  "class_name_reference", "dynamic_class_name_reference", "@6",
  "object_properties", "dynamic_class_name_variable_prop", "exit_expr",
  "ctor_arguments", "common_scalar", "static_scalar",
  "static_class_constant", "scalar", "static_array_pair_list",
  "possible_comma", "non_empty_static_array_pair_list", "expr",
  "r_variable", "w_variable", "rw_variable", "variable", "@7", "@8",
  "variable_properties", "variable_property", "method_or_not",
  "variable_without_objects", "static_member",
  "base_variable_with_function_calls", "base_variable",
  "reference_variable", "compound_variable", "dim_offset",
  "object_property", "object_dim_list", "variable_name",
  "simple_indirect_reference", "assignment_list", "alist_element",
  "array_pair_list", "non_empty_array_pair_list", "encaps_list",
  "encaps_var", "encaps_var_offset", "internal_functions",
  "isset_variables", "class_constant", 0
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
     161,   162,   162,   163,   163,   164,   165,   165,   166,   167,
     167,   169,   168,   171,   170,   172,   170,   173,   173,   173,
     174,   174,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   179,   180,   180,   181,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   185,   185,   186,   186,   186,   187,
     187,   188,   188,   189,   189,   190,   190,   191,   191,   192,
     192,   193,   193,   193,   193,   193,   193,   193,   193,   194,
     194,   194,   195,   195,   196,   196,   196,   196,   196,   196,
     197,   197,   198,   198,   198,   199,   199,   199,   199,   200,
     200,   201,   201,   202,   201,   203,   201,   204,   204,   205,
     205,   206,   206,   207,   207,   208,   208,   208,   208,   208,
     208,   209,   209,   209,   209,   210,   210,   211,   211,   212,
     212,   213,   213,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     215,   215,   215,   215,   216,   217,   217,   219,   218,   218,
     220,   220,   221,   222,   222,   222,   223,   223,   224,   224,
     224,   224,   224,   224,   224,   224,   225,   225,   225,   225,
     225,   225,   226,   227,   227,   227,   227,   227,   227,   227,
     228,   228,   229,   229,   230,   230,   230,   230,   231,   231,
     232,   233,   234,   236,   237,   235,   235,   238,   238,   239,
     240,   240,   241,   241,   242,   243,   243,   244,   244,   244,
     245,   245,   245,   246,   246,   247,   247,   248,   248,   249,
     249,   249,   250,   250,   251,   251,   252,   252,   253,   253,
     253,   254,   254,   255,   255,   255,   255,   255,   255,   255,
     255,   256,   256,   256,   257,   257,   257,   257,   257,   257,
     258,   258,   258,   259,   259,   259,   259,   259,   259,   259,
     260,   260,   261
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     2,
       4,     3,     3,     1,     2,     1,     2,     0,     1,     1,
       1,     2,     2,     2,     1,     2,     3,     7,    10,     5,
       7,     9,     5,     2,     3,     2,     3,     2,     3,     3,
       3,     3,     3,     5,     1,     1,     8,     8,     5,    13,
       3,     1,     0,     1,     2,     8,     1,     3,     1,     1,
       0,     0,    10,     0,     8,     0,     7,     1,     2,     2,
       2,     0,     2,     0,     2,     0,     1,     3,     2,     0,
       1,     2,     1,     4,     1,     4,     1,     4,     1,     4,
       3,     5,     3,     4,     4,     5,     5,     4,     0,     1,
       1,     6,     0,     7,     0,     2,     0,     3,     0,     1,
       0,     2,     3,     5,     4,     4,     5,     7,     6,     1,
       1,     0,     1,     0,     1,     1,     2,     3,     3,     4,
       3,     1,     1,     2,     4,     3,     5,     1,     3,     2,
       0,     3,     2,     0,     9,     0,    10,     1,     3,     1,
       1,     1,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     5,     1,     3,     5,     4,     3,     1,     1,
       0,     3,     1,     6,     3,     4,     6,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     4,     3,     2,     2,
       4,     4,     6,     6,     1,     1,     1,     0,     5,     1,
       2,     0,     2,     2,     3,     0,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       4,     1,     3,     1,     1,     1,     1,     3,     3,     3,
       2,     0,     1,     0,     5,     3,     3,     1,     1,     1,
       1,     1,     1,     0,     0,     7,     1,     2,     0,     3,
       3,     0,     1,     2,     3,     1,     1,     1,     2,     1,
       4,     4,     1,     1,     4,     1,     0,     1,     1,     4,
       4,     1,     1,     3,     1,     2,     3,     1,     1,     4,
       0,     2,     0,     5,     3,     3,     1,     6,     4,     4,
       2,     2,     2,     0,     1,     4,     3,     3,     6,     3,
       1,     1,     1,     4,     4,     2,     2,     4,     2,     2,
       1,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,   258,
     259,   273,   274,   313,    45,   260,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,   263,   264,   265,   261,   262,   343,     0,     0,    44,
      17,   324,   343,   343,   343,     3,     5,    24,     6,     7,
       0,   289,   306,     0,   276,   235,     0,   288,     0,   290,
       0,   309,   296,   305,   307,   312,     0,   225,   275,     0,
     359,   358,     0,   356,   355,   238,   210,   211,   212,   213,
     234,   232,   231,   230,   229,   228,   227,   226,   244,     0,
     193,   292,   191,    25,     8,     9,   239,   178,   245,     0,
     257,   246,   249,   307,     0,     0,   233,     0,   123,     0,
     168,     0,     0,     0,   170,     0,     0,     0,    33,     0,
      35,     0,    59,     0,    37,   289,     0,   290,    17,     0,
     132,     0,     0,   131,    69,    68,   137,     0,     0,     0,
       0,     0,    65,   330,   332,     0,     0,    15,     0,    13,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,   192,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,   316,     0,   325,   308,     0,     0,     0,   123,   177,
       0,   308,   253,     0,     0,     0,     0,   122,   289,   290,
       0,    42,     0,     0,     0,   169,   172,   289,   290,     0,
       0,     0,    34,    36,    61,    38,    39,     0,    50,     0,
     133,   290,     0,    40,     0,     0,    41,     0,    56,    58,
     360,     0,     0,     0,    75,     0,   328,     0,   327,     0,
     336,     0,   283,   344,   342,   279,     0,     0,   341,    14,
       0,    11,   223,     0,    26,    16,    18,    19,    20,     0,
     237,   277,   278,    71,   362,   304,   302,     0,   196,   198,
     197,     0,   194,   195,   199,   201,   200,   215,   214,   217,
     216,   218,   220,   221,   219,   209,   208,   203,   204,   202,
     205,   206,   207,   222,     0,   174,   189,   188,   187,   186,
     185,   184,   183,   182,   181,   180,   179,     0,     0,   315,
       0,     0,   357,     0,   304,     0,     0,   254,     0,   126,
     291,   240,     0,   167,     0,     0,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,     0,     0,
     267,     0,   266,   138,   271,   135,     0,     0,     0,   353,
     354,    10,     0,     0,   330,   330,     0,   340,     0,   236,
     282,   331,     0,     0,   274,     0,     0,    12,    21,    22,
     314,     0,    73,   123,   123,   303,     0,     0,   175,   241,
     322,     0,   318,   301,   317,   321,   310,   311,   256,   251,
      17,   102,     0,   289,   290,     0,    17,    86,    29,     0,
     171,    79,     0,    79,    80,    90,     0,    17,    88,    48,
      98,    98,    32,   121,     0,   134,   268,   269,     0,   281,
       0,    57,    43,   361,   244,    74,    76,   140,     0,   326,
       0,     0,   335,     0,   334,   350,   352,   351,     0,   346,
       0,   347,   349,    70,     0,     0,     0,     0,   224,   257,
       0,   123,   294,   316,     0,   248,   104,   106,   129,     0,
       0,   170,     0,     0,    81,     0,     0,     0,    98,     0,
      98,     0,   119,   120,     0,   109,     0,     0,   272,   287,
       0,   283,   136,     0,   152,   329,   173,   339,   338,     0,
     345,     0,    72,   140,   242,   243,   176,   323,     0,   298,
       0,     0,     0,   250,   108,     0,     0,    27,    30,     0,
       0,    78,     0,     0,    91,     0,     0,     0,     0,     0,
       0,    92,     0,   121,     0,   111,     0,     0,   270,   282,
     280,    77,   152,     0,   155,   156,   157,   160,   159,   158,
     150,    66,   139,     0,     0,   149,   153,     0,     0,   333,
       0,   152,   300,   295,   319,   320,   252,     0,     0,     0,
       0,   105,    87,     0,    17,    84,    47,    46,    89,     0,
      94,     0,    99,   100,    17,    93,    17,     0,   112,     0,
       0,   286,   285,     0,   151,     0,   163,     0,    60,   154,
       0,   142,   337,   348,    64,     0,   297,     0,    17,     0,
       0,    17,    82,    31,     0,    95,    17,    97,     0,     0,
     115,     0,   114,     0,     0,    60,     0,     0,     0,   141,
       0,     0,   301,     0,   107,    28,     0,     0,     0,    96,
      62,   116,     0,   113,    17,   284,     0,   166,   164,   161,
       0,     0,   299,     0,   101,     0,    85,     0,   118,     0,
       0,     0,   143,   165,    17,    83,   117,    52,   145,   162,
     121,   103,     0,    49,    51,    53,   121,     0,     0,    54,
       0,     0,     0,     0,   147,    17,   144,     0,   146,     0,
       0,   148,    17,     0,    55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    75,   178,   179,   181,   305,   306,    77,
     713,   714,   715,   277,   278,   153,   307,   384,   308,   313,
     284,    80,   422,   495,   403,   475,   513,   453,   653,   616,
     448,   459,   260,   462,   519,   624,   507,   554,   557,   609,
     524,   525,   526,   246,   247,   162,   163,   167,   534,   592,
     710,   716,   726,   593,   594,   595,   596,   637,   597,   139,
     254,   255,    81,    82,    83,   130,   131,   240,   505,   553,
     136,   239,    84,   393,   394,    85,   530,   411,   531,    86,
      87,   369,    88,    89,   230,   549,   603,   646,   502,    90,
      91,    92,    93,    94,    95,   360,   433,   434,   435,    96,
     287,   288,   291,   292,   175,   298,   488,    97,   281,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -612
static const yytype_int16 yypact[] =
{
    -612,   100,  1078,  -612,  4909,  4909,   -92,  4909,  4909,  4909,
    4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,
    4909,  4909,   111,   111,  2496,  4909,   176,   -30,   -24,  -612,
    -612,   -34,  -612,  -612,  -612,  -612,  4909,  3385,   -15,    66,
      82,   109,   112,   765,  3639,    84,  3766,    -8,  4909,   -27,
      46,    57,    98,   115,   124,   129,   131,  -612,    73,   134,
     138,  -612,  -612,  -612,  -612,  -612,  -612,    32,  4909,  -612,
    -612,    47,  -612,  -612,  -612,  -612,  -612,  -612,  -612,  -612,
     210,  -612,  -612,   149,  -612,  -612,   200,  -612,   244,  1008,
     150,  -612,   174,  -612,   -16,  -612,    42,  -612,  -612,  4909,
    4966,  4966,  4909,  4966,  4966,  1212,  -612,  -612,   259,  -612,
    -612,  -612,  -612,  -612,  -612,  -612,  -612,  -612,   159,   170,
    -612,  -612,  -612,  -612,  -612,  -612,  -612,  -612,   172,   190,
     206,  -612,   254,   -32,    42,  3893,  -612,  4909,  4020,     9,
    4966,  3512,   233,  4909,  4909,  4909,   260,  4909,  -612,  4459,
    -612,  4586,  -612,   270,  -612,   229,  4966,   578,  -612,  4713,
    -612,   -26,    12,  -612,  -612,  -612,   366,    14,   111,   111,
     111,   243,  -612,   198,  4147,   298,   318,  -612,    15,  -612,
    5093,  1226,  4909,   195,   276,    49,  -612,   207,  4909,  4909,
    4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,
    4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,
    4909,  4909,  4909,   176,  -612,  -612,  -612,  4274,  4909,  4909,
    4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,  4909,  4020,
     277,  4909,  4909,    47,    -7,  5164,   211,    51,  4020,  -612,
     281,   -32,  -612,  5210,  5251,   111,   263,   395,    22,    71,
    4909,  -612,   266,  5292,   265,   403,  4966,   321,   774,   404,
      23,  5333,  -612,  -612,  -612,  -612,  -612,  1353,  -612,  4909,
    -612,  -612,   -27,  -612,   235,   347,  -612,    25,  -612,  -612,
    -612,    26,   284,   288,   309,   287,  -612,    33,  -612,   111,
    5497,   290,   430,    21,  -612,  -612,  5036,   111,  -612,  -612,
      32,  -612,  -612,  2496,  -612,  -612,  -612,  -612,  -612,   933,
    -612,  -612,  -612,   320,   299,   300,   -32,    42,  5593,  5634,
    1212,  4839,  5679,   631,  5699,  1066,  1345,  1472,  1472,  1472,
    1472,  1595,  1595,  1595,  1595,   525,   525,   377,   377,   377,
     259,   259,   259,  -612,    37,  1212,  1212,  1212,  1212,  1212,
    1212,  1212,  1212,  1212,  1212,  1212,  1212,   297,   108,  4966,
     293,  3696,  -612,   299,  -612,   302,   108,  -612,  2750,  -612,
    -612,  -612,  4401,  4966,  4909,  2877,  4909,  4909,   111,    50,
     235,   374,  3004,    -1,   305,   346,  3823,  -612,   235,   235,
     310,   312,  -612,  -612,  -612,   438,   111,   308,   111,  -612,
    -612,  -612,   383,   311,   198,   198,   444,  -612,  4528,  -612,
    4655,  -612,   212,   386,   401,  3950,   317,  -612,  -612,  -612,
    -612,   383,   344,  4020,  4020,   -32,  4909,   176,  -612,  -612,
    -612,  4909,  -612,   325,   -12,  -612,  -612,  -612,  -612,  -612,
    -612,  -612,   111,    34,   478,  5374,  -612,  -612,  -612,   324,
    4966,   349,   111,   349,  -612,  -612,   456,  -612,  -612,  -612,
     335,   337,  -612,    62,   341,  -612,  -612,  -612,   412,   235,
     235,  -612,  -612,  -612,  -612,   477,  -612,  -612,    35,  -612,
    4909,   111,  4966,   111,  5538,  -612,  -612,  -612,   336,  -612,
    4909,  -612,  -612,  -612,   383,   343,   360,   363,  5657,   206,
    4077,  4020,  -612,  4909,  4909,   368,  2623,   252,  -612,   364,
    1480,  4909,    50,   372,  -612,   388,   235,  1607,  -612,   232,
    -612,    55,  -612,  -612,   393,   501,   121,   383,  -612,   417,
     398,   502,  -612,   383,   153,  -612,  1212,  -612,  -612,  4782,
    -612,    28,   477,  -612,  -612,  -612,  -612,  -612,   399,  -612,
     392,  4204,   108,  -612,   272,   402,  3385,  -612,  -612,   410,
     413,  -612,  3131,  3131,  -612,   414,   258,   418,  4909,    18,
     241,  -612,   416,    30,   489,   551,   499,   235,  -612,   235,
    -612,  -612,   440,   503,  -612,  -612,  -612,  -612,  -612,  -612,
    -612,  -612,  -612,   504,   481,   367,  -612,    16,   111,  4966,
     434,   285,  -612,   461,  -612,  -612,  -612,   441,   558,   516,
    4909,  -612,  -612,  3258,  -612,  -612,  -612,  -612,  -612,   442,
    -612,  4332,  -612,  -612,  -612,  -612,  -612,   144,   574,   235,
     446,  -612,   468,   505,   440,   591,   592,    20,    84,  -612,
     534,  -612,  -612,  -612,  -612,   108,  -612,  4909,  -612,   463,
    5415,  -612,  -612,  -612,  1734,  -612,  -612,  2623,  1861,   535,
     597,   235,  -612,   467,   235,    84,   235,   235,   539,  -612,
     542,   602,   325,  5456,  2623,  -612,  3385,  1988,   473,  2623,
    -612,   605,   235,  -612,  -612,  -612,   547,  -612,  -612,   607,
     480,   235,  -612,   598,  -612,   479,  -612,   235,  -612,  2115,
     484,   235,  -612,  -612,  -612,  -612,  -612,   527,  -612,  -612,
      62,  2623,   485,  -612,   527,  -612,    62,   487,   383,  -612,
     488,   221,   559,   221,  -612,  -612,  -612,   491,  -612,  2242,
     494,  -612,  -612,  2369,  -612
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -612,  -612,  -612,  -612,  -612,   332,  -144,  -612,     3,    -5,
    -612,  -612,   -74,  -612,   245,  -558,     8,  -612,    11,  -612,
    -612,  -612,  -612,  -612,  -612,   148,   192,   136,  -612,    80,
    -612,  -612,  -612,  -612,  -363,    36,  -612,  -612,  -612,  -612,
    -611,  -612,    76,  -211,  -612,  -612,   379,  -612,   139,  -612,
    -612,  -612,   -68,  -612,    99,   102,  -517,  -612,  -612,  -612,
    -340,  -612,   -35,  -612,   -22,  -201,  -612,  -612,  -612,  -612,
    -612,   186,  -248,  -373,  -612,  -612,  -612,   127,  -612,   509,
     526,  -281,   378,   613,  -612,  -612,  -612,  -612,    17,  -185,
    -612,  -612,   -23,   -20,  -612,   183,  -345,  -612,  -612,   -17,
     286,   283,  -612,  -612,   296,  -612,  -612,  -612,  -612,  -612
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -304
static const yytype_int16 yytable[] =
{
     119,   119,   315,   132,   129,    76,   133,   455,   407,   134,
      78,   155,   343,    79,   267,   466,   467,   250,   357,   123,
     272,   439,   275,   300,   640,   460,   392,   365,   668,   231,
    -124,   381,   124,   396,   398,   125,   449,   188,   189,   190,
     142,   405,  -127,   405,   622,   231,   118,   160,    33,   503,
     102,   315,   364,   191,   231,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   234,   213,   639,  -125,
     670,   452,   412,   176,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   529,   532,   521,   717,
       3,   427,   522,   248,   177,   720,  -244,   686,   138,   118,
     257,    33,   135,   232,   241,   152,    33,   639,   137,   269,
     161,    71,   118,   293,    33,    33,  -302,   143,   294,   232,
    -292,  -292,   392,   504,   522,  -303,   123,   158,   232,   119,
     392,   392,   413,   564,   461,   172,   119,   119,   119,   568,
     569,   119,   574,   251,   523,   566,   273,   570,   276,   301,
     641,   508,   623,   164,   669,  -124,   382,   316,   397,   399,
     317,   560,   166,   432,   165,   659,   406,  -127,   535,   600,
     430,   432,    33,   118,    71,    33,   523,   296,   297,   233,
     132,   129,   182,   133,   248,   575,   134,    71,    71,   312,
     537,   571,   538,   248,   631,  -110,   632,   606,   144,   188,
     189,   190,   496,   497,  -125,   582,   316,   316,   660,   317,
     317,   392,   392,   119,   145,   191,   499,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   128,   213,
      33,   146,   583,   431,   147,    71,   662,   168,    71,   584,
     585,   586,   587,   588,   589,   590,   169,   119,   392,   293,
     118,   170,    33,   171,   294,   119,   173,   388,   389,   314,
     174,    33,   186,   363,   485,    33,   486,   487,   683,   187,
     548,   685,   229,   687,   688,  -293,   506,   425,   123,   591,
     672,   138,   510,   215,   216,    29,    30,   390,   213,   698,
     236,   418,  -244,   517,   419,    35,   252,   642,   703,   555,
     556,   285,   119,    71,   706,   567,   568,   569,   709,   392,
     237,   392,   259,   296,   297,   568,   569,   443,   316,   607,
     608,   317,   264,   310,   214,    71,   316,   582,   238,   317,
     293,   619,   568,   569,    71,   294,   119,   119,    71,   391,
      61,    62,    63,    64,    65,   724,   725,   432,   183,   184,
     185,   441,   293,   265,   119,  -247,   119,   294,   447,   274,
     476,   392,   119,   119,   583,   458,   283,   625,   248,   248,
     299,   584,   585,   586,   587,   588,   589,   590,   358,   493,
     120,   122,   366,   372,   132,   129,   371,   133,   374,   376,
     134,   377,   378,   392,   296,   297,   392,   380,   392,   392,
     119,   395,   210,   211,   212,   311,   213,   400,   402,   404,
     119,   644,   401,   409,   392,   295,   296,   297,   410,   421,
     429,   423,   424,   392,   436,   438,   456,   463,   464,   392,
     468,   470,   472,   392,   469,   474,   477,   480,   489,   119,
     432,   119,   490,   492,   494,  -151,   248,   501,   511,   516,
     654,   512,   476,   584,   585,   586,   587,   588,   589,   518,
     657,   520,   658,   527,   528,   533,  -128,   540,   543,   552,
     119,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   544,   674,   576,   545,   677,   558,   573,
     579,   581,   679,   100,   101,   562,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   563,   316,   126,   127,   317,   572,  -292,  -292,   577,
     699,   578,   602,   604,   610,   140,   584,   585,   586,   587,
     588,   589,   149,   151,   612,   156,   613,   159,   618,   611,
     711,   626,   620,   628,   629,   615,   615,   207,   208,   209,
     210,   211,   212,   630,   213,   635,   119,   180,   636,   638,
     643,   729,   645,   647,   648,   649,   655,   661,   733,   663,
     664,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   665,   666,   667,   671,   675,   126,   681,
     682,   235,   684,   689,   690,   691,   652,   696,   697,   700,
     701,  -128,   702,   705,   704,   316,   708,   718,   317,   712,
     721,   723,   417,   727,   730,   121,   121,  -292,  -292,   732,
     719,   471,   542,   617,   243,   515,   244,   156,   561,   627,
     126,   387,   253,   256,   156,   728,   261,   656,   580,   157,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   694,
     213,   633,   601,   290,   634,   546,   550,   270,   479,   692,
     478,   309,     0,     0,     0,     0,   722,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   266,     0,     0,     0,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   156,     0,
     359,   361,     0,     0,     0,     0,     0,   156,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,   258,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,     7,     8,     0,   271,     0,     0,     9,   386,     0,
       0,   279,   280,   282,     0,     0,   286,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,     0,
       0,     0,     0,     0,     0,   415,     0,    10,    11,     0,
       0,     0,   126,    12,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    99,    25,    26,
      27,     0,     0,  -292,  -292,    29,    30,    31,    32,    33,
       0,     0,   249,     0,     0,    35,     0,     0,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,   370,     0,
       0,     0,     0,     0,     0,   379,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      55,   156,     0,   445,     0,   256,   450,     0,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,    66,   370,     0,     0,     0,     0,    68,     0,   148,
     416,     0,    71,    72,    73,    74,     0,   482,     0,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   156,   156,     0,   498,     0,     0,     0,     0,
     500,     0,   188,   189,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   428,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,   213,     0,     0,   444,     0,     0,     0,   536,
       0,   451,   454,     0,     0,     0,     0,     0,     0,   541,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   279,
     156,   473,   359,   551,     0,     0,     0,   286,   286,     0,
     256,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,     0,     0,     0,   249,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,   370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   514,     0,  -292,  -292,     0,
       0,     0,     0,     0,     0,     0,     0,   621,     0,   420,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,     0,   370,     0,   370,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   249,   213,     0,     0,     0,   650,
      10,    11,     0,     0,     0,   454,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      24,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,     0,    34,     0,   673,     0,    35,    36,
      37,    38,     0,    39,     0,    40,     0,    41,     0,     0,
      42,     0,     0,     0,    43,    44,    45,     0,    46,    47,
       0,    48,     0,    49,     0,     0,     0,    50,    51,    52,
       0,    53,    54,    55,    56,    57,    58,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,   370,     0,     0,    66,     0,     0,     0,     0,    67,
      68,     0,    69,    70,     0,    71,    72,    73,    74,     4,
       5,     6,     7,     8,     0,     0,     0,   191,     9,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,   303,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
       0,    39,     0,    40,     0,    41,     0,     0,    42,     0,
       0,     0,    43,    44,    45,     0,    46,    47,     0,    48,
       0,    49,     0,     0,     0,    50,    51,    52,     0,    53,
      54,    55,     0,    57,    58,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,     4,     5,     6,     7,
       8,     0,    66,     0,     0,     9,     0,     0,    68,     0,
      69,    70,   304,    71,    72,    73,    74,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,   303,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    32,    33,     0,    34,
       0,     0,     0,    35,    36,    37,    38,     0,    39,     0,
      40,     0,    41,     0,     0,    42,     0,     0,     0,    43,
      44,    45,     0,    46,    47,     0,    48,     0,    49,     0,
       0,     0,    50,    51,    52,     0,    53,    54,    55,     0,
      57,    58,     0,     0,     0,     0,    59,    60,    61,    62,
      63,    64,    65,     4,     5,     6,     7,     8,     0,    66,
       0,     0,     9,     0,     0,    68,     0,    69,    70,   385,
      71,    72,    73,    74,  -304,  -304,  -304,  -304,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,   303,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,   559,    39,     0,    40,     0,    41,
       0,     0,    42,     0,     0,     0,    43,    44,    45,     0,
      46,    47,     0,    48,     0,    49,     0,     0,     0,    50,
      51,    52,     0,    53,    54,    55,     0,    57,    58,     0,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    65,
       4,     5,     6,     7,     8,     0,    66,     0,     0,     9,
       0,     0,    68,     0,    69,    70,     0,    71,    72,    73,
      74,  -304,  -304,  -304,  -304,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,   303,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
      32,    33,     0,    34,     0,     0,     0,    35,    36,    37,
      38,     0,    39,     0,    40,     0,    41,   565,     0,    42,
       0,     0,     0,    43,    44,    45,     0,    46,    47,     0,
      48,     0,    49,     0,     0,     0,    50,    51,    52,     0,
      53,    54,    55,     0,    57,    58,     0,     0,     0,     0,
      59,    60,    61,    62,    63,    64,    65,     4,     5,     6,
       7,     8,     0,    66,     0,     0,     9,     0,     0,    68,
       0,    69,    70,     0,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,   303,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,     0,    39,
       0,    40,   678,    41,     0,     0,    42,     0,     0,     0,
      43,    44,    45,     0,    46,    47,     0,    48,     0,    49,
       0,     0,     0,    50,    51,    52,     0,    53,    54,    55,
       0,    57,    58,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    65,     4,     5,     6,     7,     8,     0,
      66,     0,     0,     9,     0,     0,    68,     0,    69,    70,
       0,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,   303,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,    45,
       0,    46,    47,     0,    48,     0,    49,     0,     0,     0,
      50,    51,    52,     0,    53,    54,    55,     0,    57,    58,
       0,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     4,     5,     6,     7,     8,     0,    66,     0,     0,
       9,     0,     0,    68,     0,    69,    70,   680,    71,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
     303,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,     0,    34,     0,     0,     0,    35,    36,
      37,    38,     0,    39,   695,    40,     0,    41,     0,     0,
      42,     0,     0,     0,    43,    44,    45,     0,    46,    47,
       0,    48,     0,    49,     0,     0,     0,    50,    51,    52,
       0,    53,    54,    55,     0,    57,    58,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    65,     4,     5,
       6,     7,     8,     0,    66,     0,     0,     9,     0,     0,
      68,     0,    69,    70,     0,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,   303,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,     0,
      39,     0,    40,     0,    41,     0,     0,    42,     0,     0,
       0,    43,    44,    45,     0,    46,    47,     0,    48,     0,
      49,     0,     0,     0,    50,    51,    52,     0,    53,    54,
      55,     0,    57,    58,     0,     0,     0,     0,    59,    60,
      61,    62,    63,    64,    65,     4,     5,     6,     7,     8,
       0,    66,     0,     0,     9,     0,     0,    68,     0,    69,
      70,   707,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,   303,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,     0,    39,     0,    40,
       0,    41,     0,     0,    42,     0,     0,     0,    43,    44,
      45,     0,    46,    47,     0,    48,     0,    49,     0,     0,
       0,    50,    51,    52,     0,    53,    54,    55,     0,    57,
      58,     0,     0,     0,     0,    59,    60,    61,    62,    63,
      64,    65,     4,     5,     6,     7,     8,     0,    66,     0,
       0,     9,     0,     0,    68,     0,    69,    70,   731,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,   303,    25,    26,    27,    28,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,     0,     0,    35,
      36,    37,    38,     0,    39,     0,    40,     0,    41,     0,
       0,    42,     0,     0,     0,    43,    44,    45,     0,    46,
      47,     0,    48,     0,    49,     0,     0,     0,    50,    51,
      52,     0,    53,    54,    55,     0,    57,    58,     0,     0,
       0,     0,    59,    60,    61,    62,    63,    64,    65,     4,
       5,     6,     7,     8,     0,    66,     0,     0,     9,     0,
       0,    68,     0,    69,    70,   734,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    99,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
       0,    39,     0,    40,     0,    41,     0,     0,    42,     0,
       0,     0,    43,    44,    45,     0,    46,    47,     0,    48,
       0,    49,     0,     0,     0,    50,    51,    52,     0,    53,
      54,    55,     0,    57,    58,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,     4,     5,     6,     7,
       8,     0,    66,     0,     0,     9,     0,     0,    68,     0,
      69,    70,     0,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,   303,    25,    26,    27,    28,
       0,     0,     0,    29,    30,    31,    32,    33,     0,    34,
       0,     0,     0,    35,    36,    37,    38,     0,    39,     0,
      40,     0,    41,     0,     0,    42,     0,     0,     0,    43,
      44,    45,     0,    46,    47,     0,    48,     0,    49,     0,
       0,     0,    50,    51,    52,     0,    53,    54,    55,     0,
      57,    58,     0,     0,     0,     0,    59,    60,    61,    62,
      63,    64,    65,     4,     5,     6,     7,     8,     0,    66,
       0,     0,     9,     0,     0,    68,     0,    69,    70,     0,
      71,    72,    73,    74,     0,     0,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,   141,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,     0,    39,     0,    40,     0,    41,
       0,     0,    42,     0,     0,     0,    43,    44,     0,     0,
      46,    47,     0,    48,     0,    49,     0,     0,     0,     0,
       0,    52,     0,    53,    54,    55,     0,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    65,
       4,     5,     6,     7,     8,     0,    66,     0,     0,     9,
       0,     0,    68,     0,    69,    70,     0,    71,    72,    73,
      74,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,   141,
      25,    26,    27,    28,     0,     0,     0,    29,    30,    31,
      32,    33,     0,    34,     0,     0,     0,    35,    36,    37,
      38,     0,    39,     0,    40,     0,    41,     0,     0,    42,
       0,     0,     0,    43,    44,     0,     0,    46,    47,     0,
      48,     0,    49,     0,     0,     0,     0,     0,    52,     0,
      53,    54,    55,     0,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,    64,    65,     4,     5,     6,
       7,     8,     0,    66,     0,     0,     9,     0,     0,    68,
       0,    69,    70,     0,    71,    72,    73,    74,     0,     0,
     457,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,   141,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,     0,    39,
       0,    40,     0,    41,     0,     0,    42,     0,     0,     0,
      43,    44,     0,     0,    46,    47,     0,    48,     0,    49,
       0,     0,     0,     0,     0,    52,     0,    53,    54,    55,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    65,     4,     5,     6,     7,     8,     0,
      66,     0,     0,     9,     0,     0,    68,     0,    69,    70,
       0,    71,    72,    73,    74,     0,     0,   614,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,   141,    25,    26,    27,    28,     0,     0,
       0,    29,    30,    31,    32,    33,     0,    34,     0,     0,
       0,    35,    36,    37,    38,     0,    39,     0,    40,     0,
      41,     0,     0,    42,     0,     0,     0,    43,    44,     0,
       0,    46,    47,     0,    48,     0,    49,     0,     0,     0,
       0,     0,    52,     0,    53,    54,    55,     0,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     4,     5,     6,     7,     8,     0,    66,     0,     0,
       9,     0,     0,    68,     0,    69,    70,     0,    71,    72,
      73,    74,     0,     0,   651,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
     141,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,     0,    34,     0,     0,     0,    35,    36,
      37,    38,     0,    39,     0,    40,     0,    41,     0,     0,
      42,     0,     0,     0,    43,    44,     0,     0,    46,    47,
       0,    48,     0,    49,     0,     0,     0,     0,     0,    52,
       0,    53,    54,    55,     0,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    65,     4,     5,
       6,     7,     8,     0,    66,     0,     0,     9,     0,     0,
      68,     0,    69,    70,     0,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,   141,    25,    26,
      27,    28,     0,     0,     0,    29,    30,    31,    32,    33,
       0,    34,     0,     0,     0,    35,    36,    37,    38,     0,
      39,     0,    40,     0,    41,     0,     0,    42,     0,     0,
       0,    43,    44,     0,     0,    46,    47,     0,    48,     0,
      49,     0,     0,     0,     0,     0,    52,     0,    53,    54,
      55,     0,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,    64,    65,     4,     5,     6,     7,     8,
       0,    66,     0,     0,     9,     0,     0,    68,     0,    69,
      70,     0,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    99,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,     0,    39,     0,    40,
       0,    41,     0,     0,    42,     0,     0,     0,    43,    44,
       0,     0,    46,    47,     0,    48,     0,    49,     0,     0,
       0,     0,     0,    52,     0,    53,    54,    55,     0,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
      64,    65,     4,     5,     6,     7,     8,     0,    66,     0,
       0,     9,     0,     0,    68,     0,    69,    70,     0,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,    99,    25,    26,    27,   188,   189,   190,     0,    29,
      30,    31,    32,    33,     0,     0,     0,     0,     0,    35,
       0,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,   213,     0,     0,     0,     0,
       0,     0,     0,    54,    55,     0,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,    64,    65,     4,
       5,     6,     7,     8,     0,    66,     0,     0,     9,     0,
       0,    68,     0,   150,     0,     0,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    99,    25,
      26,    27,   188,   189,   190,     0,    29,    30,    31,    32,
      33,     0,   437,     0,     0,     0,    35,     0,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,   213,     0,     0,     0,     0,     0,     0,     0,
      54,    55,     0,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,     4,     5,     6,     7,
       8,     0,    66,     0,     0,     9,     0,     0,    68,     0,
     154,     0,     0,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     0,    99,    25,    26,    27,   188,
     189,   190,     0,    29,    30,    31,    32,    33,     0,   465,
       0,     0,     0,    35,     0,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,   213,
       0,     0,     0,     0,     0,     0,     0,    54,    55,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      63,    64,    65,     4,     5,     6,     7,     8,     0,    66,
       0,     0,     9,     0,     0,    68,   242,     0,     0,     0,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
       0,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     0,    99,    25,    26,    27,   188,   189,   190,     0,
      29,    30,    31,    32,    33,     0,   491,     0,     0,     0,
      35,     0,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,     0,   213,     0,     0,     0,
       0,     0,     0,     0,    54,    55,     0,     0,     0,     0,
       0,     0,     0,    59,    60,    61,    62,    63,    64,    65,
       4,     5,     6,     7,     8,     0,    66,     0,     0,     9,
       0,     0,    68,     0,     0,     0,     0,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,    99,
      25,    26,    27,   188,   189,   190,     0,    29,    30,    31,
      32,    33,     0,   547,     0,     0,     0,    35,     0,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,     0,     0,     0,     0,     0,     0,
       0,    54,    55,     0,     0,     0,     0,     0,     0,     0,
      59,    60,    61,    62,    63,    64,    65,     4,     5,     6,
       7,     8,     0,    66,     0,     0,     9,     0,     0,    68,
       0,     0,     0,     0,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,   344,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     0,    99,    25,    26,    27,
       0,   188,   189,   190,    29,    30,    31,    32,    33,     0,
     605,     0,     0,     0,    35,     0,     0,   191,   622,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,     0,     0,     0,     0,     0,     0,    54,    55,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    63,    64,    65,     4,     5,     6,     7,     8,     0,
      66,     0,     0,     9,     0,     0,    68,     0,     0,     0,
       0,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,    12,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     0,    99,    25,    26,    27,     0,   188,   189,
     190,    29,    30,    31,    32,    33,   623,     0,     0,     0,
       0,    35,     0,     0,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,     0,
       0,     0,     0,     0,     0,    54,    55,     0,     0,     0,
       0,     0,     0,     0,    59,    60,    61,    62,    63,    64,
      65,     4,     5,     6,     7,     8,     0,    66,     0,     0,
       9,     0,     0,    68,     0,     0,     0,     0,    71,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,   481,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     0,
      99,    25,    26,    27,     0,   188,   189,   190,    29,    30,
      31,    32,    33,   262,     0,     0,     0,     0,    35,     0,
       0,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,   213,     0,     0,     0,     0,
       0,     0,    54,    55,     0,     0,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    64,    65,     4,     5,
       6,     7,     8,     0,    66,     0,     0,     9,     0,     0,
      68,     0,     0,     0,     0,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,     0,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,    99,    25,    26,
      27,     0,   188,   189,   190,    29,    30,    31,    32,    33,
     263,     0,     0,     0,     0,    35,     0,     0,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,   213,     0,     0,     0,     0,     0,     0,    54,
      55,     0,     0,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,    64,    65,     4,     5,     6,     7,     8,
       0,    66,     0,     0,     9,     0,     0,    68,     0,     0,
       0,     0,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     0,    99,    25,    26,    27,   188,   189,
     190,     0,    29,    30,    31,    32,    33,   268,     0,     0,
       0,     0,    35,     0,   191,   426,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,     0,
       0,     0,     0,     0,     0,     0,    54,    55,     0,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
      64,    65,     4,     5,     6,     7,     8,     0,    66,     0,
       0,     9,     0,     0,    68,     0,     0,     0,     0,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       0,    99,    25,    26,    27,   188,   189,   190,     0,    29,
      30,    31,    32,    33,     0,     0,     0,     0,     0,    35,
       0,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,   213,     0,     0,     0,     0,
       0,     0,     0,    54,    55,     0,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,    64,    65,     4,
       5,     6,     7,     8,     0,    66,     0,     0,     9,     0,
       0,    68,     0,     0,     0,     0,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
       0,     0,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     0,    99,    25,
      26,    27,   188,   189,   190,     0,    29,    30,    31,   414,
      33,     0,     0,     0,     0,     0,    35,     0,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,   213,     0,     0,     0,     0,     0,     0,     0,
      54,    55,     0,     0,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,    66,   188,   189,   190,     0,     0,    68,     0,
       0,     0,     0,    71,    72,    73,    74,     0,     0,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,     0,     0,     0,     0,     0,   188,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   302,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,   213,
     188,   189,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
     213,   188,   189,   190,     0,     0,     0,   362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,   188,   189,   190,     0,     0,     0,     0,     0,
       0,     0,     0,   367,     0,     0,     0,     0,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,   213,   188,   189,   190,     0,     0,     0,     0,
       0,     0,     0,     0,   368,     0,     0,     0,     0,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,   188,   189,   190,     0,     0,     0,
       0,     0,     0,     0,     0,   375,     0,     0,     0,     0,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     0,   213,   188,   189,   190,     0,     0,
       0,     0,     0,     0,     0,     0,   383,     0,     0,     0,
       0,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,   213,   188,   189,   190,     0,
       0,     0,     0,     0,     0,     0,     0,   509,     0,     0,
       0,     0,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,     0,   213,   188,   189,   190,
       0,     0,     0,     0,     0,     0,     0,     0,   676,     0,
       0,     0,     0,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   693,
       0,     0,     0,   189,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   408,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,   213,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     539,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,     0,   213,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,   213
};

static const yytype_int16 yycheck[] =
{
      22,    23,   187,    26,    26,     2,    26,   380,   289,    26,
       2,    46,   213,     2,   158,   388,   389,     8,   229,    24,
       8,   366,     8,     8,     8,    26,   274,   238,     8,    61,
       8,     8,    24,     8,     8,    24,   376,     9,    10,    11,
      37,     8,     8,     8,    26,    61,    72,    74,    74,    61,
     142,   236,   237,    25,    61,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    96,    49,   595,     8,
     638,    31,    61,    51,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   469,   470,   461,   710,
       0,    64,    72,   138,    72,   716,   140,   665,   142,    72,
     145,    74,   142,   145,   134,    31,    74,   634,   142,   145,
     147,   147,    72,    74,    74,    74,   142,   142,    79,   145,
      59,    60,   380,   145,    72,   142,   141,   145,   145,   161,
     388,   389,   121,   516,   145,    72,   168,   169,   170,    94,
      95,   173,    31,   144,   124,   518,   144,   520,   144,   144,
     144,   442,   144,   117,   144,   143,   143,   187,   143,   143,
     187,   511,    74,   358,   117,    31,   143,   143,   143,   151,
      72,   366,    74,    72,   147,    74,   124,   138,   139,   147,
     213,   213,   145,   213,   229,    74,   213,   147,   147,   150,
     481,   146,   483,   238,   577,   143,   579,   552,   142,     9,
      10,    11,   423,   424,   143,    62,   236,   237,    74,   236,
     237,   469,   470,   245,   142,    25,   427,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    72,    49,
      74,   142,    99,   145,   142,   147,   629,   142,   147,   106,
     107,   108,   109,   110,   111,   112,   142,   289,   516,    74,
      72,   142,    74,   142,    79,   297,   142,    42,    43,    72,
     142,    74,    72,    72,    72,    74,    74,    75,   661,   140,
     501,   664,   142,   666,   667,   121,   440,   317,   303,   146,
     645,   142,   446,    59,    60,    70,    71,    72,    49,   682,
     140,   303,   140,   457,   303,    80,    83,   598,   691,    67,
      68,   123,   344,   147,   697,    93,    94,    95,   701,   577,
     140,   579,    72,   138,   139,    94,    95,   372,   358,    67,
      68,   358,    72,   148,   144,   147,   366,    62,   142,   366,
      74,    93,    94,    95,   147,    79,   378,   379,   147,   124,
     125,   126,   127,   128,   129,   144,   145,   552,    72,    73,
      74,   368,    74,   144,   396,   121,   398,    79,   375,    13,
     402,   629,   404,   405,    99,   382,   143,   146,   423,   424,
      72,   106,   107,   108,   109,   110,   111,   112,   121,   421,
      22,    23,   121,     8,   427,   427,   143,   427,   142,   144,
     427,     8,    91,   661,   138,   139,   664,    13,   666,   667,
     442,    74,    45,    46,    47,   149,    49,   143,   119,   142,
     452,   146,   144,   143,   682,   137,   138,   139,     8,   119,
     143,   142,   142,   691,   151,   143,    72,   142,   102,   697,
     140,    13,   144,   701,   142,    72,   145,    13,    72,   481,
     645,   483,    61,   146,   120,    98,   501,   142,   144,    13,
     614,   122,   494,   106,   107,   108,   109,   110,   111,   144,
     624,   144,   626,   142,    72,     8,     8,   151,   145,   121,
     512,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   143,   648,   527,   143,   651,   144,     8,
       8,   533,   656,     4,     5,   143,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   143,   552,    24,    25,   552,   143,    59,    60,   122,
     684,   143,   143,   151,   142,    36,   106,   107,   108,   109,
     110,   111,    43,    44,   144,    46,   143,    48,   144,   556,
     704,   145,   144,    74,    13,   562,   563,    42,    43,    44,
      45,    46,    47,    74,    49,    72,   598,    68,    74,    98,
     146,   725,   121,   142,    26,    69,   144,    13,   732,   143,
     122,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    98,    13,    13,    72,   144,    99,    74,
      13,   102,   145,    74,    72,    13,   613,   144,    13,    72,
      13,   143,   142,   144,    26,   645,   142,   142,   645,   102,
     143,   143,   300,    74,   143,    22,    23,    59,    60,   145,
     714,   396,   494,   563,   135,   453,   137,   138,   512,   573,
     141,   272,   143,   144,   145,   723,   147,   621,   531,    46,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,   676,
      49,   582,   543,   174,   582,   499,   503,   161,   405,   672,
     404,   182,    -1,    -1,    -1,    -1,   718,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   144,    -1,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,    -1,
     231,   232,    -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   145,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,   161,    -1,    -1,    12,   269,    -1,
      -1,   168,   169,   170,    -1,    -1,   173,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,   296,    -1,    42,    43,    -1,
      -1,    -1,   303,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    -1,    59,    60,    70,    71,    72,    73,    74,
      -1,    -1,   229,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,   372,    -1,   374,    -1,   376,   377,    -1,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   289,    -1,    -1,    -1,    -1,   142,    -1,   144,
     297,    -1,   147,   148,   149,   150,    -1,   408,    -1,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   423,   424,    -1,   426,    -1,    -1,    -1,    -1,
     431,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,   372,    -1,    -1,    -1,   480,
      -1,   378,   379,    -1,    -1,    -1,    -1,    -1,    -1,   490,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
     501,   398,   503,   504,    -1,    -1,    -1,   404,   405,    -1,
     511,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,   423,   424,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,    -1,
      -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   452,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   568,    -1,   146,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,   481,    -1,   483,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   501,    49,    -1,    -1,    -1,   610,
      42,    43,    -1,    -1,    -1,   512,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,   647,    -1,    80,    81,
      82,    83,    -1,    85,    -1,    87,    -1,    89,    -1,    -1,
      92,    -1,    -1,    -1,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,   598,    -1,    -1,   136,    -1,    -1,    -1,    -1,   141,
     142,    -1,   144,   145,    -1,   147,   148,   149,   150,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    25,    12,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,
      -1,    85,    -1,    87,    -1,    89,    -1,    -1,    92,    -1,
      -1,    -1,    96,    97,    98,    -1,   100,   101,    -1,   103,
      -1,   105,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,   117,   118,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,     3,     4,     5,     6,
       7,    -1,   136,    -1,    -1,    12,    -1,    -1,   142,    -1,
     144,   145,   146,   147,   148,   149,   150,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    -1,    76,
      -1,    -1,    -1,    80,    81,    82,    83,    -1,    85,    -1,
      87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,     3,     4,     5,     6,     7,    -1,   136,
      -1,    -1,    12,    -1,    -1,   142,    -1,   144,   145,   146,
     147,   148,   149,   150,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,
      80,    81,    82,    83,    84,    85,    -1,    87,    -1,    89,
      -1,    -1,    92,    -1,    -1,    -1,    96,    97,    98,    -1,
     100,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,   109,
     110,   111,    -1,   113,   114,   115,    -1,   117,   118,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,   127,   128,   129,
       3,     4,     5,     6,     7,    -1,   136,    -1,    -1,    12,
      -1,    -1,   142,    -1,   144,   145,    -1,   147,   148,   149,
     150,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    85,    -1,    87,    -1,    89,    90,    -1,    92,
      -1,    -1,    -1,    96,    97,    98,    -1,   100,   101,    -1,
     103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,    -1,
     113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,     3,     4,     5,
       6,     7,    -1,   136,    -1,    -1,    12,    -1,    -1,   142,
      -1,   144,   145,    -1,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    -1,
      76,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    85,
      -1,    87,    88,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    97,    98,    -1,   100,   101,    -1,   103,    -1,   105,
      -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,   115,
      -1,   117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,     3,     4,     5,     6,     7,    -1,
     136,    -1,    -1,    12,    -1,    -1,   142,    -1,   144,   145,
      -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    -1,    76,    -1,    -1,
      -1,    80,    81,    82,    83,    -1,    85,    -1,    87,    -1,
      89,    -1,    -1,    92,    -1,    -1,    -1,    96,    97,    98,
      -1,   100,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,
     109,   110,   111,    -1,   113,   114,   115,    -1,   117,   118,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,   128,
     129,     3,     4,     5,     6,     7,    -1,   136,    -1,    -1,
      12,    -1,    -1,   142,    -1,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    83,    -1,    85,    86,    87,    -1,    89,    -1,    -1,
      92,    -1,    -1,    -1,    96,    97,    98,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,   111,
      -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,     3,     4,
       5,     6,     7,    -1,   136,    -1,    -1,    12,    -1,    -1,
     142,    -1,   144,   145,    -1,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,    -1,
      85,    -1,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    96,    97,    98,    -1,   100,   101,    -1,   103,    -1,
     105,    -1,    -1,    -1,   109,   110,   111,    -1,   113,   114,
     115,    -1,   117,   118,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,     3,     4,     5,     6,     7,
      -1,   136,    -1,    -1,    12,    -1,    -1,   142,    -1,   144,
     145,   146,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    -1,    76,    -1,
      -1,    -1,    80,    81,    82,    83,    -1,    85,    -1,    87,
      -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,    97,
      98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,    -1,
      -1,   109,   110,   111,    -1,   113,   114,   115,    -1,   117,
     118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,     3,     4,     5,     6,     7,    -1,   136,    -1,
      -1,    12,    -1,    -1,   142,    -1,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    85,    -1,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    97,    98,    -1,   100,
     101,    -1,   103,    -1,   105,    -1,    -1,    -1,   109,   110,
     111,    -1,   113,   114,   115,    -1,   117,   118,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,     3,
       4,     5,     6,     7,    -1,   136,    -1,    -1,    12,    -1,
      -1,   142,    -1,   144,   145,   146,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,
      -1,    85,    -1,    87,    -1,    89,    -1,    -1,    92,    -1,
      -1,    -1,    96,    97,    98,    -1,   100,   101,    -1,   103,
      -1,   105,    -1,    -1,    -1,   109,   110,   111,    -1,   113,
     114,   115,    -1,   117,   118,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,     3,     4,     5,     6,
       7,    -1,   136,    -1,    -1,    12,    -1,    -1,   142,    -1,
     144,   145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    -1,    76,
      -1,    -1,    -1,    80,    81,    82,    83,    -1,    85,    -1,
      87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    98,    -1,   100,   101,    -1,   103,    -1,   105,    -1,
      -1,    -1,   109,   110,   111,    -1,   113,   114,   115,    -1,
     117,   118,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,     3,     4,     5,     6,     7,    -1,   136,
      -1,    -1,    12,    -1,    -1,   142,    -1,   144,   145,    -1,
     147,   148,   149,   150,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,
      80,    81,    82,    83,    -1,    85,    -1,    87,    -1,    89,
      -1,    -1,    92,    -1,    -1,    -1,    96,    97,    -1,    -1,
     100,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,   127,   128,   129,
       3,     4,     5,     6,     7,    -1,   136,    -1,    -1,    12,
      -1,    -1,   142,    -1,   144,   145,    -1,   147,   148,   149,
     150,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    85,    -1,    87,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    96,    97,    -1,    -1,   100,   101,    -1,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,     3,     4,     5,
       6,     7,    -1,   136,    -1,    -1,    12,    -1,    -1,   142,
      -1,   144,   145,    -1,   147,   148,   149,   150,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    -1,
      76,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    85,
      -1,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      96,    97,    -1,    -1,   100,   101,    -1,   103,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,    -1,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,     3,     4,     5,     6,     7,    -1,
     136,    -1,    -1,    12,    -1,    -1,   142,    -1,   144,   145,
      -1,   147,   148,   149,   150,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    -1,    76,    -1,    -1,
      -1,    80,    81,    82,    83,    -1,    85,    -1,    87,    -1,
      89,    -1,    -1,    92,    -1,    -1,    -1,    96,    97,    -1,
      -1,   100,   101,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,   128,
     129,     3,     4,     5,     6,     7,    -1,   136,    -1,    -1,
      12,    -1,    -1,   142,    -1,   144,   145,    -1,   147,   148,
     149,   150,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,
      82,    83,    -1,    85,    -1,    87,    -1,    89,    -1,    -1,
      92,    -1,    -1,    -1,    96,    97,    -1,    -1,   100,   101,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
      -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,     3,     4,
       5,     6,     7,    -1,   136,    -1,    -1,    12,    -1,    -1,
     142,    -1,   144,   145,    -1,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,    -1,
      85,    -1,    87,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    96,    97,    -1,    -1,   100,   101,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,   111,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,     3,     4,     5,     6,     7,
      -1,   136,    -1,    -1,    12,    -1,    -1,   142,    -1,   144,
     145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    -1,    76,    -1,
      -1,    -1,    80,    81,    82,    83,    -1,    85,    -1,    87,
      -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,    97,
      -1,    -1,   100,   101,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,     3,     4,     5,     6,     7,    -1,   136,    -1,
      -1,    12,    -1,    -1,   142,    -1,   144,   145,    -1,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,     9,    10,    11,    -1,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,     3,
       4,     5,     6,     7,    -1,   136,    -1,    -1,    12,    -1,
      -1,   142,    -1,   144,    -1,    -1,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,     9,    10,    11,    -1,    70,    71,    72,    73,
      74,    -1,   146,    -1,    -1,    -1,    80,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,     3,     4,     5,     6,
       7,    -1,   136,    -1,    -1,    12,    -1,    -1,   142,    -1,
     144,    -1,    -1,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,     9,
      10,    11,    -1,    70,    71,    72,    73,    74,    -1,   146,
      -1,    -1,    -1,    80,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,
     127,   128,   129,     3,     4,     5,     6,     7,    -1,   136,
      -1,    -1,    12,    -1,    -1,   142,   143,    -1,    -1,    -1,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,     9,    10,    11,    -1,
      70,    71,    72,    73,    74,    -1,   146,    -1,    -1,    -1,
      80,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,   125,   126,   127,   128,   129,
       3,     4,     5,     6,     7,    -1,   136,    -1,    -1,    12,
      -1,    -1,   142,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,     9,    10,    11,    -1,    70,    71,    72,
      73,    74,    -1,   146,    -1,    -1,    -1,    80,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     123,   124,   125,   126,   127,   128,   129,     3,     4,     5,
       6,     7,    -1,   136,    -1,    -1,    12,    -1,    -1,   142,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    65,
      -1,     9,    10,    11,    70,    71,    72,    73,    74,    -1,
     146,    -1,    -1,    -1,    80,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,     3,     4,     5,     6,     7,    -1,
     136,    -1,    -1,    12,    -1,    -1,   142,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    -1,     9,    10,
      11,    70,    71,    72,    73,    74,   144,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,   128,
     129,     3,     4,     5,     6,     7,    -1,   136,    -1,    -1,
      12,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    65,    -1,     9,    10,    11,    70,    71,
      72,    73,    74,   144,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   125,   126,   127,   128,   129,     3,     4,
       5,     6,     7,    -1,   136,    -1,    -1,    12,    -1,    -1,
     142,    -1,    -1,    -1,    -1,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,     9,    10,    11,    70,    71,    72,    73,    74,
     144,    -1,    -1,    -1,    -1,    80,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
     125,   126,   127,   128,   129,     3,     4,     5,     6,     7,
      -1,   136,    -1,    -1,    12,    -1,    -1,   142,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    65,     9,    10,
      11,    -1,    70,    71,    72,    73,    74,   144,    -1,    -1,
      -1,    -1,    80,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   125,   126,   127,
     128,   129,     3,     4,     5,     6,     7,    -1,   136,    -1,
      -1,    12,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,     9,    10,    11,    -1,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,   124,   125,   126,   127,   128,   129,     3,
       4,     5,     6,     7,    -1,   136,    -1,    -1,    12,    -1,
      -1,   142,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    65,     9,    10,    11,    -1,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,     9,    10,    11,    -1,    -1,   142,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,    -1,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   143,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,     9,    10,    11,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    25,
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
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   122,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     122,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   153,   154,     0,     3,     4,     5,     6,     7,    12,
      42,    43,    48,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    62,    63,    64,    65,    66,    70,
      71,    72,    73,    74,    76,    80,    81,    82,    83,    85,
      87,    89,    92,    96,    97,    98,   100,   101,   103,   105,
     109,   110,   111,   113,   114,   115,   116,   117,   118,   123,
     124,   125,   126,   127,   128,   129,   136,   141,   142,   144,
     145,   147,   148,   149,   150,   155,   160,   161,   168,   170,
     173,   214,   215,   216,   224,   227,   231,   232,   234,   235,
     241,   242,   243,   244,   245,   246,   251,   259,   261,    62,
     231,   231,   142,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,    72,   216,
     234,   235,   234,   161,   168,   170,   231,   231,    72,   216,
     217,   218,   244,   245,   251,   142,   222,   142,   142,   211,
     231,    62,   160,   142,   142,   142,   142,   142,   144,   231,
     144,   231,    31,   167,   144,   214,   231,   235,   145,   231,
      74,   147,   197,   198,   117,   117,    74,   199,   142,   142,
     142,   142,    72,   142,   142,   256,    51,    72,   156,   157,
     231,   158,   145,   256,   256,   256,    72,   140,     9,    10,
      11,    25,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    49,   144,    59,    60,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   142,
     236,    61,   145,   147,   245,   231,   140,   140,   142,   223,
     219,   245,   143,   231,   231,    31,   195,   196,   214,   235,
       8,   144,    83,   231,   212,   213,   231,   214,   235,    72,
     184,   231,   144,   144,    72,   144,   144,   158,   144,   145,
     232,   235,     8,   144,    13,     8,   144,   165,   166,   235,
     235,   260,   235,   143,   172,   123,   235,   252,   253,    31,
     231,   254,   255,    74,    79,   137,   138,   139,   257,    72,
       8,   144,   143,    62,   146,   159,   160,   168,   170,   231,
     148,   149,   150,   171,    72,   241,   245,   251,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   217,    31,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   195,   121,   231,
     247,   231,   143,    72,   241,   195,   121,   143,   143,   233,
     235,   143,     8,   231,   142,   143,   144,     8,    91,    91,
      13,     8,   143,   143,   169,   146,   231,   198,    42,    43,
      72,   124,   224,   225,   226,    74,     8,   143,     8,   143,
     143,   144,   119,   176,   142,     8,   143,   233,   122,   143,
       8,   229,    61,   121,    73,   231,   235,   157,   168,   170,
     146,   119,   174,   142,   142,   245,    26,    64,   235,   143,
      72,   145,   241,   248,   249,   250,   151,   146,   143,   248,
      26,   160,    31,   214,   235,   231,    26,   160,   182,   212,
     231,   235,    31,   179,   235,   225,    72,    26,   160,   183,
      26,   145,   185,   142,   102,   146,   225,   225,   140,   142,
      13,   166,   144,   235,    72,   177,   216,   145,   252,   253,
      13,    31,   231,    31,   231,    72,    74,    75,   258,    72,
      61,   146,   146,   216,   120,   175,   195,   195,   231,   217,
     231,   142,   240,    61,   145,   220,   158,   188,   233,   143,
     158,   144,   122,   178,   235,   178,    13,   158,   144,   186,
     144,   186,    72,   124,   192,   193,   194,   142,    72,   225,
     228,   230,   225,     8,   200,   143,   231,   233,   233,   122,
     151,   231,   177,   145,   143,   143,   223,   146,   195,   237,
     247,   231,   121,   221,   189,    67,    68,   190,   144,    84,
     212,   179,   143,   143,   225,    90,   186,    93,    94,    95,
     186,   146,   143,     8,    31,    74,   216,   122,   143,     8,
     229,   216,    62,    99,   106,   107,   108,   109,   110,   111,
     112,   146,   201,   205,   206,   207,   208,   210,    31,   231,
     151,   200,   143,   238,   151,   146,   248,    67,    68,   191,
     142,   160,   144,   143,    26,   160,   181,   181,   144,    93,
     144,   231,    26,   144,   187,   146,   145,   194,    74,    13,
      74,   225,   225,   206,   207,    72,    74,   209,    98,   208,
       8,   144,   233,   146,   146,   121,   239,   142,    26,    69,
     231,    26,   160,   180,   158,   144,   187,   158,   158,    31,
      74,    13,   225,   143,   122,    98,    13,    13,     8,   144,
     167,    72,   248,   231,   158,   144,   143,   158,    88,   158,
     146,    74,    13,   225,   145,   225,   167,   225,   225,    74,
      72,    13,   240,   143,   160,    86,   144,    13,   225,   158,
      72,    13,   142,   225,    26,   144,   225,   146,   142,   225,
     202,   158,   102,   162,   163,   164,   203,   192,   142,   164,
     192,   143,   216,   143,   144,   145,   204,    74,   204,   158,
     143,   146,   145,   158,   146
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
#line 124 "hphp.y"
    { _p->saveParseTree(&(yyval));;}
    break;

  case 3:
#line 129 "hphp.y"
    { _p->addStatement(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 4:
#line 130 "hphp.y"
    { (yyval).reset();;}
    break;

  case 5:
#line 133 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 6:
#line 134 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 7:
#line 135 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 8:
#line 137 "hphp.y"
    { _p->onHphpNoteStatement(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 9:
#line 139 "hphp.y"
    { _p->onHphpNoteStatement(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 10:
#line 140 "hphp.y"
    { (yyval).reset();;}
    break;

  case 11:
#line 142 "hphp.y"
    { (yyval).reset(); ;}
    break;

  case 12:
#line 146 "hphp.y"
    { (yyval).reset();;}
    break;

  case 13:
#line 147 "hphp.y"
    { (yyval).reset();;}
    break;

  case 14:
#line 150 "hphp.y"
    { _p->addHphpSuppressError(&(yyvsp[(2) - (2)]));;}
    break;

  case 15:
#line 151 "hphp.y"
    { _p->addHphpDeclare(&(yyvsp[(1) - (1)]));;}
    break;

  case 16:
#line 155 "hphp.y"
    { _p->addStatement(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 17:
#line 156 "hphp.y"
    { (yyval).reset();;}
    break;

  case 18:
#line 159 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 19:
#line 160 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 20:
#line 161 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 21:
#line 163 "hphp.y"
    { _p->onHphpNoteStatement(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 22:
#line 165 "hphp.y"
    { _p->onHphpNoteStatement(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 23:
#line 168 "hphp.y"
    { _p->onExpStatement(&(yyval), &(yyvsp[(1) - (2)]));;}
    break;

  case 24:
#line 169 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 25:
#line 170 "hphp.y"
    { _p->onHphpNoteStatement(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 26:
#line 173 "hphp.y"
    { _p->onBlock(&(yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 27:
#line 178 "hphp.y"
    { _p->onIf(&(yyval),&(yyvsp[(3) - (7)]),&(yyvsp[(5) - (7)]),&(yyvsp[(6) - (7)]),&(yyvsp[(7) - (7)]));;}
    break;

  case 28:
#line 184 "hphp.y"
    { _p->onIf(&(yyval),&(yyvsp[(3) - (10)]),&(yyvsp[(6) - (10)]),&(yyvsp[(7) - (10)]),&(yyvsp[(8) - (10)]));;}
    break;

  case 29:
#line 187 "hphp.y"
    { _p->onWhile(&(yyval),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 30:
#line 190 "hphp.y"
    { _p->onDo(&(yyval),&(yyvsp[(2) - (7)]),&(yyvsp[(5) - (7)]));;}
    break;

  case 31:
#line 194 "hphp.y"
    { _p->onFor(&(yyval),&(yyvsp[(3) - (9)]),&(yyvsp[(5) - (9)]),&(yyvsp[(7) - (9)]),&(yyvsp[(9) - (9)]));;}
    break;

  case 32:
#line 197 "hphp.y"
    { _p->onSwitch(&(yyval),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 33:
#line 199 "hphp.y"
    { _p->onBreak(&(yyval), NULL);;}
    break;

  case 34:
#line 200 "hphp.y"
    { _p->onBreak(&(yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 35:
#line 202 "hphp.y"
    { _p->onContinue(&(yyval), NULL);;}
    break;

  case 36:
#line 203 "hphp.y"
    { _p->onContinue(&(yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 37:
#line 205 "hphp.y"
    { _p->onReturn(&(yyval), NULL);;}
    break;

  case 38:
#line 206 "hphp.y"
    { _p->onReturn(&(yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 39:
#line 207 "hphp.y"
    { _p->onReturn(&(yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 40:
#line 209 "hphp.y"
    { _p->onGlobal(&(yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 41:
#line 210 "hphp.y"
    { _p->onStatic(&(yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 42:
#line 211 "hphp.y"
    { _p->onEcho(&(yyval), &(yyvsp[(2) - (3)]), 0);;}
    break;

  case 43:
#line 213 "hphp.y"
    { _p->onUnset(&(yyval), &(yyvsp[(3) - (5)]));;}
    break;

  case 44:
#line 214 "hphp.y"
    { (yyval).reset();;}
    break;

  case 45:
#line 216 "hphp.y"
    { _p->onEcho(&(yyval), &(yyvsp[(1) - (1)]), 1);;}
    break;

  case 46:
#line 221 "hphp.y"
    { _p->onForEach(&(yyval),&(yyvsp[(3) - (8)]),&(yyvsp[(5) - (8)]),&(yyvsp[(6) - (8)]),&(yyvsp[(8) - (8)]));;}
    break;

  case 47:
#line 226 "hphp.y"
    { _p->onForEach(&(yyval),&(yyvsp[(3) - (8)]),&(yyvsp[(5) - (8)]),&(yyvsp[(6) - (8)]),&(yyvsp[(8) - (8)]));;}
    break;

  case 48:
#line 229 "hphp.y"
    { _p->onBlock(&(yyval), &(yyvsp[(5) - (5)]));;}
    break;

  case 49:
#line 236 "hphp.y"
    { _p->onTry(&(yyval),&(yyvsp[(3) - (13)]),&(yyvsp[(7) - (13)]),&(yyvsp[(8) - (13)]),&(yyvsp[(11) - (13)]),&(yyvsp[(13) - (13)]));;}
    break;

  case 50:
#line 238 "hphp.y"
    { _p->onThrow(&(yyval), &(yyvsp[(2) - (3)]));;}
    break;

  case 51:
#line 242 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 52:
#line 243 "hphp.y"
    { (yyval).reset();;}
    break;

  case 53:
#line 246 "hphp.y"
    { _p->addStatement(&(yyval), NULL, &(yyvsp[(1) - (1)]));;}
    break;

  case 54:
#line 248 "hphp.y"
    { _p->addStatement(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]));;}
    break;

  case 55:
#line 254 "hphp.y"
    { _p->onCatch(&(yyval), &(yyvsp[(3) - (8)]), &(yyvsp[(4) - (8)]), &(yyvsp[(7) - (8)]));;}
    break;

  case 56:
#line 258 "hphp.y"
    { _p->onExprListElem(&(yyval), NULL, &(yyvsp[(1) - (1)]));;}
    break;

  case 57:
#line 259 "hphp.y"
    { _p->onExprListElem(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 58:
#line 262 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 59:
#line 266 "hphp.y"
    { (yyval) = 1;;}
    break;

  case 60:
#line 267 "hphp.y"
    { (yyval).reset();;}
    break;

  case 61:
#line 271 "hphp.y"
    { _p->onFunctionStart();;}
    break;

  case 62:
#line 273 "hphp.y"
    { _p->onFunction(&(yyval),&(yyvsp[(2) - (10)]),&(yyvsp[(3) - (10)]),&(yyvsp[(6) - (10)]),&(yyvsp[(9) - (10)]));;}
    break;

  case 63:
#line 277 "hphp.y"
    { _p->onClassStart();;}
    break;

  case 64:
#line 280 "hphp.y"
    { _p->onClass(&(yyval),&(yyvsp[(1) - (8)]),&(yyvsp[(2) - (8)]),&(yyvsp[(4) - (8)]),&(yyvsp[(5) - (8)]),&(yyvsp[(7) - (8)]));;}
    break;

  case 65:
#line 282 "hphp.y"
    { _p->onClassStart();;}
    break;

  case 66:
#line 284 "hphp.y"
    { _p->onInterface(&(yyval),&(yyvsp[(2) - (7)]),&(yyvsp[(4) - (7)]),&(yyvsp[(6) - (7)]));;}
    break;

  case 67:
#line 287 "hphp.y"
    { (yyval) = T_CLASS;;}
    break;

  case 68:
#line 288 "hphp.y"
    { (yyval) = T_ABSTRACT;;}
    break;

  case 69:
#line 289 "hphp.y"
    { (yyval) = T_FINAL;;}
    break;

  case 70:
#line 293 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 71:
#line 294 "hphp.y"
    { (yyval).reset();;}
    break;

  case 72:
#line 297 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 73:
#line 298 "hphp.y"
    { (yyval).reset();;}
    break;

  case 74:
#line 301 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 75:
#line 302 "hphp.y"
    { (yyval).reset();;}
    break;

  case 76:
#line 305 "hphp.y"
    { _p->onInterfaceName(&(yyval), NULL, &(yyvsp[(1) - (1)]));;}
    break;

  case 77:
#line 307 "hphp.y"
    { _p->onInterfaceName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 78:
#line 311 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 79:
#line 312 "hphp.y"
    { (yyval).reset();;}
    break;

  case 80:
#line 315 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 81:
#line 316 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = 1;;}
    break;

  case 82:
#line 320 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 83:
#line 322 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 84:
#line 325 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 85:
#line 327 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 86:
#line 330 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 87:
#line 332 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 88:
#line 335 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 89:
#line 337 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 92:
#line 347 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 93:
#line 348 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]);;}
    break;

  case 94:
#line 349 "hphp.y"
    { (yyval) = (yyvsp[(2) - (4)]);;}
    break;

  case 95:
#line 350 "hphp.y"
    { (yyval) = (yyvsp[(3) - (5)]);;}
    break;

  case 96:
#line 355 "hphp.y"
    { _p->onCase(&(yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 97:
#line 357 "hphp.y"
    { _p->onCase(&(yyval),&(yyvsp[(1) - (4)]),NULL,&(yyvsp[(4) - (4)]));;}
    break;

  case 98:
#line 358 "hphp.y"
    { (yyval).reset();;}
    break;

  case 99:
#line 361 "hphp.y"
    { (yyval).reset();;}
    break;

  case 100:
#line 362 "hphp.y"
    { (yyval).reset();;}
    break;

  case 101:
#line 367 "hphp.y"
    { _p->onElseIf(&(yyval),&(yyvsp[(1) - (6)]),&(yyvsp[(4) - (6)]),&(yyvsp[(6) - (6)]));;}
    break;

  case 102:
#line 368 "hphp.y"
    { (yyval).reset();;}
    break;

  case 103:
#line 373 "hphp.y"
    { _p->onElseIf(&(yyval),&(yyvsp[(1) - (7)]),&(yyvsp[(4) - (7)]),&(yyvsp[(7) - (7)]));;}
    break;

  case 104:
#line 374 "hphp.y"
    { (yyval).reset();;}
    break;

  case 105:
#line 377 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]);;}
    break;

  case 106:
#line 378 "hphp.y"
    { (yyval).reset();;}
    break;

  case 107:
#line 381 "hphp.y"
    { (yyval) = (yyvsp[(3) - (3)]);;}
    break;

  case 108:
#line 382 "hphp.y"
    { (yyval).reset();;}
    break;

  case 109:
#line 386 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 110:
#line 387 "hphp.y"
    { (yyval).reset();;}
    break;

  case 111:
#line 390 "hphp.y"
    { _p->onParam(&(yyval),NULL,&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]),0,NULL);;}
    break;

  case 112:
#line 391 "hphp.y"
    { _p->onParam(&(yyval),NULL,&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),1,NULL);;}
    break;

  case 113:
#line 393 "hphp.y"
    { _p->onParam(&(yyval),NULL,&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),1,&(yyvsp[(5) - (5)]));;}
    break;

  case 114:
#line 395 "hphp.y"
    { _p->onParam(&(yyval),NULL,&(yyvsp[(1) - (4)]),&(yyvsp[(2) - (4)]),0,&(yyvsp[(4) - (4)]));;}
    break;

  case 115:
#line 397 "hphp.y"
    { _p->onParam(&(yyval),&(yyvsp[(1) - (4)]),&(yyvsp[(3) - (4)]),&(yyvsp[(4) - (4)]),0,NULL);;}
    break;

  case 116:
#line 399 "hphp.y"
    { _p->onParam(&(yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]),1,NULL);;}
    break;

  case 117:
#line 402 "hphp.y"
    { _p->onParam(&(yyval),&(yyvsp[(1) - (7)]),&(yyvsp[(3) - (7)]),&(yyvsp[(5) - (7)]),1,&(yyvsp[(7) - (7)]));;}
    break;

  case 118:
#line 405 "hphp.y"
    { _p->onParam(&(yyval),&(yyvsp[(1) - (6)]),&(yyvsp[(3) - (6)]),&(yyvsp[(4) - (6)]),0,&(yyvsp[(6) - (6)]));;}
    break;

  case 119:
#line 408 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 120:
#line 409 "hphp.y"
    { (yyval).setText("array");;}
    break;

  case 121:
#line 410 "hphp.y"
    { (yyval).reset();;}
    break;

  case 122:
#line 414 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 123:
#line 415 "hphp.y"
    { (yyval).reset();;}
    break;

  case 124:
#line 418 "hphp.y"
    { _p->onCallParam(&(yyval),NULL,&(yyvsp[(1) - (1)]),0);;}
    break;

  case 125:
#line 419 "hphp.y"
    { _p->onCallParam(&(yyval),NULL,&(yyvsp[(1) - (1)]),0);;}
    break;

  case 126:
#line 420 "hphp.y"
    { _p->onCallParam(&(yyval),NULL,&(yyvsp[(2) - (2)]),1);;}
    break;

  case 127:
#line 422 "hphp.y"
    { _p->onCallParam(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),0);;}
    break;

  case 128:
#line 424 "hphp.y"
    { _p->onCallParam(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),0);;}
    break;

  case 129:
#line 426 "hphp.y"
    { _p->onCallParam(&(yyval),&(yyvsp[(1) - (4)]),&(yyvsp[(4) - (4)]),1);;}
    break;

  case 130:
#line 430 "hphp.y"
    { _p->onGlobalVar(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 131:
#line 431 "hphp.y"
    { _p->onGlobalVar(&(yyval), NULL, &(yyvsp[(1) - (1)]));;}
    break;

  case 132:
#line 434 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 133:
#line 435 "hphp.y"
    { (yyval) = (yyvsp[(2) - (2)]); (yyval) = 1;;}
    break;

  case 134:
#line 436 "hphp.y"
    { (yyval) = (yyvsp[(3) - (4)]); (yyval) = 1;;}
    break;

  case 135:
#line 440 "hphp.y"
    { _p->onVariable(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),0);;}
    break;

  case 136:
#line 442 "hphp.y"
    { _p->onVariable(&(yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 137:
#line 443 "hphp.y"
    { _p->onVariable(&(yyval),0,&(yyvsp[(1) - (1)]),0);;}
    break;

  case 138:
#line 444 "hphp.y"
    { _p->onVariable(&(yyval),0,&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 139:
#line 449 "hphp.y"
    { _p->addStatement(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]));;}
    break;

  case 140:
#line 450 "hphp.y"
    { (yyval).reset();;}
    break;

  case 141:
#line 454 "hphp.y"
    { _p->onClassVariable(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(2) - (3)]));;}
    break;

  case 142:
#line 455 "hphp.y"
    { _p->onClassVariable(&(yyval),NULL,&(yyvsp[(1) - (2)]));;}
    break;

  case 143:
#line 457 "hphp.y"
    { _p->onFunctionStart();;}
    break;

  case 144:
#line 458 "hphp.y"
    { _p->onMethod(&(yyval),&(yyvsp[(1) - (9)]),&(yyvsp[(3) - (9)]),&(yyvsp[(4) - (9)]),&(yyvsp[(7) - (9)]),
                                                      &(yyvsp[(9) - (9)]));;}
    break;

  case 145:
#line 462 "hphp.y"
    { _p->onFunctionStart();;}
    break;

  case 146:
#line 463 "hphp.y"
    { _p->onMethod(&(yyval),&(yyvsp[(2) - (10)]),&(yyvsp[(4) - (10)]),&(yyvsp[(5) - (10)]),&(yyvsp[(8) - (10)]),
                                                      &(yyvsp[(10) - (10)]));
                                         _p->onHphpNoteStatement(&(yyval),&(yyvsp[(1) - (10)]),&(yyval));;}
    break;

  case 147:
#line 468 "hphp.y"
    { (yyval).reset();;}
    break;

  case 148:
#line 469 "hphp.y"
    { _p->finishStatement(&(yyval), &(yyvsp[(2) - (3)]));
                                         (yyval) = 1;;}
    break;

  case 149:
#line 473 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 150:
#line 474 "hphp.y"
    { (yyval).reset();;}
    break;

  case 151:
#line 477 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 152:
#line 478 "hphp.y"
    { (yyval).reset();;}
    break;

  case 153:
#line 481 "hphp.y"
    { _p->onMemberModifier(&(yyval),NULL,&(yyvsp[(1) - (1)]));;}
    break;

  case 154:
#line 483 "hphp.y"
    { _p->onMemberModifier(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 155:
#line 486 "hphp.y"
    { (yyval) = T_PUBLIC;;}
    break;

  case 156:
#line 487 "hphp.y"
    { (yyval) = T_PROTECTED;;}
    break;

  case 157:
#line 488 "hphp.y"
    { (yyval) = T_PRIVATE;;}
    break;

  case 158:
#line 489 "hphp.y"
    { (yyval) = T_STATIC;;}
    break;

  case 159:
#line 490 "hphp.y"
    { (yyval) = T_ABSTRACT;;}
    break;

  case 160:
#line 491 "hphp.y"
    { (yyval) = T_FINAL;;}
    break;

  case 161:
#line 495 "hphp.y"
    { _p->onVariable(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),0);;}
    break;

  case 162:
#line 497 "hphp.y"
    { _p->onVariable(&(yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]));;}
    break;

  case 163:
#line 498 "hphp.y"
    { _p->onVariable(&(yyval),0,&(yyvsp[(1) - (1)]),0);;}
    break;

  case 164:
#line 499 "hphp.y"
    { _p->onVariable(&(yyval),0,&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 165:
#line 503 "hphp.y"
    { _p->onVariable(&(yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]),1);;}
    break;

  case 166:
#line 504 "hphp.y"
    { _p->onVariable(&(yyval),0,&(yyvsp[(2) - (4)]),&(yyvsp[(4) - (4)]),1);;}
    break;

  case 167:
#line 508 "hphp.y"
    { _p->onExprListElem(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 168:
#line 509 "hphp.y"
    { _p->onExprListElem(&(yyval), NULL, &(yyvsp[(1) - (1)]));;}
    break;

  case 169:
#line 513 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 170:
#line 514 "hphp.y"
    { (yyval).reset();;}
    break;

  case 171:
#line 517 "hphp.y"
    { _p->onExprListElem(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 172:
#line 518 "hphp.y"
    { _p->onExprListElem(&(yyval), NULL, &(yyvsp[(1) - (1)]));;}
    break;

  case 173:
#line 523 "hphp.y"
    { _p->onListAssignment(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(6) - (6)]));;}
    break;

  case 174:
#line 524 "hphp.y"
    { _p->onAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), 0);;}
    break;

  case 175:
#line 525 "hphp.y"
    { _p->onAssign(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(4) - (4)]), 1);;}
    break;

  case 176:
#line 528 "hphp.y"
    { _p->onAssignNew(&(yyval),&(yyvsp[(1) - (6)]),&(yyvsp[(5) - (6)]),&(yyvsp[(6) - (6)]));;}
    break;

  case 177:
#line 530 "hphp.y"
    { _p->onNewObject(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 178:
#line 531 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_CLONE,1);;}
    break;

  case 179:
#line 532 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_PLUS_EQUAL);;}
    break;

  case 180:
#line 533 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_MINUS_EQUAL);;}
    break;

  case 181:
#line 534 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_MUL_EQUAL);;}
    break;

  case 182:
#line 535 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_DIV_EQUAL);;}
    break;

  case 183:
#line 536 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_CONCAT_EQUAL);;}
    break;

  case 184:
#line 537 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_MOD_EQUAL);;}
    break;

  case 185:
#line 538 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_AND_EQUAL);;}
    break;

  case 186:
#line 539 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_OR_EQUAL);;}
    break;

  case 187:
#line 540 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_XOR_EQUAL);;}
    break;

  case 188:
#line 541 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_SL_EQUAL);;}
    break;

  case 189:
#line 542 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_SR_EQUAL);;}
    break;

  case 190:
#line 543 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(1) - (2)]),T_INC,0);;}
    break;

  case 191:
#line 544 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_INC,1);;}
    break;

  case 192:
#line 545 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(1) - (2)]),T_DEC,0);;}
    break;

  case 193:
#line 546 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_DEC,1);;}
    break;

  case 194:
#line 547 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_BOOLEAN_OR);;}
    break;

  case 195:
#line 548 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_BOOLEAN_AND);;}
    break;

  case 196:
#line 549 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_LOGICAL_OR);;}
    break;

  case 197:
#line 550 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_LOGICAL_AND);;}
    break;

  case 198:
#line 551 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_LOGICAL_XOR);;}
    break;

  case 199:
#line 552 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'|');;}
    break;

  case 200:
#line 553 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'&');;}
    break;

  case 201:
#line 554 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'^');;}
    break;

  case 202:
#line 555 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'.');;}
    break;

  case 203:
#line 556 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'+');;}
    break;

  case 204:
#line 557 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'-');;}
    break;

  case 205:
#line 558 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'*');;}
    break;

  case 206:
#line 559 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'/');;}
    break;

  case 207:
#line 560 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'%');;}
    break;

  case 208:
#line 561 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_SL);;}
    break;

  case 209:
#line 562 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_SR);;}
    break;

  case 210:
#line 563 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 211:
#line 564 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 212:
#line 565 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),'!',1);;}
    break;

  case 213:
#line 566 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),'~',1);;}
    break;

  case 214:
#line 567 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_IS_IDENTICAL);;}
    break;

  case 215:
#line 568 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_IS_NOT_IDENTICAL);;}
    break;

  case 216:
#line 569 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_IS_EQUAL);;}
    break;

  case 217:
#line 570 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_IS_NOT_EQUAL);;}
    break;

  case 218:
#line 571 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'<');;}
    break;

  case 219:
#line 572 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),
                                              T_IS_SMALLER_OR_EQUAL);;}
    break;

  case 220:
#line 574 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),'>');;}
    break;

  case 221:
#line 575 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),
                                              T_IS_GREATER_OR_EQUAL);;}
    break;

  case 222:
#line 578 "hphp.y"
    { BEXP(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),T_INSTANCEOF);;}
    break;

  case 223:
#line 579 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (3)]),'(',1);;}
    break;

  case 224:
#line 580 "hphp.y"
    { _p->onQOp(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(3) - (5)]), &(yyvsp[(5) - (5)]));;}
    break;

  case 225:
#line 581 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 226:
#line 582 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_INT_CAST,1);;}
    break;

  case 227:
#line 583 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_DOUBLE_CAST,1);;}
    break;

  case 228:
#line 584 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_STRING_CAST,1);;}
    break;

  case 229:
#line 585 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_ARRAY_CAST,1);;}
    break;

  case 230:
#line 586 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_OBJECT_CAST,1);;}
    break;

  case 231:
#line 587 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_BOOL_CAST,1);;}
    break;

  case 232:
#line 588 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_UNSET_CAST,1);;}
    break;

  case 233:
#line 589 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_EXIT,1);;}
    break;

  case 234:
#line 590 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),'@',1);;}
    break;

  case 235:
#line 591 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 236:
#line 592 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(3) - (4)]),T_ARRAY,1);;}
    break;

  case 237:
#line 593 "hphp.y"
    { _p->onEncapsList(&(yyval),'`',&(yyvsp[(2) - (3)]));;}
    break;

  case 238:
#line 594 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_PRINT,1);;}
    break;

  case 239:
#line 595 "hphp.y"
    { _p->onHphpNoteExpr(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 240:
#line 600 "hphp.y"
    { _p->onCall(&(yyval),0,&(yyvsp[(1) - (4)]),&(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 241:
#line 602 "hphp.y"
    { _p->onCall(&(yyval),1,&(yyvsp[(1) - (4)]),&(yyvsp[(3) - (4)]),NULL);;}
    break;

  case 242:
#line 606 "hphp.y"
    { _p->onCall(&(yyval),0,&(yyvsp[(3) - (6)]),&(yyvsp[(5) - (6)]),&(yyvsp[(1) - (6)]));;}
    break;

  case 243:
#line 610 "hphp.y"
    { _p->onCall(&(yyval),1,&(yyvsp[(3) - (6)]),&(yyvsp[(5) - (6)]),&(yyvsp[(1) - (6)]));;}
    break;

  case 244:
#line 613 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 245:
#line 616 "hphp.y"
    { _p->onScalar(&(yyval), T_STRING, &(yyvsp[(1) - (1)]));;}
    break;

  case 246:
#line 617 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 247:
#line 620 "hphp.y"
    { _p->pushObject(&(yyvsp[(1) - (1)]));;}
    break;

  case 248:
#line 622 "hphp.y"
    { _p->popObject(&(yyval));;}
    break;

  case 249:
#line 623 "hphp.y"
    { _p->pushObject(&(yyvsp[(1) - (1)]));
                                         _p->popObject(&(yyval));;}
    break;

  case 250:
#line 628 "hphp.y"
    { ;}
    break;

  case 251:
#line 629 "hphp.y"
    { ;}
    break;

  case 252:
#line 632 "hphp.y"
    { ;}
    break;

  case 253:
#line 636 "hphp.y"
    { (yyval).reset();;}
    break;

  case 254:
#line 637 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 255:
#line 638 "hphp.y"
    { (yyval).reset();;}
    break;

  case 256:
#line 643 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 257:
#line 644 "hphp.y"
    { (yyval).reset();;}
    break;

  case 258:
#line 648 "hphp.y"
    { _p->onScalar(&(yyval), T_LNUMBER, &(yyvsp[(1) - (1)]));;}
    break;

  case 259:
#line 649 "hphp.y"
    { _p->onScalar(&(yyval), T_DNUMBER, &(yyvsp[(1) - (1)]));;}
    break;

  case 260:
#line 650 "hphp.y"
    { _p->onScalar(&(yyval),
                                         T_CONSTANT_ENCAPSED_STRING, &(yyvsp[(1) - (1)]));;}
    break;

  case 261:
#line 652 "hphp.y"
    { _p->onScalar(&(yyval), T_LINE, &(yyvsp[(1) - (1)]));;}
    break;

  case 262:
#line 653 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(1) - (1)]),T_FILE,1);;}
    break;

  case 263:
#line 654 "hphp.y"
    { _p->onScalar(&(yyval), T_CLASS_C, &(yyvsp[(1) - (1)]));;}
    break;

  case 264:
#line 655 "hphp.y"
    { _p->onScalar(&(yyval), T_METHOD_C, &(yyvsp[(1) - (1)]));;}
    break;

  case 265:
#line 656 "hphp.y"
    { _p->onScalar(&(yyval), T_FUNC_C, &(yyvsp[(1) - (1)]));;}
    break;

  case 266:
#line 659 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 267:
#line 660 "hphp.y"
    { _p->onConstant(&(yyval), &(yyvsp[(1) - (1)]));;}
    break;

  case 268:
#line 661 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),'+',1);;}
    break;

  case 269:
#line 662 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),'-',1);;}
    break;

  case 270:
#line 664 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(3) - (4)]),T_ARRAY,1);;}
    break;

  case 271:
#line 665 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 272:
#line 669 "hphp.y"
    { _p->onClassConst(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 273:
#line 672 "hphp.y"
    { _p->onConstant(&(yyval), &(yyvsp[(1) - (1)]));;}
    break;

  case 274:
#line 673 "hphp.y"
    { _p->onConstant(&(yyval), &(yyvsp[(1) - (1)]));;}
    break;

  case 275:
#line 674 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 276:
#line 675 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 277:
#line 676 "hphp.y"
    { _p->onEncapsList(&(yyval),'"',&(yyvsp[(2) - (3)]));;}
    break;

  case 278:
#line 677 "hphp.y"
    { _p->onEncapsList(&(yyval),'\'',&(yyvsp[(2) - (3)]));;}
    break;

  case 279:
#line 679 "hphp.y"
    { _p->onEncapsList(&(yyval),T_START_HEREDOC,
                                                          &(yyvsp[(2) - (3)]));;}
    break;

  case 280:
#line 684 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 281:
#line 685 "hphp.y"
    { (yyval).reset();;}
    break;

  case 282:
#line 688 "hphp.y"
    { (yyval).reset();;}
    break;

  case 283:
#line 689 "hphp.y"
    { (yyval).reset();;}
    break;

  case 284:
#line 694 "hphp.y"
    { _p->onArrayPair(&(yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]),0);;}
    break;

  case 285:
#line 696 "hphp.y"
    { _p->onArrayPair(&(yyval),&(yyvsp[(1) - (3)]),  0,&(yyvsp[(3) - (3)]),0);;}
    break;

  case 286:
#line 698 "hphp.y"
    { _p->onArrayPair(&(yyval),  0,&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),0);;}
    break;

  case 287:
#line 699 "hphp.y"
    { _p->onArrayPair(&(yyval),  0,  0,&(yyvsp[(1) - (1)]),0);;}
    break;

  case 288:
#line 703 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 289:
#line 704 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 290:
#line 707 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 291:
#line 710 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 292:
#line 713 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 293:
#line 716 "hphp.y"
    { _p->pushObject(&(yyvsp[(1) - (1)]));;}
    break;

  case 294:
#line 718 "hphp.y"
    { _p->appendMethodParams(&(yyvsp[(5) - (5)]));;}
    break;

  case 295:
#line 719 "hphp.y"
    { _p->popObject(&(yyval));;}
    break;

  case 296:
#line 720 "hphp.y"
    { _p->pushObject(&(yyvsp[(1) - (1)]));
                                         _p->popObject(&(yyval));;}
    break;

  case 297:
#line 725 "hphp.y"
    { ;}
    break;

  case 298:
#line 726 "hphp.y"
    { ;}
    break;

  case 299:
#line 730 "hphp.y"
    { _p->appendMethodParams(&(yyvsp[(3) - (3)]));;}
    break;

  case 300:
#line 734 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]); (yyval).num = 1;;}
    break;

  case 301:
#line 735 "hphp.y"
    { (yyval).reset();;}
    break;

  case 302:
#line 739 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 303:
#line 741 "hphp.y"
    { _p->onIndirectRef(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 304:
#line 746 "hphp.y"
    { _p->onStaticMember(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 305:
#line 750 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 306:
#line 751 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 307:
#line 754 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 308:
#line 756 "hphp.y"
    { _p->onIndirectRef(&(yyval),&(yyvsp[(1) - (2)]),&(yyvsp[(2) - (2)]));;}
    break;

  case 309:
#line 757 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = 2;;}
    break;

  case 310:
#line 761 "hphp.y"
    { _p->onRefDim(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]));;}
    break;

  case 311:
#line 762 "hphp.y"
    { _p->onRefDim(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]));;}
    break;

  case 312:
#line 763 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 313:
#line 766 "hphp.y"
    { _p->onSimpleVariable(&(yyval), &(yyvsp[(1) - (1)]));;}
    break;

  case 314:
#line 767 "hphp.y"
    { _p->onDynamicVariable(&(yyval), &(yyvsp[(3) - (4)]), 0);;}
    break;

  case 315:
#line 770 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 316:
#line 771 "hphp.y"
    { (yyval).reset();;}
    break;

  case 317:
#line 775 "hphp.y"
    { ;}
    break;

  case 318:
#line 776 "hphp.y"
    { _p->appendProperty(&(yyvsp[(1) - (1)]));;}
    break;

  case 319:
#line 779 "hphp.y"
    { _p->appendRefDim(&(yyvsp[(3) - (4)]));;}
    break;

  case 320:
#line 780 "hphp.y"
    { _p->appendRefDim(&(yyvsp[(3) - (4)]));;}
    break;

  case 321:
#line 781 "hphp.y"
    { _p->appendProperty(&(yyvsp[(1) - (1)]));;}
    break;

  case 322:
#line 784 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 323:
#line 785 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 324:
#line 789 "hphp.y"
    { (yyval) = 1;;}
    break;

  case 325:
#line 790 "hphp.y"
    { (yyval)++;;}
    break;

  case 326:
#line 794 "hphp.y"
    { _p->onExprListElem(&(yyval),&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]));;}
    break;

  case 327:
#line 795 "hphp.y"
    { _p->onExprListElem(&(yyval),NULL,&(yyvsp[(1) - (1)]));;}
    break;

  case 328:
#line 798 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 329:
#line 799 "hphp.y"
    { _p->onListAssignment(&(yyval), &(yyvsp[(3) - (4)]), NULL);;}
    break;

  case 330:
#line 800 "hphp.y"
    { (yyval).reset();;}
    break;

  case 331:
#line 805 "hphp.y"
    { (yyval) = (yyvsp[(1) - (2)]);;}
    break;

  case 332:
#line 806 "hphp.y"
    { (yyval).reset();;}
    break;

  case 333:
#line 810 "hphp.y"
    { _p->onArrayPair(&(yyval),&(yyvsp[(1) - (5)]),&(yyvsp[(3) - (5)]),&(yyvsp[(5) - (5)]),0);;}
    break;

  case 334:
#line 811 "hphp.y"
    { _p->onArrayPair(&(yyval),&(yyvsp[(1) - (3)]),  0,&(yyvsp[(3) - (3)]),0);;}
    break;

  case 335:
#line 812 "hphp.y"
    { _p->onArrayPair(&(yyval),  0,&(yyvsp[(1) - (3)]),&(yyvsp[(3) - (3)]),0);;}
    break;

  case 336:
#line 813 "hphp.y"
    { _p->onArrayPair(&(yyval),  0,  0,&(yyvsp[(1) - (1)]),0);;}
    break;

  case 337:
#line 816 "hphp.y"
    { _p->onArrayPair(&(yyval),&(yyvsp[(1) - (6)]),&(yyvsp[(3) - (6)]),&(yyvsp[(6) - (6)]),1);;}
    break;

  case 338:
#line 818 "hphp.y"
    { _p->onArrayPair(&(yyval),&(yyvsp[(1) - (4)]),  0,&(yyvsp[(4) - (4)]),1);;}
    break;

  case 339:
#line 819 "hphp.y"
    { _p->onArrayPair(&(yyval),  0,&(yyvsp[(1) - (4)]),&(yyvsp[(4) - (4)]),1);;}
    break;

  case 340:
#line 820 "hphp.y"
    { _p->onArrayPair(&(yyval),  0,  0,&(yyvsp[(2) - (2)]),1);;}
    break;

  case 341:
#line 824 "hphp.y"
    { _p->addEncap(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), -1);;}
    break;

  case 342:
#line 826 "hphp.y"
    { _p->addEncap(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), 0);;}
    break;

  case 343:
#line 827 "hphp.y"
    { (yyval).reset();;}
    break;

  case 344:
#line 830 "hphp.y"
    { _p->onSimpleVariable(&(yyval), &(yyvsp[(1) - (1)]));;}
    break;

  case 345:
#line 832 "hphp.y"
    { _p->encapRefDim(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]));;}
    break;

  case 346:
#line 834 "hphp.y"
    { _p->encapObjProp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 347:
#line 836 "hphp.y"
    { _p->onDynamicVariable(&(yyval), &(yyvsp[(2) - (3)]), 1);;}
    break;

  case 348:
#line 838 "hphp.y"
    { _p->encapArray(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]));;}
    break;

  case 349:
#line 839 "hphp.y"
    { (yyval) = (yyvsp[(2) - (3)]);;}
    break;

  case 350:
#line 842 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_STRING;;}
    break;

  case 351:
#line 843 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_NUM_STRING;;}
    break;

  case 352:
#line 844 "hphp.y"
    { (yyval) = (yyvsp[(1) - (1)]); (yyval) = T_VARIABLE;;}
    break;

  case 353:
#line 848 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(3) - (4)]),T_ISSET,1);;}
    break;

  case 354:
#line 849 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(3) - (4)]),T_EMPTY,1);;}
    break;

  case 355:
#line 850 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_INCLUDE,1);;}
    break;

  case 356:
#line 851 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_INCLUDE_ONCE,1);;}
    break;

  case 357:
#line 852 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(3) - (4)]),T_EVAL,1);;}
    break;

  case 358:
#line 853 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_REQUIRE,1);;}
    break;

  case 359:
#line 854 "hphp.y"
    { UEXP(&(yyval),&(yyvsp[(2) - (2)]),T_REQUIRE_ONCE,1);;}
    break;

  case 360:
#line 858 "hphp.y"
    { _p->onExprListElem(&(yyval), NULL, &(yyvsp[(1) - (1)]));;}
    break;

  case 361:
#line 859 "hphp.y"
    { _p->onExprListElem(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;

  case 362:
#line 864 "hphp.y"
    { _p->onClassConst(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]));;}
    break;


/* Line 1267 of yacc.c.  */
#line 5097 "hphp.tab.cpp"
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


#line 866 "hphp.y"


static int __attribute__((unused)) suppress_warning = yydebug;

