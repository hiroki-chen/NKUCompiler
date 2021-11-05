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
#include <frontend/nodes/item_all.hh>
#include <frontend/parser/parser.hh>
#include <common/compile_excepts.hh>

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdint>
#include <string>

extern void yyerror(const char* error_information);
int yycolumn = 1;

#define YY_USER_ACTION yylloc.first_line = yylineno;            \
                       yylloc.first_column = yycolumn;          \
                       for (char c : std::string(yytext)) {     \
                           if (c == '\n' || c == '\r') {        \
                               yycolumn = 1;                    \
                           } else {                             \
                               yycolumn++;                      \
                           }                                    \
                       }                                        \
                       yylloc.last_line = yylineno;             \
                       yylloc.last_column = yycolumn - 1;
%}


DECIMAL     ([0-9]+\.?[0-9]*|\.[0-9]+)
OCTAL       0([0-7]+)
HEX         (0x|0X)([0-9a-fA-F]+)
ID          [[:alpha:]_][[:alpha:][:digit:]_]*
EMPTY       [ \t\n\r]+
COMMENT     \/\/[^\n\r]*(\n|\r|\n\r)
BEGIN       \/\*
STRING      \"[^\"]*\"
CHAR        '\\?.'

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

"int"        { return INT; }
"double"     { return DOUBLE; }
"float"      { return FLOAT; } 
"char"       { return CHAR; }
"void"       { return VOID; }

"if"         { return IF; }
"else"       { return ELSE; }
"while"      { return WHILE; }
"true"       { return TRUE; }
"false"      { return FALSE; }
"return"     { return RETURN; }
"continue"   { return CONTINUE; }
"break"      { return BREAK; }
"for"        { return FOR; }
"const"      { return CONST; }
"struct"     { return STRUCT; }

{HEX}        { yylval.raw_number = double(std::stoi(std::string(yytext, yyleng), nullptr, 16)); return HEX; }
{OCTAL}      { yylval.raw_number = double(std::stoi(std::string(yytext, yyleng), nullptr, 8)); return OCTAL; }
{DECIMAL}    { yylval.raw_number = std::stod(std::string(yytext, yyleng)); return DECIMAL; }

"["          { return LSQUARE; }
"]"          { return RSQUARE; }
"{"          { return LBRACE; }
"}"          { return RBRACE; }
"("          { return LPARENTHESIS; }
")"          { return RPARENTHESIS; }
";"          { return SEMICOLON; }
"."          { return DOT; }
","          { return COMMA; }

"=="         { return EQ; }
">="         { return GEQ; }
"<="         { return LEQ; }
"<"          { return L; }
">"          { return G; }
"!="         { return NEQ; }

"="          { return ASSIGN; }

"&&"         { return LOGIC_AND; }
"||"         { return LOGIC_OR; }
"!"          { return LOGIC_NOT; }

"&"          { return BIT_AND; }
"|"          { return BIT_OR; }
"^"          { return BIT_XOR; }
"~"          { return BIT_NEG; }

"++"         { return INC; }
"--"         { return DEC; }
"+"          { return ADD; }
"-"          { return MINUS; }
"*"          { return MUL; }
"/"          { return DIV; }
"%"          { return MOD; }

{ID}         { yylval.raw_string = new std::string(yytext, yyleng); return ID; }
{CHAR}       { yylval.raw_char = yytext[1]; return CHAR; }
{STRING}     { yylval.raw_string = new std::string(yytext, yyleng); return STRING; }
{EMPTY}      { ; }

. { 
    std::ostringstream oss;
    oss << "Error: Unknown character " << yytext;
    throw compiler::unknown_character(oss.str());
}


<<EOF>> { yyterminate(); }

%%