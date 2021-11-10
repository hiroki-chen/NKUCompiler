/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     ADD = 259,
     MINUS = 260,
     MUL = 261,
     DIV = 262,
     MOD = 263,
     INC = 264,
     DEC = 265,
     EQ = 266,
     NEQ = 267,
     GEQ = 268,
     LEQ = 269,
     G = 270,
     L = 271,
     BIT_AND = 272,
     BIT_OR = 273,
     BIT_XOR = 274,
     BIT_NEG = 275,
     LOGIC_AND = 276,
     LOGIC_OR = 277,
     LOGIC_NOT = 278,
     DECIMAL = 279,
     OCTAL = 280,
     HEX = 281,
     STRING = 282,
     INT = 283,
     DOUBLE = 284,
     FLOAT = 285,
     CHAR = 286,
     VOID = 287,
     STRUCT_TOKEN = 288,
     IF = 289,
     ELSE = 290,
     WHILE = 291,
     FOR = 292,
     RETURN = 293,
     BREAK = 294,
     CONTINUE = 295,
     CONST = 296,
     ASSIGN = 297,
     TRUE = 298,
     FALSE = 299,
     LBRACE = 300,
     RBRACE = 301,
     LPARENTHESIS = 302,
     RPARENTHESIS = 303,
     LSQUARE = 304,
     RSQUARE = 305,
     SEMICOLON = 306,
     DOT = 307,
     COMMA = 308
   };
#endif
/* Tokens.  */
#define ID 258
#define ADD 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define INC 264
#define DEC 265
#define EQ 266
#define NEQ 267
#define GEQ 268
#define LEQ 269
#define G 270
#define L 271
#define BIT_AND 272
#define BIT_OR 273
#define BIT_XOR 274
#define BIT_NEG 275
#define LOGIC_AND 276
#define LOGIC_OR 277
#define LOGIC_NOT 278
#define DECIMAL 279
#define OCTAL 280
#define HEX 281
#define STRING 282
#define INT 283
#define DOUBLE 284
#define FLOAT 285
#define CHAR 286
#define VOID 287
#define STRUCT_TOKEN 288
#define IF 289
#define ELSE 290
#define WHILE 291
#define FOR 292
#define RETURN 293
#define BREAK 294
#define CONTINUE 295
#define CONST 296
#define ASSIGN 297
#define TRUE 298
#define FALSE 299
#define LBRACE 300
#define RBRACE 301
#define LPARENTHESIS 302
#define RPARENTHESIS 303
#define LSQUARE 304
#define RSQUARE 305
#define SEMICOLON 306
#define DOT 307
#define COMMA 308




/* Copy the first part of user declarations.  */
#line 3 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"

    /*************************************************************
    parser.ypp
    YACC FILE
    Date: 2021/10/18
    Haobin Chen (@Aoyamahiroki) <etyyuiope@gmail.com>
    Jiawei Xu   (@Darren-8)

    Main tokenizer
    **************************************************************/
    #include <common/types.hh>
    #include <common/compile_excepts.hh>
    #include <runtime/runtime.hh>
    #include <frontend/nodes/item_all.hh>
    #include <frontend/parser/parser.hh>
    #include <sylib.hh>

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <stdexcept>

    //extern compiler::Symbol_table symbol_table;
    extern uint32_t yylineno;
    extern int yydebug;

    extern compiler::Compiler_runtime* compiler_runtime;

    extern int yylex(void);
    extern int yyget_lineno(void);
    extern int yylex_destroy(void);

    #ifdef YYDEBUG
    #undef YYDEBUG
    #endif
    #define YYDEBUG 1
    # define YYLLOC_DEFAULT(Cur, Rhs, N)                          \
    do {                                                          \
        if (N) {                                                  \
            (Cur).first_line   = YYRHSLOC(Rhs, 1).first_line;     \
            (Cur).first_column = YYRHSLOC(Rhs, 1).first_column;   \
            (Cur).last_line    = YYRHSLOC(Rhs, N).last_line;      \
            (Cur).last_column  = YYRHSLOC(Rhs, N).last_column;    \
        } else {                                                  \
            (Cur).first_line   = (Cur).last_line   =              \
                YYRHSLOC(Rhs, 0).last_line;                       \
            (Cur).first_column = (Cur).last_column =              \
                YYRHSLOC(Rhs, 0).last_column;                     \
        }                                                         \
    } while (0)

    void yyerror(const char* str)
    {
        std::ostringstream oss;
        oss << "\033[1;31;490m" << yylloc.first_line << ':'
            << yylloc.first_column << " : [ERROR]: " << str << "\033[0m" <<std::endl;
        throw compiler::parse_error(oss.str());
        yylex_destroy();
    }

    extern FILE* yyin;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 66 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
{
    compiler::basic_type                btype;
    compiler::Item_root*                item_root;               // root
    compiler::Item_decl*                item_decl;
    compiler::Item_stmt*                item_stmt;
    compiler::Item_stmt_decl*           item_stmt_decl;
    compiler::Item_func_def*            item_func_def;
    compiler::Item_expr*                item_expr;
    compiler::Item_expr_comma*          item_expr_comma;
    compiler::Item_ident*               item_ident;
    compiler::Item_ident_array*         item_ident_array;
    compiler::Item_ident_pointer*       item_ident_pointer;
    compiler::Item_decl_array_init*     item_decl_array_init;
    compiler::Item_literal*             item_literal;
    compiler::Item_literal_array_init*  item_literal_array_init;
    compiler::Item_decl_var*            item_decl_var;
    compiler::Item_decl_var_init*       item_decl_var_init;
    compiler::Item_func_def_list*       item_func_def_list;
    compiler::Item_func_def_arg*        item_func_def_arg;
    compiler::Item_func_call_list*      item_func_call_list;
    compiler::Item_block*               item_block;
    compiler::Item_struct_body*         item_struct_body;
    std::string*                        raw_string;
    double                              raw_number;
    char                                raw_char;
}
/* Line 193 of yacc.c.  */
#line 292 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.cc"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 317 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.cc"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   641

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNRULES -- Number of states.  */
#define YYNSTATES  284

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    15,    17,    19,
      22,    25,    28,    30,    32,    34,    36,    38,    41,    45,
      49,    53,    57,    60,    64,    66,    71,    73,    76,    78,
      80,    84,    86,    90,    92,    95,    98,   102,   104,   109,
     114,   118,   121,   123,   125,   129,   133,   137,   144,   151,
     157,   163,   167,   169,   171,   173,   176,   180,   185,   189,
     191,   195,   199,   201,   203,   207,   209,   213,   216,   220,
     222,   225,   227,   229,   231,   233,   235,   237,   239,   241,
     243,   245,   247,   250,   253,   256,   260,   266,   274,   277,
     279,   285,   292,   300,   307,   315,   318,   322,   325,   328,
     331,   334,   336,   338,   343,   348,   350,   352,   356,   360,
     364,   368,   370,   374,   376,   380,   384,   386,   390,   394,
     398,   402,   404,   406,   410,   414,   416,   420,   424,   426,
     430,   434,   436,   440,   444,   446,   450,   454,   458,   460,
     463,   466,   469,   472,   475,   478,   480,   482,   486,   488,
     490,   492,   494,   496,   498,   500,   502,   504,   506,   510,
     515,   519
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    55,    56,    -1,    55,    75,    -1,    56,
      -1,    75,    -1,    58,    -1,    59,    -1,    57,    -1,    63,
      51,    -1,    61,    51,    -1,    62,    51,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1,    27,    -1,    60,    66,
      -1,    61,    53,    66,    -1,    41,    60,    72,    -1,    62,
      53,    72,    -1,    60,    41,    72,    -1,    33,    64,    -1,
      63,    53,    64,    -1,    80,    -1,    80,    45,    65,    46,
      -1,    56,    -1,    65,    56,    -1,    67,    -1,    69,    -1,
      80,    42,    97,    -1,    80,    -1,    68,    42,    97,    -1,
      68,    -1,     6,     3,    -1,     6,    68,    -1,    70,    42,
      71,    -1,    70,    -1,    70,    49,    97,    50,    -1,    80,
      49,    97,    50,    -1,    45,    81,    46,    -1,    45,    46,
      -1,    73,    -1,    74,    -1,    80,    42,    97,    -1,    68,
      42,    97,    -1,    70,    42,    71,    -1,    60,    80,    47,
      76,    48,    82,    -1,    32,    80,    47,    76,    48,    82,
      -1,    60,    80,    47,    48,    82,    -1,    32,    80,    47,
      48,    82,    -1,    76,    53,    77,    -1,    77,    -1,    78,
      -1,    79,    -1,    60,    80,    -1,    41,    60,    80,    -1,
      60,    80,    49,    50,    -1,    79,    49,    50,    -1,     3,
      -1,    81,    53,    71,    -1,    81,    53,    97,    -1,    71,
      -1,    99,    -1,    99,    53,    71,    -1,    98,    -1,    98,
      53,    71,    -1,    45,    46,    -1,    45,    83,    46,    -1,
      84,    -1,    83,    84,    -1,    56,    -1,    85,    -1,    82,
      -1,    91,    -1,    92,    -1,    89,    -1,    88,    -1,    86,
      -1,    87,    -1,    93,    -1,    90,    -1,    39,    51,    -1,
      40,    51,    -1,    38,    51,    -1,    38,    97,    51,    -1,
      34,    47,    97,    48,    85,    -1,    34,    47,    97,    48,
      85,    35,    85,    -1,    97,    51,    -1,    51,    -1,    36,
      47,    97,    48,    85,    -1,    37,    47,    90,    90,    48,
      82,    -1,    37,    47,    90,    90,    48,    97,    82,    -1,
      37,    47,    56,    90,    48,    82,    -1,    37,    47,    56,
      90,    97,    48,    82,    -1,    94,    51,    -1,    95,    42,
      97,    -1,    95,     9,    -1,    95,    10,    -1,     9,    95,
      -1,    10,    95,    -1,    80,    -1,    96,    -1,    95,    49,
      97,    50,    -1,    96,    49,    97,    50,    -1,    99,    -1,
      98,    -1,    99,    53,    99,    -1,    98,    53,    99,    -1,
     100,    22,   100,    -1,    99,    22,   100,    -1,   100,    -1,
     100,    21,   103,    -1,   103,    -1,   102,    11,   102,    -1,
     102,    12,   102,    -1,   102,    -1,   102,    13,   102,    -1,
     102,    14,   102,    -1,   102,    15,   102,    -1,   102,    16,
     102,    -1,   107,    -1,   104,    -1,   105,    18,   105,    -1,
     104,    18,   105,    -1,   105,    -1,   106,    19,   106,    -1,
     105,    19,   106,    -1,   106,    -1,   101,    17,   101,    -1,
     106,    17,   101,    -1,   101,    -1,   107,     4,   108,    -1,
     107,     5,   108,    -1,   108,    -1,   108,     6,   109,    -1,
     108,     7,   109,    -1,   108,     8,   109,    -1,   109,    -1,
       4,   109,    -1,     5,   109,    -1,    23,   109,    -1,    20,
     109,    -1,    17,   109,    -1,     6,   109,    -1,   112,    -1,
     110,    -1,    47,    97,    48,    -1,    95,    -1,   111,    -1,
      94,    -1,    26,    -1,    25,    -1,    24,    -1,    31,    -1,
      27,    -1,    43,    -1,    44,    -1,    80,    47,    48,    -1,
      80,    47,   113,    48,    -1,   113,    53,   103,    -1,   103,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   150,   151,   152,   155,   156,   157,   160,
     163,   166,   169,   170,   171,   172,   173,   176,   177,   180,
     181,   182,   185,   186,   189,   190,   193,   194,   197,   198,
     201,   202,   203,   204,   207,   208,   211,   212,   215,   216,
     219,   220,   223,   224,   227,   228,   231,   234,   235,   236,
     237,   240,   241,   244,   245,   248,   249,   252,   257,   260,
     263,   264,   269,   270,   275,   281,   286,   294,   295,   298,
     299,   302,   303,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   317,   320,   323,   324,   327,   328,   331,   332,
     335,   338,   339,   340,   341,   344,   347,   348,   357,   366,
     367,   370,   371,   374,   375,   378,   379,   382,   383,   386,
     387,   388,   391,   392,   395,   396,   397,   400,   401,   402,
     403,   404,   408,   411,   412,   413,   416,   417,   418,   421,
     422,   423,   426,   427,   428,   431,   432,   433,   434,   437,
     438,   439,   440,   441,   442,   443,   444,   447,   448,   449,
     450,   453,   454,   455,   456,   457,   458,   459,   462,   463,
     466,   467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "ADD", "MINUS", "MUL", "DIV",
  "MOD", "INC", "DEC", "EQ", "NEQ", "GEQ", "LEQ", "G", "L", "BIT_AND",
  "BIT_OR", "BIT_XOR", "BIT_NEG", "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT",
  "DECIMAL", "OCTAL", "HEX", "STRING", "INT", "DOUBLE", "FLOAT", "CHAR",
  "VOID", "STRUCT_TOKEN", "IF", "ELSE", "WHILE", "FOR", "RETURN", "BREAK",
  "CONTINUE", "CONST", "ASSIGN", "TRUE", "FALSE", "LBRACE", "RBRACE",
  "LPARENTHESIS", "RPARENTHESIS", "LSQUARE", "RSQUARE", "SEMICOLON", "DOT",
  "COMMA", "$accept", "CompUnit", "Decl", "StructDeclStmt", "VarDeclStmt",
  "ConstDeclStmt", "BType", "VarDecl", "ConstDecl", "StructDecl",
  "StructDef", "Body", "VarDef", "VarDefNormal", "POINTER", "VarDefArray",
  "ArrayID", "ArrayInitVal", "ConstDef", "ConstDefNormal", "ConstDefArray",
  "FuncDef", "FuncDefList", "FuncParam", "FuncParamNormal",
  "FuncParamArray", "Ident", "ArrayInitValHelper", "BLOCK", "BlockItems",
  "BlockItem", "Stmt", "BreakStmt", "ContinueStmt", "ReturnStmt",
  "eIfStmt", "ExpStmt", "WhileStmt", "ForStmt", "AssignStmt", "Assignment",
  "LVal", "ArrayItem", "Exp", "CommaExp", "LOrExp", "LAndExp", "EqExp",
  "RelExp", "BitExp", "BitOrExp", "BitXorExp", "BitAndExp", "AddExp",
  "MulExp", "UnaryExp", "PrimaryExp", "LITERAL", "FunctionCall",
  "FunctionRParams", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    56,    56,    56,    57,
      58,    59,    60,    60,    60,    60,    60,    61,    61,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    75,    75,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    87,    88,    88,    89,    89,    90,    90,
      91,    92,    92,    92,    92,    93,    94,    94,    94,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,    99,   100,   100,   101,   101,   101,   102,   102,   102,
     102,   102,   103,   104,   104,   104,   105,   105,   105,   106,
     106,   106,   107,   107,   107,   108,   108,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     113,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     3,     2,     3,     1,     4,     1,     2,     1,     1,
       3,     1,     3,     1,     2,     2,     3,     1,     4,     4,
       3,     2,     1,     1,     3,     3,     3,     6,     6,     5,
       5,     3,     1,     1,     1,     2,     3,     4,     3,     1,
       3,     3,     1,     1,     3,     1,     3,     2,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     3,     5,     7,     2,     1,
       5,     6,     7,     6,     7,     2,     3,     2,     2,     2,
       2,     1,     1,     4,     4,     1,     1,     3,     3,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     2,     2,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    12,    13,    14,    15,     0,     0,     0,     0,
       4,     8,     6,     7,     0,     0,     0,     0,     5,    59,
       0,    22,    24,     0,     1,     2,     3,     0,     0,    17,
      28,    33,    29,    37,    31,    10,     0,    11,     0,     9,
       0,     0,     0,     0,     0,    19,    42,    43,     0,    34,
      35,    21,     0,     0,     0,     0,     0,     0,    18,    31,
      20,    23,     0,     0,     0,     0,    52,    53,    54,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   153,   152,   151,   155,   154,   156,   157,
       0,   101,   150,   148,   102,    32,   106,   105,   111,   131,
     116,   113,   122,   125,   128,   121,   134,   138,   146,   149,
     145,     0,    36,     0,    30,     0,     0,     0,     0,     0,
      50,    55,     0,     0,     0,    25,    27,    45,    46,    44,
     139,   140,   144,   101,    99,   100,   143,   142,   141,     0,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,    62,
       0,    65,    63,    38,    49,     0,    39,    56,   155,   154,
       0,     0,     0,     0,     0,     0,    67,    89,    71,    73,
       0,    69,    72,    78,    79,    77,    76,    81,    74,    75,
      80,   150,     0,     0,    48,    51,    58,   147,   158,   161,
       0,    96,     0,     0,   108,   110,   107,   112,   109,   129,
     114,   115,   117,   118,   119,   120,   124,   123,   127,   130,
     126,   132,   133,   135,   136,   137,    40,     0,     0,     0,
      47,     0,     0,     0,    84,     0,    82,    83,    68,    70,
      95,    88,    57,   159,     0,   103,   104,    60,    61,    66,
      64,     0,     0,     0,     0,    85,   160,     0,     0,     0,
       0,    86,    90,     0,     0,     0,     0,    93,     0,    91,
       0,    87,    94,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,   188,    11,    12,    13,    70,    15,    16,    17,
      21,    71,    29,    30,    31,    32,    33,   112,    45,    46,
      47,    18,    65,    66,    67,    68,    91,   170,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      92,    93,    94,   202,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   210
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -207
static const yytype_int16 yypact[] =
{
     165,  -207,  -207,  -207,  -207,  -207,    27,    27,   255,    56,
    -207,  -207,  -207,  -207,    19,   151,   162,   219,  -207,  -207,
      33,  -207,     6,     9,  -207,  -207,  -207,    92,     9,  -207,
    -207,    54,  -207,   -11,   105,  -207,     9,  -207,     9,  -207,
      27,    74,   376,    57,    26,  -207,  -207,  -207,    32,  -207,
    -207,  -207,   594,    91,   594,   594,    79,   594,  -207,    86,
    -207,  -207,   255,   122,    27,    24,  -207,  -207,    17,  -207,
      19,   112,   594,    91,   594,   594,   594,   594,    27,    27,
     594,   594,   594,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
     594,   127,  -207,     4,   152,  -207,   163,     2,   102,   188,
     620,  -207,   205,   159,   270,   144,   214,  -207,  -207,  -207,
    -207,   505,  -207,   190,  -207,   122,    98,   191,    27,   222,
    -207,   208,   122,   599,   194,  -207,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,   215,   215,  -207,  -207,  -207,   206,
     447,  -207,  -207,   594,   594,   594,   594,   594,   594,   594,
     594,   594,   594,   594,   594,   594,   594,   594,   594,   594,
     594,   594,   594,   594,   594,   594,   594,   594,  -207,  -207,
     104,   218,    14,  -207,  -207,   122,  -207,  -207,    38,    59,
     231,   232,   246,   156,   252,   262,  -207,  -207,  -207,  -207,
     271,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,  -207,
    -207,   268,   269,   256,  -207,  -207,  -207,  -207,  -207,  -207,
     115,  -207,   277,   278,   299,   310,   299,  -207,   310,  -207,
     195,   195,  -207,  -207,  -207,  -207,   313,   313,   316,  -207,
     316,   214,   214,  -207,  -207,  -207,  -207,   536,   536,   536,
    -207,   594,   594,   369,  -207,   283,  -207,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,   594,  -207,  -207,  -207,  -207,  -207,
    -207,   287,   288,   418,   418,  -207,  -207,   320,   320,   476,
     290,   304,  -207,   122,   293,   565,   320,  -207,   122,  -207,
     122,  -207,  -207,  -207
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,     0,  -207,  -207,  -207,     8,  -207,  -207,  -207,
     302,  -207,   312,  -207,   106,  -207,    88,   -68,    31,  -207,
    -207,   340,   294,   229,  -207,  -207,    12,  -207,   -61,  -207,
     171,  -155,  -207,  -207,  -207,  -207,  -206,  -207,  -207,  -207,
    -112,   110,  -207,   -51,   242,  -101,    25,   -88,    81,  -129,
    -207,    71,   130,  -207,    21,   -48,  -207,  -207,  -207,  -207
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -17
static const yytype_int16 yytable[] =
{
      10,    95,   120,   113,   114,   128,   117,   201,    14,    25,
     172,   209,    19,   141,   142,    27,    23,    14,    20,    22,
     217,   127,    19,   129,   147,    27,    34,   130,   131,   132,
      19,    53,   136,   137,   138,    48,   147,   264,    54,   139,
      48,   -16,    69,   169,   -16,   214,   143,   216,    59,    64,
      48,    42,    22,   144,   174,   148,    24,   269,   270,    51,
      28,   204,   -15,   219,    64,   -15,   124,   239,    73,    60,
     118,   126,   122,   229,    74,    54,   121,   123,   201,   -16,
      41,    57,    59,     1,     2,     3,     4,     5,     6,     7,
     133,   133,   211,   212,   213,    49,    52,     8,    27,    72,
     -15,     1,     2,     3,     4,     5,     1,     2,     3,     4,
       5,    44,   271,   272,   240,    62,    44,   233,   234,   235,
      62,   281,    63,   149,   150,   266,    44,   115,    55,    43,
     177,    64,   245,    50,    43,    57,   111,   214,   216,     1,
       2,     3,     4,     5,    43,     7,   175,    55,   163,   164,
     236,   123,    56,     8,    57,   201,   201,   237,   125,    19,
      75,    76,    77,   253,   201,    78,    79,   119,   254,   257,
     259,   260,   215,    80,   140,   218,    81,   159,   160,    82,
      83,    84,    85,    86,   231,   232,   258,    87,   134,   135,
     261,   262,     1,     2,     3,     4,     5,     6,     7,    88,
      89,   145,    35,    90,    36,   151,     8,   244,   154,   155,
     156,   157,   277,    37,   279,    38,   146,   282,   274,   283,
     165,   166,   167,   158,   280,    19,    75,    76,    77,   226,
     227,    78,    79,   220,   221,   222,   223,   224,   225,    80,
     173,   176,    81,   263,   206,    82,    83,    84,    85,   178,
       2,     3,     4,   179,   207,     7,   180,   203,   181,   182,
     183,   184,   185,     8,   144,    88,    89,   119,   186,    90,
      39,   238,    40,   187,    19,    75,    76,    77,   241,   242,
      78,    79,     1,     2,     3,     4,     5,   161,    80,   162,
     228,    81,   230,   243,    82,    83,    84,    85,   178,     2,
       3,     4,   179,   246,     7,   180,   252,   181,   182,   183,
     184,   185,     8,   247,    88,    89,   119,   248,    90,   250,
     251,   147,   187,    19,    75,    76,    77,   255,   256,    78,
      79,   149,   160,   161,   265,   267,   268,    80,   275,   276,
      81,   278,    61,    82,    83,    84,    85,    86,    58,    26,
     116,    87,   205,   171,   180,     0,   181,   182,   183,   184,
     185,   249,     0,    88,    89,   119,     0,    90,     0,     0,
       0,   187,    19,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
       0,     0,    82,    83,    84,    85,   178,     2,     3,     4,
     179,     0,     7,     1,     2,     3,     4,     5,     0,     7,
       8,     0,    88,    89,     0,     0,    90,     8,     0,     0,
     187,    19,    75,    76,    77,     0,     0,    78,    79,     0,
       0,     0,     0,     0,     0,    80,     0,     0,    81,     0,
       0,    82,    83,    84,    85,    86,     0,     0,     0,    87,
      19,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    88,    89,     0,    80,    90,     0,    81,     0,   187,
      82,    83,    84,    85,    86,     0,     0,     0,    87,    19,
      75,    76,    77,     0,     0,    78,    79,     0,     0,     0,
      88,    89,     0,    80,    90,   208,    81,     0,     0,    82,
      83,    84,    85,    86,     0,     0,     0,    87,    19,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    88,
      89,     0,    80,    90,   273,    81,     0,     0,    82,    83,
      84,    85,    86,     0,     0,     0,    87,     0,     0,    19,
      75,    76,    77,     0,     0,    78,    79,     0,    88,    89,
     111,   168,    90,    80,     0,     0,    81,     0,     0,    82,
      83,    84,    85,    86,     0,     0,     0,    87,    19,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    88,
      89,   111,    80,    90,     0,    81,     0,     0,    82,    83,
      84,    85,    86,     0,     0,     0,    87,    19,    75,    76,
      77,     0,     0,    78,    79,     0,     0,     0,    88,    89,
     119,    80,    90,     0,    81,     0,     0,    82,    83,    84,
      85,    86,     0,     0,     0,    87,     1,     2,     3,     4,
       5,   152,   153,   154,   155,   156,   157,    88,    89,     0,
      62,    90
};

static const yytype_int16 yycheck[] =
{
       0,    52,    63,    54,    55,    73,    57,   119,     0,     9,
     111,   140,     3,     9,    10,     6,     8,     9,     6,     7,
     149,    72,     3,    74,    22,     6,    14,    75,    76,    77,
       3,    42,    80,    81,    82,    23,    22,   243,    49,    90,
      28,     3,    42,   111,     6,   146,    42,   148,    36,    41,
      38,    45,    40,    49,   115,    53,     0,   263,   264,    28,
      41,   122,     3,   151,    56,     6,    49,    53,    42,    38,
      62,    71,    48,   161,    42,    49,    64,    53,   190,    41,
      47,    49,    70,    27,    28,    29,    30,    31,    32,    33,
      78,    79,   143,   144,   145,     3,    42,    41,     6,    42,
      41,    27,    28,    29,    30,    31,    27,    28,    29,    30,
      31,    23,   267,   268,   175,    41,    28,   165,   166,   167,
      41,   276,    48,    21,    22,   254,    38,    48,    42,    23,
     118,   123,   183,    27,    28,    49,    45,   238,   239,    27,
      28,    29,    30,    31,    38,    33,    48,    42,     4,     5,
      46,    53,    47,    41,    49,   267,   268,    53,    46,     3,
       4,     5,     6,    48,   276,     9,    10,    45,    53,   237,
     238,   239,   147,    17,    47,   150,    20,    18,    19,    23,
      24,    25,    26,    27,   163,   164,   237,    31,    78,    79,
     241,   242,    27,    28,    29,    30,    31,    32,    33,    43,
      44,    49,    51,    47,    53,    17,    41,    51,    13,    14,
      15,    16,   273,    51,   275,    53,    53,   278,   269,   280,
       6,     7,     8,    18,   275,     3,     4,     5,     6,   158,
     159,     9,    10,   152,   153,   154,   155,   156,   157,    17,
      50,    50,    20,   243,    50,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    48,    33,    34,    49,    36,    37,
      38,    39,    40,    41,    49,    43,    44,    45,    46,    47,
      51,    53,    53,    51,     3,     4,     5,     6,    47,    47,
       9,    10,    27,    28,    29,    30,    31,    17,    17,    19,
     160,    20,   162,    47,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    51,    33,    34,    50,    36,    37,    38,
      39,    40,    41,    51,    43,    44,    45,    46,    47,    51,
      51,    22,    51,     3,     4,     5,     6,    50,    50,     9,
      10,    21,    19,    17,    51,    48,    48,    17,    48,    35,
      20,    48,    40,    23,    24,    25,    26,    27,    36,     9,
      56,    31,   123,   111,    34,    -1,    36,    37,    38,    39,
      40,   190,    -1,    43,    44,    45,    -1,    47,    -1,    -1,
      -1,    51,     3,     4,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    27,    28,    29,    30,    31,    -1,    33,
      41,    -1,    43,    44,    -1,    -1,    47,    41,    -1,    -1,
      51,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,
      -1,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    43,    44,    -1,    17,    47,    -1,    20,    -1,    51,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,     3,
       4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,
      43,    44,    -1,    17,    47,    48,    20,    -1,    -1,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,    43,
      44,    -1,    17,    47,    48,    20,    -1,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    10,    -1,    43,    44,
      45,    46,    47,    17,    -1,    -1,    20,    -1,    -1,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,    43,
      44,    45,    17,    47,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    -1,    -1,    43,    44,
      45,    17,    47,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    27,    28,    29,    30,
      31,    11,    12,    13,    14,    15,    16,    43,    44,    -1,
      41,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    28,    29,    30,    31,    32,    33,    41,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    75,     3,
      80,    64,    80,    60,     0,    56,    75,     6,    41,    66,
      67,    68,    69,    70,    80,    51,    53,    51,    53,    51,
      53,    47,    45,    68,    70,    72,    73,    74,    80,     3,
      68,    72,    42,    42,    49,    42,    47,    49,    66,    80,
      72,    64,    41,    48,    60,    76,    77,    78,    79,    56,
      60,    65,    42,    42,    42,     4,     5,     6,     9,    10,
      17,    20,    23,    24,    25,    26,    27,    31,    43,    44,
      47,    80,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    45,    71,    97,    97,    48,    76,    97,    60,    45,
      82,    80,    48,    53,    49,    46,    56,    97,    71,    97,
     109,   109,   109,    80,    95,    95,   109,   109,   109,    97,
      47,     9,    10,    42,    49,    49,    53,    22,    53,    21,
      22,    17,    11,    12,    13,    14,    15,    16,    18,    18,
      19,    17,    19,     4,     5,     6,     7,     8,    46,    71,
      81,    98,    99,    50,    82,    48,    50,    80,    27,    31,
      34,    36,    37,    38,    39,    40,    46,    51,    56,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    97,    49,    82,    77,    50,    48,    48,   103,
     113,    97,    97,    97,    99,   100,    99,   103,   100,   101,
     102,   102,   102,   102,   102,   102,   105,   105,   106,   101,
     106,   108,   108,   109,   109,   109,    46,    53,    53,    53,
      82,    47,    47,    47,    51,    97,    51,    51,    46,    84,
      51,    51,    50,    48,    53,    50,    50,    71,    97,    71,
      71,    97,    97,    56,    90,    51,   103,    48,    48,    90,
      90,    85,    85,    48,    97,    48,    35,    82,    48,    82,
      97,    85,    82,    82
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

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
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 149 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_root)->add_child((yyvsp[(2) - (2)].item_decl)); ;}
    break;

  case 3:
#line 150 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_root)->add_child((yyvsp[(2) - (2)].item_func_def)); ;}
    break;

  case 4:
#line 151 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[(1) - (1)].item_decl)); ;}
    break;

  case 5:
#line 152 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[(1) - (1)].item_func_def)); ;}
    break;

  case 9:
#line 160 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); ;}
    break;

  case 10:
#line 163 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); ;}
    break;

  case 11:
#line 166 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); ;}
    break;

  case 12:
#line 169 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::INT_TYPE; ;}
    break;

  case 13:
#line 170 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; ;}
    break;

  case 14:
#line 171 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; ;}
    break;

  case 15:
#line 172 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::CHAR_TYPE; ;}
    break;

  case 16:
#line 173 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::STR_TYPE; ;}
    break;

  case 17:
#line 176 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(1) - (2)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(2) - (2)].item_decl)); ;}
    break;

  case 18:
#line 177 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 19:
#line 180 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(2) - (3)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 20:
#line 181 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 21:
#line 182 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(1) - (3)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 22:
#line 185 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), compiler::basic_type::STRUCT); (yyval.item_stmt_decl)->add_declaration((yyvsp[(2) - (2)].item_decl)); ;}
    break;

  case 23:
#line 186 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 24:
#line 189 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[(1) - (1)].item_ident), nullptr, true); ;}
    break;

  case 25:
#line 190 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[(1) - (4)].item_ident), (yyvsp[(3) - (4)].item_struct_body), false);;}
    break;

  case 26:
#line 193 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_struct_body) = new compiler::Item_struct_body(yyget_lineno()); (yyval.item_struct_body)->add_body((yyvsp[(1) - (1)].item_stmt_decl)); ;}
    break;

  case 27:
#line 194 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_struct_body) = (yyvsp[(1) - (2)].item_struct_body); (yyval.item_struct_body)->add_body((yyvsp[(2) - (2)].item_stmt_decl)); ;}
    break;

  case 30:
#line 201 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr), false); ;}
    break;

  case 31:
#line 202 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var(yyget_lineno(), (yyvsp[(1) - (1)].item_ident)); ;}
    break;

  case 32:
#line 203 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_pointer), (yyvsp[(3) - (3)].item_expr), false); ;}
    break;

  case 33:
#line 204 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_pointer(yyget_lineno(), (yyvsp[(1) - (1)].item_ident_pointer)); ;}
    break;

  case 34:
#line 207 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_pointer) = new compiler::Item_ident_pointer(yyget_lineno(), *(yyvsp[(2) - (2)].raw_string)); ;}
    break;

  case 35:
#line 208 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_pointer) = (yyvsp[(2) - (2)].item_ident_pointer); (yyvsp[(2) - (2)].item_ident_pointer)->add_shape(); ;}
    break;

  case 36:
#line 211 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_array), (yyvsp[(3) - (3)].item_literal_array_init), false); ;}
    break;

  case 37:
#line 212 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array(yyget_lineno(), (yyvsp[(1) - (1)].item_ident_array)); ;}
    break;

  case 38:
#line 215 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (4)].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 39:
#line 216 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (4)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 40:
#line 219 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = (yyvsp[(2) - (3)].item_literal_array_init); ;}
    break;

  case 41:
#line 220 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); ;}
    break;

  case 44:
#line 227 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr), true); ;}
    break;

  case 45:
#line 228 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_pointer), (yyvsp[(3) - (3)].item_expr), true); ;}
    break;

  case 46:
#line 231 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_array), (yyvsp[(3) - (3)].item_literal_array_init), true); ;}
    break;

  case 47:
#line 234 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[(1) - (6)].btype), (yyvsp[(2) - (6)].item_ident), (yyvsp[(4) - (6)].item_func_def_list), (yyvsp[(6) - (6)].item_block)); ;}
    break;

  case 48:
#line 235 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[(2) - (6)].item_ident), (yyvsp[(4) - (6)].item_func_def_list), (yyvsp[(6) - (6)].item_block)); ;}
    break;

  case 49:
#line 236 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[(1) - (5)].btype), (yyvsp[(2) - (5)].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[(5) - (5)].item_block)); ;}
    break;

  case 50:
#line 237 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[(2) - (5)].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[(5) - (5)].item_block)); ;}
    break;

  case 51:
#line 240 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_list)->add_arg((yyvsp[(3) - (3)].item_func_def_arg)); ;}
    break;

  case 52:
#line 241 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_list) = new compiler::Item_func_def_list(yyget_lineno()); (yyval.item_func_def_list)->add_arg((yyvsp[(1) - (1)].item_func_def_arg)); ;}
    break;

  case 55:
#line 248 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (2)].btype), (yyvsp[(2) - (2)].item_ident)); ;}
    break;

  case 56:
#line 249 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(2) - (3)].btype), (yyvsp[(3) - (3)].item_ident)); ;}
    break;

  case 57:
#line 252 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(2) - (4)].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (4)].btype), ident);
                                                        ;}
    break;

  case 58:
#line 257 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = (yyvsp[(1) - (3)].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); ;}
    break;

  case 59:
#line 260 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident) = new compiler::Item_ident(yyget_lineno(), *(yyvsp[(1) - (1)].raw_string)); ;}
    break;

  case 60:
#line 263 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = (yyvsp[(1) - (3)].item_literal_array_init); (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init)); ;}
    break;

  case 61:
#line 264 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = (yyvsp[(1) - (3)].item_literal_array_init);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(3) - (3)].item_expr), false);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                              ;}
    break;

  case 62:
#line 269 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); (yyval.item_literal_array_init)->add_value((yyvsp[(1) - (1)].item_literal_array_init)); ;}
    break;

  case 63:
#line 270 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(1) - (1)].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init); 
                                                              ;}
    break;

  case 64:
#line 275 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                                (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init));
                                                              ;}
    break;

  case 65:
#line 281 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { 
                                                                 (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                                                                 compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(1) - (1)].item_expr_comma), true);
                                                                 (yyval.item_literal_array_init)->add_value(array_init);
                                                              ;}
    break;

  case 66:
#line 286 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                                 (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                                                                 compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_expr_comma), true);
                                                                 (yyval.item_literal_array_init)->add_value(array_init);
                                                                 (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init));
                                                              ;}
    break;

  case 67:
#line 294 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); ;}
    break;

  case 68:
#line 295 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_block) = (yyvsp[(2) - (3)].item_block); ;}
    break;

  case 69:
#line 298 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); (yyval.item_block)->add_item((yyvsp[(1) - (1)].item_stmt)); ;}
    break;

  case 70:
#line 299 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_block) = (yyvsp[(1) - (2)].item_block); (yyval.item_block)->add_item((yyvsp[(2) - (2)].item_stmt)); ;}
    break;

  case 71:
#line 302 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 72:
#line 303 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 73:
#line 306 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 82:
#line 317 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_break(yyget_lineno()); ;}
    break;

  case 83:
#line 320 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_continue(yyget_lineno()); ;}
    break;

  case 84:
#line 323 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), nullptr); ;}
    break;

  case 85:
#line 324 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), (yyvsp[(2) - (3)].item_expr)); ;}
    break;

  case 86:
#line 327 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), (yyvsp[(3) - (5)].item_expr), (yyvsp[(5) - (5)].item_stmt), new compiler::Item_stmt_void(yyget_lineno())); ;}
    break;

  case 87:
#line 328 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), (yyvsp[(3) - (7)].item_expr), (yyvsp[(5) - (7)].item_stmt), (yyvsp[(7) - (7)].item_stmt)); ;}
    break;

  case 88:
#line 331 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_eval(yyget_lineno(), (yyvsp[(1) - (2)].item_expr)); ;}
    break;

  case 89:
#line 332 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_void(yyget_lineno()); ;}
    break;

  case 90:
#line 335 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), (yyvsp[(3) - (5)].item_expr), (yyvsp[(5) - (5)].item_stmt)); ;}
    break;

  case 95:
#line 344 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (2)].item_stmt); ;}
    break;

  case 96:
#line 347 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 97:
#line 348 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::ADD_TYPE,
                                                    (yyvsp[(1) - (2)].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (2)].item_ident), expr);
                                      ;}
    break;

  case 98:
#line 357 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::SUB_TYPE,
                                                    (yyvsp[(1) - (2)].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (2)].item_ident), expr);
                                      ;}
    break;

  case 99:
#line 366 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[(2) - (2)].item_ident), compiler::binary_type::ADD_TYPE); ;}
    break;

  case 100:
#line 367 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[(2) - (2)].item_ident), compiler::binary_type::SUB_TYPE); ;}
    break;

  case 102:
#line 371 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident) = (yyvsp[(1) - (1)].item_ident); ;}
    break;

  case 103:
#line 374 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (4)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr));;}
    break;

  case 104:
#line 375 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (4)].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 106:
#line 379 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 107:
#line 382 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr_comma) = new compiler::Item_expr_comma(yyget_lineno()); (yyval.item_expr_comma)->add_expression((yyvsp[(1) - (3)].item_expr)); (yyval.item_expr_comma)->add_expression((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 108:
#line 383 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr_comma) = (yyvsp[(1) - (3)].item_expr_comma); (yyval.item_expr_comma)->add_expression((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 109:
#line 386 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 110:
#line 387 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 112:
#line 391 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 114:
#line 395 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::EQ_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 115:
#line 396 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::NEQ_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 117:
#line 400 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::GE_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 118:
#line 401 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LE_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 119:
#line 402 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::G_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 120:
#line 403 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::L_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 123:
#line 411 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 124:
#line 412 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 126:
#line 416 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 127:
#line 417 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 129:
#line 421 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 130:
#line 422 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 132:
#line 426 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::ADD_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 133:
#line 427 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::SUB_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 135:
#line 431 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MUL_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 136:
#line 432 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::DIV_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 137:
#line 433 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MOD_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 139:
#line 437 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UADD_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 140:
#line 438 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UMINUS_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 141:
#line 439 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::LNOT_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 142:
#line 440 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::BITNEG_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 143:
#line 441 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UREF_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 144:
#line 442 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UDEREFER_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 147:
#line 447 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(2) - (3)].item_expr); ;}
    break;

  case 148:
#line 448 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 149:
#line 449 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 150:
#line 450 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 151:
#line 453 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[(1) - (1)].raw_number)); ;}
    break;

  case 152:
#line 454 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[(1) - (1)].raw_number)); ;}
    break;

  case 153:
#line 455 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_real(yyget_lineno(), (yyvsp[(1) - (1)].raw_number)); ;}
    break;

  case 154:
#line 456 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_char(yyget_lineno(), (yyvsp[(1) - (1)].raw_char)); ;}
    break;

  case 155:
#line 457 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_string(yyget_lineno(), *(yyvsp[(1) - (1)].raw_string)); ;}
    break;

  case 156:
#line 458 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 1); ;}
    break;

  case 157:
#line 459 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 0); ;}
    break;

  case 158:
#line 462 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), new compiler::Item_func_call_list(yyget_lineno())); ;}
    break;

  case 159:
#line 463 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[(1) - (4)].item_ident), (yyvsp[(3) - (4)].item_func_call_list)); ;}
    break;

  case 160:
#line 466 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_call_list) = (yyvsp[(1) - (3)].item_func_call_list); (yyvsp[(1) - (3)].item_func_call_list)->add_arg((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 161:
#line 467 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_call_list) = new compiler::Item_func_call_list(yyget_lineno()); (yyval.item_func_call_list)->add_arg((yyvsp[(1) - (1)].item_expr)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2552 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.cc"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 469 "/Users/chenhaobin/Documents/NKU/Computer/Compilation/compiler/Compiler/src/frontend/parser/parser.ypp"

