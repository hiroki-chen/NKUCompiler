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
#define YYSTYPE char*

FILE* yyin;
extern int yywrap(void);
extern int yyparse(void);

int yylex(void);
void yyerror(const char* error);
%}

%token LETTER NUMBER
%token ADD MINUS MUL DIV UMINUS SEMICOLON

%left ADD MINUS
%left MUL DIV
%nonassoc UMINUS
%start lines

%%
lines:  lines expr SEMICOLON    { printf("The postfix form is: %s.\n", $2); }
     |  lines SEMICOLON
     |
     ;

expr:  expr ADD expr            { 
    unsigned int length = strlen($1) + 2 + strlen($3);
    $$ = (char*)(malloc)(length); /* \0 + '+' */
    memset($$, 0, length);
    strcpy($$, $1);
    strcat($$, $3);
    strcat($$, "+");
}
    | expr MINUS expr          { 
    unsigned int length = strlen($1) + 2 + strlen($3);
    $$ = (char*)(malloc)(length); /* \0 + '+' */
    memset($$, 0, length);
    strcpy($$, $1);
    strcat($$, $3);
    strcat($$, "-");
}
    |  expr MUL expr            {
    unsigned int length = strlen($1) + 2 + strlen($3);
    $$ = (char*)(malloc)(length); /* \0 + '+' */
    memset($$, 0, length);
    strcpy($$, $1);
    strcat($$, $3);
    strcat($$, "*");
}
    |  expr DIV expr            {
    unsigned int length = strlen($1) + 2 + strlen($3);
    $$ = (char*)(malloc)(length); /* \0 + '+' */
    memset($$, 0, length);
    strcpy($$, $1);
    strcat($$, $3);
    strcat($$, "/");
}
    |  NUMBER                   { $$ = $1; printf("%s", $1); }
    |  LETTER                   { $$ = $1; }
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
            yylval = (char*)(malloc(128));
            memset(yylval, '\0', 128);
            int i = 0;
            while (isdigit(c)) {
                yylval[i++] = c;
                c = getchar();
            }
            yylval[i] = '\0';
            ungetc(c, yyin);
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
        } else if (isalpha(c)) {
            yylval = (char*)(malloc(2));
            yylval[0] = c;
            yylval[1] = '\0';
            return LETTER;
        } else {
            return c;
        }
    }
}