%{
/*************************************************************
    expr.y
    YACC FILE
    Date: 2021/10/11
    Haobin Chen (@Aoyamahiroki) <etyyuiope@gmail.com>
**************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "symbol.h"

#define true 1

int yylex();
extern int yyparse();
extern int yywrap();
FILE* yyin;
void yyerror(const char* str);

struct symbol symbol_table[1024];

int init_symbol_table(void);
%}

// Operators
%token ADD MINUS MUL DIV EQ END SEMICOLON

%left EQ
%left ADD MINUS
%left MUL DIV
%nonassoc UMINUS

%union {
    double value;
    struct symbol* id;
}

// Numbers and identifiers.
%token <id> ID
%token <value> NUMBER
%type  <value> expr

%start lines
%%

lines:   lines stmt SEMICOLON
     |   stmt SEMICOLON
     |   END                    { printf("Goodbye:)\n"); exit(0); }
     ;

stmt:   ID EQ expr { $1->value = $3; }
    |   expr       { printf("%f\n", $1); }
    ;

expr:   expr ADD expr           { $$ = $1 + $3; }
    |   expr MINUS expr         { $$ = $1 - $3; }
    |   expr MUL expr           { $$ = $1 * $3; }
    |   expr DIV expr           { 
                                  if ($3 == 0.0) yyerror("The divisor cannot be zero!"); 
                                  else           $$ = $1 / $3;
                                }
    |   '(' expr ')'            { $$ = $2; }
    |   MINUS expr %prec UMINUS { $$ = -$2; }
    |   NUMBER                  { $$ = $1; }
    |   ID                      { $$ = $1->value; }
    ;
%%

/*============ Program Section ==============*/

int main(int argc, const char** argv)
{
    init_symbol_table();
    yyin = stdin;
    // Initialize the symbol table.
    do {
        yyparse();
    } while (!feof(yyin));
    
    return 0;
}

void yyerror(const char* error)
{
    fprintf(stderr, "Parse error: %s\n", error);
    exit(1);
}

int init_symbol_table(void)
{
    //symbol_table = (struct symbol*)(malloc(MAXIMUM_SYMBOL * sizeof(struct symbol)));

    for (unsigned int i = 0; i < MAXIMUM_SYMBOL; i++) {
        symbol_table[i].name = NULL;
        symbol_table[i].value = 0.0;
    }

    if (symbol_table == NULL) {
        fprintf(stderr, "Malloc failed.n");
        exit(1);
    }

    return 0;
}

int yylex(void)
{
    char c;
    while (true) {
        c = getchar();
        if (c == ' ' || c == '\t' || c == '\n') {
            // We ignore all the empty characters.
            continue;
        } else if (isdigit(c)) {
            double num = 0.0;
            while (isdigit(c)) {
                num = num * 10 + c - '0';
                c = getchar();
            }
            yylval.value = num;
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
        } else if (c == '=') {
            return EQ;
        } else if (isalpha(c)){
            yylval.id = get_symbol(symbol_table, c);
            // printf("res: %s", yylval.id->name);
            return ID;
        } else if (c == '$') {
            return END;
        } else {
            return c;
        }
    }
}