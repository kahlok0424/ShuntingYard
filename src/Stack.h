#ifndef _STACK_H
#define _STACK_H
#define MAXSTACK 12

typedef struct Stack Stack;

Stack *initStack();

// Inserts an item at the top of the stack.
void push(Stack **stack, const void *value);

// Removes an item from the top of the stack.
const void *pop(Stack **stack);

// Returns the item at the top of the stack without removing it.
const void *stack_top(const Stack *stack);

#endif // _STACK_H
