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
#include <symbol_table.hh>

#include <yacc.hh>

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdint>
#include <string>

extern FILE* yyin;
extern YYSTYPE yylval;

compiler::Symbol_table symbol_table;

extern std::ofstream output;

//extern compiler::Symbol_table symbol_table;

uint32_t word_count = 0;
uint32_t line_count = 0;
uint32_t cur_pos    = 0;

// Preprocessors.
#define ONLY_FOR_LEX

#ifdef ONLY_FOR_LEX
#else
    #define YYSTYPE void *
    #include "parser.h"

#endif
%}
DECIMAL     [+-]?(\d+\.?[0-9]*|\.\d+)
OCTAL       0([1-7][0-7]*|0)
HEX         (0x|0X)([0-9a-fA-F]+)
ID          [[:alpha:]_][[:alpha:][:digit:]_]*
LINE        ((\r\n)|\n|\r)
EMPTY       [ \t]
COMMENT     \/\/.*(\n|\r|\n\r)
BEGIN       \/\*
STRING      \"(\\.|[^"\\])*\"

%x          BLOCKCOMMENT

%%
"int" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "INT\t\t\t\tint" << std::endl;
        cur_pos += 3;
        return INT;
    #else
        
    #endif
}

"const" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "CONST\t\t\t\tconst" << std::endl;
        cur_pos += 5;
    #else
        return CONST;
    #endif
}

"double" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "DOUBLE\t\t\t\tdouble" << std::endl;
        cur_pos += 6;
    #else
        return DOUBLE;
    #endif
}

"float" {
        #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "FLOAT\t\t\t\tfloat" << std::endl;
        cur_pos += 5;
    #else
        return FLOAT;
    #endif
}

"char" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "CHAR\t\t\t\tchar" << std::endl;
        cur_pos += 4;
    #else
        return CHAR;
    #endif
}

"void" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "VOID\t\t\t\tvoid" << std::endl;
        cur_pos += 4;
    #else
        return VOID;
    #endif
}

"struct" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "STRUCT\t\t\t\tstruct" << std::endl;
        cur_pos += 6;
    #else
        return STRUCT;
    #endif
}

"if" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "IF\t\t\t\tif" << std::endl;
        cur_pos += 2;
    #else
        return IF;
    #endif
}

"else" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "ELSE\t\t\t\telse" << std::endl;
        cur_pos += 4;
    #else
        return ELSE;
    #endif
}

"while" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "WHILE\t\t\t\twhile" << std::endl;
        cur_pos += 5;
    #else
        return WHILE;
    #endif
}

"for" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "FOR\t\t\t\tfor" << std::endl;
        cur_pos += 3;
    #else
        return FOR;
    #endif
}

"break" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "BREAK\t\t\t\tbreak" << std::endl;
        cur_pos += 5;
    #else
        return INT;
    #endif
}

"continue" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "CONTINUE\t\t\t\tcontinue" << std::endl;
        cur_pos += 8;
    #else
        return CONTINUE;
    #endif
}

"return" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "RETURN\t\t\t\treturn" << std::endl;
        cur_pos += 6;
    #else
        return RETURN;
    #endif
}

"+" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "ADD\t\t\t\tadd" << std::endl;
        cur_pos += 1;
    #else
        return ADD;
    #endif
}

"-" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "MINUS\t\t\t\tminus" << std::endl;
        cur_pos += 1;
    #else
        return MINUS;
    #endif
}

"*" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "MUL\t\t\t\tmul" << std::endl;
        cur_pos += 1;
    #else
        return MUL;
    #endif
}

"/" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "DIV\t\t\t\tdiv" << std::endl;
        cur_pos += 1;
    #else
        return DIV;
    #endif
}

"%" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "MOD\t\t\t\tmod" << std::endl;
        cur_pos += 1;
    #else
        return MOD;
    #endif
}

"&&" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "LOGIC_AND\t\t\t\tand" << std::endl;
        cur_pos += 2;
    #else
        return LOGIC_AND;
    #endif
}

"||" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "LOGIC_OR\t\t\t\tor" << std::endl;
        cur_pos += 2;
    #else
        return LOGIC_OR;
    #endif
}

"=" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "ASSIGN\t\t\t\tassign" << std::endl;
        cur_pos += 1;
    #else
        return ASSIGN;
    #endif
}

"==" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "EQ\t\t\t\teq" << std::endl;
        cur_pos += 2;
    #else
        return EQ;
    #endif
}

"!=" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "NEQ\t\t\t\tneq" << std::endl;
        cur_pos += 2;
    #else
        return NEQ;
    #endif
}

"!" {
     #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "LOGIC_NOT\t\t\t\tnot" << std::endl;
        cur_pos += 1;
    #else
        return LOGIC_NOT;
    #endif
}

">" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "GREATE\t\t\t\tgreat" << std::endl;
        cur_pos += 1;
    #else
        return G;
    #endif
}

"<" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "LESS\t\t\t\tless" << std::endl;
        cur_pos += 1;
    #else
        return L;
    #endif
}

">=" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "GEQ\t\t\t\tgeq" << std::endl;
        cur_pos += 2;
    #else
        return GEQ;
    #endif
}

"<=" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "LEQ\t\t\t\tleq" << std::endl;
        cur_pos += 2;
    #else
        return LEQ;
    #endif
}

"+" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "ADD\t\t\t\tadd" << std::endl;
        cur_pos += 1;
    #else
        return ADD;
    #endif
}

"-" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "MINUS\t\t\t\tminus" << std::endl;
        cur_pos += 1;
    #else
        return MINUS;
    #endif
}

"*" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "MUL\t\t\t\tmul" << std::endl;
        cur_pos += 1;
    #else
        return MUL;
    #endif
}

"/" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "DIV\t\t\t\tdiv" << std::endl;
        cur_pos += 1;
    #else
        return DIV;
    #endif
}

";" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "SEMICOLON\t\t\t\tsemicolon" << std::endl;
        cur_pos += 1;
        
    #else
        return SEMICOLON;
    #endif
}

"{" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "LBRACE\t\t\t\tlbrace" << std::endl;
        cur_pos += 1;
        symbol_table.enter_scope();
    #else
        return LBRACE;
    #endif
}

"}" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "RBRACE\t\t\t\trbrace" << std::endl;
        cur_pos += 1;
        symbol_table.leave_scope();
    #else
        return RBRACE;
    #endif
}

"(" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "LPARENTHESIS\t\t\t\tlparenthesis" << std::endl;
        cur_pos += 1;
    #else
        return LPARENTHESIS;
    #endif
}

")" {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "RPARENTHESIS\t\t\t\trparenthesis" << std::endl;
        cur_pos += 1;
    #else
        return RPARENTHESIS;
    #endif
}

{DECIMAL} {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "Decimal\t\t\t\t" << yytext << std::endl;
        cur_pos += strlen(yytext);
    #else
        yylval.raw_int = std::stoi((std::string)yytext);
        return DECIMAL;
    #endif
}

{OCTAL} {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "OCTAL\t\t\t\t" << std::stoi(yytext, 0, 8) << std::endl;
        cur_pos += strlen(yytext);
    #else
        return OCTAL;
    #endif
}

{HEX} {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "HEX\t\t\t\t" << std::stoi(yytext, 0, 16) << std::endl;
        cur_pos += strlen(yytext);
    #else
        return HEX;
    #endif
}

{ID} {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "ID\t\t\t\tid: " << yytext << " with scope: " << symbol_table.get_current_scope() << std::endl;
        yylval.raw_symbol = strdup(yytext);
        return ID;
    #else
        return ID;
    #endif
}

{STRING} {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "STRING\t\t\t\tstring: " << yytext << std::endl;
        cur_pos += strlen(yytext);
        // yylval.raw_string = strdup(yytext);
    #else
        return STRING;
    #endif
}

{EMPTY} { cur_pos ++; }

{LINE} { line_count ++; cur_pos = 0; }

{BEGIN} {
    // Handles mutilline comment.
    output << line_count << " " << cur_pos << ":\t" <<  "MULTILINE COMMENT\t\t\t\t" << std::endl;
    char c;
    while ((c = yyinput()) != 0) {
        if (c == '\n') {
            line_count ++;
            cur_pos = 0;
        } else if (c == '*') {
            if ((c = yyinput()) == '/') {
                break;
            } else {
                unput(c);
            }
        }
    }
}

{COMMENT} {
    #ifdef ONLY_FOR_LEX
        output << line_count << " " << cur_pos << ":\t" <<  "SINGLE_COMMENT\t\t\t\t empty" << std::endl;
        cur_pos += strlen(yytext);
        line_count ++;
    #else
        return SINGLE_COMMENT;
    #endif
}

. {
    output << line_count << " " << cur_pos << ":\t" <<  "Syntax error!" << std::endl;
}

<<EOF>> { yyterminate(); }

%%

void yyerror(const char* str)
{
    std::cout << str << std::endl;
}