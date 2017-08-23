#include "unity.h"
#include "computeExpression.h"
#include "Token.h"
#include "Tokenizer.h"
#include "Stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_computeExpression_createNumberToken(void)
{
  Token *token;
  IntegerToken *intToken;
  token = createNumberToken(10);
  intToken =(IntegerToken *)token;

  TEST_ASSERT_EQUAL(10,intToken->value);
}

void test_computeExpression_calculate_100_add_58(void)
{
  IntegerToken intToken = {TOKEN_INTEGER_TYPE, "100", 100};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE, "58", 58};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "+", };

  //TEST_ASSERT_EQUAL(8,calculate(&opToken,&intToken2,&intToken));
  TEST_ASSERT_EQUAL(158,calculate(&opToken,&intToken2,&intToken));
}

void test_computeExpression_calculate_40_minus_20(void)
{
  IntegerToken intToken = {TOKEN_INTEGER_TYPE, "40", 40};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE, "20", 20};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "-", };

  //TEST_ASSERT_EQUAL(8,calculate(&opToken,&intToken2,&intToken));
  TEST_ASSERT_EQUAL(20,calculate(&opToken,&intToken2,&intToken));
}

void test_computeExpression_calculate_6_multiply_2(void)
{
  IntegerToken intToken = {TOKEN_INTEGER_TYPE, "6", 6};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE, "2", 2};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "*", };

  //TEST_ASSERT_EQUAL(200,calculate(&opToken,&intToken2,&intToken));
  TEST_ASSERT_EQUAL(12,calculate(&opToken,&intToken2,&intToken));
}

void test_computeExpression_calculate_80_divide_2(void)
{
  IntegerToken intToken = {TOKEN_INTEGER_TYPE, "80", 80};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE, "2", 2};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "/", };

  //TEST_ASSERT_EQUAL(200,calculate(&opToken,&intToken2,&intToken));
  TEST_ASSERT_EQUAL(40,calculate(&opToken,&intToken2,&intToken));
}

void test_computeExpression_4_add_4_expect_8(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE, "4", 4};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE, "4", 4};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE , "+", };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &optoken);

  IntegerToken *result =(IntegerToken *)pop(&operand);
  //TEST_ASSERT_EQUAL(8,computeExpression(&operand ,&operator));
}

void test_computeExpression_10_minus_4_expect_6(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,"10", 10};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE ,"5", 5};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE , "-", };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &optoken);

  IntegerToken *result =(IntegerToken *)pop(&operand);
  //TEST_ASSERT_EQUAL(5,computeExpression(&operand ,&operator));
}

void test_computeExpression_3_multiply_3_expect_9(void)
{
  Stack *operand, *operator;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"3", 3};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE , "3", 3};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "*", };

  push(&operand,&intToken);
  push(&operand, &intToken2);
  push(&operator, &opToken);
//  printf("& of operand in test: %d\n",&operand);
  computeExpression(&operand ,&opToken);
  //printf("value operand in test after compute: %d\n",&operand);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  //printf("address of result in test: %d\n",&result);
//  printf("value of result in test: %d\n",result);
  //TEST_ASSERT_EQUAL(9, result->value );
}

void test_computeExpression_100_divide_5_expect_20(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,"100", 100};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE ,"5", 5};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE ,"/", };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &optoken);

  IntegerToken *result =(IntegerToken *)pop(&operand);
  //TEST_ASSERT_EQUAL(20,computeExpression(&operand ,&operator));
}
