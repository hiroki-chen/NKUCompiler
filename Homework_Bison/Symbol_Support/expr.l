%{
    /*************************************************************
    expr.l
    LEX FILE
    Date: 2021/10/11
    Haobin Chen (@Aoyamahiroki) <etyyuiope@gmail.com>

    Defines regular expressions.
    **************************************************************/
#include "yacc.h"
#include "symbol.h"

void yyerror(const char* error);

extern YYSTYPE yylval;
extern struct symbol* symbol_table;
%}

digit          [0-9]
letter         [a-zA-Z]
digit_letter   [a-zA-Z0-9]
ignore         [\t\s\n]

%%
"+"     { return ADD; }
"="     { return EQ; }
"-"     { return MINUS; }
"*"     { return MUL; }
"/"     { return DIV; }
"$$"    { return END; }
";"     { return SEMICOLON; }

{digit}+|{digit}*\.{digit}+  { yylval.value = atof(yytext);  return NUMBER; }
{letter}{digit_letter}*    { yylval.id = get_symbol(symbol_table, yytext); return ID; }

[ \t\n] ;
%%

void yyerror(const char* error)
{
    fprintf(stderr, "Parse Error: %s\n", error);
}

int yywrap(void)
{
    return 1;
}