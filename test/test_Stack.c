#include "unity.h"
#include "Stack.h"
#include "CException.h"
#include "Exception.h"
#include "Token.h"
#include "mock_Tokenizer.h"
//#include "ShuntingYard.h"
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
  Stack *stack1=NULL; // = malloc(sizeof *Stack);
  printf("stack1: %d\n",stack1);
  printf("%d\n",&stack1);
  push(stack1,(void *)19 );
  push(stack1,(void *)25 );
  printf("%d\n",stack1);
  TEST_ASSERT_EQUAL(25,pop(stack1));
  TEST_ASSERT_EQUAL(19, pop(stack1));
}

/*void test_push_add_and_pop_add(void)
{
  Stack *operator = NULL;
  push(operator ,"+");
  TEST_ASSERT_EQUAL_STRING("+",pop(operator));
}

void test_push_Token_into_stack(void)
{
  Stack *stack = NULL;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE , "777", 44};
  push(stack,&inttoken);
  TEST_ASSERT_EQUAL(&inttoken,pop(stack));
}

void test_push_Token_into_stack_op(void)
{
  Stack *stack= NULL;
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE ,"+", };
  push(stack,&optoken);
  TEST_ASSERT_EQUAL(&optoken,pop(stack));
}*/

/*void test_push_double_stack_19_and_pop_double_19(void)
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
}*/

void xtest_randomtest(void)
{
   char str[30] = "20.200 This is test ";
   char *ptr;
   double ret;

   ret = strtod(str, &ptr);
   printf("The number(double) is %lf\n", ret);
   printf("String part is |%s|", ptr);
}
