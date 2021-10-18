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

#include "register_status.h"

#define true 1

FILE* yyin;
extern int yywrap(void);
extern int yyparse(void);

int vacant[17];
int occupied[17];

int* vacant_register;
int* occupied_register;

void init_register();
int yylex(void);
void yyerror(const char* error);
%}

%token      ADD MINUS MUL DIV SEMICOLON END
%left       ADD MINUS
%left       MUL DIV
%nonassoc   UMINUS

%union {
    int         value;
    char*       assembly_code;
}

%token <value>              NUMBER
%type  <assembly_code>      expr

%start lines
%%
lines:  lines SEMICOLON
     |  lines expr SEMICOLON     { printf("Assembly Result:\n%s", $2); }
     |  END                      { printf("Goodbye:)"); exit(0); }
     |
     ;

expr:   expr ADD   expr          {
     char buffer[1024];
     $$ = "ok";
}
    |   expr MINUS expr          {
     char buffer[1024];
     strcpy(buffer, $1);
     strcat(buffer, "MOV r1, r0\n"); // 保存expr1计算的结果
     strcat(buffer, $3);
     strcat(buffer, "MOV r2, r0\n"); // 保存expr2计算的结果
     strcat(buffer, "SUB r0, r1, r2\n");
     $$ = strdup(buffer);    
}
    |   '(' expr ')'             { $$ = $2; }
    |   expr MUL   expr          {
     char buffer[1024];
     strcpy(buffer, $1);
     strcat(buffer, "MOV r1, r0\n"); // 保存expr1计算的结果
     strcat(buffer, $3);
     strcat(buffer, "MOV r2, r0\n"); // 保存expr2计算的结果
     strcat(buffer, "MUL r0, r1, r2\n");
}
    |   expr DIV   expr          {
     char buffer[1024];
     strcpy(buffer, $1);
     strcat(buffer, "MOV r1, r0\n"); // 保存expr1计算的结果
     strcat(buffer, $3);
     strcat(buffer, "MOV r2, r0\n"); // 保存expr2计算的结果
     strcat(buffer, "DIV r0, r1, r2\n");
}
    |   NUMBER                   {
        char buffer[1024];
        char num[1024];
        sprintf(num, "#%d", $1);
        strcpy(buffer, "MOV ");
        char reg[8];
        get_available_register(vacant_register, occupied_register, reg);
        strcat(buffer, reg);
        strcat(buffer, ", ");
        strcat(buffer, num);
        strcat(buffer, "\n");
        $$ = buffer;
    }
    ;

%%
int main(int argc, const char** argv)
{
    init_register();
    yyin = stdin;
    do {
        yyparse();
    } while (!feof(yyin));
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
            int num = 0;
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
        } else if (c == '$') {
            return END;
        } else {
            return c;
        }
    }
}

void yyerror(const char* error)
{
    fprintf(stderr, "Parse error:%s\n", error);
    exit(1);
}

void init_register()
{
    for (unsigned int i = 0; i < 17; i++) {
        vacant[i] = i;
        occupied[i] = -1;
    }
    vacant_register = vacant;
    occupied_register = occupied;
}

/*
    |    '(' expr ')'            { $$ = $2; }
    |   MINUS expr %prec UMINUS  { $$ = -$2; }
*/