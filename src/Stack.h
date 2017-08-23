#ifndef _STACK_H
#define _STACK_H
#define MAXSTACK 12
#include "Token.h"

typedef struct Stack Stack;

Stack *initStack();

// Inserts an item at the top of the stack.
Stack *push(Stack *stack, const void *value);

// Removes an item from the top of the stack.
const void *pop(Stack *stack);

// Returns the item at the top of the stack without removing it.
const void *stack_top(const Stack *stack);

//Push double onto the stack
//void push_double(Stack **operands , double x);

//double pop_double(Stack **operands);

#endif // _STACK_H
