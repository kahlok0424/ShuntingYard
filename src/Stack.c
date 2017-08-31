#include "Stack.h"
#include <stdio.h>
#include "CExceptionConfig.h"
#include "Exception.h"
#include <stdlib.h>
//#include "Token.h"

#define stackempty 0
#define stackfulled 1

struct Stack {
    const void *data;
    Stack *next;
};

Stack *initStack()
{
  Stack *newstack = malloc(sizeof *newstack);
  newstack = NULL;
  return newstack;
}

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
      return 0;
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
