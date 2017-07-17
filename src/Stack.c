#include "Stack.h"
#include <stdio.h>
#include "CException.h"

#define stackfulled 1
#define stackempty 2

int stack_is_empty(num_stack *stack)
{
   if(stack->top == -1)
    {
   Throw(createException("The stack is empty!",  \
                      stackempty));
      return 1;
    }
   else
      return 0;
}

int stack_is_full(num_stack *stack) {

   if(stack->top == MAXSTACK){
    Throw(createException("The stack is fulled!", \
                       stackfulled));
    return 1;
    }
   else{
      return 0;
    }
}

void stack_init(num_stack *stack)
{
//stack->number = NULL;
  stack->top = -1;
}

void push(int num, num_stack *stack){  //function used to push element to stack
  CEXCEPTION_T ex;
  Try
{
  if(stack_is_full(stack) ){
      }
  else
   {
    stack->top = (stack->top)+1;
    stack->number[stack->top] = num;
    printf("The number pushed into stack is: %d ",stack->number[stack->top]);
   }
}Catch(ex)
  {
  dumpException(ex);
  }
}

int pop(num_stack *stack){
  CEXCEPTION_T ex;
  int num;
  Try{
  if(stack_is_empty(stack)){
  }
  else{
    num = stack->number[stack->top];
    stack->top = (stack->top -1);
  }
}Catch(ex){
  dumpException(ex);
}
  return num;
}
