#include "stack.h"

Stack* create_stack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, void* data) {
    StackNode* new_node = malloc(sizeof(StackNode));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

void pop(Stack* stack) {
    if (stack->top == NULL) {
        return;
    }
    StackNode* tmp = stack->top;
    stack->top = stack->top->next;
    stack->size--;
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
