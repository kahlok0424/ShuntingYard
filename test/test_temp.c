#include "unity.h"
#include "ShuntingYard.h"
#include "Token.h"
#include "mock_Tokenizer.h"
#include "Stack.h"
#include "Exception.h"
#include "computeExpression.h"
#include "Operator.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*void xtest_ShuntingYard_simple_expression_add(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken1 = {TOKEN_OPERATOR_TYPE ,"+", };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "5+5";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression , result);
  }Catch(ex){
    dumpException(ex);
  }
  printf("lallala : %d\n", testToken->value);
  TEST_ASSERT_EQUAL(10,*result);
}*/

/*void xtest_evaluateOperatorToken_with_compute_expression(void)
{
  Stack *operator;
  Stack *operand;
  operator = initStack();
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "+",&OPERATORS_TABLE[0] };
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"10",10 };

  push(&operand,&intToken);
  push(&operand,&intToken1);
  push(&operator,&mulToken);

  CEXCEPTION_T ex;
  Try{
    evaluateOperatorToken(&operator,&operand,&plusToken);
    IntegerToken *result;
  	result = (IntegerToken *)pop(&operand);
    TEST_ASSERT_EQUAL(50, result->value);
  }Catch(ex){
    dumpException(ex);
  }
}*/

void test_ShuntingYard_simple_expression_add_1(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  FloatToken fToken = {TOKEN_FLOAT_TYPE,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "5+5";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  printf("Token returned from SY : %d\n", testToken->value);
  //TEST_ASSERT_EQUAL(10,*result);
}

void test_ShuntingYard_simple_expression_add_10(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  FloatToken fToken = {TOKEN_FLOAT_TYPE,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "5+5+10";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  printf("Token returned from SY : %d\n", testToken->value);
  //TEST_ASSERT_EQUAL(10,*result);
}

void test_ShuntingYard_simple_expression_mul_10(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  FloatToken fToken = {TOKEN_FLOAT_TYPE,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "5+5*10";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&mulToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  printf("Token returned from SY : %d\n", testToken->value);
  //TEST_ASSERT_EQUAL(10,*result);
}
