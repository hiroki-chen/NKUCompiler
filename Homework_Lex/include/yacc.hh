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
     INT = 280,
     DOUBLE = 281,
     FLOAT = 282,
     CHAR = 283,
     VOID = 284,
     STRUCT = 285,
     IF = 286,
     ELSE = 287,
     WHILE = 288,
     FOR = 289,
     RETURN = 290,
     BREAK = 291,
     CONTINUE = 292,
     CONST = 293,
     ASSIGN = 294,
     LBRACE = 295,
     RBRACE = 296,
     LPARENTHESIS = 297,
     RPARENTHESIS = 298,
     SEMICOLON = 299,
     UADD = 300,
     UMINUS = 301
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
#define INT 280
#define DOUBLE 281
#define FLOAT 282
#define CHAR 283
#define VOID 284
#define STRUCT 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define RETURN 290
#define BREAK 291
#define CONTINUE 292
#define CONST 293
#define ASSIGN 294
#define LBRACE 295
#define RBRACE 296
#define LPARENTHESIS 297
#define RPARENTHESIS 298
#define SEMICOLON 299
#define UADD 300
#define UMINUS 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "src/tokenizer.ypp"
{
    char*   raw_symbol;
    int     raw_int;
    double  raw_real;
}
/* Line 1529 of yacc.c.  */
#line 147 "src/yacc.hh"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

