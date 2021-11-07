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
#line 3 "./src/frontend/parser/parser.ypp" /* yacc.c:339  */

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

#line 129 "./src/frontend/parser/parser.cc" /* yacc.c:339  */

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
   by #include "parser.hh".  */
#ifndef YY_YY_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED
# define YY_YY_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    COMMA = 308,
    LE = 309,
    GE = 310,
    THEN = 311
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
#define LE 309
#define GE 310
#define THEN 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "./src/frontend/parser/parser.ypp" /* yacc.c:355  */

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
    std::string*                        raw_string;
    double                              raw_number;
    char                                raw_char;

#line 307 "./src/frontend/parser/parser.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 338 "./src/frontend/parser/parser.cc" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   150,   150,   151,   152,   153,   156,   157,   160,   163,
     166,   167,   168,   169,   172,   173,   176,   177,   178,   181,
     182,   185,   186,   187,   188,   191,   192,   195,   196,   199,
     200,   203,   204,   207,   208,   211,   212,   215,   218,   219,
     220,   221,   224,   225,   228,   229,   232,   233,   236,   241,
     244,   247,   248,   253,   254,   259,   265,   270,   278,   279,
     282,   283,   286,   287,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   301,   304,   307,   308,   311,   312,   315,
     316,   319,   322,   323,   324,   325,   328,   331,   332,   341,
     350,   351,   354,   355,   358,   359,   362,   363,   366,   367,
     370,   371,   372,   375,   376,   379,   380,   381,   384,   385,
     386,   387,   388,   392,   395,   396,   397,   400,   401,   402,
     405,   406,   407,   410,   411,   412,   415,   416,   417,   418,
     421,   422,   423,   424,   425,   426,   427,   428,   431,   432,
     433,   434,   437,   438,   439,   440,   441,   442,   443,   446,
     447,   450,   451
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "ADD", "MINUS", "MUL", "DIV",
  "MOD", "INC", "DEC", "EQ", "NEQ", "GEQ", "LEQ", "G", "L", "BIT_AND",
  "BIT_OR", "BIT_XOR", "BIT_NEG", "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT",
  "DECIMAL", "OCTAL", "HEX", "STRING", "INT", "DOUBLE", "FLOAT", "CHAR",
  "VOID", "STRUCT", "IF", "ELSE", "WHILE", "FOR", "RETURN", "BREAK",
  "CONTINUE", "CONST", "ASSIGN", "TRUE", "FALSE", "LBRACE", "RBRACE",
  "LPARENTHESIS", "RPARENTHESIS", "LSQUARE", "RSQUARE", "SEMICOLON", "DOT",
  "COMMA", "LE", "GE", "THEN", "$accept", "CompUnit", "Decl",
  "VarDeclStmt", "ConstDeclStmt", "BType", "VarDecl", "ConstDecl",
  "VarDef", "VarDefNormal", "POINTER", "VarDefArray", "ArrayID",
  "ArrayInitVal", "ConstDef", "ConstDefNormal", "ConstDefArray", "FuncDef",
  "FuncDefList", "FuncParam", "FuncParamNormal", "FuncParamArray", "Ident",
  "ArrayInitValHelper", "BLOCK", "BlockItems", "BlockItem", "Stmt",
  "BreakStmt", "ContinueStmt", "ReturnStmt", "eIfStmt", "ExpStmt",
  "WhileStmt", "ForStmt", "AssignStmt", "Assignment", "LVal", "ArrayItem",
  "Exp", "CommaExp", "LOrExp", "LAndExp", "EqExp", "RelExp", "BitExp",
  "BitOrExp", "BitXorExp", "BitAndExp", "AddExp", "MulExp", "UnaryExp",
  "PrimaryExp", "LITERAL", "FunctionCall", "FunctionRParams", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -174

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-174)))

#define YYTABLE_NINF -14

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,  -174,  -174,  -174,  -174,    33,   115,    40,  -174,  -174,
    -174,    20,    77,   118,  -174,  -174,    60,    16,  -174,  -174,
    -174,   147,    16,  -174,  -174,     5,  -174,     7,    76,  -174,
      16,  -174,    16,    57,    41,    82,  -174,  -174,  -174,    99,
    -174,  -174,  -174,   565,    66,   565,   565,    62,   565,  -174,
     100,  -174,   115,    74,    33,    25,  -174,  -174,    91,   565,
      66,   565,   565,   565,   565,    33,    33,   565,   565,   565,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,   565,   114,  -174,
       8,   119,  -174,   111,     6,   133,   157,   586,  -174,   177,
     184,   172,   201,   179,  -174,  -174,  -174,  -174,   476,  -174,
     140,  -174,    74,    31,   148,    33,   213,  -174,   164,    74,
     106,   158,  -174,  -174,  -174,  -174,  -174,  -174,  -174,   166,
     166,  -174,  -174,  -174,   173,   418,  -174,  -174,   565,   565,
     565,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   565,   565,   565,   565,   565,   565,   565,   565,   565,
     565,   565,   565,  -174,  -174,    36,   174,    13,  -174,  -174,
      74,  -174,  -174,    39,   198,   199,   208,   360,   210,   211,
    -174,  -174,  -174,    20,  -174,   262,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,   212,   218,   220,  -174,
    -174,  -174,  -174,  -174,  -174,    79,  -174,   230,   231,   226,
     263,   226,  -174,   263,  -174,   309,   309,   309,   309,   197,
     197,   264,   264,   277,  -174,   277,   179,   179,  -174,  -174,
    -174,  -174,   507,   507,   507,  -174,   565,   565,   153,  -174,
     244,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,   565,
    -174,  -174,  -174,  -174,  -174,  -174,   249,   256,   389,   389,
    -174,  -174,   311,   311,   447,   270,   275,  -174,    74,   271,
     536,   311,  -174,    74,  -174,    74,  -174,  -174,  -174
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,    12,    13,     0,     0,     0,     4,     6,
       7,     0,     0,     0,     5,    50,     0,     0,     1,     2,
       3,     0,     0,    14,    19,    24,    20,    28,    22,     8,
       0,     9,     0,     0,     0,     0,    16,    33,    34,     0,
      25,    26,    18,     0,     0,     0,     0,     0,     0,    15,
      22,    17,     0,     0,     0,     0,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,   143,   142,   146,   145,   147,   148,     0,    92,   141,
     139,    93,    23,    97,    96,   102,   122,   107,   104,   113,
     116,   119,   112,   125,   129,   137,   140,   136,     0,    27,
       0,    21,     0,     0,     0,     0,     0,    41,    46,     0,
       0,     0,    36,    37,    35,   130,   131,   135,    92,    90,
      91,   134,   133,   132,     0,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    53,     0,    56,    54,    29,    40,
       0,    30,    47,   145,     0,     0,     0,     0,     0,     0,
      58,    80,    62,     0,    64,     0,    60,    63,    69,    70,
      68,    67,    72,    65,    66,    71,   141,     0,     0,    39,
      42,    49,   138,   149,   152,     0,    87,     0,     0,    99,
     101,    98,   103,   100,   120,   105,   106,   108,   109,   110,
     111,   115,   114,   118,   121,   117,   123,   124,   126,   127,
     128,    31,     0,     0,     0,    38,     0,     0,     0,    75,
       0,    73,    74,    59,    61,    86,    79,    48,   150,     0,
      94,    95,    51,    52,    57,    55,     0,     0,     0,     0,
      76,   151,     0,     0,     0,     0,    77,    81,     0,     0,
       0,     0,    84,     0,    82,     0,    78,    85,    83
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,     1,  -174,  -174,     0,  -174,  -174,   281,  -174,
      80,  -174,    45,   -57,    -2,  -174,  -174,   305,   279,   217,
    -174,  -174,    -1,  -174,   -51,  -174,   154,  -153,  -174,  -174,
    -174,  -174,  -173,  -174,  -174,  -174,  -101,   159,  -174,   -34,
     232,   -85,   -72,   -92,   136,  -110,  -174,    88,    54,  -174,
      86,   -30,  -174,  -174,  -174,  -174
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,   172,     9,    10,    54,    12,    13,    23,    24,
      25,    26,    27,    99,    36,    37,    38,    14,    55,    56,
      57,    58,    78,   155,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,    79,    80,    81,   187,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,   195
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,     8,   107,   113,    16,   186,    17,    11,    19,    82,
      28,   100,   101,   157,   104,   194,    39,   126,   127,    15,
      42,    39,    21,    15,   202,   112,    21,   114,   132,    50,
      51,    39,   115,   116,   117,   132,    15,   121,   122,   123,
      18,   154,   -13,   124,   204,   -13,   199,    43,   201,    44,
     128,   159,   105,   108,   214,   249,    45,   129,   189,   133,
     200,    22,    35,   203,   118,   118,   224,    35,     1,     2,
       3,     4,     5,   109,   186,   254,   255,    35,   110,   160,
     -13,     6,   221,    59,   110,     1,     2,     3,     4,   222,
       1,     2,     3,     4,   196,   197,   198,    34,    52,   256,
     257,    41,    34,    52,   162,    53,   173,    33,   266,   225,
     102,    98,    34,     1,     2,     3,     4,     5,    46,   106,
     218,   219,   220,    47,    60,    48,     6,   238,    29,   251,
      30,    45,   239,   230,     1,     2,     3,     4,   199,   201,
     111,    61,    46,     1,     2,     3,     4,    52,    48,    48,
      40,   186,   186,    21,   134,   135,    15,    62,    63,    64,
     186,   125,    65,    66,   131,   242,   244,   245,   130,    31,
      67,    32,    50,    68,   136,   173,    69,    70,    71,    72,
      73,     1,     2,     3,   163,   150,   151,   152,   243,   146,
     158,   147,   246,   247,     6,   143,    75,    76,   161,   213,
      77,   215,   144,   145,   171,   148,   149,   262,   191,   264,
     139,   140,   267,   188,   268,   129,    15,    62,    63,    64,
     259,   192,    65,    66,   119,   120,   265,   223,   173,   248,
      67,   211,   212,    68,   216,   217,    69,    70,    71,    72,
      73,     1,     2,     3,   163,   226,   227,   164,   132,   165,
     166,   167,   168,   169,     6,   228,    75,    76,   106,   170,
      77,   231,   232,   235,   171,    15,    62,    63,    64,   236,
     237,    65,    66,   205,   206,   207,   208,   209,   210,    67,
     240,   241,    68,   145,   134,    69,    70,    71,    72,    73,
       1,     2,     3,   163,   146,   250,   164,   252,   165,   166,
     167,   168,   169,     6,   253,    75,    76,   106,   233,    77,
     261,    49,    20,   171,    15,    62,    63,    64,   260,   263,
      65,    66,   139,   140,   141,   142,   103,   190,    67,   234,
     156,    68,     0,     0,    69,    70,    71,    72,    73,     0,
       0,     0,    74,     0,     0,   164,     0,   165,   166,   167,
     168,   169,     0,     0,    75,    76,   106,     0,    77,     0,
       0,     0,   171,    15,    62,    63,    64,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,    67,     0,     0,
      68,     0,     0,    69,    70,    71,    72,    73,     0,     0,
       0,    74,    15,    62,    63,    64,     0,     0,    65,    66,
       0,     0,     0,    75,    76,     0,    67,    77,     0,    68,
       0,   229,    69,    70,    71,    72,    73,     0,     0,     0,
      74,    15,    62,    63,    64,     0,     0,    65,    66,     0,
       0,     0,    75,    76,     0,    67,    77,     0,    68,     0,
     171,    69,    70,    71,    72,    73,     0,     0,     0,    74,
      15,    62,    63,    64,     0,     0,    65,    66,     0,     0,
       0,    75,    76,     0,    67,    77,   193,    68,     0,     0,
      69,    70,    71,    72,    73,     0,     0,     0,    74,    15,
      62,    63,    64,     0,     0,    65,    66,     0,     0,     0,
      75,    76,     0,    67,    77,   258,    68,     0,     0,    69,
      70,    71,    72,    73,     0,     0,     0,    74,     0,     0,
      15,    62,    63,    64,     0,     0,    65,    66,     0,    75,
      76,    98,   153,    77,    67,     0,     0,    68,     0,     0,
      69,    70,    71,    72,    73,     0,     0,     0,    74,    15,
      62,    63,    64,     0,     0,    65,    66,     0,     0,     0,
      75,    76,    98,    67,    77,     0,    68,     0,     0,    69,
      70,    71,    72,    73,     0,     0,     0,    74,    15,    62,
      63,    64,     0,     0,    65,    66,     0,     0,     0,    75,
      76,   106,    67,    77,     0,    68,     0,     0,    69,    70,
      71,    72,    73,     0,     0,     0,    74,   137,   138,   139,
     140,   141,   142,     0,     0,     0,     0,     0,    75,    76,
       0,     0,    77
};

static const yytype_int16 yycheck[] =
{
       0,     0,    53,    60,     5,   106,     6,     7,     7,    43,
      11,    45,    46,    98,    48,   125,    17,     9,    10,     3,
      22,    22,     6,     3,   134,    59,     6,    61,    22,    30,
      32,    32,    62,    63,    64,    22,     3,    67,    68,    69,
       0,    98,     3,    77,   136,     6,   131,    42,   133,    42,
      42,   102,    52,    54,   146,   228,    49,    49,   109,    53,
     132,    41,    17,   135,    65,    66,    53,    22,    28,    29,
      30,    31,    32,    48,   175,   248,   249,    32,    53,    48,
      41,    41,    46,    42,    53,    28,    29,    30,    31,    53,
      28,    29,    30,    31,   128,   129,   130,    17,    41,   252,
     253,    21,    22,    41,   105,    48,   106,    47,   261,   160,
      48,    45,    32,    28,    29,    30,    31,    32,    42,    45,
     150,   151,   152,    47,    42,    49,    41,    48,    51,   239,
      53,    49,    53,   167,    28,    29,    30,    31,   223,   224,
      49,    42,    42,    28,    29,    30,    31,    41,    49,    49,
       3,   252,   253,     6,    21,    22,     3,     4,     5,     6,
     261,    47,     9,    10,    53,   222,   223,   224,    49,    51,
      17,    53,   173,    20,    17,   175,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     6,     7,     8,   222,    17,
      50,    19,   226,   227,    41,    18,    43,    44,    50,   145,
      47,   147,    18,    19,    51,     4,     5,   258,    50,   260,
      13,    14,   263,    49,   265,    49,     3,     4,     5,     6,
     254,    48,     9,    10,    65,    66,   260,    53,   228,   228,
      17,   143,   144,    20,   148,   149,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    47,    47,    34,    22,    36,
      37,    38,    39,    40,    41,    47,    43,    44,    45,    46,
      47,    51,    51,    51,    51,     3,     4,     5,     6,    51,
      50,     9,    10,   137,   138,   139,   140,   141,   142,    17,
      50,    50,    20,    19,    21,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    17,    51,    34,    48,    36,    37,
      38,    39,    40,    41,    48,    43,    44,    45,    46,    47,
      35,    30,     7,    51,     3,     4,     5,     6,    48,    48,
       9,    10,    13,    14,    15,    16,    47,   110,    17,   175,
      98,    20,    -1,    -1,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,    -1,    -1,    34,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    43,    44,    45,    -1,    47,    -1,
      -1,    -1,    51,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      20,    -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,     3,     4,     5,     6,    -1,    -1,     9,    10,
      -1,    -1,    -1,    43,    44,    -1,    17,    47,    -1,    20,
      -1,    51,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,     3,     4,     5,     6,    -1,    -1,     9,    10,    -1,
      -1,    -1,    43,    44,    -1,    17,    47,    -1,    20,    -1,
      51,    23,    24,    25,    26,    27,    -1,    -1,    -1,    31,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,
      -1,    43,    44,    -1,    17,    47,    48,    20,    -1,    -1,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,     3,
       4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,
      43,    44,    -1,    17,    47,    48,    20,    -1,    -1,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    10,    -1,    43,
      44,    45,    46,    47,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    31,     3,
       4,     5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,
      43,    44,    45,    17,    47,    -1,    20,    -1,    -1,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    -1,    43,
      44,    45,    17,    47,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    30,    31,    32,    41,    58,    59,    60,
      61,    62,    63,    64,    74,     3,    79,    62,     0,    59,
      74,     6,    41,    65,    66,    67,    68,    69,    79,    51,
      53,    51,    53,    47,    67,    69,    71,    72,    73,    79,
       3,    67,    71,    42,    42,    49,    42,    47,    49,    65,
      79,    71,    41,    48,    62,    75,    76,    77,    78,    42,
      42,    42,     4,     5,     6,     9,    10,    17,    20,    23,
      24,    25,    26,    27,    31,    43,    44,    47,    79,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    45,    70,
      96,    96,    48,    75,    96,    62,    45,    81,    79,    48,
      53,    49,    96,    70,    96,   108,   108,   108,    79,    94,
      94,   108,   108,   108,    96,    47,     9,    10,    42,    49,
      49,    53,    22,    53,    21,    22,    17,    11,    12,    13,
      14,    15,    16,    18,    18,    19,    17,    19,     4,     5,
       6,     7,     8,    46,    70,    80,    97,    98,    50,    81,
      48,    50,    79,    31,    34,    36,    37,    38,    39,    40,
      46,    51,    59,    62,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    96,    49,    81,
      76,    50,    48,    48,   102,   112,    96,    96,    96,    98,
      99,    98,   102,    99,   100,   101,   101,   101,   101,   101,
     101,   104,   104,   105,   100,   105,   107,   107,   108,   108,
     108,    46,    53,    53,    53,    81,    47,    47,    47,    51,
      96,    51,    51,    46,    83,    51,    51,    50,    48,    53,
      50,    50,    70,    96,    70,    70,    96,    96,    59,    89,
      51,   102,    48,    48,    89,    89,    84,    84,    48,    96,
      48,    35,    81,    48,    81,    96,    84,    81,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    59,    59,    60,    61,
      62,    62,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    74,    74,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      79,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    86,    87,    87,    88,    88,    89,
      89,    90,    91,    91,    91,    91,    92,    93,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    98,    99,    99,   100,   100,   100,   101,   101,
     101,   101,   101,   102,   103,   103,   103,   104,   104,   104,
     105,   105,   105,   106,   106,   106,   107,   107,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   109,   110,   110,   110,   110,   110,   110,   110,   111,
     111,   112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     2,     3,     3,     3,     3,     1,
       1,     3,     1,     3,     1,     2,     2,     3,     1,     4,
       4,     3,     2,     1,     1,     3,     3,     3,     6,     6,
       5,     5,     3,     1,     1,     1,     2,     3,     4,     3,
       1,     3,     3,     1,     1,     3,     1,     3,     2,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     3,     5,     7,     2,
       1,     5,     6,     7,     6,     7,     2,     3,     2,     2,
       2,     2,     1,     1,     4,     4,     1,     1,     3,     3,
       3,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
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
     '$$ = $1'.

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
#line 150 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_root)->add_child((yyvsp[0].item_decl)); }
#line 1780 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 151 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_root)->add_child((yyvsp[0].item_func_def)); }
#line 1786 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 152 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[0].item_decl)); }
#line 1792 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 153 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[0].item_func_def)); }
#line 1798 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 160 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = (yyvsp[-1].item_stmt_decl); }
#line 1804 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 163 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = (yyvsp[-1].item_stmt_decl); }
#line 1810 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 166 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::INT_TYPE; }
#line 1816 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; }
#line 1822 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 168 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; }
#line 1828 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 169 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::CHAR_TYPE; }
#line 1834 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 172 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-1].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1840 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 173 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1846 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 176 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-1].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1852 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 177 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1858 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 178 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-2].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1864 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 185 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr), false); }
#line 1870 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 186 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_var(yyget_lineno(), (yyvsp[0].item_ident)); }
#line 1876 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 187 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[-2].item_ident_pointer), (yyvsp[0].item_expr), false); }
#line 1882 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 188 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_pointer(yyget_lineno(), (yyvsp[0].item_ident_pointer)); }
#line 1888 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 191 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_pointer) = new compiler::Item_ident_pointer(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 1894 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 192 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_pointer) = (yyvsp[0].item_ident_pointer); (yyvsp[0].item_ident_pointer)->add_shape(); }
#line 1900 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 195 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[-2].item_ident_array), (yyvsp[0].item_literal_array_init), false); }
#line 1906 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 196 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_array(yyget_lineno(), (yyvsp[0].item_ident_array)); }
#line 1912 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 199 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = (yyvsp[-3].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 1918 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 200 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-3].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 1924 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 203 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal_array_init) = (yyvsp[-1].item_literal_array_init); }
#line 1930 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 204 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); }
#line 1936 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 211 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr), true); }
#line 1942 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 212 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[-2].item_ident_pointer), (yyvsp[0].item_expr), true); }
#line 1948 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 215 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[-2].item_ident_array), (yyvsp[0].item_literal_array_init), true); }
#line 1954 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 218 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[-5].btype), (yyvsp[-4].item_ident), (yyvsp[-2].item_func_def_list), (yyvsp[0].item_block)); }
#line 1960 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 219 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[-4].item_ident), (yyvsp[-2].item_func_def_list), (yyvsp[0].item_block)); }
#line 1966 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 220 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[-4].btype), (yyvsp[-3].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[0].item_block)); }
#line 1972 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 221 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[-3].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[0].item_block)); }
#line 1978 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 224 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_list)->add_arg((yyvsp[0].item_func_def_arg)); }
#line 1984 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 225 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_list) = new compiler::Item_func_def_list(yyget_lineno()); (yyval.item_func_def_list)->add_arg((yyvsp[0].item_func_def_arg)); }
#line 1990 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 232 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-1].btype), (yyvsp[0].item_ident)); }
#line 1996 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 233 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-1].btype), (yyvsp[0].item_ident)); }
#line 2002 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 236 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-2].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-3].btype), ident);
                                                        }
#line 2012 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 241 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_arg) = (yyvsp[-2].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); }
#line 2018 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 244 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident) = new compiler::Item_ident(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 2024 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 247 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal_array_init) = (yyvsp[-2].item_literal_array_init); (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init)); }
#line 2030 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 248 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.item_literal_array_init) = (yyvsp[-2].item_literal_array_init);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[0].item_expr), false);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                              }
#line 2040 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 253 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init)); }
#line 2046 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 254 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[0].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init); 
                                                              }
#line 2056 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 259 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[-2].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                                (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init));
                                                              }
#line 2067 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 265 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { 
                                                                 (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                                                                 compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[0].item_expr_comma), true);
                                                                 (yyval.item_literal_array_init)->add_value(array_init);
                                                              }
#line 2077 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 270 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                                 (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                                                                 compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[-2].item_expr_comma), true);
                                                                 (yyval.item_literal_array_init)->add_value(array_init);
                                                                 (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init));
                                                              }
#line 2088 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 278 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); }
#line 2094 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 279 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_block) = (yyvsp[-1].item_block); }
#line 2100 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 282 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); (yyval.item_block)->add_item((yyvsp[0].item_stmt)); }
#line 2106 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 283 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_block) = (yyvsp[-1].item_block); (yyval.item_block)->add_item((yyvsp[0].item_stmt)); }
#line 2112 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 286 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2118 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 287 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2124 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 290 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2130 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 301 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_break(yyget_lineno()); }
#line 2136 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 304 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_continue(yyget_lineno()); }
#line 2142 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 307 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), nullptr); }
#line 2148 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 308 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), (yyvsp[-1].item_expr)); }
#line 2154 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 311 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), (yyvsp[-2].item_expr), (yyvsp[0].item_stmt), new compiler::Item_stmt_void(yyget_lineno())); }
#line 2160 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 312 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), (yyvsp[-4].item_expr), (yyvsp[-2].item_stmt), (yyvsp[0].item_stmt)); }
#line 2166 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 315 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_eval(yyget_lineno(), (yyvsp[-1].item_expr)); }
#line 2172 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 316 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_void(yyget_lineno()); }
#line 2178 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 319 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), (yyvsp[-2].item_expr), (yyvsp[0].item_stmt)); }
#line 2184 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 328 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = (yyvsp[-1].item_stmt); }
#line 2190 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 87:
#line 331 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr)); }
#line 2196 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 88:
#line 332 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::ADD_TYPE,
                                                    (yyvsp[-1].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-1].item_ident), expr);
                                      }
#line 2210 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 341 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::SUB_TYPE,
                                                    (yyvsp[-1].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-1].item_ident), expr);
                                      }
#line 2224 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 350 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[0].item_ident), compiler::binary_type::ADD_TYPE); }
#line 2230 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 351 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[0].item_ident), compiler::binary_type::SUB_TYPE); }
#line 2236 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 355 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident) = (yyvsp[0].item_ident); }
#line 2242 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 358 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-3].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr));}
#line 2248 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 359 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = (yyvsp[-3].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 2254 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 366 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr_comma) = new compiler::Item_expr_comma(yyget_lineno()); (yyval.item_expr_comma)->add_expression((yyvsp[-2].item_expr)); (yyval.item_expr_comma)->add_expression((yyvsp[0].item_expr)); }
#line 2260 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 367 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr_comma) = (yyvsp[-2].item_expr_comma); (yyval.item_expr_comma)->add_expression((yyvsp[0].item_expr)); }
#line 2266 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 370 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2272 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 371 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2278 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 375 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2284 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 379 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::EQ_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2290 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 380 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::NEQ_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2296 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 384 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::GE_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2302 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 385 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LE_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2308 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 386 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::G_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2314 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 387 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::L_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2320 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 395 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2326 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 396 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2332 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 400 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2338 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 401 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2344 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 405 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2350 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 121:
#line 406 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2356 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 410 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::ADD_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2362 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 411 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::SUB_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2368 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 415 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MUL_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2374 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 416 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::DIV_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2380 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 417 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MOD_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2386 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 130:
#line 421 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UADD_TYPE, (yyvsp[0].item_expr)); }
#line 2392 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 422 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UMINUS_TYPE, (yyvsp[0].item_expr)); }
#line 2398 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 423 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::LNOT_TYPE, (yyvsp[0].item_expr)); }
#line 2404 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 424 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::BITNEG_TYPE, (yyvsp[0].item_expr)); }
#line 2410 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 425 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UREF_TYPE, (yyvsp[0].item_expr)); }
#line 2416 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 426 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UDEREFER_TYPE, (yyvsp[0].item_expr)); }
#line 2422 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 431 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[-1].item_expr); }
#line 2428 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 432 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2434 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 433 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2440 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 434 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2446 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 142:
#line 437 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[0].raw_number)); }
#line 2452 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 438 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[0].raw_number)); }
#line 2458 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 439 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_real(yyget_lineno(), (yyvsp[0].raw_number)); }
#line 2464 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 440 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_char(yyget_lineno(), (yyvsp[0].raw_char)); }
#line 2470 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 441 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_string(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 2476 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 442 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 1); }
#line 2482 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 443 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 0); }
#line 2488 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 446 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[-2].item_ident), new compiler::Item_func_call_list(yyget_lineno())); }
#line 2494 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 447 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[-3].item_ident), (yyvsp[-1].item_func_call_list)); }
#line 2500 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 450 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_call_list) = (yyvsp[-2].item_func_call_list); (yyvsp[-2].item_func_call_list)->add_arg((yyvsp[0].item_expr)); }
#line 2506 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 451 "./src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_call_list) = new compiler::Item_func_call_list(yyget_lineno()); (yyval.item_func_call_list)->add_arg((yyvsp[0].item_expr)); }
#line 2512 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;


#line 2516 "./src/frontend/parser/parser.cc" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 453 "./src/frontend/parser/parser.ypp" /* yacc.c:1906  */
