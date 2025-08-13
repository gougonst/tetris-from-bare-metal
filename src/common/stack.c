#include "stack.h"

Stack* create_stack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, void* data) {
    StackNode* new_node = malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

void pop(Stack* stack) {
    if (stack->top == NULL) {
        return;
    }
    StackNode* tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp->data);
    free(tmp);
}

void* top(Stack* stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    return stack->top->data;
}

void free_stack(Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
    free(stack);
}
