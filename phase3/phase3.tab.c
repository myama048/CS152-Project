/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "phase3.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "phase3.tab.h".  */
#ifndef YY_YY_PHASE3_TAB_H_INCLUDED
# define YY_YY_PHASE3_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEGIN_PARAMS = 258,
    END_PARAMS = 259,
    BEGIN_LOCALS = 260,
    END_LOCALS = 261,
    BEGIN_BODY = 262,
    END_BODY = 263,
    FUNCTION = 264,
    RETURN = 265,
    MAIN = 266,
    L_SQUARE_BRACKET = 267,
    R_SQUARE_BRACKET = 268,
    INTEGER = 269,
    ARRAY = 270,
    OF = 271,
    IF = 272,
    THEN = 273,
    ENDIF = 274,
    ELSE = 275,
    WHILE = 276,
    DO = 277,
    BEGINLOOP = 278,
    ENDLOOP = 279,
    CONTINUE = 280,
    READ = 281,
    WRITE = 282,
    TRUE = 283,
    FALSE = 284,
    AND = 285,
    OR = 286,
    NOT = 287,
    ASSIGN = 288,
    SUB = 289,
    ADD = 290,
    MULT = 291,
    DIV = 292,
    MOD = 293,
    EQ = 294,
    NEQ = 295,
    LT = 296,
    GT = 297,
    LTE = 298,
    GTE = 299,
    SEMICOLON = 300,
    COLON = 301,
    COMMA = 302,
    L_PAREN = 303,
    R_PAREN = 304,
    NUMBER = 305,
    IDENT = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "phase3.y" /* yacc.c:355  */

  int num_val;
  char *op_val;

#line 164 "phase3.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PHASE3_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 181 "phase3.tab.c" /* yacc.c:358  */
/* Unqualified %code blocks.  */
#line 2 "phase3.y" /* yacc.c:359  */

   // All includes go here
   #include<string>
   #include<stack>
   #include<iostream>
   #include<utility>
   #include "phase3.tab.h"
   #include "phase2.tab.h"
   using namespace std;
 
   // All lines below come from sample doc
  void yyerror(const char *msg);
   extern int yylex();
   extern int currLine;
   int myError = 0;
   int otherError = 0;

   char *identToken;	
   int numberToken;
   int productionID = 0;

   char list_of_function_names[100][100];
   int count_names = 0; 


	// Global Variables
    int count = 0;
    //int expressionCount = 0;
    //bool read_bool = false;
    //bool is_array = false;
    //char string[100][20] = {'\0'};
    int index_ident = 0;
    char string_var[100][20] = {'\0'};
    int index_var = 0;
	int index_label = 0;
	int index_end_label = 0;
	//pair<string,string> str_int_pair;
	
   	stack<string> varsStack;
	stack<string> termStack;
	stack<string> identifierStack;
	stack<string> compStack;
	stack<int> whileStack;

#line 228 "phase3.tab.c" /* yacc.c:359  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    85,    87,    90,    98,   102,   106,    97,
     115,   118,   120,   124,   132,   141,   145,   152,   160,   166,
     170,   159,   181,   180,   192,   197,   206,   191,   217,   221,
     225,   229,   234,   242,   244,   248,   254,   266,   280,   286,
     298,   311,   328,   334,   339,   343,   343,   353,   356,   360,
     365,   372,   377,   381,   386,   390,   406,   408,   410,   412,
     414,   416,   418,   422,   428,   432,   436,   441,   446,   453,
     458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "FUNCTION",
  "RETURN", "MAIN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "TRUE", "FALSE", "AND", "OR",
  "NOT", "ASSIGN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT",
  "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN",
  "NUMBER", "IDENT", "$accept", "prog_start", "functions", "function",
  "$@1", "$@2", "$@3", "ident", "declarations", "declaration",
  "identifiers", "statement", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "$@10", "statements", "expression", "multiplicative_expression", "term",
  "$@11", "expressions", "comma_sep_expressions", "bool_exp",
  "relation_and_exp", "relation_exp", "comp", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -5,   -42,    15,    -5,    -5,   -62,   -19,   -62,   -62,   -62,
     -62,    14,   -42,   -10,    38,    -2,     0,   -42,   -62,   -42,
       9,   -62,    42,   -62,   -62,    36,   -42,     2,    48,    46,
     -62,    40,    60,    57,    43,   -62,   -38,    53,   -62,    52,
     -62,    25,    29,    71,    39,    81,    59,   -38,   -62,    -9,
     -62,    -3,   -16,   -62,   -62,   -62,     7,    53,    85,   -62,
      62,    65,    53,    43,   -62,   -62,   -38,    43,   -62,   -38,
      41,    49,   -38,   -38,   -38,   -38,   -38,   -62,   -62,    53,
      85,    72,    47,   -62,   -62,   -62,   -62,   -62,   -62,   -38,
      82,    87,    53,    53,   -62,    75,    93,   -62,   -62,   -62,
     -38,   -62,   -62,   -62,   -62,   -62,    58,   -38,   -62,   -62,
      43,    43,   -62,   -62,    94,    97,   -62,    61,    70,   -62,
     -62,   -62,   -62,   101,    43,    53,   -38,   -62,   102,   -62,
     -62,   -62,   -62,   -62,   106,    43,   -62,   112,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     4,    10,     0,     1,     3,     5,
       6,     0,    11,    15,     0,     0,     0,     0,     7,    11,
       0,    16,     0,    12,    13,     0,    11,     0,     0,     0,
       8,     0,     0,     0,     0,    14,     0,     0,    24,     0,
      31,     0,     0,    69,     0,     0,     0,     0,    43,    69,
      32,    35,    38,    42,    57,    59,     0,     0,     0,    18,
      51,    53,     0,     0,    29,    30,     0,    33,     9,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    60,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,     0,
       0,     0,     0,     0,    25,     0,     0,    34,    17,    44,
      47,    37,    36,    39,    40,    41,     0,     0,    61,    55,
       0,     0,    52,    54,     0,     0,    70,    49,     0,    48,
      62,    56,    19,     0,     0,     0,     0,    46,     0,    23,
      26,    28,    50,    20,     0,     0,    27,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   129,   131,   -62,   -62,   -62,   -62,    -1,   -12,   -62,
     116,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -61,
     -28,    12,   -62,   -62,   -62,    10,   -52,    44,    76,    63,
     -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    22,    32,    49,    14,    15,
      16,    44,    90,   128,   135,    91,    62,   114,   134,    45,
      58,    51,    52,    71,   118,   119,    59,    60,    61,    89,
      53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    46,    95,    66,     1,    82,    97,    23,    50,     5,
      47,    13,    48,     5,    28,     7,    13,    12,    13,    70,
      74,    75,    76,    24,    25,    13,    10,   106,    80,    81,
      46,    72,    73,    43,    46,    77,    78,    17,    96,   -45,
     112,    98,    18,    19,   101,   102,    20,    26,    27,   122,
     123,    81,    29,    36,    30,    79,    33,    48,     5,    31,
      37,   109,    43,   130,    38,    39,    43,    34,    40,    41,
      42,    35,   117,   131,   137,    63,    64,    46,    46,   121,
      65,    54,    55,    66,    67,    56,   103,   104,   105,    68,
      99,    46,    69,    92,     5,    93,   108,   100,   117,   115,
     110,    57,    46,    48,     5,   111,   116,   120,   126,    43,
      43,    83,    84,    85,    86,    87,    88,   124,   125,   127,
     129,    99,   133,    43,    83,    84,    85,    86,    87,    88,
     136,   138,     8,    21,    43,     9,   132,   113,    94,     0,
       0,     0,     0,   107
};

static const yytype_int16 yycheck[] =
{
       1,    34,    63,    12,     9,    57,    67,    19,    36,    51,
      48,    12,    50,    51,    26,     0,    17,     3,    19,    47,
      36,    37,    38,    14,    15,    26,    45,    79,    56,    57,
      63,    34,    35,    34,    67,    28,    29,    47,    66,    48,
      92,    69,     4,    45,    72,    73,    46,     5,    12,   110,
     111,    79,    50,    10,     6,    48,    16,    50,    51,    13,
      17,    89,    63,   124,    21,    22,    67,     7,    25,    26,
      27,    14,   100,   125,   135,    23,    51,   110,   111,   107,
      51,    28,    29,    12,    45,    32,    74,    75,    76,     8,
      49,   124,    33,    31,    51,    30,    49,    48,   126,    24,
      18,    48,   135,    50,    51,    18,    13,    49,    47,   110,
     111,    39,    40,    41,    42,    43,    44,    23,    21,    49,
      19,    49,    20,   124,    39,    40,    41,    42,    43,    44,
      24,    19,     3,    17,   135,     4,   126,    93,    62,    -1,
      -1,    -1,    -1,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    53,    54,    55,    51,    59,     0,    53,    54,
      45,    56,     3,    59,    60,    61,    62,    47,     4,    45,
      46,    62,    57,    60,    14,    15,     5,    12,    60,    50,
       6,    13,    58,    16,     7,    14,    10,    17,    21,    22,
      25,    26,    27,    59,    63,    71,    82,    48,    50,    59,
      72,    73,    74,    82,    28,    29,    32,    48,    72,    78,
      79,    80,    68,    23,    51,    51,    12,    45,     8,    33,
      72,    75,    34,    35,    36,    37,    38,    28,    29,    48,
      72,    72,    78,    39,    40,    41,    42,    43,    44,    81,
      64,    67,    31,    30,    80,    71,    72,    71,    72,    49,
      48,    72,    72,    73,    73,    73,    78,    81,    49,    72,
      18,    18,    78,    79,    69,    24,    13,    72,    76,    77,
      49,    72,    71,    71,    23,    21,    47,    49,    65,    19,
      71,    78,    77,    20,    70,    66,    24,    71,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    56,    57,    58,    55,
      59,    60,    60,    61,    61,    62,    62,    63,    64,    65,
      66,    63,    67,    63,    68,    69,    70,    63,    63,    63,
      63,    63,    63,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    75,    74,    76,    76,    77,
      77,    78,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,     0,     0,    15,
       1,     0,     3,     3,     8,     1,     3,     3,     0,     0,
       0,    10,     0,     6,     0,     0,     0,     8,     6,     2,
       2,     1,     2,     2,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     1,     3,     0,     5,     0,     1,     1,
       3,     1,     3,     1,     3,     3,     4,     1,     2,     1,
       2,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 85 "phase3.y" /* yacc.c:1646  */
    {}
#line 1408 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "phase3.y" /* yacc.c:1646  */
    {
		
	}
#line 1416 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "phase3.y" /* yacc.c:1646  */
    {
	   printf("func %s\n", (yyvsp[-1].op_val));
	}
#line 1424 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "phase3.y" /* yacc.c:1646  */
    {
		
	}
#line 1432 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 106 "phase3.y" /* yacc.c:1646  */
    {
		
	}
#line 1440 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "phase3.y" /* yacc.c:1646  */
    {
		cout << "endfunc" << endl;
	}
#line 1448 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "phase3.y" /* yacc.c:1646  */
    {(yyval.op_val) = (yyvsp[0].op_val);}
#line 1454 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 125 "phase3.y" /* yacc.c:1646  */
    {
	 while(!identifierStack.empty()) {
		 cout << ". " << identifierStack.top() << endl;
		 identifierStack.pop();
	 	}
	}
#line 1465 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "phase3.y" /* yacc.c:1646  */
    {
	while(!identifierStack.empty())	{
		cout << ".[] " << identifierStack.top() <<"," << (yyvsp[-3].op_val) << endl;
		identifierStack.pop();
		}
	}
#line 1476 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "phase3.y" /* yacc.c:1646  */
    {
        identifierStack.push((yyvsp[0].op_val));
	}
#line 1484 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 146 "phase3.y" /* yacc.c:1646  */
    {	
		identifierStack.push((yyvsp[-2].op_val));	  
	}
#line 1492 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 153 "phase3.y" /* yacc.c:1646  */
    {
 			char *dest = (yyvsp[-2].op_val);
 			char *src  = (yyvsp[0].op_val);
 			printf("= %s, %s\n", dest, src);
		}
#line 1502 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 160 "phase3.y" /* yacc.c:1646  */
    {	
			//cout << "WRONG GRAMMAR1" << endl;
			cout << "! " << (yyvsp[0].op_val) << ", " << (yyvsp[0].op_val) << endl;
			cout << "?:= " << "label" << index_label << ", " << (yyvsp[0].op_val) << endl;
		}
#line 1512 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 166 "phase3.y" /* yacc.c:1646  */
    {
			cout << ":= end"<< index_end_label << endl;
		}
#line 1520 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 170 "phase3.y" /* yacc.c:1646  */
    {
			cout << ": label" << index_label++ << endl;
		}
#line 1528 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 174 "phase3.y" /* yacc.c:1646  */
    {
			//cout << "WRONG GRAMMAR" << endl;
			cout << ": end" << index_end_label++ << endl;
			//cout << "WRONG GRAMMAR" << endl;
		}
#line 1538 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 181 "phase3.y" /* yacc.c:1646  */
    {
			//cout << "RIGHT GRAMMAR1" << endl;
			cout <<"! " << (yyvsp[0].op_val) << ", " << (yyvsp[0].op_val) << endl;
			cout << "?:= " << "label" << index_label << ", " << (yyvsp[0].op_val) << endl;
		}
#line 1548 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 187 "phase3.y" /* yacc.c:1646  */
    {
			//cout << "NO ELSE" << endl;
			cout << ": label" << index_label++ << endl;
		}
#line 1557 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 192 "phase3.y" /* yacc.c:1646  */
    {
			whileStack.push(index_label++);
			cout << ": label" << whileStack.top() << endl;
		}
#line 1566 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 197 "phase3.y" /* yacc.c:1646  */
    {
			// push stack
			//whileStack.push("label" + index_label++);
			//cout << ": label" << index_label << endl;
			cout << "?:= loop_body" << whileStack.top() << ", " << (yyvsp[0].op_val) << endl;
			cout << ":= loop_end" << whileStack.top() << endl;
			cout << ": loop_body" << whileStack.top() << endl;
		}
#line 1579 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 206 "phase3.y" /* yacc.c:1646  */
    {
    			// loop body.
		}
#line 1587 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 210 "phase3.y" /* yacc.c:1646  */
    {
   			// end of the loop
			cout << ":= label" << whileStack.top() << endl;
   			cout << ": loop_end" << whileStack.top() << endl;
			// pop stack
			whileStack.pop();
		}
#line 1599 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 218 "phase3.y" /* yacc.c:1646  */
    {
			
		}
#line 1607 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 222 "phase3.y" /* yacc.c:1646  */
    {
			printf(".< %s\n", (yyvsp[0].op_val));
		}
#line 1615 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 226 "phase3.y" /* yacc.c:1646  */
    {
			printf(".> %s\n", (yyvsp[0].op_val));
		}
#line 1623 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 230 "phase3.y" /* yacc.c:1646  */
    {
			//cout << "CONTIUNE" << endl;
			cout << ":= label" << whileStack.top() << endl;			
		}
#line 1632 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 235 "phase3.y" /* yacc.c:1646  */
    {
			
		}
#line 1640 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 249 "phase3.y" /* yacc.c:1646  */
    {
			//std::cout<< "abcde"<<endl;
			(yyval.op_val) = (yyvsp[0].op_val); 
		}
#line 1649 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 255 "phase3.y" /* yacc.c:1646  */
    {
		char *src1 = (yyvsp[-2].op_val);
		char *src2 = (yyvsp[0].op_val);
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "+ " << *dest << ", " << *src1 << ", " << *src2 << endl;
		(yyval.op_val) = (char*)dest->c_str();
	}
#line 1665 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 267 "phase3.y" /* yacc.c:1646  */
    {
		char *src1 = (yyvsp[-2].op_val);
		char *src2 = (yyvsp[0].op_val);
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << dest << endl;
		cout << "- " << dest << ", " << src1 << ", " << src2 << endl;
		(yyval.op_val) = (char*)dest->c_str();
	}
#line 1681 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 281 "phase3.y" /* yacc.c:1646  */
    { 
			//cout<<"term: "<< $1 << endl; 
			(yyval.op_val) = (yyvsp[0].op_val);
		}
#line 1690 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 287 "phase3.y" /* yacc.c:1646  */
    { 
		char *src1 = (yyvsp[-2].op_val);
		char *src2 = (yyvsp[0].op_val);
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "* " << *dest << ", " << src1 << ", " << src2 << endl;
		(yyval.op_val) = (char*)dest->c_str();
		}
#line 1706 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 299 "phase3.y" /* yacc.c:1646  */
    {
		char *src1 = (yyvsp[-2].op_val);
		char *src2 = (yyvsp[0].op_val);
		char buffer[10];
		string *dest = new string; 
		//*dest = "temp" + to_string(count++);
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "/ " << *dest << ", " << src1 << ", " << src2 << endl;
		(yyval.op_val) = (char*)dest->c_str();
		}
#line 1723 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 312 "phase3.y" /* yacc.c:1646  */
    {
		char *src1 = (yyvsp[-2].op_val);
		char *src2 = (yyvsp[0].op_val);
		//char *dest = new char[10];
		//dest = "temp";
		char buffer[10];
		string *dest = new string; 
		//*dest = "temp" + to_string(count++);
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "%" << *dest << ", " << src1 << ", " << src2 << endl;
		(yyval.op_val) = (char*)dest->c_str();
		}
#line 1742 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 329 "phase3.y" /* yacc.c:1646  */
    {   
			//cout<<"var: " << $1 << endl;
			(yyval.op_val) = (yyvsp[0].op_val);

		}
#line 1752 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 335 "phase3.y" /* yacc.c:1646  */
    {
			//cout<<"Number: " << $1 << endl;
			(yyval.op_val) = (yyvsp[0].op_val);
		}
#line 1761 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 340 "phase3.y" /* yacc.c:1646  */
    {
		(yyval.op_val) = (yyvsp[-1].op_val);
	}
#line 1769 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 343 "phase3.y" /* yacc.c:1646  */
    {}
#line 1775 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 344 "phase3.y" /* yacc.c:1646  */
    {  
		char buffer[10]; // Create buffer
		string *dest = new string;
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout<< "call" << (char*)dest->c_str();
	}
#line 1787 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 361 "phase3.y" /* yacc.c:1646  */
    {  
	  printf("param %s\n", (yyvsp[0].op_val));
	}
#line 1795 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 366 "phase3.y" /* yacc.c:1646  */
    {

	}
#line 1803 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 373 "phase3.y" /* yacc.c:1646  */
    {
		(yyval.op_val) = (yyvsp[0].op_val);
	}
#line 1811 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 382 "phase3.y" /* yacc.c:1646  */
    {
		(yyval.op_val) = (yyvsp[0].op_val);
	}
#line 1819 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 387 "phase3.y" /* yacc.c:1646  */
    {}
#line 1825 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 391 "phase3.y" /* yacc.c:1646  */
    {
		char *src1 = (yyvsp[-2].op_val);
		char *src2 = (yyvsp[0].op_val);
		//char *sign = $2;
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << compStack.top();
		compStack.pop(); 
		cout << " " << *dest << ", " << src1 << ", " << src2 << endl; // == dest, src1, src2
		(yyval.op_val) = (char*)dest->c_str();
	}
#line 1844 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 423 "phase3.y" /* yacc.c:1646  */
    {
		//$$=$1;
		compStack.push("==");
	}
#line 1853 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 429 "phase3.y" /* yacc.c:1646  */
    {
			compStack.push("!=");
		}
#line 1861 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 433 "phase3.y" /* yacc.c:1646  */
    {
			compStack.push("<");
		}
#line 1869 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 437 "phase3.y" /* yacc.c:1646  */
    {
			compStack.push(">");
		}
#line 1877 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 442 "phase3.y" /* yacc.c:1646  */
    {
			compStack.push("<=");
		}
#line 1885 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 447 "phase3.y" /* yacc.c:1646  */
    {
			compStack.push(">=");
		}
#line 1893 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 454 "phase3.y" /* yacc.c:1646  */
    {
			//cout << "ident: " << $1 << endl;
			(yyval.op_val) = (yyvsp[0].op_val);
	}
#line 1902 "phase3.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 459 "phase3.y" /* yacc.c:1646  */
    { 
		char *src1 = (yyvsp[-3].op_val);
		char *src2 = (yyvsp[-1].op_val);
		char buffer[10];
		string *dest = new string; 
		sprintf(buffer, "%d", count++);
		*dest = string("temp") + buffer;
		cout << ". " << *dest << endl;
		cout << "=[]" << *dest << ", " << src1 << ", " << src2 << endl;
	}
#line 1917 "phase3.tab.c" /* yacc.c:1646  */
    break;


#line 1921 "phase3.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 487 "phase3.y" /* yacc.c:1906  */


int main(int argc, char **argv)
{
   yyparse();
   return 0;
}

void yyerror(const char *msg)
{
   if(myError == 0)
   {
      printf("** Line %d: %s\n", currLine, msg);
      otherError = 1;
   }
   else
   {
      if(otherError == 1)
      {
         printf("   (%s)\n", msg);
         otherError = 0;
      }
   }
   myError = 0;
}
