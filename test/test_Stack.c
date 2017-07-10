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
  num_stack stack = {
    4,
    1
  };
   push(7,&stack);
   num = pop(&stack);
   TEST_ASSERT_EQUAL(7,num);
  // TEST_ASSERT_EQUAL(9,num);
}

void test_stack_pop_empty_stack_expect_error_message(void)
{
  int num;
  num_stack stack={
    NULL,
    0
  };
  TEST_ASSERT_NULL(pop(&stack));
}

void test_stack_push_fulled_stack_expect_error_message(void)
{
  num_stack stack ={
    16,
    12
  };
  push(21,&stack);

}
