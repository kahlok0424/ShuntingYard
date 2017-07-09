#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void push(num_stack *num_stack){
  int num;
  // num_stack s;
  if(num_stack->top == (MaxStack -1) ){
    prinf("Stack is fulled\n");
    return;
  }
  else{
    prinf("Enter the number to be pushed\n");
    scanf("%d",&num);
    num_stack->top = num_stack->top+1;
    num_stack->number[num_stack->top] = num;
  }
  return;
}
