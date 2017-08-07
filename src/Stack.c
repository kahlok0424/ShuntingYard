#include "Stack.h"
#include <stdio.h>
#include "CException.h"
#include <stdlib.h>

#define stackempty 0
#define stackfulled 1

struct Stack {
    const void *data;
    Stack *next;
};

void push(Stack **stack, const void *data) {
    Stack *item = malloc(sizeof *item);
    item->data = data;
    item->next = *stack;
    *stack = item;
}

const void *pop(Stack **stack) {
    Stack *item = *stack;
    if(item == NULL)
    {
      printf("Stack is empty");
      Throw(createException("The stack is empty!",  \
                            stackempty));
    }
    else{
    const void *data = item->data;
    *stack = item->next;
    free(item);
    return data;
  }
    return 0;
}

const void *stack_top(const Stack *stack) {
    return stack->data;
}
