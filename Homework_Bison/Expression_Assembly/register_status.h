#ifndef REGISTER_STATUS_H
#define REGISTER_STATUS_H

#define push(sp, n) (*((sp)--) = (n))
#define pop(sp) (*++(sp))
#define top(sp) (*sp)

void get_available_register(int* stack_vacant, int* stack_occupied, char* buffer);

void free_register(int* stack_vacant, int* stack_occupied, char* buffer);

#endif