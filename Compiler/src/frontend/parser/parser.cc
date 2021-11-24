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
     DO = 291,
     WHILE = 292,
     FOR = 293,
     RETURN = 294,
     BREAK = 295,
     CONTINUE = 296,
     CONST = 297,
     ASSIGN = 298,
     TRUE = 299,
     FALSE = 300,
     LBRACE = 301,
     RBRACE = 302,
     LPARENTHESIS = 303,
     RPARENTHESIS = 304,
     LSQUARE = 305,
     RSQUARE = 306,
     SEMICOLON = 307,
     DOT = 308,
     COMMA = 309
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
#define DO 291
#define WHILE 292
#define FOR 293
#define RETURN 294
#define BREAK 295
#define CONTINUE 296
#define CONST 297
#define ASSIGN 298
#define TRUE 299
#define FALSE 300
#define LBRACE 301
#define RBRACE 302
#define LPARENTHESIS 303
#define RPARENTHESIS 304
#define LSQUARE 305
#define RSQUARE 306
#define SEMICOLON 307
#define DOT 308
#define COMMA 309




/* Copy the first part of user declarations.  */
#line 3 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"

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
#line 66 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
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
    double                              raw_number;
    std::string*                        raw_string;
    char                                raw_char;
}
/* Line 193 of yacc.c.  */
#line 294 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.cc"
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
#line 319 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.cc"

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
#define YYLAST   813

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNRULES -- Number of states.  */
#define YYNSTATES  301

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    13,    15,    17,    19,
      22,    25,    28,    30,    32,    34,    36,    38,    41,    45,
      49,    53,    57,    60,    64,    66,    70,    75,    77,    80,
      82,    85,    87,    89,    93,    95,    99,   101,   104,   107,
     111,   113,   118,   123,   127,   131,   135,   138,   140,   142,
     146,   150,   154,   161,   168,   174,   180,   184,   186,   188,
     190,   193,   197,   202,   208,   212,   217,   219,   223,   227,
     229,   231,   235,   237,   241,   244,   248,   250,   253,   255,
     257,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     278,   281,   284,   288,   294,   302,   305,   307,   313,   321,
     328,   336,   343,   351,   354,   358,   361,   364,   367,   370,
     372,   374,   379,   384,   386,   388,   392,   396,   400,   404,
     406,   410,   412,   416,   420,   422,   426,   430,   434,   438,
     440,   442,   446,   450,   452,   456,   460,   462,   466,   470,
     472,   476,   480,   482,   486,   490,   494,   496,   499,   502,
     505,   508,   511,   514,   516,   518,   522,   524,   526,   528,
     530,   532,   534,   536,   538,   540,   542,   546,   551,   555
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    56,    57,    -1,    56,    76,    -1,    57,
      -1,    76,    -1,    59,    -1,    60,    -1,    58,    -1,    64,
      52,    -1,    62,    52,    -1,    63,    52,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1,    27,    -1,    61,    67,
      -1,    62,    54,    67,    -1,    42,    61,    73,    -1,    63,
      54,    73,    -1,    61,    42,    73,    -1,    33,    65,    -1,
      64,    54,    65,    -1,    81,    -1,    81,    46,    47,    -1,
      81,    46,    66,    47,    -1,    57,    -1,    66,    57,    -1,
      76,    -1,    66,    76,    -1,    68,    -1,    70,    -1,    81,
      43,    98,    -1,    81,    -1,    69,    43,    98,    -1,    69,
      -1,     6,     3,    -1,     6,    69,    -1,    71,    43,    72,
      -1,    71,    -1,    71,    50,    98,    51,    -1,    81,    50,
      98,    51,    -1,    81,    50,    51,    -1,    71,    50,    51,
      -1,    46,    82,    47,    -1,    46,    47,    -1,    74,    -1,
      75,    -1,    81,    43,    98,    -1,    69,    43,    98,    -1,
      71,    43,    72,    -1,    61,    81,    48,    77,    49,    83,
      -1,    32,    81,    48,    77,    49,    83,    -1,    61,    81,
      48,    49,    83,    -1,    32,    81,    48,    49,    83,    -1,
      77,    54,    78,    -1,    78,    -1,    79,    -1,    80,    -1,
      61,    81,    -1,    42,    61,    81,    -1,    61,    81,    50,
      51,    -1,    61,    81,    50,    98,    51,    -1,    80,    50,
      51,    -1,    80,    50,    98,    51,    -1,     3,    -1,    82,
      54,    72,    -1,    82,    54,    98,    -1,    72,    -1,   100,
      -1,   100,    54,    72,    -1,    99,    -1,    99,    54,    72,
      -1,    46,    47,    -1,    46,    84,    47,    -1,    85,    -1,
      84,    85,    -1,    57,    -1,    86,    -1,    83,    -1,    92,
      -1,    93,    -1,    90,    -1,    89,    -1,    87,    -1,    88,
      -1,    94,    -1,    91,    -1,    40,    52,    -1,    41,    52,
      -1,    39,    52,    -1,    39,    98,    52,    -1,    34,    48,
      98,    49,    86,    -1,    34,    48,    98,    49,    86,    35,
      86,    -1,    98,    52,    -1,    52,    -1,    37,    48,    98,
      49,    86,    -1,    36,    83,    37,    48,    98,    49,    52,
      -1,    38,    48,    91,    91,    49,    83,    -1,    38,    48,
      91,    91,    98,    49,    83,    -1,    38,    48,    57,    91,
      49,    83,    -1,    38,    48,    57,    91,    98,    49,    83,
      -1,    95,    52,    -1,    96,    43,    98,    -1,    96,     9,
      -1,    96,    10,    -1,     9,    96,    -1,    10,    96,    -1,
      81,    -1,    97,    -1,    96,    50,    98,    51,    -1,    97,
      50,    98,    51,    -1,   100,    -1,    99,    -1,   100,    54,
     100,    -1,    99,    54,   100,    -1,   101,    22,   101,    -1,
     100,    22,   101,    -1,   101,    -1,   101,    21,   104,    -1,
     104,    -1,   103,    11,   103,    -1,   103,    12,   103,    -1,
     103,    -1,   103,    13,   103,    -1,   103,    14,   103,    -1,
     103,    15,   103,    -1,   103,    16,   103,    -1,   108,    -1,
     105,    -1,   106,    18,   106,    -1,   105,    18,   106,    -1,
     106,    -1,   107,    19,   107,    -1,   106,    19,   107,    -1,
     107,    -1,   102,    17,   102,    -1,   107,    17,   102,    -1,
     102,    -1,   108,     4,   109,    -1,   108,     5,   109,    -1,
     109,    -1,   109,     6,   110,    -1,   109,     7,   110,    -1,
     109,     8,   110,    -1,   110,    -1,     4,   110,    -1,     5,
     110,    -1,    23,   110,    -1,    20,   110,    -1,    17,   110,
      -1,     6,   110,    -1,   113,    -1,   111,    -1,    48,    98,
      49,    -1,    96,    -1,   112,    -1,    95,    -1,    26,    -1,
      25,    -1,    24,    -1,    31,    -1,    27,    -1,    44,    -1,
      45,    -1,    81,    48,    49,    -1,    81,    48,   114,    49,
      -1,   114,    54,   104,    -1,   104,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   150,   151,   152,   155,   156,   157,   160,
     163,   166,   169,   170,   171,   172,   173,   176,   177,   180,
     181,   182,   185,   186,   189,   190,   191,   194,   195,   196,
     197,   200,   201,   204,   205,   206,   207,   210,   211,   214,
     215,   218,   219,   220,   221,   224,   225,   228,   229,   232,
     233,   236,   239,   240,   241,   242,   245,   246,   249,   250,
     253,   254,   257,   262,   267,   268,   271,   274,   275,   280,
     281,   286,   292,   300,   311,   312,   315,   316,   319,   320,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   334,
     337,   340,   341,   344,   349,   355,   356,   359,   364,   370,
     379,   389,   398,   410,   413,   414,   423,   432,   433,   436,
     437,   440,   441,   444,   445,   448,   449,   452,   453,   454,
     457,   458,   461,   462,   463,   466,   467,   468,   469,   470,
     474,   477,   478,   479,   482,   483,   484,   487,   488,   489,
     492,   493,   494,   497,   498,   499,   500,   503,   504,   505,
     506,   507,   508,   509,   510,   513,   514,   515,   516,   519,
     520,   521,   530,   531,   532,   533,   536,   537,   540,   541
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
  "VOID", "STRUCT_TOKEN", "IF", "ELSE", "DO", "WHILE", "FOR", "RETURN",
  "BREAK", "CONTINUE", "CONST", "ASSIGN", "TRUE", "FALSE", "LBRACE",
  "RBRACE", "LPARENTHESIS", "RPARENTHESIS", "LSQUARE", "RSQUARE",
  "SEMICOLON", "DOT", "COMMA", "$accept", "CompUnit", "Decl",
  "StructDeclStmt", "VarDeclStmt", "ConstDeclStmt", "BType", "VarDecl",
  "ConstDecl", "StructDecl", "StructDef", "Body", "VarDef", "VarDefNormal",
  "POINTER", "VarDefArray", "ArrayID", "ArrayInitVal", "ConstDef",
  "ConstDefNormal", "ConstDefArray", "FuncDef", "FuncDefList", "FuncParam",
  "FuncParamNormal", "FuncParamArray", "Ident", "ArrayInitValHelper",
  "BLOCK", "BlockItems", "BlockItem", "Stmt", "BreakStmt", "ContinueStmt",
  "ReturnStmt", "eIfStmt", "ExpStmt", "WhileStmt", "ForStmt", "AssignStmt",
  "Assignment", "LVal", "ArrayItem", "Exp", "CommaExp", "LOrExp",
  "LAndExp", "EqExp", "RelExp", "BitExp", "BitOrExp", "BitXorExp",
  "BitAndExp", "AddExp", "MulExp", "UnaryExp", "PrimaryExp", "LITERAL",
  "FunctionCall", "FunctionRParams", 0
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
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    57,    57,    57,    58,
      59,    60,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    76,    76,    76,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    80,    80,    81,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    87,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    94,    95,    95,    95,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     101,   101,   102,   102,   102,   103,   103,   103,   103,   103,
     104,   105,   105,   105,   106,   106,   106,   107,   107,   107,
     108,   108,   108,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   114
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     3,     2,     3,     1,     3,     4,     1,     2,     1,
       2,     1,     1,     3,     1,     3,     1,     2,     2,     3,
       1,     4,     4,     3,     3,     3,     2,     1,     1,     3,
       3,     3,     6,     6,     5,     5,     3,     1,     1,     1,
       2,     3,     4,     5,     3,     4,     1,     3,     3,     1,
       1,     3,     1,     3,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     3,     5,     7,     2,     1,     5,     7,     6,
       7,     6,     7,     2,     3,     2,     2,     2,     2,     1,
       1,     4,     4,     1,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     2,
       2,     2,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    12,    13,    14,    15,     0,     0,     0,     0,
       4,     8,     6,     7,     0,     0,     0,     0,     5,    66,
       0,    22,    24,     0,     1,     2,     3,     0,     0,    17,
      31,    36,    32,    40,    34,    10,     0,    11,     0,     9,
       0,     0,     0,     0,     0,    19,    47,    48,     0,    37,
      38,    21,     0,     0,     0,     0,     0,     0,    18,    34,
      20,    23,     0,     0,     0,     0,    57,    58,    59,    25,
      27,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   160,   159,   163,   162,   164,
     165,     0,   109,   158,   156,   110,    35,   114,   113,   119,
     139,   124,   121,   130,   133,   136,   129,   142,   146,   154,
     157,   153,     0,    39,    44,     0,    33,     0,     0,    43,
       0,     0,     0,    55,    60,     0,     0,     0,    26,    28,
      30,    50,    51,    49,   147,   148,   152,   109,   107,   108,
     151,   150,   149,     0,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    69,     0,    72,    70,    41,    54,     0,
      42,    61,   163,   162,     0,     0,     0,     0,     0,     0,
       0,    74,    96,    78,     0,    80,     0,    76,    79,    85,
      86,    84,    83,    88,    81,    82,    87,   158,     0,     0,
      53,    56,    64,     0,   155,   166,   169,     0,   104,     0,
       0,   116,   118,   115,   120,   117,   137,   122,   123,   125,
     126,   127,   128,   132,   131,   135,   138,   134,   140,   141,
     143,   144,   145,    45,     0,     0,     0,    52,     0,     0,
       0,     0,    91,     0,    89,    90,    75,    77,   103,    95,
      62,     0,    65,   167,     0,   111,   112,    67,    68,    73,
      71,     0,     0,     0,     0,     0,    92,    63,   168,     0,
       0,     0,     0,     0,    93,     0,    97,     0,     0,     0,
       0,     0,     0,   101,     0,    99,     0,    94,    98,   102,
     100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,   193,    11,    12,    13,    14,    15,    16,    17,
      21,    71,    29,    30,    31,    32,    33,   113,    45,    46,
      47,    18,    65,    66,    67,    68,    92,   174,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      93,    94,    95,   208,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   217
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -192
static const yytype_int16 yypact[] =
{
     180,  -192,  -192,  -192,  -192,  -192,    24,    24,   140,    45,
    -192,  -192,  -192,  -192,     9,    84,    91,   138,  -192,  -192,
     -15,  -192,    17,   146,  -192,  -192,  -192,   148,   146,  -192,
    -192,    53,  -192,   -11,    51,  -192,   146,  -192,   146,  -192,
      24,    99,   130,   159,    36,  -192,  -192,  -192,    63,  -192,
    -192,  -192,   765,   101,   497,   765,   104,   526,  -192,    64,
    -192,  -192,   140,   175,    24,    48,  -192,  -192,   177,  -192,
    -192,   151,  -192,   765,   101,   765,   765,   765,   765,    24,
      24,   765,   765,   765,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,   765,    34,  -192,    11,   181,  -192,   176,    -6,   134,
     217,   410,  -192,   214,   102,   182,   215,   189,  -192,  -192,
    -192,  -192,   703,  -192,  -192,   186,  -192,   175,    68,  -192,
     194,    24,   237,  -192,   200,   175,   187,   555,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   205,   205,
    -192,  -192,  -192,   207,   613,  -192,  -192,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   765,
     765,   765,  -192,  -192,    69,   204,     4,  -192,  -192,   175,
    -192,  -192,    47,    56,   211,   175,   221,   224,   437,   228,
     234,  -192,  -192,  -192,     9,  -192,   287,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,   235,   236,   584,
    -192,  -192,  -192,   243,  -192,  -192,  -192,    88,  -192,   244,
     254,   284,   288,   284,  -192,   288,  -192,   172,   172,  -192,
    -192,  -192,  -192,   289,   289,   302,  -192,   302,   189,   189,
    -192,  -192,  -192,  -192,   735,   735,   735,  -192,   765,   285,
     765,   387,  -192,   278,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,   286,  -192,  -192,   765,  -192,  -192,  -192,  -192,  -192,
    -192,   295,   290,   296,   467,   467,  -192,  -192,  -192,   337,
     765,   337,   643,   673,   301,   299,  -192,   175,   300,   175,
     303,   337,   298,  -192,   175,  -192,   175,  -192,  -192,  -192,
    -192
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,     0,  -192,  -192,  -192,    -7,  -192,  -192,  -192,
     311,  -192,   317,  -192,    57,  -192,     2,   -71,    32,  -192,
    -192,    -5,   309,   229,  -192,  -192,    29,  -192,   -61,  -192,
     160,  -191,  -192,  -192,  -192,  -192,  -183,  -192,  -192,  -192,
    -115,   145,  -192,   -44,   246,  -106,    40,  -127,   142,  -139,
    -192,    86,    39,  -192,    85,   -59,  -192,  -192,  -192,  -192
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -17
static const yytype_int16 yytable[] =
{
      10,    23,   123,   132,    26,   216,   176,   207,    96,    25,
     115,   116,    19,   120,   224,    27,   151,   134,   135,   136,
     145,   146,   140,   141,   142,    44,   151,    19,   226,   131,
      44,   133,    53,    41,    64,    20,    22,    72,   236,    54,
      44,   173,    70,    34,   221,    24,   223,   143,   152,    64,
     -16,    28,    48,   -16,   147,   121,   178,    48,   246,   -15,
      51,   148,   -15,    42,   210,    59,   130,    48,   275,    22,
      60,   129,     1,     2,     3,     4,     5,     6,     7,    74,
      43,   207,   144,   213,    50,    43,    54,     8,   284,   -16,
     286,   282,   283,   124,    55,    43,    52,   125,   -15,    56,
     297,    57,   126,   218,   219,   220,    75,    55,   137,   137,
     240,   241,   242,    57,    57,   194,   243,   179,   247,    64,
     163,   164,   126,   244,   249,   278,     1,     2,     3,     4,
       5,     1,     2,     3,     4,     5,    35,   263,    36,   221,
     223,    62,   264,    37,   253,    38,    62,   112,    63,    19,
     181,    49,    27,   117,    27,   153,   154,     1,     2,     3,
       4,     5,     6,     7,   207,   261,   207,     1,     2,     3,
       4,     5,     8,   267,   269,   270,   207,    69,     1,     2,
       3,     4,     5,     6,     7,   158,   159,   160,   161,   194,
      39,   222,    40,     8,   225,   169,   170,   171,   128,   165,
     268,   166,    73,   235,   271,   237,   273,     1,     2,     3,
       4,     5,     6,     7,     1,     2,     3,     4,     5,   167,
     168,   122,     8,    59,   138,   139,   293,   127,   295,    62,
     150,   149,   162,   299,   155,   300,   285,   177,   288,   290,
      19,    76,    77,    78,   194,   180,    79,    80,   233,   234,
     209,   274,   238,   239,    81,   148,   214,    82,   245,   248,
      83,    84,    85,    86,   182,     2,     3,     4,   183,   250,
       7,   184,   251,   185,   186,   187,   188,   189,   190,     8,
     254,    89,    90,   122,   191,    91,   255,   258,   259,   192,
      19,    76,    77,    78,   262,   265,    79,    80,   227,   228,
     229,   230,   231,   232,    81,   266,   151,    82,   164,   153,
      83,    84,    85,    86,   182,     2,     3,     4,   183,   165,
       7,   184,   272,   185,   186,   187,   188,   189,   190,     8,
     276,    89,    90,   122,   256,    91,   291,   277,   280,   192,
      19,    76,    77,    78,   279,   281,    79,    80,   292,   294,
     298,    61,   296,    58,    81,   211,   257,    82,   175,     0,
      83,    84,    85,    86,    87,   118,     0,     0,    88,     0,
       0,   184,     0,   185,   186,   187,   188,   189,   190,     0,
       0,    89,    90,   122,     0,    91,     0,     0,     0,   192,
      19,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    82,     0,     0,
      83,    84,    85,    86,   182,     2,     3,     4,   183,     0,
       7,   156,   157,   158,   159,   160,   161,     0,     0,     8,
       0,    89,    90,     0,     0,    91,     0,     0,     0,   192,
      19,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    82,     0,     0,
      83,    84,    85,    86,    87,     0,     0,     0,    88,     0,
      19,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,    89,    90,     0,    81,    91,     0,    82,     0,   252,
      83,    84,    85,    86,    87,     0,     0,     0,    88,     0,
      19,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,    89,    90,     0,    81,    91,     0,    82,     0,   192,
      83,    84,    85,    86,    87,     0,     0,     0,    88,    19,
      76,    77,    78,     0,     0,    79,    80,     0,     0,     0,
       0,    89,    90,    81,     0,    91,    82,     0,   114,    83,
      84,    85,    86,    87,     0,     0,     0,    88,    19,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,     0,
      89,    90,    81,     0,    91,    82,     0,   119,    83,    84,
      85,    86,    87,     0,     0,     0,    88,    19,    76,    77,
      78,     0,     0,    79,    80,     0,     0,     0,     0,    89,
      90,    81,     0,    91,    82,     0,   212,    83,    84,    85,
      86,    87,     0,     0,     0,    88,    19,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,     0,    89,    90,
      81,     0,    91,    82,     0,   260,    83,    84,    85,    86,
      87,     0,     0,     0,    88,     0,    19,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    89,    90,     0,
      81,    91,   215,    82,     0,     0,    83,    84,    85,    86,
      87,     0,     0,     0,    88,     0,    19,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    89,    90,     0,
      81,    91,   287,    82,     0,     0,    83,    84,    85,    86,
      87,     0,     0,     0,    88,     0,    19,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    89,    90,     0,
      81,    91,   289,    82,     0,     0,    83,    84,    85,    86,
      87,     0,     0,     0,    88,     0,     0,     0,    19,    76,
      77,    78,     0,     0,    79,    80,     0,    89,    90,   112,
     172,    91,    81,     0,     0,    82,     0,     0,    83,    84,
      85,    86,    87,     0,     0,     0,    88,     0,    19,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,    89,
      90,   112,    81,    91,     0,    82,     0,     0,    83,    84,
      85,    86,    87,     0,     0,     0,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,     0,     0,    91
};

static const yytype_int16 yycheck[] =
{
       0,     8,    63,    74,     9,   144,   112,   122,    52,     9,
      54,    55,     3,    57,   153,     6,    22,    76,    77,    78,
       9,    10,    81,    82,    83,    23,    22,     3,   155,    73,
      28,    75,    43,    48,    41,     6,     7,    42,   165,    50,
      38,   112,    42,    14,   150,     0,   152,    91,    54,    56,
       3,    42,    23,     6,    43,    62,   117,    28,    54,     3,
      28,    50,     6,    46,   125,    36,    71,    38,   251,    40,
      38,    71,    27,    28,    29,    30,    31,    32,    33,    43,
      23,   196,    48,   127,    27,    28,    50,    42,   279,    42,
     281,   274,   275,    64,    43,    38,    43,    49,    42,    48,
     291,    50,    54,   147,   148,   149,    43,    43,    79,    80,
     169,   170,   171,    50,    50,   122,    47,    49,   179,   126,
      18,    19,    54,    54,   185,   264,    27,    28,    29,    30,
      31,    27,    28,    29,    30,    31,    52,    49,    54,   245,
     246,    42,    54,    52,   188,    54,    42,    46,    49,     3,
     121,     3,     6,    49,     6,    21,    22,    27,    28,    29,
      30,    31,    32,    33,   279,   209,   281,    27,    28,    29,
      30,    31,    42,   244,   245,   246,   291,    47,    27,    28,
      29,    30,    31,    32,    33,    13,    14,    15,    16,   196,
      52,   151,    54,    42,   154,     6,     7,     8,    47,    17,
     244,    19,    43,   164,   248,   166,   250,    27,    28,    29,
      30,    31,    32,    33,    27,    28,    29,    30,    31,     4,
       5,    46,    42,   194,    79,    80,   287,    50,   289,    42,
      54,    50,    18,   294,    17,   296,   280,    51,   282,   283,
       3,     4,     5,     6,   251,    51,     9,    10,   162,   163,
      50,   251,   167,   168,    17,    50,    49,    20,    54,    48,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    48,
      33,    34,    48,    36,    37,    38,    39,    40,    41,    42,
      52,    44,    45,    46,    47,    48,    52,    52,    52,    52,
       3,     4,     5,     6,    51,    51,     9,    10,   156,   157,
     158,   159,   160,   161,    17,    51,    22,    20,    19,    21,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    17,
      33,    34,    37,    36,    37,    38,    39,    40,    41,    42,
      52,    44,    45,    46,    47,    48,    35,    51,    48,    52,
       3,     4,     5,     6,    49,    49,     9,    10,    49,    49,
      52,    40,    49,    36,    17,   126,   196,    20,   112,    -1,
      23,    24,    25,    26,    27,    56,    -1,    -1,    31,    -1,
      -1,    34,    -1,    36,    37,    38,    39,    40,    41,    -1,
      -1,    44,    45,    46,    -1,    48,    -1,    -1,    -1,    52,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    11,    12,    13,    14,    15,    16,    -1,    -1,    42,
      -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,    52,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    44,    45,    -1,    17,    48,    -1,    20,    -1,    52,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    44,    45,    -1,    17,    48,    -1,    20,    -1,    52,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,     3,
       4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,
      -1,    44,    45,    17,    -1,    48,    20,    -1,    51,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,    -1,
      44,    45,    17,    -1,    48,    20,    -1,    51,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     3,     4,     5,
       6,    -1,    -1,     9,    10,    -1,    -1,    -1,    -1,    44,
      45,    17,    -1,    48,    20,    -1,    51,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    -1,    -1,    44,    45,
      17,    -1,    48,    20,    -1,    51,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    -1,    44,    45,    -1,
      17,    48,    49,    20,    -1,    -1,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    -1,    44,    45,    -1,
      17,    48,    49,    20,    -1,    -1,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    -1,    44,    45,    -1,
      17,    48,    49,    20,    -1,    -1,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    44,    45,    46,
      47,    48,    17,    -1,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,    44,
      45,    46,    17,    48,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    28,    29,    30,    31,    32,    33,    42,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    76,     3,
      81,    65,    81,    61,     0,    57,    76,     6,    42,    67,
      68,    69,    70,    71,    81,    52,    54,    52,    54,    52,
      54,    48,    46,    69,    71,    73,    74,    75,    81,     3,
      69,    73,    43,    43,    50,    43,    48,    50,    67,    81,
      73,    65,    42,    49,    61,    77,    78,    79,    80,    47,
      57,    66,    76,    43,    43,    43,     4,     5,     6,     9,
      10,    17,    20,    23,    24,    25,    26,    27,    31,    44,
      45,    48,    81,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    46,    72,    51,    98,    98,    49,    77,    51,
      98,    61,    46,    83,    81,    49,    54,    50,    47,    57,
      76,    98,    72,    98,   110,   110,   110,    81,    96,    96,
     110,   110,   110,    98,    48,     9,    10,    43,    50,    50,
      54,    22,    54,    21,    22,    17,    11,    12,    13,    14,
      15,    16,    18,    18,    19,    17,    19,     4,     5,     6,
       7,     8,    47,    72,    82,    99,   100,    51,    83,    49,
      51,    81,    27,    31,    34,    36,    37,    38,    39,    40,
      41,    47,    52,    57,    61,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    98,    50,
      83,    78,    51,    98,    49,    49,   104,   114,    98,    98,
      98,   100,   101,   100,   104,   101,   102,   103,   103,   103,
     103,   103,   103,   106,   106,   107,   102,   107,   109,   109,
     110,   110,   110,    47,    54,    54,    54,    83,    48,    83,
      48,    48,    52,    98,    52,    52,    47,    85,    52,    52,
      51,    98,    51,    49,    54,    51,    51,    72,    98,    72,
      72,    98,    37,    98,    57,    91,    52,    51,   104,    49,
      48,    49,    91,    91,    86,    98,    86,    49,    98,    49,
      98,    35,    49,    83,    49,    83,    49,    86,    52,    83,
      83
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
#line 149 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_root)->add_child((yyvsp[(2) - (2)].item_decl)); ;}
    break;

  case 3:
#line 150 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_root)->add_child((yyvsp[(2) - (2)].item_func_def)); ;}
    break;

  case 4:
#line 151 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[(1) - (1)].item_decl)); ;}
    break;

  case 5:
#line 152 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[(1) - (1)].item_func_def)); ;}
    break;

  case 9:
#line 160 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); ;}
    break;

  case 10:
#line 163 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); ;}
    break;

  case 11:
#line 166 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); ;}
    break;

  case 12:
#line 169 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::INT_TYPE; ;}
    break;

  case 13:
#line 170 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; ;}
    break;

  case 14:
#line 171 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; ;}
    break;

  case 15:
#line 172 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::CHAR_TYPE; ;}
    break;

  case 16:
#line 173 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::STR_TYPE; ;}
    break;

  case 17:
#line 176 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(1) - (2)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(2) - (2)].item_decl)); ;}
    break;

  case 18:
#line 177 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 19:
#line 180 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(2) - (3)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 20:
#line 181 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 21:
#line 182 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(1) - (3)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 22:
#line 185 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), compiler::basic_type::STRUCT); (yyval.item_stmt_decl)->add_declaration((yyvsp[(2) - (2)].item_decl)); ;}
    break;

  case 23:
#line 186 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); ;}
    break;

  case 24:
#line 189 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[(1) - (1)].item_ident), nullptr, true); ;}
    break;

  case 25:
#line 190 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), nullptr, true); ;}
    break;

  case 26:
#line 191 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[(1) - (4)].item_ident), (yyvsp[(3) - (4)].item_struct_body), false);;}
    break;

  case 27:
#line 194 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_struct_body) = new compiler::Item_struct_body(yyget_lineno()); (yyval.item_struct_body)->add_body((yyvsp[(1) - (1)].item_stmt_decl)); ;}
    break;

  case 28:
#line 195 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_struct_body) = (yyvsp[(1) - (2)].item_struct_body); (yyval.item_struct_body)->add_body((yyvsp[(2) - (2)].item_stmt_decl)); ;}
    break;

  case 29:
#line 196 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_struct_body) = new compiler::Item_struct_body(yyget_lineno()); (yyval.item_struct_body)->add_body((yyvsp[(1) - (1)].item_func_def)); ;}
    break;

  case 30:
#line 197 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_struct_body) = (yyvsp[(1) - (2)].item_struct_body); (yyval.item_struct_body)->add_body((yyvsp[(2) - (2)].item_func_def)); ;}
    break;

  case 33:
#line 204 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr), false); ;}
    break;

  case 34:
#line 205 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var(yyget_lineno(), (yyvsp[(1) - (1)].item_ident)); ;}
    break;

  case 35:
#line 206 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_pointer), (yyvsp[(3) - (3)].item_expr), false); ;}
    break;

  case 36:
#line 207 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_pointer(yyget_lineno(), (yyvsp[(1) - (1)].item_ident_pointer)); ;}
    break;

  case 37:
#line 210 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_pointer) = new compiler::Item_ident_pointer(yyget_lineno(), *(yyvsp[(2) - (2)].raw_string)); ;}
    break;

  case 38:
#line 211 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_pointer) = (yyvsp[(2) - (2)].item_ident_pointer); (yyvsp[(2) - (2)].item_ident_pointer)->add_shape(); ;}
    break;

  case 39:
#line 214 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_array), (yyvsp[(3) - (3)].item_literal_array_init), false); ;}
    break;

  case 40:
#line 215 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array(yyget_lineno(), (yyvsp[(1) - (1)].item_ident_array)); ;}
    break;

  case 41:
#line 218 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (4)].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 42:
#line 219 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (4)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 43:
#line 220 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (3)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape(nullptr); ;}
    break;

  case 44:
#line 221 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (3)].item_ident_array); (yyval.item_ident_array)->add_shape(nullptr); ;}
    break;

  case 45:
#line 224 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = (yyvsp[(2) - (3)].item_literal_array_init); ;}
    break;

  case 46:
#line 225 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); ;}
    break;

  case 49:
#line 232 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr), true); ;}
    break;

  case 50:
#line 233 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_pointer), (yyvsp[(3) - (3)].item_expr), true); ;}
    break;

  case 51:
#line 236 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_array), (yyvsp[(3) - (3)].item_literal_array_init), true); ;}
    break;

  case 52:
#line 239 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[(1) - (6)].btype), (yyvsp[(2) - (6)].item_ident), (yyvsp[(4) - (6)].item_func_def_list), (yyvsp[(6) - (6)].item_block)); ;}
    break;

  case 53:
#line 240 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[(2) - (6)].item_ident), (yyvsp[(4) - (6)].item_func_def_list), (yyvsp[(6) - (6)].item_block)); ;}
    break;

  case 54:
#line 241 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[(1) - (5)].btype), (yyvsp[(2) - (5)].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[(5) - (5)].item_block)); ;}
    break;

  case 55:
#line 242 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[(2) - (5)].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[(5) - (5)].item_block)); ;}
    break;

  case 56:
#line 245 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_list)->add_arg((yyvsp[(3) - (3)].item_func_def_arg)); ;}
    break;

  case 57:
#line 246 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_list) = new compiler::Item_func_def_list(yyget_lineno()); (yyval.item_func_def_list)->add_arg((yyvsp[(1) - (1)].item_func_def_arg)); ;}
    break;

  case 60:
#line 253 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (2)].btype), (yyvsp[(2) - (2)].item_ident)); ;}
    break;

  case 61:
#line 254 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(2) - (3)].btype), (yyvsp[(3) - (3)].item_ident)); ;}
    break;

  case 62:
#line 257 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(2) - (4)].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (4)].btype), ident);
                                                        ;}
    break;

  case 63:
#line 262 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(2) - (5)].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (5)].btype), ident);
                                                        ;}
    break;

  case 64:
#line 267 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = (yyvsp[(1) - (3)].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); ;}
    break;

  case 65:
#line 268 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = (yyvsp[(1) - (4)].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); ;}
    break;

  case 66:
#line 271 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident) = new compiler::Item_ident(yyget_lineno(), *(yyvsp[(1) - (1)].raw_string)); ;}
    break;

  case 67:
#line 274 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = (yyvsp[(1) - (3)].item_literal_array_init); (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init)); ;}
    break;

  case 68:
#line 275 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = (yyvsp[(1) - (3)].item_literal_array_init);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(3) - (3)].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                              ;}
    break;

  case 69:
#line 280 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); (yyval.item_literal_array_init)->add_value((yyvsp[(1) - (1)].item_literal_array_init)); ;}
    break;

  case 70:
#line 281 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(1) - (1)].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init); 
                                                              ;}
    break;

  case 71:
#line 286 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                                (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init));
                                                              ;}
    break;

  case 72:
#line 293 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { 
                    (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                    for (auto expr : (yyvsp[(1) - (1)].item_expr_comma)->get_expressions()) {
                        (yyval.item_literal_array_init)->add_value(new compiler::Item_literal_array_init(yyget_lineno(), expr, true));
                    }
                    delete (yyvsp[(1) - (1)].item_expr_comma);                                                
                  ;}
    break;

  case 73:
#line 301 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
                    (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                    for (auto expr : (yyvsp[(1) - (3)].item_expr_comma)->get_expressions()) {
                        (yyval.item_literal_array_init)->add_value(new compiler::Item_literal_array_init(yyget_lineno(), expr, true));
                    }
                    (yyval.item_literal_array_init)->add_value((yyvsp[(3) - (3)].item_literal_array_init));
                    delete (yyvsp[(1) - (3)].item_expr_comma);
                  ;}
    break;

  case 74:
#line 311 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); ;}
    break;

  case 75:
#line 312 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_block) = (yyvsp[(2) - (3)].item_block); ;}
    break;

  case 76:
#line 315 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); (yyval.item_block)->add_item((yyvsp[(1) - (1)].item_stmt)); ;}
    break;

  case 77:
#line 316 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_block) = (yyvsp[(1) - (2)].item_block); (yyval.item_block)->add_item((yyvsp[(2) - (2)].item_stmt)); ;}
    break;

  case 78:
#line 319 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 79:
#line 320 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 80:
#line 323 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); ;}
    break;

  case 89:
#line 334 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_break(yyget_lineno()); ;}
    break;

  case 90:
#line 337 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_continue(yyget_lineno()); ;}
    break;

  case 91:
#line 340 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), nullptr); ;}
    break;

  case 92:
#line 341 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), (yyvsp[(2) - (3)].item_expr)); ;}
    break;

  case 93:
#line 345 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
    compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[(3) - (5)].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), condition, (yyvsp[(5) - (5)].item_stmt), new compiler::Item_stmt_void(yyget_lineno())); 
;}
    break;

  case 94:
#line 350 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[(3) - (7)].item_expr));
  (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), condition, (yyvsp[(5) - (7)].item_stmt), (yyvsp[(7) - (7)].item_stmt)); 
;}
    break;

  case 95:
#line 355 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_eval(yyget_lineno(), (yyvsp[(1) - (2)].item_expr)); ;}
    break;

  case 96:
#line 356 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_void(yyget_lineno()); ;}
    break;

  case 97:
#line 360 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
    compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[(3) - (5)].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[(5) - (5)].item_stmt)); 
;}
    break;

  case 98:
#line 365 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {   compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[(5) - (7)].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[(2) - (7)].item_block), true); 
;}
    break;

  case 99:
#line 371 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
             compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
             block->add_item((yyvsp[(3) - (6)].item_stmt));
             compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[(4) - (6)].item_stmt)));
             compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[(6) - (6)].item_block));
             block->add_item(while_stmt);
             (yyval.item_stmt) = block;
         ;}
    break;

  case 100:
#line 380 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[(3) - (7)].item_stmt));
           (yyvsp[(7) - (7)].item_block)->add_item(static_cast<compiler::Item_stmt*>((yyvsp[(5) - (7)].item_expr)));
           compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[(4) - (7)].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(),condition, (yyvsp[(7) - (7)].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       ;}
    break;

  case 101:
#line 390 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[(3) - (6)].item_stmt_decl));
            compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[(4) - (6)].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[(6) - (6)].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       ;}
    break;

  case 102:
#line 399 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[(3) - (7)].item_stmt_decl));
           (yyvsp[(7) - (7)].item_block)->add_item(static_cast<compiler::Item_stmt*>((yyvsp[(5) - (7)].item_expr)));
        compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[(4) - (7)].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(),condition, (yyvsp[(7) - (7)].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       ;}
    break;

  case 103:
#line 410 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (2)].item_stmt); ;}
    break;

  case 104:
#line 413 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 105:
#line 414 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
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

  case 106:
#line 423 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
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

  case 107:
#line 432 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[(2) - (2)].item_ident), compiler::binary_type::ADD_TYPE); ;}
    break;

  case 108:
#line 433 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[(2) - (2)].item_ident), compiler::binary_type::SUB_TYPE); ;}
    break;

  case 110:
#line 437 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident) = (yyvsp[(1) - (1)].item_ident); ;}
    break;

  case 111:
#line 440 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (4)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr));;}
    break;

  case 112:
#line 441 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (4)].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); ;}
    break;

  case 114:
#line 445 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 115:
#line 448 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr_comma) = new compiler::Item_expr_comma(yyget_lineno()); (yyval.item_expr_comma)->add_expression((yyvsp[(1) - (3)].item_expr)); (yyval.item_expr_comma)->add_expression((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 116:
#line 449 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr_comma) = (yyvsp[(1) - (3)].item_expr_comma); (yyval.item_expr_comma)->add_expression((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 117:
#line 452 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 118:
#line 453 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 120:
#line 457 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 122:
#line 461 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::EQ_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 123:
#line 462 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::NEQ_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 125:
#line 466 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::GE_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 126:
#line 467 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LE_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 127:
#line 468 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::G_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 128:
#line 469 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::L_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 131:
#line 477 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 132:
#line 478 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 134:
#line 482 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 135:
#line 483 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 137:
#line 487 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 138:
#line 488 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 140:
#line 492 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::ADD_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 141:
#line 493 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::SUB_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 143:
#line 497 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MUL_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 144:
#line 498 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::DIV_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 145:
#line 499 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MOD_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 147:
#line 503 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UADD_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 148:
#line 504 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UMINUS_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 149:
#line 505 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::LNOT_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 150:
#line 506 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::BITNEG_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 151:
#line 507 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UREF_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 152:
#line 508 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UDEREFER_TYPE, (yyvsp[(2) - (2)].item_expr)); ;}
    break;

  case 155:
#line 513 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(2) - (3)].item_expr); ;}
    break;

  case 156:
#line 514 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 157:
#line 515 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 158:
#line 516 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); ;}
    break;

  case 159:
#line 519 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[(1) - (1)].raw_number)); ;}
    break;

  case 160:
#line 520 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[(1) - (1)].raw_number)); ;}
    break;

  case 161:
#line 522 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { 
          if (((yyvsp[(1) - (1)].raw_string))->find(".") != std::string::npos) {
            (yyval.item_literal) = new compiler::Item_literal_real(yyget_lineno(), std::stod(*(yyvsp[(1) - (1)].raw_string))); 
          } else {
            (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), std::stoi(*(yyvsp[(1) - (1)].raw_string))); 
          }
          
        ;}
    break;

  case 162:
#line 530 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_char(yyget_lineno(), (yyvsp[(1) - (1)].raw_char)); ;}
    break;

  case 163:
#line 531 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_string(yyget_lineno(), *(yyvsp[(1) - (1)].raw_string)); ;}
    break;

  case 164:
#line 532 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 1); ;}
    break;

  case 165:
#line 533 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 0); ;}
    break;

  case 166:
#line 536 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), new compiler::Item_func_call_list(yyget_lineno())); ;}
    break;

  case 167:
#line 537 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[(1) - (4)].item_ident), (yyvsp[(3) - (4)].item_func_call_list)); ;}
    break;

  case 168:
#line 540 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_call_list) = (yyvsp[(1) - (3)].item_func_call_list); (yyvsp[(1) - (3)].item_func_call_list)->add_arg((yyvsp[(3) - (3)].item_expr)); ;}
    break;

  case 169:
#line 541 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"
    { (yyval.item_func_call_list) = new compiler::Item_func_call_list(yyget_lineno()); (yyval.item_func_call_list)->add_arg((yyvsp[(1) - (1)].item_expr)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2712 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.cc"
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


#line 543 "/Users/chenhaobin/Documents/NKU/Computer/compilation/compiler/Compiler/src/frontend/parser/parser.ypp"

