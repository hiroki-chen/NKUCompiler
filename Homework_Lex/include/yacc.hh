/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     EQ = 264,
     NEQ = 265,
     GEQ = 266,
     LEQ = 267,
     G = 268,
     L = 269,
     BIT_AND = 270,
     BIT_OR = 271,
     BIT_XOR = 272,
     BIT_NEG = 273,
     LOGIC_AND = 274,
     LOGIC_OR = 275,
     LOGIC_NOT = 276,
     DECIMAL = 277,
     OCTAL = 278,
     HEX = 279,
     STRING = 280,
     INT = 281,
     DOUBLE = 282,
     FLOAT = 283,
     CHAR = 284,
     VOID = 285,
     STRUCT = 286,
     IF = 287,
     ELSE = 288,
     WHILE = 289,
     FOR = 290,
     RETURN = 291,
     BREAK = 292,
     CONTINUE = 293,
     CONST = 294,
     ASSIGN = 295,
     LBRACE = 296,
     RBRACE = 297,
     LPARENTHESIS = 298,
     RPARENTHESIS = 299,
     SEMICOLON = 300,
     UADD = 301,
     UMINUS = 302
   };
#endif
/* Tokens.  */
#define ID 258
#define ADD 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define EQ 264
#define NEQ 265
#define GEQ 266
#define LEQ 267
#define G 268
#define L 269
#define BIT_AND 270
#define BIT_OR 271
#define BIT_XOR 272
#define BIT_NEG 273
#define LOGIC_AND 274
#define LOGIC_OR 275
#define LOGIC_NOT 276
#define DECIMAL 277
#define OCTAL 278
#define HEX 279
#define STRING 280
#define INT 281
#define DOUBLE 282
#define FLOAT 283
#define CHAR 284
#define VOID 285
#define STRUCT 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define FOR 290
#define RETURN 291
#define BREAK 292
#define CONTINUE 293
#define CONST 294
#define ASSIGN 295
#define LBRACE 296
#define RBRACE 297
#define LPARENTHESIS 298
#define RPARENTHESIS 299
#define SEMICOLON 300
#define UADD 301
#define UMINUS 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "src/tokenizer.ypp"
{
    char*   raw_symbol;
    char*   raw_string;
    int     raw_int;
    double  raw_real;
}
/* Line 1529 of yacc.c.  */
#line 150 "src/yacc.hh"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

