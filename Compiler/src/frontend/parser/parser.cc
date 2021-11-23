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
#line 3 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:339  */

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

#line 129 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:339  */

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
#ifndef YY_YY_HOME_CHB_COMPILATION_COMPILER_COMPILER_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED
# define YY_YY_HOME_CHB_COMPILATION_COMPILER_COMPILER_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:355  */

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

#line 251 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:355  */
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

#endif /* !YY_YY_HOME_CHB_COMPILATION_COMPILER_COMPILER_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 282 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:358  */

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   813

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  301

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   149,   149,   150,   151,   152,   155,   156,   157,   160,
     163,   166,   169,   170,   171,   172,   173,   176,   177,   180,
     181,   182,   185,   186,   189,   190,   191,   194,   195,   196,
     197,   200,   201,   204,   205,   206,   207,   210,   211,   214,
     215,   218,   219,   220,   221,   224,   225,   228,   229,   232,
     233,   236,   239,   240,   241,   242,   245,   246,   249,   250,
     253,   254,   257,   262,   267,   268,   271,   274,   275,   280,
     281,   286,   292,   297,   305,   306,   309,   310,   313,   314,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   328,
     331,   334,   335,   338,   343,   349,   350,   353,   358,   364,
     373,   383,   392,   404,   407,   408,   417,   426,   427,   430,
     431,   434,   435,   438,   439,   442,   443,   446,   447,   448,
     451,   452,   455,   456,   457,   460,   461,   462,   463,   464,
     468,   471,   472,   473,   476,   477,   478,   481,   482,   483,
     486,   487,   488,   491,   492,   493,   494,   497,   498,   499,
     500,   501,   502,   503,   504,   507,   508,   509,   510,   513,
     514,   515,   524,   525,   526,   527,   530,   531,   534,   535
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
  "FunctionCall", "FunctionRParams", YY_NULLPTR
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
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -192

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-192)))

#define YYTABLE_NINF -17

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
#line 149 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_root)->add_child((yyvsp[0].item_decl)); }
#line 1779 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_root)->add_child((yyvsp[0].item_func_def)); }
#line 1785 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 151 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[0].item_decl)); }
#line 1791 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 152 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[0].item_func_def)); }
#line 1797 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = (yyvsp[-1].item_stmt_decl); }
#line 1803 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 163 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = (yyvsp[-1].item_stmt_decl); }
#line 1809 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 166 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = (yyvsp[-1].item_stmt_decl); }
#line 1815 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 169 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::INT_TYPE; }
#line 1821 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 170 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; }
#line 1827 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 171 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::REAL_TYPE; }
#line 1833 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 172 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::CHAR_TYPE; }
#line 1839 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 173 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.btype) = compiler::basic_type::STR_TYPE; }
#line 1845 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 176 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-1].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1851 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 177 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1857 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 180 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-1].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1863 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 181 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1869 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 182 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-2].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1875 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 185 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), compiler::basic_type::STRUCT); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1881 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 186 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1887 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[0].item_ident), nullptr, true); }
#line 1893 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 190 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[-2].item_ident), nullptr, true); }
#line 1899 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 191 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[-3].item_ident), (yyvsp[-1].item_struct_body), false);}
#line 1905 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_struct_body) = new compiler::Item_struct_body(yyget_lineno()); (yyval.item_struct_body)->add_body((yyvsp[0].item_stmt_decl)); }
#line 1911 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 195 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_struct_body) = (yyvsp[-1].item_struct_body); (yyval.item_struct_body)->add_body((yyvsp[0].item_stmt_decl)); }
#line 1917 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 196 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_struct_body) = new compiler::Item_struct_body(yyget_lineno()); (yyval.item_struct_body)->add_body((yyvsp[0].item_func_def)); }
#line 1923 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 197 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_struct_body) = (yyvsp[-1].item_struct_body); (yyval.item_struct_body)->add_body((yyvsp[0].item_func_def)); }
#line 1929 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 204 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr), false); }
#line 1935 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 205 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_var(yyget_lineno(), (yyvsp[0].item_ident)); }
#line 1941 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 206 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[-2].item_ident_pointer), (yyvsp[0].item_expr), false); }
#line 1947 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 207 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_pointer(yyget_lineno(), (yyvsp[0].item_ident_pointer)); }
#line 1953 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 210 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_pointer) = new compiler::Item_ident_pointer(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 1959 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 211 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_pointer) = (yyvsp[0].item_ident_pointer); (yyvsp[0].item_ident_pointer)->add_shape(); }
#line 1965 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 214 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[-2].item_ident_array), (yyvsp[0].item_literal_array_init), false); }
#line 1971 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 215 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_array(yyget_lineno(), (yyvsp[0].item_ident_array)); }
#line 1977 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 218 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = (yyvsp[-3].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 1983 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 219 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-3].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 1989 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 220 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-2].item_ident)->get_name()); (yyval.item_ident_array)->add_shape(nullptr); }
#line 1995 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 221 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = (yyvsp[-2].item_ident_array); (yyval.item_ident_array)->add_shape(nullptr); }
#line 2001 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 224 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal_array_init) = (yyvsp[-1].item_literal_array_init); }
#line 2007 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 225 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); }
#line 2013 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 232 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr), true); }
#line 2019 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 233 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[-2].item_ident_pointer), (yyvsp[0].item_expr), true); }
#line 2025 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[-2].item_ident_array), (yyvsp[0].item_literal_array_init), true); }
#line 2031 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 239 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[-5].btype), (yyvsp[-4].item_ident), (yyvsp[-2].item_func_def_list), (yyvsp[0].item_block)); }
#line 2037 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 240 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[-4].item_ident), (yyvsp[-2].item_func_def_list), (yyvsp[0].item_block)); }
#line 2043 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 241 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[-4].btype), (yyvsp[-3].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[0].item_block)); }
#line 2049 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 242 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[-3].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[0].item_block)); }
#line 2055 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 245 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_list)->add_arg((yyvsp[0].item_func_def_arg)); }
#line 2061 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 246 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_list) = new compiler::Item_func_def_list(yyget_lineno()); (yyval.item_func_def_list)->add_arg((yyvsp[0].item_func_def_arg)); }
#line 2067 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 253 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-1].btype), (yyvsp[0].item_ident)); }
#line 2073 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 254 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-1].btype), (yyvsp[0].item_ident)); }
#line 2079 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 257 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-2].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-3].btype), ident);
                                                        }
#line 2089 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 262 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-3].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-4].btype), ident);
                                                        }
#line 2099 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 267 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_arg) = (yyvsp[-2].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); }
#line 2105 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 268 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_def_arg) = (yyvsp[-3].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); }
#line 2111 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 271 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident) = new compiler::Item_ident(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 2117 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 274 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal_array_init) = (yyvsp[-2].item_literal_array_init); (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init)); }
#line 2123 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 275 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.item_literal_array_init) = (yyvsp[-2].item_literal_array_init);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[0].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                              }
#line 2133 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 280 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init)); }
#line 2139 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 281 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[0].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init); 
                                                              }
#line 2149 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 286 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[-2].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                                (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init));
                                                              }
#line 2160 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 292 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { 
                                                                 (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                                                                 compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[0].item_expr_comma), true);
                                                                 (yyval.item_literal_array_init)->add_value(array_init);
                                                              }
#line 2170 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 297 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                                                 (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                                                                 compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[-2].item_expr_comma), true);
                                                                 (yyval.item_literal_array_init)->add_value(array_init);
                                                                 (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init));
                                                              }
#line 2181 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 305 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); }
#line 2187 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 306 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_block) = (yyvsp[-1].item_block); }
#line 2193 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 309 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); (yyval.item_block)->add_item((yyvsp[0].item_stmt)); }
#line 2199 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 310 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_block) = (yyvsp[-1].item_block); (yyval.item_block)->add_item((yyvsp[0].item_stmt)); }
#line 2205 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 313 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2211 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 314 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2217 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 317 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2223 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 89:
#line 328 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_break(yyget_lineno()); }
#line 2229 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 331 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_continue(yyget_lineno()); }
#line 2235 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 91:
#line 334 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), nullptr); }
#line 2241 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 335 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), (yyvsp[-1].item_expr)); }
#line 2247 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 93:
#line 339 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
    compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[-2].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), condition, (yyvsp[0].item_stmt), new compiler::Item_stmt_void(yyget_lineno())); 
}
#line 2256 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 94:
#line 344 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[-4].item_expr));
  (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), condition, (yyvsp[-2].item_stmt), (yyvsp[0].item_stmt)); 
}
#line 2264 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 95:
#line 349 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_eval(yyget_lineno(), (yyvsp[-1].item_expr)); }
#line 2270 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 96:
#line 350 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_void(yyget_lineno()); }
#line 2276 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 97:
#line 354 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
    compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[-2].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[0].item_stmt)); 
}
#line 2285 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 359 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {   compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[-2].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[-5].item_block), true); 
}
#line 2293 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 365 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
             compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
             block->add_item((yyvsp[-3].item_stmt));
             compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[-2].item_stmt)));
             compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[0].item_block));
             block->add_item(while_stmt);
             (yyval.item_stmt) = block;
         }
#line 2306 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 374 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[-4].item_stmt));
           (yyvsp[0].item_block)->add_item(static_cast<compiler::Item_stmt*>((yyvsp[-2].item_expr)));
           compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[-3].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(),condition, (yyvsp[0].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       }
#line 2320 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 384 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[-3].item_stmt_decl));
            compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[-2].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[0].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       }
#line 2333 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 393 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[-4].item_stmt_decl));
           (yyvsp[0].item_block)->add_item(static_cast<compiler::Item_stmt*>((yyvsp[-2].item_expr)));
        compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[-3].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(),condition, (yyvsp[0].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       }
#line 2347 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 103:
#line 404 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = (yyvsp[-1].item_stmt); }
#line 2353 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 104:
#line 407 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr)); }
#line 2359 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 408 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::ADD_TYPE,
                                                    (yyvsp[-1].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-1].item_ident), expr);
                                      }
#line 2373 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 106:
#line 417 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::SUB_TYPE,
                                                    (yyvsp[-1].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-1].item_ident), expr);
                                      }
#line 2387 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 107:
#line 426 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[0].item_ident), compiler::binary_type::ADD_TYPE); }
#line 2393 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 108:
#line 427 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[0].item_ident), compiler::binary_type::SUB_TYPE); }
#line 2399 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 110:
#line 431 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident) = (yyvsp[0].item_ident); }
#line 2405 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 434 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-3].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr));}
#line 2411 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 112:
#line 435 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_ident_array) = (yyvsp[-3].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 2417 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 114:
#line 439 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2423 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 115:
#line 442 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr_comma) = new compiler::Item_expr_comma(yyget_lineno()); (yyval.item_expr_comma)->add_expression((yyvsp[-2].item_expr)); (yyval.item_expr_comma)->add_expression((yyvsp[0].item_expr)); }
#line 2429 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 116:
#line 443 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr_comma) = (yyvsp[-2].item_expr_comma); (yyval.item_expr_comma)->add_expression((yyvsp[0].item_expr)); }
#line 2435 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 446 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2441 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 447 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2447 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 120:
#line 451 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2453 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 455 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::EQ_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2459 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 456 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::NEQ_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2465 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 460 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::GE_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2471 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 126:
#line 461 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LE_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2477 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 127:
#line 462 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::G_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2483 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 128:
#line 463 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::L_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2489 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 131:
#line 471 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2495 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 472 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2501 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 134:
#line 476 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2507 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 135:
#line 477 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2513 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 481 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2519 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 138:
#line 482 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2525 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 140:
#line 486 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::ADD_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2531 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 141:
#line 487 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::SUB_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2537 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 491 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MUL_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2543 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 492 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::DIV_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2549 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 493 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MOD_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2555 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 147:
#line 497 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UADD_TYPE, (yyvsp[0].item_expr)); }
#line 2561 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 148:
#line 498 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UMINUS_TYPE, (yyvsp[0].item_expr)); }
#line 2567 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 499 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::LNOT_TYPE, (yyvsp[0].item_expr)); }
#line 2573 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 500 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::BITNEG_TYPE, (yyvsp[0].item_expr)); }
#line 2579 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 501 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UREF_TYPE, (yyvsp[0].item_expr)); }
#line 2585 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 502 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UDEREFER_TYPE, (yyvsp[0].item_expr)); }
#line 2591 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 507 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[-1].item_expr); }
#line 2597 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 508 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2603 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 157:
#line 509 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2609 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 158:
#line 510 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2615 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 513 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[0].raw_number)); }
#line 2621 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 514 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), (yyvsp[0].raw_number)); }
#line 2627 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 161:
#line 516 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { 
          if (((yyvsp[0].raw_string))->find(".") != std::string::npos) {
            (yyval.item_literal) = new compiler::Item_literal_real(yyget_lineno(), std::stod(*(yyvsp[0].raw_string))); 
          } else {
            (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), std::stoi(*(yyvsp[0].raw_string))); 
          }
          
        }
#line 2640 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 162:
#line 524 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_char(yyget_lineno(), (yyvsp[0].raw_char)); }
#line 2646 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 525 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_string(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 2652 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 526 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 1); }
#line 2658 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 527 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 0); }
#line 2664 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 530 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[-2].item_ident), new compiler::Item_func_call_list(yyget_lineno())); }
#line 2670 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 531 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[-3].item_ident), (yyvsp[-1].item_func_call_list)); }
#line 2676 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 534 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_call_list) = (yyvsp[-2].item_func_call_list); (yyvsp[-2].item_func_call_list)->add_arg((yyvsp[0].item_expr)); }
#line 2682 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;

  case 169:
#line 535 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1646  */
    { (yyval.item_func_call_list) = new compiler::Item_func_call_list(yyget_lineno()); (yyval.item_func_call_list)->add_arg((yyvsp[0].item_expr)); }
#line 2688 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
    break;


#line 2692 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.cc" /* yacc.c:1646  */
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
#line 537 "/home/chb/compilation/compiler/Compiler/src/frontend/parser/parser.ypp" /* yacc.c:1906  */
