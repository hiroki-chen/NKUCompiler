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
     STRUCT = 288,
     IF = 289,
     ELSE = 290,
     WHILE = 291,
     FOR = 292,
     RETURN = 293,
     BREAK = 294,
     CONTINUE = 295,
     CONST = 296,
     ASSIGN = 297,
     LBRACE = 298,
     RBRACE = 299,
     LPARENTHESIS = 300,
     RPARENTHESIS = 301,
     LSQUARE = 302,
     RSQUARE = 303,
     SEMICOLON = 304,
     DOT = 305,
     COMMA = 306,
     GE = 307,
     LE = 308
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
#define STRUCT 288
#define IF 289
#define ELSE 290
#define WHILE 291
#define FOR 292
#define RETURN 293
#define BREAK 294
#define CONTINUE 295
#define CONST 296
#define ASSIGN 297
#define LBRACE 298
#define RBRACE 299
#define LPARENTHESIS 300
#define RPARENTHESIS 301
#define LSQUARE 302
#define RSQUARE 303
#define SEMICOLON 304
#define DOT 305
#define COMMA 306
#define GE 307
#define LE 308




/* Copy the first part of user declarations.  */
#line 3 "./src/frontend/parser/parser.ypp"

    /*************************************************************
    parser.ypp
    YACC FILE
    Date: 2021/10/18
    Haobin Chen (@Aoyamahiroki) <etyyuiope@gmail.com>
    Jiawei Xu   (@Darren-8)

    Main tokenizer
    **************************************************************/
    #include <common/config.hh>
    #include <common/types.hh>
    #include <runtime/runtime.hh>
    #include <frontend/nodes/item_all.hh>
    #include <frontend/parser/parser.hh>
    //#include <frontend/symbol_table.hh>

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <stdexcept>

    //extern compiler::Symbol_table symbol_table;
    extern uint32_t yylineno;

    extern compiler::Compiler_runtime* compiler_runtime;

    extern int yylex(void);
    extern int yyget_lineno(void);
    extern int yylex_destroy();
    extern int yyparse(void);

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
        std::cerr << yylloc.first_line << ':'
                  << yylloc.first_column << " : [ERROR]: " << str << std::endl;
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
#line 60 "./src/frontend/parser/parser.ypp"
{
    compiler::basic_type                btype;
    compiler::Item_root*                item_root;               // root
    compiler::Item_decl*                item_decl;
    compiler::Item_stmt*                item_stmt;
    compiler::Item_stmt_decl*           item_stmt_decl;
    compiler::Item_func_def*            item_func_def;
    compiler::Item_expr*                item_expr;
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
    std::string*                        raw_string;
    double                              raw_number;
    char                                raw_char;
}
/* Line 193 of yacc.c.  */
#line 284 "./src/frontend/parser/parser.cc"
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
#line 309 "./src/frontend/parser/parser.cc"

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNRULES -- Number of states.  */
#define YYNSTATES  235

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
       2,     2,    54,     2,     2,     2,     2,     2,     2,     2,
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
       0,     0,     3,     6,     9,    11,    13,    15,    17,    20,
      23,    25,    27,    29,    31,    34,    38,    42,    46,    48,
      50,    54,    56,    60,    62,    67,    72,    76,    79,    81,
      83,    87,    91,    98,   105,   111,   117,   121,   123,   125,
     127,   130,   135,   139,   141,   143,   146,   150,   152,   155,
     157,   159,   161,   163,   165,   167,   169,   171,   173,   175,
     177,   180,   183,   186,   190,   196,   204,   207,   209,   215,
     222,   230,   237,   245,   248,   252,   255,   258,   261,   264,
     266,   268,   273,   278,   280,   284,   288,   290,   294,   296,
     300,   304,   306,   310,   314,   318,   322,   324,   326,   330,
     334,   336,   340,   344,   346,   350,   354,   356,   360,   364,
     366,   370,   374,   378,   380,   383,   386,   389,   392,   394,
     396,   400,   402,   404,   406,   408,   410,   412,   414,   416,
     420,   425,   429
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    56,    57,    -1,    56,    71,    -1,    57,
      -1,    71,    -1,    58,    -1,    59,    -1,    61,    49,    -1,
      62,    49,    -1,    28,    -1,    29,    -1,    30,    -1,    31,
      -1,    60,    63,    -1,    61,    51,    63,    -1,    41,    60,
      68,    -1,    62,    51,    68,    -1,    64,    -1,    65,    -1,
      76,    42,    93,    -1,    76,    -1,    66,    42,    67,    -1,
      66,    -1,    66,    47,    93,    48,    -1,    76,    47,    93,
      48,    -1,    43,    77,    44,    -1,    43,    44,    -1,    69,
      -1,    70,    -1,    76,    42,    93,    -1,    66,    42,    67,
      -1,    60,    76,    45,    72,    46,    78,    -1,    32,    76,
      45,    72,    46,    78,    -1,    60,    76,    45,    46,    78,
      -1,    32,    76,    45,    46,    78,    -1,    72,    51,    73,
      -1,    73,    -1,    74,    -1,    75,    -1,    60,    76,    -1,
      60,    76,    47,    48,    -1,    75,    47,    48,    -1,     3,
      -1,    54,    -1,    43,    44,    -1,    43,    79,    44,    -1,
      80,    -1,    79,    80,    -1,    57,    -1,    81,    -1,    78,
      -1,    87,    -1,    88,    -1,    85,    -1,    84,    -1,    82,
      -1,    83,    -1,    89,    -1,    86,    -1,    39,    49,    -1,
      40,    49,    -1,    38,    49,    -1,    38,    93,    49,    -1,
      34,    45,    93,    46,    81,    -1,    34,    45,    93,    46,
      81,    35,    81,    -1,    93,    49,    -1,    49,    -1,    36,
      45,    93,    46,    81,    -1,    37,    45,    86,    86,    46,
      78,    -1,    37,    45,    86,    86,    46,    93,    78,    -1,
      37,    45,    57,    86,    46,    78,    -1,    37,    45,    57,
      86,    93,    46,    78,    -1,    90,    49,    -1,    91,    42,
      93,    -1,    91,     9,    -1,    91,    10,    -1,     9,    91,
      -1,    10,    91,    -1,    76,    -1,    92,    -1,    91,    47,
      93,    48,    -1,    92,    47,    93,    48,    -1,    94,    -1,
      95,    22,    95,    -1,    94,    22,    95,    -1,    95,    -1,
      95,    21,    96,    -1,    96,    -1,    97,    11,    97,    -1,
      97,    12,    97,    -1,    97,    -1,    97,    52,    97,    -1,
      97,    53,    97,    -1,    97,    15,    97,    -1,    97,    16,
      97,    -1,   102,    -1,    99,    -1,   100,    18,   100,    -1,
      99,    18,   100,    -1,   100,    -1,   101,    19,   101,    -1,
     100,    19,   101,    -1,   101,    -1,    94,    17,    94,    -1,
     101,    17,    94,    -1,    94,    -1,   102,     4,   103,    -1,
     102,     5,   103,    -1,   103,    -1,   103,     6,   104,    -1,
     103,     7,   104,    -1,   103,     8,   104,    -1,   104,    -1,
       4,   104,    -1,     5,   104,    -1,    23,   104,    -1,    20,
     104,    -1,   107,    -1,   105,    -1,    45,    93,    46,    -1,
      91,    -1,   106,    -1,    90,    -1,    26,    -1,    25,    -1,
      24,    -1,    31,    -1,    27,    -1,    76,    45,    46,    -1,
      76,    45,   108,    46,    -1,   108,    51,    98,    -1,    98,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   139,   140,   141,   144,   145,   148,   151,
     154,   155,   156,   157,   160,   161,   164,   165,   168,   169,
     172,   173,   176,   177,   180,   181,   184,   185,   188,   189,
     192,   195,   198,   199,   200,   201,   204,   205,   208,   209,
     212,   215,   220,   223,   226,   229,   230,   233,   234,   237,
     238,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     252,   255,   258,   259,   262,   263,   266,   267,   270,   273,
     274,   275,   276,   279,   282,   283,   292,   301,   302,   305,
     306,   309,   310,   313,   316,   317,   318,   321,   322,   325,
     326,   327,   330,   331,   332,   333,   334,   338,   341,   342,
     343,   346,   347,   348,   351,   352,   353,   356,   357,   358,
     361,   362,   363,   364,   367,   368,   369,   370,   371,   372,
     375,   376,   377,   378,   381,   382,   383,   384,   385,   388,
     389,   392,   393
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
  "VOID", "STRUCT", "IF", "ELSE", "WHILE", "FOR", "RETURN", "BREAK",
  "CONTINUE", "CONST", "ASSIGN", "LBRACE", "RBRACE", "LPARENTHESIS",
  "RPARENTHESIS", "LSQUARE", "RSQUARE", "SEMICOLON", "DOT", "COMMA", "GE",
  "LE", "'foo'", "$accept", "CompUnit", "Decl", "VarDeclStmt",
  "ConstDeclStmt", "BType", "VarDecl", "ConstDecl", "VarDef",
  "VarDefNormal", "VarDefArray", "ArrayID", "ArrayInitVal", "ConstDef",
  "ConstDefNormal", "ConstDefArray", "FuncDef", "FuncDefList", "FuncParam",
  "FuncParamNormal", "FuncParamArray", "Ident", "ArrayInitValHelper",
  "BLOCK", "BlockItems", "BlockItem", "Stmt", "BreakStmt", "ContinueStmt",
  "ReturnStmt", "eIfStmt", "ExpStmt", "WhileStmt", "ForStmt", "AssignStmt",
  "Assignment", "LVal", "ArrayItem", "Exp", "LOrExp", "LAndExp", "EqExp",
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
     305,   306,   307,   308,   102
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    57,    57,    58,    59,
      60,    60,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    75,    75,    76,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    83,    84,    84,    85,    85,    86,    86,    87,    88,
      88,    88,    88,    89,    90,    90,    90,    90,    90,    91,
      91,    92,    92,    93,    94,    94,    94,    95,    95,    96,
      96,    96,    97,    97,    97,    97,    97,    98,    99,    99,
      99,   100,   100,   100,   101,   101,   101,   102,   102,   102,
     103,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     105,   105,   105,   105,   106,   106,   106,   106,   106,   107,
     107,   108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     3,     3,     3,     1,     1,
       3,     1,     3,     1,     4,     4,     3,     2,     1,     1,
       3,     3,     6,     6,     5,     5,     3,     1,     1,     1,
       2,     4,     3,     1,     1,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     3,     5,     7,     2,     1,     5,     6,
       7,     6,     7,     2,     3,     2,     2,     2,     2,     1,
       1,     4,     4,     1,     3,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,    12,    13,     0,     0,     0,     4,     6,
       7,     0,     0,     0,     5,    43,     0,     0,     1,     2,
       3,    14,    18,    19,    23,    21,     8,     0,     9,     0,
       0,     0,    16,    28,    29,     0,     0,     0,     0,     0,
       0,    15,    21,    17,     0,     0,     0,    37,    38,    39,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
     126,   125,   124,   128,   127,     0,    79,   123,   121,    80,
       0,    83,    86,    88,    91,    96,   109,   113,   119,   122,
     118,    20,     0,     0,     0,     0,    35,    40,     0,     0,
       0,    31,    30,    27,    44,     0,   114,   115,    79,    77,
      78,   117,   116,     0,     0,    75,    76,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,    25,   127,     0,
       0,     0,     0,     0,     0,    45,    67,    49,     0,    51,
       0,    47,    50,    56,    57,    55,    54,    59,    52,    53,
      58,   123,     0,     0,    33,    36,    42,    26,   120,   129,
     106,   132,    97,   100,   103,     0,    74,     0,     0,    85,
      87,    84,    89,    90,    94,    95,    92,    93,   107,   108,
     110,   111,   112,    32,     0,     0,     0,    62,     0,    60,
      61,    46,    48,    73,    66,    41,     0,     0,     0,     0,
       0,     0,   130,     0,    81,    82,     0,     0,     0,     0,
      63,   104,    99,    98,   102,   105,   101,   131,     0,     0,
       0,     0,    64,    68,     0,     0,     0,     0,    71,     0,
      69,     0,    65,    72,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,   137,     9,    10,    45,    12,    13,    21,    22,
      23,    24,    53,    32,    33,    34,    14,    46,    47,    48,
      49,    66,    95,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    67,    68,    69,   152,    71,
      72,    73,    74,   161,   162,   163,   164,    75,    76,    77,
      78,    79,    80,   165
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -184
static const yytype_int16 yypact[] =
{
      52,  -184,  -184,  -184,  -184,     5,   177,    37,  -184,  -184,
    -184,     5,    -3,    71,  -184,  -184,   -33,     5,  -184,  -184,
    -184,  -184,  -184,  -184,    14,    67,  -184,     5,  -184,     5,
      87,    44,  -184,  -184,  -184,    60,    30,   404,   404,   131,
     404,  -184,    66,  -184,    34,     5,    88,  -184,  -184,   -15,
      30,   404,   -14,  -184,   404,   404,     5,     5,   404,   404,
    -184,  -184,  -184,  -184,  -184,   404,     0,  -184,    32,    38,
      75,    70,   145,  -184,    11,   196,   174,  -184,  -184,  -184,
    -184,  -184,    34,    92,    89,   194,  -184,    72,    34,   177,
      93,  -184,  -184,  -184,  -184,   111,  -184,  -184,  -184,    98,
      98,  -184,  -184,   117,   148,  -184,  -184,   404,   404,   404,
    -184,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,  -184,    34,  -184,   181,   141,
     143,   146,   323,   153,   164,  -184,  -184,  -184,     5,  -184,
     237,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,   180,   187,   197,  -184,  -184,  -184,  -184,  -184,  -184,
     147,  -184,   226,   191,    43,   119,  -184,   200,   201,   229,
    -184,   229,    23,    23,  -184,  -184,  -184,  -184,   174,   174,
    -184,  -184,  -184,  -184,   404,   404,   101,  -184,   202,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,   404,   404,   404,   404,
     404,   404,  -184,   404,  -184,  -184,   206,   207,   332,   332,
    -184,    70,   235,   235,   238,    70,   238,  -184,   280,   280,
     366,   210,   223,  -184,    34,   213,   375,   280,  -184,    34,
    -184,    34,  -184,  -184,  -184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,    10,  -184,  -184,     9,  -184,  -184,   242,  -184,
    -184,   -11,   220,   243,  -184,  -184,   272,   248,   199,  -184,
    -184,     2,  -184,   -39,  -184,   151,  -183,  -184,  -184,  -184,
    -184,  -175,  -184,  -184,  -184,   -83,   155,  -184,   -37,  -100,
      65,   182,   -64,    90,  -184,    18,   -45,  -184,   106,   -34,
    -184,  -184,  -184,  -184
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -14
static const yytype_int16 yytable[] =
{
      70,    81,   151,    84,   160,    86,    31,    16,    15,    11,
       8,   209,    30,    25,    92,    17,    11,    19,    31,    35,
      96,    97,   114,   115,   101,   102,   116,   117,   103,    42,
      93,    35,    90,   220,   221,   222,   223,    18,   116,   117,
      94,   105,   106,   125,   232,   104,    26,    87,    27,   154,
     172,   173,   174,   175,   176,   177,    36,   151,    98,    98,
     200,    37,   201,   118,   119,     1,     2,     3,     4,     5,
     166,   167,   168,    52,   107,   118,   119,    85,     6,   108,
       1,     2,     3,     4,     5,   109,    50,   183,   180,   181,
     182,    37,   111,     6,   138,   188,   211,   160,   160,   160,
     215,   160,    51,   160,    15,    54,    55,    40,    38,    38,
      56,    57,    39,    40,    40,     1,     2,     3,     4,   153,
      28,    58,    29,   110,    59,    60,    61,    62,    63,     1,
       2,     3,   128,    44,    88,   151,   151,   127,   126,    89,
      42,   156,     6,    89,   151,   108,    65,   206,   207,   138,
     136,    15,    54,    55,   214,   157,   216,    56,    57,     1,
       2,     3,     4,   158,   196,   202,   112,   113,    58,   111,
     203,    59,    60,    61,    62,    63,   169,    82,   171,    64,
     122,   123,   124,   225,   -13,   228,   184,   230,   185,   231,
     233,   186,   234,    65,   159,   138,   208,    15,    54,    55,
     120,   121,   189,    56,    57,     1,     2,     3,     4,   198,
     199,    99,   100,   190,    58,   212,   213,    59,    60,    61,
      62,    63,     1,     2,     3,   128,   178,   179,   129,   193,
     130,   131,   132,   133,   134,     6,   194,    85,   135,    65,
      15,    54,    55,   136,   197,   195,    56,    57,   204,   205,
     112,   210,   218,   219,   199,   200,   226,    58,   227,   229,
      59,    60,    61,    62,    63,     1,     2,     3,   128,    41,
      91,   129,    43,   130,   131,   132,   133,   134,     6,    20,
      85,   191,    65,    15,    54,    55,   136,    83,   155,    56,
      57,   192,     0,   217,   170,     0,     0,     0,     0,     0,
      58,     0,     0,    59,    60,    61,    62,    63,     0,     0,
       0,    64,     0,     0,   129,     0,   130,   131,   132,   133,
     134,     0,     0,    85,     0,    65,    15,    54,    55,   136,
       0,     0,    56,    57,     0,    15,    54,    55,     0,     0,
       0,    56,    57,    58,     0,     0,    59,    60,    61,    62,
      63,     0,    58,     0,    64,    59,    60,    61,    62,    63,
       0,     0,     0,    64,     0,     0,     0,     0,    65,    15,
      54,    55,   187,     0,     0,    56,    57,    65,    15,    54,
      55,   136,     0,     0,    56,    57,    58,     0,     0,    59,
      60,    61,    62,    63,     0,    58,     0,    64,    59,    60,
      61,    62,    63,     0,     0,     0,    64,    15,    54,    55,
       0,    65,   224,    56,    57,     0,     0,     0,    85,     0,
      65,     0,     0,     0,    58,     0,     0,    59,    60,    61,
      62,    63,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65
};

static const yytype_int16 yycheck[] =
{
      37,    38,    85,    40,   104,    44,    17,     5,     3,     0,
       0,   186,    45,    11,    51,     6,     7,     7,    29,    17,
      54,    55,    11,    12,    58,    59,    15,    16,    65,    27,
      44,    29,    47,   208,   209,   218,   219,     0,    15,    16,
      54,     9,    10,    82,   227,    45,    49,    45,    51,    88,
     114,   115,   116,   117,   118,   119,    42,   140,    56,    57,
      17,    47,    19,    52,    53,    28,    29,    30,    31,    32,
     107,   108,   109,    43,    42,    52,    53,    43,    41,    47,
      28,    29,    30,    31,    32,    47,    42,   126,   122,   123,
     124,    47,    22,    41,    85,   132,   196,   197,   198,   199,
     200,   201,    42,   203,     3,     4,     5,    47,    42,    42,
       9,    10,    45,    47,    47,    28,    29,    30,    31,    47,
      49,    20,    51,    48,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    46,    46,   218,   219,    48,    46,    51,
     138,    48,    41,    51,   227,    47,    45,   184,   185,   140,
      49,     3,     4,     5,   199,    44,   201,     9,    10,    28,
      29,    30,    31,    46,    17,    46,    21,    22,    20,    22,
      51,    23,    24,    25,    26,    27,   111,    46,   113,    31,
       6,     7,     8,   220,     3,   224,    45,   226,    45,   226,
     229,    45,   231,    45,    46,   186,   186,     3,     4,     5,
       4,     5,    49,     9,    10,    28,    29,    30,    31,    18,
      19,    56,    57,    49,    20,   197,   198,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   120,   121,    34,    49,
      36,    37,    38,    39,    40,    41,    49,    43,    44,    45,
       3,     4,     5,    49,    18,    48,     9,    10,    48,    48,
      21,    49,    46,    46,    19,    17,    46,    20,    35,    46,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    27,
      50,    34,    29,    36,    37,    38,    39,    40,    41,     7,
      43,    44,    45,     3,     4,     5,    49,    39,    89,     9,
      10,   140,    -1,   203,   112,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    45,     3,     4,     5,    49,
      -1,    -1,     9,    10,    -1,     3,     4,     5,    -1,    -1,
      -1,     9,    10,    20,    -1,    -1,    23,    24,    25,    26,
      27,    -1,    20,    -1,    31,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    45,     3,
       4,     5,    49,    -1,    -1,     9,    10,    45,     3,     4,
       5,    49,    -1,    -1,     9,    10,    20,    -1,    -1,    23,
      24,    25,    26,    27,    -1,    20,    -1,    31,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,     3,     4,     5,
      -1,    45,    46,     9,    10,    -1,    -1,    -1,    43,    -1,
      45,    -1,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    30,    31,    32,    41,    56,    57,    58,
      59,    60,    61,    62,    71,     3,    76,    60,     0,    57,
      71,    63,    64,    65,    66,    76,    49,    51,    49,    51,
      45,    66,    68,    69,    70,    76,    42,    47,    42,    45,
      47,    63,    76,    68,    46,    60,    72,    73,    74,    75,
      42,    42,    43,    67,     4,     5,     9,    10,    20,    23,
      24,    25,    26,    27,    31,    45,    76,    90,    91,    92,
      93,    94,    95,    96,    97,   102,   103,   104,   105,   106,
     107,    93,    46,    72,    93,    43,    78,    76,    46,    51,
      47,    67,    93,    44,    54,    77,   104,   104,    76,    91,
      91,   104,   104,    93,    45,     9,    10,    42,    47,    47,
      48,    22,    21,    22,    11,    12,    15,    16,    52,    53,
       4,     5,     6,     7,     8,    78,    46,    48,    31,    34,
      36,    37,    38,    39,    40,    44,    49,    57,    60,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    93,    47,    78,    73,    48,    44,    46,    46,
      94,    98,    99,   100,   101,   108,    93,    93,    93,    95,
      96,    95,    97,    97,    97,    97,    97,    97,   103,   103,
     104,   104,   104,    78,    45,    45,    45,    49,    93,    49,
      49,    44,    80,    49,    49,    48,    17,    18,    18,    19,
      17,    19,    46,    51,    48,    48,    93,    93,    57,    86,
      49,    94,   100,   100,   101,    94,   101,    98,    46,    46,
      86,    86,    81,    81,    46,    93,    46,    35,    78,    46,
      78,    93,    81,    78,    78
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
#line 138 "./src/frontend/parser/parser.ypp"
    { (yyval.item_root)->add_child((yyvsp[(2) - (2)].item_decl)); }
    break;

  case 3:
#line 139 "./src/frontend/parser/parser.ypp"
    { (yyval.item_root)->add_child((yyvsp[(2) - (2)].item_func_def)); }
    break;

  case 4:
#line 140 "./src/frontend/parser/parser.ypp"
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[(1) - (1)].item_decl)); }
    break;

  case 5:
#line 141 "./src/frontend/parser/parser.ypp"
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[(1) - (1)].item_func_def)); }
    break;

  case 8:
#line 148 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); }
    break;

  case 9:
#line 151 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = (yyvsp[(1) - (2)].item_stmt_decl); }
    break;

  case 10:
#line 154 "./src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::INT_TYPE; }
    break;

  case 11:
#line 155 "./src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; }
    break;

  case 12:
#line 156 "./src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; }
    break;

  case 13:
#line 157 "./src/frontend/parser/parser.ypp"
    { (yyval.btype) = compiler::basic_type::CHAR_TYPE; }
    break;

  case 14:
#line 160 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(1) - (2)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(2) - (2)].item_decl)); }
    break;

  case 15:
#line 161 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); }
    break;

  case 16:
#line 164 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[(2) - (3)].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); }
    break;

  case 17:
#line 165 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[(3) - (3)].item_decl)); }
    break;

  case 20:
#line 172 "./src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr), false); }
    break;

  case 21:
#line 173 "./src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var(yyget_lineno(), (yyvsp[(1) - (1)].item_ident)); }
    break;

  case 22:
#line 176 "./src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_array), (yyvsp[(3) - (3)].item_literal_array_init), false); }
    break;

  case 23:
#line 177 "./src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array(yyget_lineno(), (yyvsp[(1) - (1)].item_ident_array)); }
    break;

  case 24:
#line 180 "./src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (4)].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); }
    break;

  case 25:
#line 181 "./src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (4)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); }
    break;

  case 26:
#line 184 "./src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = (yyvsp[(2) - (3)].item_literal_array_init); }
    break;

  case 27:
#line 185 "./src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); }
    break;

  case 30:
#line 192 "./src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr), true); }
    break;

  case 31:
#line 195 "./src/frontend/parser/parser.ypp"
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[(1) - (3)].item_ident_array), (yyvsp[(3) - (3)].item_literal_array_init), true); }
    break;

  case 32:
#line 198 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[(1) - (6)].btype), (yyvsp[(2) - (6)].item_ident), (yyvsp[(4) - (6)].item_func_def_list), (yyvsp[(6) - (6)].item_block)); }
    break;

  case 33:
#line 199 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[(2) - (6)].item_ident), (yyvsp[(4) - (6)].item_func_def_list), (yyvsp[(6) - (6)].item_block)); }
    break;

  case 34:
#line 200 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[(1) - (5)].btype), (yyvsp[(2) - (5)].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[(5) - (5)].item_block)); }
    break;

  case 35:
#line 201 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[(2) - (5)].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[(5) - (5)].item_block)); }
    break;

  case 36:
#line 204 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_list)->add_arg((yyvsp[(3) - (3)].item_func_def_arg)); }
    break;

  case 37:
#line 205 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_list) = new compiler::Item_func_def_list(yyget_lineno()); (yyval.item_func_def_list)->add_arg((yyvsp[(1) - (1)].item_func_def_arg)); }
    break;

  case 40:
#line 212 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (2)].btype), (yyvsp[(2) - (2)].item_ident)); }
    break;

  case 41:
#line 215 "./src/frontend/parser/parser.ypp"
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(2) - (4)].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[(1) - (4)].btype), ident);
                                                        }
    break;

  case 42:
#line 220 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_def_arg) = (yyvsp[(1) - (3)].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); }
    break;

  case 43:
#line 223 "./src/frontend/parser/parser.ypp"
    { (yyval.item_ident) = new compiler::Item_ident(yyget_lineno(), *(yyvsp[(1) - (1)].raw_string)); }
    break;

  case 44:
#line 226 "./src/frontend/parser/parser.ypp"
    { (yyval.item_literal_array_init) = nullptr; /* NOT IMPLEMENTED YET. */}
    break;

  case 45:
#line 229 "./src/frontend/parser/parser.ypp"
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); }
    break;

  case 46:
#line 230 "./src/frontend/parser/parser.ypp"
    { (yyval.item_block) = (yyvsp[(2) - (3)].item_block); }
    break;

  case 47:
#line 233 "./src/frontend/parser/parser.ypp"
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); (yyval.item_block)->add_item((yyvsp[(1) - (1)].item_stmt)); }
    break;

  case 48:
#line 234 "./src/frontend/parser/parser.ypp"
    { (yyval.item_block) = (yyvsp[(1) - (2)].item_block); (yyval.item_block)->add_item((yyvsp[(2) - (2)].item_stmt)); }
    break;

  case 49:
#line 237 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); }
    break;

  case 50:
#line 238 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); }
    break;

  case 51:
#line 241 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (1)].item_stmt); }
    break;

  case 60:
#line 252 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_break(yyget_lineno()); }
    break;

  case 61:
#line 255 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_continue(yyget_lineno()); }
    break;

  case 62:
#line 258 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), nullptr); }
    break;

  case 63:
#line 259 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), (yyvsp[(2) - (3)].item_expr)); }
    break;

  case 64:
#line 262 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), (yyvsp[(3) - (5)].item_expr), (yyvsp[(5) - (5)].item_stmt), new compiler::Item_stmt_void(yyget_lineno())); }
    break;

  case 65:
#line 263 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), (yyvsp[(3) - (7)].item_expr), (yyvsp[(5) - (7)].item_stmt), (yyvsp[(7) - (7)].item_stmt)); }
    break;

  case 66:
#line 266 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_eval(yyget_lineno(), (yyvsp[(1) - (2)].item_expr)); }
    break;

  case 67:
#line 267 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_void(yyget_lineno()); }
    break;

  case 68:
#line 270 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), (yyvsp[(3) - (5)].item_expr), (yyvsp[(5) - (5)].item_stmt)); }
    break;

  case 73:
#line 279 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = (yyvsp[(1) - (2)].item_stmt); }
    break;

  case 74:
#line 282 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 75:
#line 283 "./src/frontend/parser/parser.ypp"
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::ADD_TYPE,
                                                    (yyvsp[(1) - (2)].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (2)].item_ident), expr);
                                      }
    break;

  case 76:
#line 292 "./src/frontend/parser/parser.ypp"
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::SUB_TYPE,
                                                    (yyvsp[(1) - (2)].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[(1) - (2)].item_ident), expr);
                                      }
    break;

  case 77:
#line 301 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[(2) - (2)].item_ident), compiler::binary_type::ADD_TYPE); }
    break;

  case 78:
#line 302 "./src/frontend/parser/parser.ypp"
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[(2) - (2)].item_ident), compiler::binary_type::SUB_TYPE); }
    break;

  case 80:
#line 306 "./src/frontend/parser/parser.ypp"
    { (yyval.item_ident) = (yyvsp[(1) - (1)].item_ident); }
    break;

  case 81:
#line 309 "./src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[(1) - (4)].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr));}
    break;

  case 82:
#line 310 "./src/frontend/parser/parser.ypp"
    { (yyval.item_ident_array) = (yyvsp[(1) - (4)].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[(3) - (4)].item_expr)); }
    break;

  case 84:
#line 316 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 85:
#line 317 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 87:
#line 321 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 89:
#line 325 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::EQ_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 90:
#line 326 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::NEQ_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 92:
#line 330 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::GE_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 93:
#line 331 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LE_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 94:
#line 332 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::G_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 95:
#line 333 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::L_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 98:
#line 341 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 99:
#line 342 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 101:
#line 346 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 102:
#line 347 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 104:
#line 351 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 105:
#line 352 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 107:
#line 356 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::ADD_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 108:
#line 357 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::SUB_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 110:
#line 361 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MUL_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 111:
#line 362 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::DIV_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 112:
#line 363 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MOD_TYPE, (yyvsp[(1) - (3)].item_expr), (yyvsp[(3) - (3)].item_expr)); }
    break;

  case 114:
#line 367 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UADD_TYPE, (yyvsp[(2) - (2)].item_expr)); }
    break;

  case 115:
#line 368 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UMINUS_TYPE, (yyvsp[(2) - (2)].item_expr)); }
    break;

  case 116:
#line 369 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::LNOT_TYPE, (yyvsp[(2) - (2)].item_expr)); }
    break;

  case 117:
#line 370 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::BITNEG_TYPE, (yyvsp[(2) - (2)].item_expr)); }
    break;

  case 120:
#line 375 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(2) - (3)].item_expr); }
    break;

  case 121:
#line 376 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); }
    break;

  case 122:
#line 377 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); }
    break;

  case 123:
#line 378 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = (yyvsp[(1) - (1)].item_expr); }
    break;

  case 124:
#line 381 "./src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[(1) - (1)].raw_number)); }
    break;

  case 125:
#line 382 "./src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[(1) - (1)].raw_number)); }
    break;

  case 126:
#line 383 "./src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_real(yyget_lineno(), (yyvsp[(1) - (1)].raw_number)); }
    break;

  case 127:
#line 384 "./src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_char(yyget_lineno(), (yyvsp[(1) - (1)].raw_char)); }
    break;

  case 128:
#line 385 "./src/frontend/parser/parser.ypp"
    { (yyval.item_literal) = new compiler::Item_literal_string(yyget_lineno(), *(yyvsp[(1) - (1)].raw_string)); }
    break;

  case 129:
#line 388 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[(1) - (3)].item_ident), new compiler::Item_func_call_list(yyget_lineno())); }
    break;

  case 130:
#line 389 "./src/frontend/parser/parser.ypp"
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[(1) - (4)].item_ident), (yyvsp[(3) - (4)].item_func_call_list)); }
    break;

  case 131:
#line 392 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_call_list) = (yyvsp[(1) - (3)].item_func_call_list); (yyvsp[(1) - (3)].item_func_call_list)->add_arg((yyvsp[(3) - (3)].item_expr)); }
    break;

  case 132:
#line 393 "./src/frontend/parser/parser.ypp"
    { (yyval.item_func_call_list) = new compiler::Item_func_call_list(yyget_lineno()); (yyval.item_func_call_list)->add_arg((yyvsp[(1) - (1)].item_expr)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2305 "./src/frontend/parser/parser.cc"
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


#line 396 "./src/frontend/parser/parser.ypp"

