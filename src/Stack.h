#ifndef _STACK_H
#define _STACK_H
#define MaxStack 12

typedef struct num_stack num_stack;
struct num_stack{
    int number[MaxStack];
    int top;
};

void push(num_stack *num_stack);
#endif // _STACK_H
