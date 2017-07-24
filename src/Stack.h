#ifndef _STACK_H
#define _STACK_H
#define MAXSTACK 12

typedef struct num_stack num_stack;
struct num_stack{
    int number[MAXSTACK];
    int top;
};

typedef struct Stack Stack;

// Inserts an item at the top of the stack.
void stack_push(Stack **stack, const void *value);

// Removes an item from the top of the stack.
const void *stack_pop(Stack **stack);

// Returns the item at the top of the stack without removing it.
const void *stack_top(const Stack *stack);

void push(int num, num_stack *num_stack);
int pop(num_stack *num_stack);
void stack_init(num_stack *stack);

#endif // _STACK_H
