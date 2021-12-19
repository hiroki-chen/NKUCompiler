/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"

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

#line 132 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HOME_DARREN_COMPILER_COMPILER_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED
# define YY_YY_HOME_DARREN_COMPILER_COMPILER_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED
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
#line 65 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"

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
    char                                raw_char;

#line 265 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"

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

#endif /* !YY_YY_HOME_DARREN_COMPILER_COMPILER_SRC_FRONTEND_PARSER_PARSER_HH_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   793

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  301

#define YYUNDEFTOK  2
#define YYMAXUTOK   309


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,   146,   146,   147,   148,   149,   152,   153,   154,   157,
     160,   163,   166,   167,   168,   169,   170,   173,   174,   177,
     178,   179,   182,   183,   186,   187,   188,   191,   192,   193,
     194,   197,   198,   201,   202,   203,   204,   207,   208,   211,
     212,   215,   216,   217,   218,   221,   222,   225,   226,   229,
     230,   233,   236,   237,   238,   239,   242,   243,   246,   247,
     250,   251,   254,   259,   264,   265,   268,   271,   272,   277,
     278,   283,   289,   297,   308,   309,   312,   313,   316,   317,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   331,
     334,   337,   338,   341,   346,   352,   353,   356,   361,   367,
     376,   386,   395,   407,   410,   411,   420,   429,   430,   433,
     434,   437,   438,   441,   442,   445,   446,   449,   450,   451,
     454,   455,   458,   459,   460,   463,   464,   465,   466,   467,
     471,   474,   475,   476,   479,   480,   481,   484,   485,   486,
     489,   490,   491,   494,   495,   496,   497,   500,   501,   502,
     503,   504,   505,   506,   507,   510,   511,   512,   513,   516,
     517,   518,   527,   528,   529,   530,   533,   534,   537,   538
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
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF (-208)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     735,  -208,  -208,  -208,  -208,  -208,     8,     8,   194,   178,
    -208,  -208,  -208,  -208,    15,   101,   138,   139,  -208,  -208,
      -9,  -208,     7,    72,  -208,  -208,  -208,   133,    72,  -208,
    -208,    38,  -208,   -28,   136,  -208,    72,  -208,    72,  -208,
       8,   185,   707,    52,     2,  -208,  -208,  -208,    34,  -208,
    -208,  -208,   702,    64,   137,   702,   391,   463,  -208,    50,
    -208,  -208,   194,    68,     8,    12,  -208,  -208,    70,  -208,
    -208,   728,  -208,   702,    64,   702,   702,   702,   702,     8,
       8,   702,   702,   702,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,   702,    77,  -208,     4,    88,   134,   219,   149,   772,
    -208,   158,    85,   181,   241,   144,  -208,  -208,  -208,  -208,
     640,  -208,  -208,   129,   148,     6,   134,    68,    62,  -208,
     132,     8,   233,  -208,   180,    68,   751,   492,  -208,  -208,
    -208,   134,  -208,   134,  -208,  -208,  -208,  -208,   199,   199,
    -208,  -208,  -208,   169,   550,  -208,  -208,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   702,
    -208,  -208,    47,   198,    29,  -208,   702,   702,  -208,    68,
    -208,  -208,    17,    23,   217,    68,   220,   228,    82,   135,
     232,  -208,  -208,  -208,    15,  -208,   283,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,  -208,  -208,   238,   239,   521,
    -208,  -208,  -208,   250,  -208,  -208,  -208,    63,  -208,   251,
     253,   284,  -208,   284,  -208,   156,   156,  -208,  -208,  -208,
    -208,   296,   296,   301,  -208,   301,   144,   144,  -208,  -208,
    -208,  -208,   672,   672,   672,   134,   134,  -208,   702,   289,
     702,   383,  -208,   280,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,   282,  -208,  -208,   702,  -208,  -208,  -208,   134,  -208,
    -208,   285,   292,   295,   433,   433,  -208,  -208,  -208,   333,
     702,   333,   580,   610,   306,   297,  -208,    68,   298,    68,
     299,   333,   293,  -208,    68,  -208,    68,  -208,  -208,  -208,
    -208
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
     165,     0,   109,   158,   156,   110,    35,   119,   139,   124,
     121,   130,   133,   136,   129,   142,   146,   154,   157,   153,
       0,    39,    44,     0,   114,   113,    33,     0,     0,    43,
       0,     0,     0,    55,    60,     0,     0,     0,    26,    28,
      30,    50,    51,    49,   147,   148,   152,   109,   107,   108,
     151,   150,   149,     0,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    69,     0,    72,    70,    41,     0,     0,    54,     0,
      42,    61,   163,   162,     0,     0,     0,     0,     0,     0,
       0,    74,    96,    78,     0,    80,     0,    76,    79,    85,
      86,    84,    83,    88,    81,    82,    87,   158,     0,     0,
      53,    56,    64,     0,   155,   166,   169,     0,   104,     0,
       0,   118,   120,   117,   137,   122,   123,   125,   126,   127,
     128,   132,   131,   135,   138,   134,   140,   141,   143,   144,
     145,    45,     0,     0,     0,   116,   115,    52,     0,     0,
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
    -208,  -208,     0,  -208,  -208,  -208,    -7,  -208,  -208,  -208,
     309,  -208,   315,  -208,   121,  -208,    35,   -69,    41,  -208,
    -208,     1,   305,   226,  -208,  -208,    10,  -208,   -61,  -208,
     159,  -146,  -208,  -208,  -208,  -208,  -207,  -208,  -208,  -208,
    -114,   168,  -208,   -51,   244,   -48,    51,   -83,   140,  -132,
    -208,    94,    55,  -208,   117,   -46,  -208,  -208,  -208,  -208
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,   193,    11,    12,    13,    14,    15,    16,    17,
      21,    71,    29,    30,    31,    32,    33,   111,    45,    46,
      47,    18,    65,    66,    67,    68,    92,   172,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
      93,    94,    95,   208,   114,   115,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   217
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    23,   123,   113,    96,   132,   120,   116,   207,    25,
      26,    19,   216,   145,   146,    53,    20,    22,    19,   222,
     -16,    27,    54,   -16,    34,   131,   -15,   133,   150,   -15,
     134,   135,   136,    48,    64,   140,   141,   142,    48,    41,
     143,   171,    70,    72,   275,    74,    59,   147,    48,    64,
      22,   150,    54,    42,   148,   121,   178,    28,    44,   -16,
     177,   125,   174,    44,   210,   -15,   126,   282,   283,    51,
     224,   129,   130,    44,   124,    19,   213,    75,    27,    60,
     234,    52,   207,   244,    57,    19,    76,    77,    78,   137,
     137,    79,    80,    55,   241,    73,   218,   219,   220,    81,
      57,   242,    82,   161,   162,    83,    84,    85,    86,    87,
     110,   179,   263,    88,   122,   194,   126,   264,   247,    64,
     127,   238,   239,   240,   249,   144,    89,    90,   245,   246,
      91,   181,   278,   284,   252,   286,    49,   253,   149,    27,
      19,    76,    77,    78,    43,   297,    79,    80,    50,    43,
     167,   168,   169,    35,    81,    36,   150,    82,   261,    43,
      83,    84,    85,    86,    87,   207,   153,   207,    88,   156,
     157,   158,   159,   267,   269,   270,   160,   207,    24,    55,
     175,    89,    90,   180,    56,    91,    57,   254,   112,   194,
      37,    39,    38,    40,   268,   245,   246,   271,   163,   273,
     164,   221,   176,   223,    59,     1,     2,     3,     4,     5,
       6,     7,     1,     2,     3,     4,     5,   233,   214,   235,
       8,     1,     2,     3,     4,     5,   293,    62,   295,   285,
     209,   288,   290,   299,    63,   300,    19,    76,    77,    78,
     151,   152,    79,    80,   194,   165,   166,   138,   139,   148,
      81,   274,   243,    82,   231,   232,    83,    84,    85,    86,
     182,     2,     3,     4,   183,   248,     7,   184,   250,   185,
     186,   187,   188,   189,   190,     8,   251,    89,    90,   122,
     191,    91,   236,   237,   255,   192,    19,    76,    77,    78,
     258,   259,    79,    80,   225,   226,   227,   228,   229,   230,
      81,   262,   265,    82,   266,   151,    83,    84,    85,    86,
     182,     2,     3,     4,   183,   162,     7,   184,   163,   185,
     186,   187,   188,   189,   190,     8,   272,    89,    90,   122,
     256,    91,   276,   277,   279,   192,    19,    76,    77,    78,
     280,   291,    79,    80,   281,   298,   292,   294,   296,    61,
      81,    58,   211,    82,   173,   257,    83,    84,    85,    86,
      87,   118,     0,     0,    88,     0,     0,   184,     0,   185,
     186,   187,   188,   189,   190,     0,     0,    89,    90,   122,
       0,    91,     0,     0,     0,   192,    19,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,     0,     0,     0,
      81,     0,     0,    82,     0,     0,    83,    84,    85,    86,
     182,     2,     3,     4,   183,     0,     7,     0,     1,     2,
       3,     4,     5,     0,     0,     8,     0,    89,    90,     0,
       0,    91,     0,    62,     0,   192,    19,    76,    77,    78,
     117,     0,    79,    80,     0,     0,     0,     0,     0,     0,
      81,     0,     0,    82,     0,     0,    83,    84,    85,    86,
      87,     0,     0,     0,    88,     0,    19,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    89,    90,     0,
      81,    91,     0,    82,     0,   192,    83,    84,    85,    86,
      87,     0,     0,     0,    88,    19,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,     0,    89,    90,    81,
       0,    91,    82,     0,   119,    83,    84,    85,    86,    87,
       0,     0,     0,    88,    19,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,     0,    89,    90,    81,     0,
      91,    82,     0,   212,    83,    84,    85,    86,    87,     0,
       0,     0,    88,    19,    76,    77,    78,     0,     0,    79,
      80,     0,     0,     0,     0,    89,    90,    81,     0,    91,
      82,     0,   260,    83,    84,    85,    86,    87,     0,     0,
       0,    88,     0,    19,    76,    77,    78,     0,     0,    79,
      80,     0,     0,     0,    89,    90,     0,    81,    91,   215,
      82,     0,     0,    83,    84,    85,    86,    87,     0,     0,
       0,    88,     0,    19,    76,    77,    78,     0,     0,    79,
      80,     0,     0,     0,    89,    90,     0,    81,    91,   287,
      82,     0,     0,    83,    84,    85,    86,    87,     0,     0,
       0,    88,     0,    19,    76,    77,    78,     0,     0,    79,
      80,     0,     0,     0,    89,    90,     0,    81,    91,   289,
      82,     0,     0,    83,    84,    85,    86,    87,     0,     0,
       0,    88,     0,     0,     0,    19,    76,    77,    78,     0,
       0,    79,    80,     0,    89,    90,   110,   170,    91,    81,
       0,     0,    82,     0,     0,    83,    84,    85,    86,    87,
       0,     0,     0,    88,     0,    19,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    89,    90,   110,    81,
      91,     0,    82,     0,     0,    83,    84,    85,    86,    87,
       0,     0,     0,    88,     1,     2,     3,     4,     5,     6,
       7,     0,     0,     0,     0,     0,    89,    90,     0,     8,
      91,     0,     0,     0,    69,     1,     2,     3,     4,     5,
       6,     7,     1,     2,     3,     4,     5,     6,     7,     0,
       8,     0,     0,     0,     0,   128,     0,     8,     1,     2,
       3,     4,     5,   154,   155,   156,   157,   158,   159,     0,
       0,     0,     0,    62
};

static const yytype_int16 yycheck[] =
{
       0,     8,    63,    54,    52,    74,    57,    55,   122,     9,
       9,     3,   144,     9,    10,    43,     6,     7,     3,   151,
       3,     6,    50,     6,    14,    73,     3,    75,    22,     6,
      76,    77,    78,    23,    41,    81,    82,    83,    28,    48,
      91,   110,    42,    42,   251,    43,    36,    43,    38,    56,
      40,    22,    50,    46,    50,    62,   117,    42,    23,    42,
      54,    49,   110,    28,   125,    42,    54,   274,   275,    28,
     153,    71,    71,    38,    64,     3,   127,    43,     6,    38,
     163,    43,   196,    54,    50,     3,     4,     5,     6,    79,
      80,     9,    10,    43,    47,    43,   147,   148,   149,    17,
      50,    54,    20,    18,    19,    23,    24,    25,    26,    27,
      46,    49,    49,    31,    46,   122,    54,    54,   179,   126,
      50,   167,   168,   169,   185,    48,    44,    45,   176,   177,
      48,   121,   264,   279,    52,   281,     3,   188,    50,     6,
       3,     4,     5,     6,    23,   291,     9,    10,    27,    28,
       6,     7,     8,    52,    17,    54,    22,    20,   209,    38,
      23,    24,    25,    26,    27,   279,    17,   281,    31,    13,
      14,    15,    16,   242,   243,   244,    18,   291,     0,    43,
      51,    44,    45,    51,    48,    48,    50,    52,    51,   196,
      52,    52,    54,    54,   242,   243,   244,   248,    17,   250,
      19,   150,    54,   152,   194,    27,    28,    29,    30,    31,
      32,    33,    27,    28,    29,    30,    31,   162,    49,   164,
      42,    27,    28,    29,    30,    31,   287,    42,   289,   280,
      50,   282,   283,   294,    49,   296,     3,     4,     5,     6,
      21,    22,     9,    10,   251,     4,     5,    79,    80,    50,
      17,   251,    54,    20,   160,   161,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    48,    33,    34,    48,    36,
      37,    38,    39,    40,    41,    42,    48,    44,    45,    46,
      47,    48,   165,   166,    52,    52,     3,     4,     5,     6,
      52,    52,     9,    10,   154,   155,   156,   157,   158,   159,
      17,    51,    51,    20,    51,    21,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    19,    33,    34,    17,    36,
      37,    38,    39,    40,    41,    42,    37,    44,    45,    46,
      47,    48,    52,    51,    49,    52,     3,     4,     5,     6,
      48,    35,     9,    10,    49,    52,    49,    49,    49,    40,
      17,    36,   126,    20,   110,   196,    23,    24,    25,    26,
      27,    56,    -1,    -1,    31,    -1,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    48,    -1,    -1,    -1,    52,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    42,    -1,    44,    45,    -1,
      -1,    48,    -1,    42,    -1,    52,     3,     4,     5,     6,
      49,    -1,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    -1,    -1,    -1,    44,    45,    -1,
      17,    48,    -1,    20,    -1,    52,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,     3,     4,     5,     6,    -1,
      -1,     9,    10,    -1,    -1,    -1,    -1,    44,    45,    17,
      -1,    48,    20,    -1,    51,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,     3,     4,     5,     6,    -1,    -1,
       9,    10,    -1,    -1,    -1,    -1,    44,    45,    17,    -1,
      48,    20,    -1,    51,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    31,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    -1,    44,    45,    17,    -1,    48,
      20,    -1,    51,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    44,    45,    -1,    17,    48,    49,
      20,    -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    44,    45,    -1,    17,    48,    49,
      20,    -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    -1,    44,    45,    -1,    17,    48,    49,
      20,    -1,    -1,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    10,    -1,    44,    45,    46,    47,    48,    17,
      -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    10,    -1,    -1,    -1,    44,    45,    46,    17,
      48,    -1,    20,    -1,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    42,
      48,    -1,    -1,    -1,    47,    27,    28,    29,    30,    31,
      32,    33,    27,    28,    29,    30,    31,    32,    33,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    42,    27,    28,
      29,    30,    31,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
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
      45,    48,    81,    95,    96,    97,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      46,    72,    51,    98,    99,   100,   100,    49,    77,    51,
      98,    61,    46,    83,    81,    49,    54,    50,    47,    57,
      76,   100,    72,   100,   110,   110,   110,    81,    96,    96,
     110,   110,   110,    98,    48,     9,    10,    43,    50,    50,
      22,    21,    22,    17,    11,    12,    13,    14,    15,    16,
      18,    18,    19,    17,    19,     4,     5,     6,     7,     8,
      47,    72,    82,    99,   100,    51,    54,    54,    83,    49,
      51,    81,    27,    31,    34,    36,    37,    38,    39,    40,
      41,    47,    52,    57,    61,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    98,    50,
      83,    78,    51,    98,    49,    49,   104,   114,    98,    98,
      98,   101,   104,   101,   102,   103,   103,   103,   103,   103,
     103,   106,   106,   107,   102,   107,   109,   109,   110,   110,
     110,    47,    54,    54,    54,   100,   100,    83,    48,    83,
      48,    48,    52,    98,    52,    52,    47,    85,    52,    52,
      51,    98,    51,    49,    54,    51,    51,    72,   100,    72,
      72,    98,    37,    98,    57,    91,    52,    51,   104,    49,
      48,    49,    91,    91,    86,    98,    86,    49,    98,    49,
      98,    35,    49,    83,    49,    83,    49,    86,    52,    83,
      83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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
static const yytype_int8 yyr2[] =
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

#define YYBACKUP(Token, Value)                                    \
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

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

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 146 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.item_root)->add_child((yyvsp[0].item_decl)); }
#line 1872 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 3:
#line 147 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.item_root)->add_child((yyvsp[0].item_func_def)); }
#line 1878 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 4:
#line 148 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[0].item_decl)); }
#line 1884 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 5:
#line 149 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.item_root) = new compiler::Item_root(yyget_lineno()); compiler_runtime->set_root((yyval.item_root)); (yyval.item_root)->add_child((yyvsp[0].item_func_def)); }
#line 1890 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 9:
#line 157 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                     { (yyval.item_stmt_decl) = (yyvsp[-1].item_stmt_decl); }
#line 1896 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 10:
#line 160 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                               { (yyval.item_stmt_decl) = (yyvsp[-1].item_stmt_decl); }
#line 1902 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 11:
#line 163 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                   { (yyval.item_stmt_decl) = (yyvsp[-1].item_stmt_decl); }
#line 1908 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 12:
#line 166 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.btype) = compiler::basic_type::INT_TYPE; }
#line 1914 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 13:
#line 167 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.btype) = compiler::basic_type::REAL_TYPE; }
#line 1920 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 14:
#line 168 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.btype) = compiler::basic_type::REAL_TYPE; }
#line 1926 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 15:
#line 169 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.btype) = compiler::basic_type::CHAR_TYPE; }
#line 1932 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 16:
#line 170 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                { (yyval.btype) = compiler::basic_type::STR_TYPE; }
#line 1938 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 17:
#line 173 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                    { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-1].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1944 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 18:
#line 174 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                    { (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1950 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 19:
#line 177 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                     { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-1].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1956 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 20:
#line 178 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                     { (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1962 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 21:
#line 179 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                     { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), (yyvsp[-2].btype)); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1968 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 22:
#line 182 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                       { (yyval.item_stmt_decl) = new compiler::Item_stmt_decl(yyget_lineno(), compiler::basic_type::STRUCT); (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1974 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 23:
#line 183 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                       { (yyval.item_stmt_decl)->add_declaration((yyvsp[0].item_decl)); }
#line 1980 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 24:
#line 186 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                       { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[0].item_ident), nullptr, true); }
#line 1986 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 25:
#line 187 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                       { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[-2].item_ident), nullptr, true); }
#line 1992 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 26:
#line 188 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                       { (yyval.item_decl) = new compiler::Item_decl_struct(yyget_lineno(), (yyvsp[-3].item_ident), (yyvsp[-1].item_struct_body), false);}
#line 1998 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 27:
#line 191 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_struct_body) = new compiler::Item_struct_body(yyget_lineno()); (yyval.item_struct_body)->add_body((yyvsp[0].item_stmt_decl)); }
#line 2004 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 28:
#line 192 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_struct_body) = (yyvsp[-1].item_struct_body); (yyval.item_struct_body)->add_body((yyvsp[0].item_stmt_decl)); }
#line 2010 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 29:
#line 193 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_struct_body) = new compiler::Item_struct_body(yyget_lineno()); (yyval.item_struct_body)->add_body((yyvsp[0].item_func_def)); }
#line 2016 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 30:
#line 194 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_struct_body) = (yyvsp[-1].item_struct_body); (yyval.item_struct_body)->add_body((yyvsp[0].item_func_def)); }
#line 2022 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 33:
#line 201 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr), false); }
#line 2028 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 34:
#line 202 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                           { (yyval.item_decl) = new compiler::Item_decl_var(yyget_lineno(), (yyvsp[0].item_ident)); }
#line 2034 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 35:
#line 203 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[-2].item_ident_pointer), (yyvsp[0].item_expr), false); }
#line 2040 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 36:
#line 204 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                           { (yyval.item_decl) = new compiler::Item_decl_pointer(yyget_lineno(), (yyvsp[0].item_ident_pointer)); }
#line 2046 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 37:
#line 207 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                         { (yyval.item_ident_pointer) = new compiler::Item_ident_pointer(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 2052 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 38:
#line 208 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                         { (yyval.item_ident_pointer) = (yyvsp[0].item_ident_pointer); (yyvsp[0].item_ident_pointer)->add_shape(); }
#line 2058 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 39:
#line 211 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                            { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[-2].item_ident_array), (yyvsp[0].item_literal_array_init), false); }
#line 2064 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 40:
#line 212 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                            { (yyval.item_decl) = new compiler::Item_decl_array(yyget_lineno(), (yyvsp[0].item_ident_array)); }
#line 2070 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 41:
#line 215 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                            { (yyval.item_ident_array) = (yyvsp[-3].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 2076 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 42:
#line 216 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                            { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-3].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 2082 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 43:
#line 217 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                            { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-2].item_ident)->get_name()); (yyval.item_ident_array)->add_shape(nullptr); }
#line 2088 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 44:
#line 218 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                            { (yyval.item_ident_array) = (yyvsp[-2].item_ident_array); (yyval.item_ident_array)->add_shape(nullptr); }
#line 2094 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 45:
#line 221 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                           { (yyval.item_literal_array_init) = (yyvsp[-1].item_literal_array_init); }
#line 2100 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 46:
#line 222 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                           { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); }
#line 2106 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 49:
#line 229 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_decl) = new compiler::Item_decl_var_init(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr), true); }
#line 2112 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 50:
#line 230 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_decl) = new compiler::Item_decl_pointer_init(yyget_lineno(), (yyvsp[-2].item_ident_pointer), (yyvsp[0].item_expr), true); }
#line 2118 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 51:
#line 233 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                { (yyval.item_decl) = new compiler::Item_decl_array_init(yyget_lineno(), (yyvsp[-2].item_ident_array), (yyvsp[0].item_literal_array_init), true); }
#line 2124 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 52:
#line 236 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                                    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[-5].btype), (yyvsp[-4].item_ident), (yyvsp[-2].item_func_def_list), (yyvsp[0].item_block)); }
#line 2130 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 53:
#line 237 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                                    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[-4].item_ident), (yyvsp[-2].item_func_def_list), (yyvsp[0].item_block)); }
#line 2136 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 54:
#line 238 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                                    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), (yyvsp[-4].btype), (yyvsp[-3].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[0].item_block)); }
#line 2142 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 55:
#line 239 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                                    { (yyval.item_func_def) = new compiler::Item_func_def(yyget_lineno(), compiler::basic_type::VOID_TYPE, (yyvsp[-3].item_ident), new compiler::Item_func_def_list(yyget_lineno()), (yyvsp[0].item_block)); }
#line 2148 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 56:
#line 242 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                { (yyval.item_func_def_list)->add_arg((yyvsp[0].item_func_def_arg)); }
#line 2154 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 57:
#line 243 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                { (yyval.item_func_def_list) = new compiler::Item_func_def_list(yyget_lineno()); (yyval.item_func_def_list)->add_arg((yyvsp[0].item_func_def_arg)); }
#line 2160 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 60:
#line 250 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                   { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-1].btype), (yyvsp[0].item_ident)); }
#line 2166 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 61:
#line 251 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                   { (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-1].btype), (yyvsp[0].item_ident)); }
#line 2172 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 62:
#line 254 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                           {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-2].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-3].btype), ident);
                                                        }
#line 2182 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 63:
#line 259 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                               {
                                                            compiler::Item_ident_array* ident = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-3].item_ident)->get_name());
                                                            ident->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1));
                                                            (yyval.item_func_def_arg) = new compiler::Item_func_def_arg(yyget_lineno(), (yyvsp[-4].btype), ident);
                                                        }
#line 2192 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 64:
#line 264 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                        { (yyval.item_func_def_arg) = (yyvsp[-2].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); }
#line 2198 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 65:
#line 265 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                            { (yyval.item_func_def_arg) = (yyvsp[-3].item_func_def_arg); static_cast<compiler::Item_ident_array*>((yyval.item_func_def_arg)->get_identifier())->add_shape(new compiler::Item_literal_int(yyget_lineno(), 1)); }
#line 2204 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 66:
#line 268 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                { (yyval.item_ident) = new compiler::Item_ident(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 2210 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 67:
#line 271 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                              { (yyval.item_literal_array_init) = (yyvsp[-2].item_literal_array_init); (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init)); }
#line 2216 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 68:
#line 272 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                                 {
                                                                (yyval.item_literal_array_init) = (yyvsp[-2].item_literal_array_init);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[0].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                              }
#line 2226 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 69:
#line 277 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                              { (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init)); }
#line 2232 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 70:
#line 278 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                              {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[0].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init); 
                                                              }
#line 2242 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 71:
#line 283 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                              {
                                                                (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                                                                compiler::Item_literal_array_init* const array_init = new compiler::Item_literal_array_init(yyget_lineno(), (yyvsp[-2].item_expr), true);
                                                                (yyval.item_literal_array_init)->add_value(array_init);
                                                                (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init));
                                                              }
#line 2253 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 72:
#line 290 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                  { 
                    (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false);
                    for (auto expr : (yyvsp[0].item_expr_comma)->get_expressions()) {
                        (yyval.item_literal_array_init)->add_value(new compiler::Item_literal_array_init(yyget_lineno(), expr, true));
                    }
                    delete (yyvsp[0].item_expr_comma);                                                
                  }
#line 2265 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 73:
#line 298 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                  {
                    (yyval.item_literal_array_init) = new compiler::Item_literal_array_init(yyget_lineno(), nullptr, false); 
                    for (auto expr : (yyvsp[-2].item_expr_comma)->get_expressions()) {
                        (yyval.item_literal_array_init)->add_value(new compiler::Item_literal_array_init(yyget_lineno(), expr, true));
                    }
                    (yyval.item_literal_array_init)->add_value((yyvsp[0].item_literal_array_init));
                    delete (yyvsp[-2].item_expr_comma);
                  }
#line 2278 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 74:
#line 308 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); }
#line 2284 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 75:
#line 309 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_block) = (yyvsp[-1].item_block); }
#line 2290 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 76:
#line 312 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_block) = new compiler::Item_block(yyget_lineno()); (yyval.item_block)->add_item((yyvsp[0].item_stmt)); }
#line 2296 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 77:
#line 313 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_block) = (yyvsp[-1].item_block); (yyval.item_block)->add_item((yyvsp[0].item_stmt)); }
#line 2302 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 78:
#line 316 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2308 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 79:
#line 317 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2314 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 80:
#line 320 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_stmt) = (yyvsp[0].item_stmt); }
#line 2320 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 89:
#line 331 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                            { (yyval.item_stmt) = new compiler::Item_stmt_break(yyget_lineno()); }
#line 2326 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 90:
#line 334 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_stmt) = new compiler::Item_stmt_continue(yyget_lineno()); }
#line 2332 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 91:
#line 337 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), nullptr); }
#line 2338 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 92:
#line 338 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                        { (yyval.item_stmt) = new compiler::Item_stmt_return(yyget_lineno(), (yyvsp[-1].item_expr)); }
#line 2344 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 93:
#line 342 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
{
    compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[-2].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), condition, (yyvsp[0].item_stmt), new compiler::Item_stmt_void(yyget_lineno())); 
}
#line 2353 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 94:
#line 347 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
{ compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[-4].item_expr));
  (yyval.item_stmt) = new compiler::Item_stmt_eif(yyget_lineno(), condition, (yyvsp[-2].item_stmt), (yyvsp[0].item_stmt)); 
}
#line 2361 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 95:
#line 352 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                            { (yyval.item_stmt) = new compiler::Item_stmt_eval(yyget_lineno(), (yyvsp[-1].item_expr)); }
#line 2367 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 96:
#line 353 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                            { (yyval.item_stmt) = new compiler::Item_stmt_void(yyget_lineno()); }
#line 2373 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 97:
#line 357 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
{
    compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[-2].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[0].item_stmt)); 
}
#line 2382 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 98:
#line 362 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
{   compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), (yyvsp[-2].item_expr));
    (yyval.item_stmt) = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[-5].item_block), true); 
}
#line 2390 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 99:
#line 368 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
         {
             compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
             block->add_item((yyvsp[-3].item_stmt));
             compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[-2].item_stmt)));
             compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[0].item_block));
             block->add_item(while_stmt);
             (yyval.item_stmt) = block;
         }
#line 2403 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 100:
#line 377 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
       {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[-4].item_stmt));
           (yyvsp[0].item_block)->add_item(static_cast<compiler::Item_stmt*>((yyvsp[-2].item_expr)));
           compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[-3].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(),condition, (yyvsp[0].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       }
#line 2417 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 101:
#line 387 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
       {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[-3].item_stmt_decl));
            compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[-2].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(), condition, (yyvsp[0].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       }
#line 2430 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 102:
#line 396 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
       {
           compiler::Item_block* const block = new compiler::Item_block(yyget_lineno());
           block->add_item((yyvsp[-4].item_stmt_decl));
           (yyvsp[0].item_block)->add_item(static_cast<compiler::Item_stmt*>((yyvsp[-2].item_expr)));
        compiler::Item_expr_cond* const condition = new compiler::Item_expr_cond(yyget_lineno(), static_cast<compiler::Item_expr*>((yyvsp[-3].item_stmt)));
           compiler::Item_stmt_while* const while_stmt = new compiler::Item_stmt_while(yyget_lineno(),condition, (yyvsp[0].item_block));
           block->add_item(while_stmt);
           (yyval.item_stmt) = block;
       }
#line 2444 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 103:
#line 407 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                    { (yyval.item_stmt) = (yyvsp[-1].item_stmt); }
#line 2450 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 104:
#line 410 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                      { (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-2].item_ident), (yyvsp[0].item_expr)); }
#line 2456 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 105:
#line 411 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                      {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::ADD_TYPE,
                                                    (yyvsp[-1].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-1].item_ident), expr);
                                      }
#line 2470 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 106:
#line 420 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                      {
                                            compiler::Item_expr_binary* const expr = 
                                                new compiler::Item_expr_binary(
                                                    yyget_lineno(),
                                                    compiler::binary_type::SUB_TYPE,
                                                    (yyvsp[-1].item_ident),
                                                    new compiler::Item_literal_int(yyget_lineno(), 1));
                                            (yyval.item_stmt) = new compiler::Item_stmt_assign(yyget_lineno(), (yyvsp[-1].item_ident), expr);
                                      }
#line 2484 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 107:
#line 429 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                      { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[0].item_ident), compiler::binary_type::ADD_TYPE); }
#line 2490 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 108:
#line 430 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                      { (yyval.item_stmt) = new compiler::Item_stmt_postfix(yyget_lineno(), (yyvsp[0].item_ident), compiler::binary_type::SUB_TYPE); }
#line 2496 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 110:
#line 434 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                      { (yyval.item_ident) = (yyvsp[0].item_ident); }
#line 2502 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 111:
#line 437 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                { (yyval.item_ident_array) = new compiler::Item_ident_array(yyget_lineno(), (yyvsp[-3].item_ident)->get_name()); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr));}
#line 2508 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 112:
#line 438 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                { (yyval.item_ident_array) = (yyvsp[-3].item_ident_array); (yyval.item_ident_array)->add_shape((yyvsp[-1].item_expr)); }
#line 2514 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 114:
#line 442 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2520 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 115:
#line 445 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                { (yyval.item_expr_comma) = new compiler::Item_expr_comma(yyget_lineno()); (yyval.item_expr_comma)->add_expression((yyvsp[-2].item_expr)); (yyval.item_expr_comma)->add_expression((yyvsp[0].item_expr)); }
#line 2526 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 116:
#line 446 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                { (yyval.item_expr_comma) = (yyvsp[-2].item_expr_comma); (yyval.item_expr_comma)->add_expression((yyvsp[0].item_expr)); }
#line 2532 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 117:
#line 449 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2538 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 118:
#line 450 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2544 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 120:
#line 454 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                     { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2550 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 122:
#line 458 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::EQ_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2556 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 123:
#line 459 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                    { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::NEQ_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2562 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 125:
#line 463 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::GE_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2568 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 126:
#line 464 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::LE_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2574 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 127:
#line 465 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::G_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2580 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 128:
#line 466 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                  { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::L_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2586 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 131:
#line 474 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                            { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2592 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 132:
#line 475 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                            { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2598 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 134:
#line 479 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2604 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 135:
#line 480 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITXOR_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2610 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 137:
#line 484 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                             { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2616 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 138:
#line 485 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                             { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::BITAND_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2622 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 140:
#line 489 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::ADD_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2628 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 141:
#line 490 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::SUB_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2634 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 143:
#line 494 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MUL_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2640 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 144:
#line 495 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::DIV_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2646 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 145:
#line 496 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_binary(yyget_lineno(), compiler::binary_type::MOD_TYPE, (yyvsp[-2].item_expr), (yyvsp[0].item_expr)); }
#line 2652 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 147:
#line 500 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UADD_TYPE, (yyvsp[0].item_expr)); }
#line 2658 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 148:
#line 501 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UMINUS_TYPE, (yyvsp[0].item_expr)); }
#line 2664 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 149:
#line 502 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::LNOT_TYPE, (yyvsp[0].item_expr)); }
#line 2670 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 150:
#line 503 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::BITNEG_TYPE, (yyvsp[0].item_expr)); }
#line 2676 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 151:
#line 504 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UREF_TYPE, (yyvsp[0].item_expr)); }
#line 2682 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 152:
#line 505 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                              { (yyval.item_expr) = new compiler::Item_expr_unary(yyget_lineno(), compiler::unary_type::UDEREFER_TYPE, (yyvsp[0].item_expr)); }
#line 2688 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 155:
#line 510 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_expr) = (yyvsp[-1].item_expr); }
#line 2694 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 156:
#line 511 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2700 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 157:
#line 512 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2706 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 158:
#line 513 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_expr) = (yyvsp[0].item_expr); }
#line 2712 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 159:
#line 516 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), std::stol(*(yyvsp[0].raw_string))); }
#line 2718 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 160:
#line 517 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), std::stol(*(yyvsp[0].raw_string))); }
#line 2724 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 161:
#line 519 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
        { 
          if (((yyvsp[0].raw_string))->find(".") != std::string::npos) {
            (yyval.item_literal) = new compiler::Item_literal_real(yyget_lineno(), std::stod(*(yyvsp[0].raw_string))); 
          } else {
            (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), std::stol(*(yyvsp[0].raw_string))); 
          }
          
        }
#line 2737 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 162:
#line 527 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_literal) = new compiler::Item_literal_char(yyget_lineno(), (yyvsp[0].raw_char)); }
#line 2743 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 163:
#line 528 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_literal) = new compiler::Item_literal_string(yyget_lineno(), *(yyvsp[0].raw_string)); }
#line 2749 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 164:
#line 529 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 1); }
#line 2755 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 165:
#line 530 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                    { (yyval.item_literal) = new compiler::Item_literal_int(yyget_lineno(), 0); }
#line 2761 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 166:
#line 533 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                                    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[-2].item_ident), new compiler::Item_func_call_list(yyget_lineno())); }
#line 2767 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 167:
#line 534 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                                    { (yyval.item_expr) = new compiler::Item_func_call(yyget_lineno(), (yyvsp[-3].item_ident), (yyvsp[-1].item_func_call_list)); }
#line 2773 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 168:
#line 537 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                            { (yyval.item_func_call_list) = (yyvsp[-2].item_func_call_list); (yyvsp[-2].item_func_call_list)->add_arg((yyvsp[0].item_expr)); }
#line 2779 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;

  case 169:
#line 538 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
                                                            { (yyval.item_func_call_list) = new compiler::Item_func_call_list(yyget_lineno()); (yyval.item_func_call_list)->add_arg((yyvsp[0].item_expr)); }
#line 2785 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"
    break;


#line 2789 "/home/darren/compiler/Compiler/src/frontend/parser/parser.cc"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 540 "/home/darren/compiler/Compiler/src/frontend/parser/parser.ypp"
