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


void test_push_stack_19_and_pop_19(void)
{
  Stack *stack;
//  int *num = 19;
  int result,result1;
  push(&stack,(void *)19 );
  push(&stack,(void *)25 );
  result = pop(&stack);
  result1 = pop(&stack);
  printf("result : %d",result);
  TEST_ASSERT_EQUAL(25,result);
  TEST_ASSERT_EQUAL(19,result1);
}
