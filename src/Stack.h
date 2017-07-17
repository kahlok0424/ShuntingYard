#ifndef _STACK_H
#define _STACK_H
#define MAXSTACK 12

typedef struct num_stack num_stack;
struct num_stack{
    int number[MAXSTACK];
    int top;
};

void push(int num, num_stack *num_stack);
int pop(num_stack *num_stack);
void stack_init(num_stack *stack);

#endif // _STACK_H
