#include "unity.h"
#include "Stack.h"
#include "CException.h"
#include "Exception.h"
#include "Token.h"
#include "mock_Tokenizer.h"
#include "ShuntingYard.h"
#include <stdio.h>
#include <stdlib.h>

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
  int *result,result1;
  push(&stack,(void *)19 );
  push(&stack,(void *)25 );
//*result = pop(&stack);
//  result1 = pop(&stack);
//  printf("result : %d",result);
  TEST_ASSERT_EQUAL(25,*result);
  TEST_ASSERT_EQUAL(19,result1);
}

void test_push_double_stack_19_and_pop_double_19(void)
{
  Stack *stack;
//  int *num = 19;
  int result,result1;
  push_double(&stack,199 );
  push_double(&stack,255 );
  result = pop_double(&stack);
  result1 = pop_double(&stack);
  printf("result1 : %d",result);
  TEST_ASSERT_EQUAL(255,result);
  TEST_ASSERT_EQUAL(199,result1);
}

void test_push_integerToken_into_stack(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,11 ,4 , "7",7};
  IntegerToken *testToken;
  Token *token;

  getToken_ExpectAndReturn(tokenizer , (Token *)&inttoken);
  token = getToken(tokenizer);
  testToken = (IntegerToken *)token;
  double result;
  Stack *stack;
  push_double(&stack,testToken->value);
  result = pop_double(&stack);
  TEST_ASSERT_EQUAL(7,result);
}

void xtest_randomtest(void)
{
   char str[30] = "20.200 This is test ";
   char *ptr;
   double ret;

   ret = strtod(str, &ptr);
   printf("The number(double) is %lf\n", ret);
   printf("String part is |%s|", ptr);
}
