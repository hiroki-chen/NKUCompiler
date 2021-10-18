%{
/*************************************************************
    expr.y
    YACC FILE
    Date: 2021/10/12
    Haobin Chen (@Aoyamahiroki) <etyyuiope@gmail.com>
**************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1

FILE* yyin;
extern int yywrap(void);
extern int yyparse(void);

int yylex(void);
void yyerror(const char* error);
%}

%token      ADD MINUS MUL DIV SEMICOLON NUMBER
%left       ADD MINUS
%left       MUL DIV
%nonassoc   UMINUS

%start lines
%%

lines:  lines SEMICOLON
     |  lines expr SEMICOLON     { printf("result: %f.\n", $2); }
     |
     ;

expr:   expr ADD   expr          { $$ = $1 + $3; }
    |   expr MINUS expr          { $$ = $1 - $3; }
    |   expr MUL   expr          { $$ = $1 * $3; }
    |   expr DIV   expr          {
                                    if ($3 == 0) yyerror("Divisor cannot be zero!");
                                    else         $$ = $1 / $3;
                                 }
    |    '(' expr ')'            { $$ = $2; }
    |   MINUS expr %prec UMINUS  { $$ = -$2; }
    |   NUMBER                   { $$ = $1; }
    ;
%%

int main(int argc, const char** argv)
{
    yyin = stdin;
    do {
        yyparse();
    } while (!feof(yyin));

    return 0;
}

void yyerror(const char* error)
{
    fprintf(stderr, "Parse error:%s\n", error);
    exit(1);
}

int yylex(void)
{
    char c;
    while (true) {
        c = getchar();
        if (c == ' ' || c == '\t' || c == '\n') {
            continue;
        } else if (isdigit(c)) {
            yylval = 0.0;
            while (isdigit(c)) {
                yylval = yylval * 10 + c - '0';
                c = getchar();
            }
            ungetc(c, stdin);
            return NUMBER;
        } else if (c == '+') {
            return ADD;
        } else if (c == '-') {
            return MINUS;
        } else if (c == '*') {
            return MUL;
        } else if (c == '/') {
            return DIV;
        } else if (c == ';') {
            return SEMICOLON;
        } else {
            return c;
        }
    }
}