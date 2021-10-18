#include "register_status.h"

#include <string.h>
#include <stdio.h>

extern void yyerror(const char* error);

void get_available_register(int* stack_vacant, int* stack_occupied, char* buffer)
{
    int cur;
    if ((cur = pop(stack_vacant)) == 17) {
        yyerror("Runtime error!");
    }

    push(stack_occupied, cur);
    strcpy(buffer, "r");
    char num[4];
    sprintf(num, "%d", cur);
    strcat(buffer, num);
}

void free_register(int* stack_vacant, int* stack_occupied, char* buffer)
{
    int cur = top(stack_occupied);
    strcpy(buffer, "r");
    push(stack_vacant, pop(stack_occupied));
    char num[4];
    sprintf(num, "%d", cur);
    strcat(buffer, num);
}