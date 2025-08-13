#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    struct StackNode* top;
} Stack;

Stack* create_stack();
void push(Stack* stack, void* data);
void pop(Stack* stack);
void* top(Stack* stack);
void free_stack(Stack* stack);

#endif
