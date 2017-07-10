#include "Stack.h"
#include <stdio.h>
#include "CException.h"

#define stackfulled 1
#define stackempty 2

/*int stack_is_empty() {

   if(top == -1)
      return 1;
   else
      return 0;
}*/

int stack_is_full(num_stack *stack) {

   if(stack->top == MAXSTACK){
     printf("Error! Stack fulled!");
   Throw(createException("The stack is fulled!", stackfulled));
    return 1;
    }
   else
      return 0;
}

void push(int num, num_stack *stack){  //function used to push element to stack
  CEXCEPTION_T ex;
  Try{
  if(stack_is_full(stack) ){
    printf("Error! Stack fulled!");
    return;
  }
  else{
  // printf("Enter the number to be pushed\n");
  //  scanf("%d",&num);
    stack->top = stack->top+1;
    stack->number[stack->top] = num;
  }
}Catch(ex){
  dumpException(ex);
}
}

int pop(num_stack *stack){
  int num;
  if(stack-> top == -1){
    printf("Error! Stack is empty");
  }
  else{
    num = stack->number[stack->top];
    stack->top = (stack->top -1);
  }
  return num;
}
