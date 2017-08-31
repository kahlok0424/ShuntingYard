#include "unity.h"
#include "computeExpression.h"
#include "Token.h"
#include "Operator.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "Stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_createNumberToken_10(void)
{
  Token *token;
  IntegerToken *intToken;
  token = createNumberToken(10);
  intToken =(IntegerToken *)token;

  TEST_ASSERT_EQUAL(10,intToken->value);
}

void test_calculate_100_add_58(void)
{
  IntegerToken intToken = {TOKEN_INTEGER_TYPE, "100", 100};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE, "58", 58};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "+",&OPERATORS_TABLE[0] };

  //TEST_ASSERT_EQUAL(8,calculate(&opToken,&intToken2,&intToken));
  TEST_ASSERT_EQUAL(158,calculate(&opToken,&intToken2,&intToken));
}

void test_calculate_40_minus_20(void)
{
  IntegerToken intToken = {TOKEN_INTEGER_TYPE, "40", 40};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE, "20", 20};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "-", &OPERATORS_TABLE[1]};

  //TEST_ASSERT_EQUAL(8,calculate(&opToken,&intToken2,&intToken));
  TEST_ASSERT_EQUAL(20,calculate(&opToken,&intToken2,&intToken));
}

void test_calculate_6_multiply_2(void)
{
  IntegerToken intToken = {TOKEN_INTEGER_TYPE, "6", 6};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE, "2", 2};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };

  //TEST_ASSERT_EQUAL(200,calculate(&opToken,&intToken2,&intToken));
  TEST_ASSERT_EQUAL(12,calculate(&opToken,&intToken2,&intToken));
}

void test_calculate_80_divide_2(void)
{
  IntegerToken intToken = {TOKEN_INTEGER_TYPE, "80", 80};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE, "2", 2};
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "/", &OPERATORS_TABLE[3]};

  //TEST_ASSERT_EQUAL(200,calculate(&opToken,&intToken2,&intToken));
  TEST_ASSERT_EQUAL(40,calculate(&opToken,&intToken2,&intToken));
}

void test_computeInfix_50_add_30(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE, "50", 50};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE, "30", 30};
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "+",&OPERATORS_TABLE[0] };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &plusToken);

  computeInfix(&operand ,&plusToken);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  TEST_ASSERT_EQUAL(80, result->value );
}

void test_computeInfix_77_minus_7(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE, "77", 77};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE, "7", 7};
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "-",&OPERATORS_TABLE[1] };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &plusToken);

  computeInfix(&operand ,&plusToken);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  TEST_ASSERT_EQUAL(70, result->value );
}

void test_computeInfix_25_mul_5_expect_125(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE, "25", 25};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE, "5", 5};
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &plusToken);

  computeInfix(&operand ,&plusToken);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  TEST_ASSERT_EQUAL(125, result->value );
}

void test_computeInfix_90_divide_2(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE, "90", 90};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE, "2", 2};
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "/",&OPERATORS_TABLE[3] };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &plusToken);

  computeInfix(&operand ,&plusToken);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  TEST_ASSERT_EQUAL(45, result->value );
}

void test_computeExpression_4_add_4_expect_8(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE, "4", 4};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE, "4", 4};
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "+",&OPERATORS_TABLE[0] };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &plusToken);

  computeExpression(&operand ,&plusToken);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  TEST_ASSERT_EQUAL(8, result->value );
}

void test_computeExpression_10_minus_4_expect_6(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,"10", 10};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE ,"4", 4};
  OperatorToken minusToken = {TOKEN_OPERATOR_TYPE , "-",&OPERATORS_TABLE[1] };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &minusToken);

  computeExpression(&operand ,&minusToken);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  TEST_ASSERT_EQUAL(6, result->value );
}

void test_computeExpression_3_multiply_3_expect_9(void)
{
  Stack *operand, *operator;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"3", 3};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE , "3", 3};
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };

  push(&operand,&intToken);
  push(&operand, &intToken2);
  push(&operator, &mulToken);

  computeExpression(&operand ,&mulToken);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  TEST_ASSERT_EQUAL(9, result->value );
}

void test_computeExpression_60_divide_2_expect_30(void)
{
  Stack *operand, *operator;
  IntegerToken intToken60 = {TOKEN_INTEGER_TYPE ,"60", 60};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE , "2", 2};
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE , "/",&OPERATORS_TABLE[3] };

  push(&operand,&intToken60);
  push(&operand, &intToken2);
  push(&operator, &divToken);

  computeExpression(&operand ,&divToken);
  IntegerToken *result =(IntegerToken *)pop(&operand);
  TEST_ASSERT_EQUAL(30, result->value );
}
