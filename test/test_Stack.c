#include "unity.h"
#include "Stack.h"
#include "CException.h"
#include "Exception.h"
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Stack_push_7_to_stack_expect_pop_7(void)
{
  int num;
  //printf("Program will start here.\n");
  num_stack stack;
   stack_init(&stack);
   push(7,&stack);
   num = pop(&stack);
   printf("Stack top : %d \n",stack.top);
   push(8,&stack);
   printf("Stack top : %d \n",stack.top);
   push(9,&stack);
   printf("Stack top : %d \n",stack.top);
   push(10,&stack);
   printf("Stack top : %d \n",stack.top);
   push(11,&stack);
   printf("Stack top : %d \n",stack.top);
   push(12,&stack);
   printf("Stack top : %d \n",stack.top);
   TEST_ASSERT_EQUAL(7,num);
   TEST_ASSERT_EQUAL(0,stack.top);
  // TEST_ASSERT_EQUAL(9,num);
}

void test_stack_pop_empty_stack_expect_error_message(void)
{
  int num;
  num_stack stack;
  stack_init(&stack);
  TEST_ASSERT_NULL(pop(&stack));
}

void test_stack_push_fulled_stack_expect_error_message(void)
{
  int num;
  num_stack stack ={
    16,
    12
  };
  num = pop(&stack);
  printf("Number : %d",num);
//  push(21,&stack);
  TEST_ASSERT_EQUAL(MAXSTACK, stack.top);

}
