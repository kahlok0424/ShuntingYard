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

void xtest_stack_pop_empty_stack_expect_error_message(void)
{
  int num;
  num_stack stack;
  stack_init(&stack);
  TEST_ASSERT_NULL(pop(&stack));
}

void xtest_stack_push_fulled_stack_expect_error_message(void)
{
  int num;
  num_stack stack;
  stack.top = MAXSTACK;
  push(99,&stack);
  TEST_ASSERT_EQUAL(MAXSTACK, stack.top);

}

void xtest_Stack_push_7_to_stack_expect_pop_7(void)
{
  int num;
  //printf("Program will start here.\n");
   num_stack stack;
   stack_init(&stack);
   push(7,&stack);
   num = pop(&stack);

   TEST_ASSERT_EQUAL(7,num);
}

void test_push_stack_19_and_pop_19(void)
{
  num_stack stack;
//  int *num = 19;
  int result,result1;
  stack_push(&stack,19 );
  stack_push(&stack,25 );
  result = stack_pop(&stack);
  result1 = stack_pop(&stack);
  printf("result : %d",result);
  TEST_ASSERT_EQUAL(25,result);
  TEST_ASSERT_EQUAL(19,result1);
}
