%option noyywrap
%option yylineno
%{
    /*************************************************************
    expr.l
    LEX FILE
    Date: 2021/10/18
    Haobin Chen (@Aoyamahiroki) <etyyuiope@gmail.com>

    Defines regular expressions.
    **************************************************************/
#include <frontend/symbol_table/symbol_table.hh>

#include <frontend/parser/parser.hh>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdint>
#include <string>

extern FILE* yyin;
extern YYSTYPE yylval;

int yycolumn = 1;

compiler::Symbol_table symbol_table;

#define YY_USER_ACTION yylloc.first_line = yylineno;            \
                       yylloc.first_column = yycolumn;          \
                       for (auto i : std::string(yytext_ptr)) { \
                           if (i == '\n' || i == '\r') {        \
                               yylineno++;                      \
                               yycolumn = 1;                    \
                           } else {                             \
                               yycolumn++;                      \
                           }                                    \
                       }                                        \
                       yylloc.last_line = yylineno;             \
                       yylloc.last_column = yycolumn - 1;
%}


DECIMAL     [+-]?(\d+\.?[0-9]*|\.\d+)
OCTAL       0([1-7][0-7]*|0)
HEX         (0x|0X)([0-9a-fA-F]+)
ID          [[:alpha:]_][[:alpha:][:digit:]_]*
LINE        ((\r\n)|\n|\r)
EMPTY       [ \t]
COMMENT     \/\/[^\n\r]*(\n|\r|\n\r)
BEGIN       \/\*
STRING      \"[^\"]*\"

%%
{COMMENT} { ; }
{BEGIN} {
    // Handles mutilline comment.
    char c;
    while ((c = yyinput()) != 0) {
        if (c == '\n') {
            yylineno ++;
            yycolumn = 1;
        } else if (c == '*') {
            if ((c = yyinput()) == '/') {
                break;
            } else {
                unput(c);
            }
        }
    }
}

{ID}         { yylval.raw_string = new std::string(yytext, yyleng); }
{DECIMAL}    { yylval.raw_number = std::stod(); }
{LINE}       { yylineno ++; yycolumn = 1; }
{EMPTY} ;

. { yyerror("Unknown character detected! Check your input again :("); yyterminate(); }


<<EOF>> { yyterminate(); }

%%