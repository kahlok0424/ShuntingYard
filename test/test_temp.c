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

/*void test_ShuntingYard_simple_expression_add_1(void)
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
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  //printf("Token returned from SY : %d\n", testToken->value);
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
  //printf("Token returned from SY : %d\n", testToken->value);
  //TEST_ASSERT_EQUAL(10,*result);
}

void test_ShuntingYard_simple_expression_mul_10(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  FloatToken fToken = {TOKEN_FLOAT_TYPE,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "5+2*10";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&mulToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken3);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  //printf("Token returned from SY : %d\n", testToken->value);
  TEST_ASSERT_EQUAL(25,testToken->value);
}*/

void test_ShuntingYard_simple_expression_div_10(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  OperatorToken openToken = {TOKEN_OPERATOR_TYPE ,"(",&OPERATORS_TABLE[5] };
  OperatorToken closeToken = {TOKEN_OPERATOR_TYPE ,")",&OPERATORS_TABLE[6] };
  IntegerToken intToken5 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken intToken10 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"3",3 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  FloatToken fToken = {TOKEN_FLOAT_TYPE,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "5*(2+10)+2";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken5);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&mulToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&openToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken10);
  getToken_ExpectAndReturn(tokenizer , (Token *)&closeToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  //printf("Token returned from SY : %d\n", testToken->value);
  TEST_ASSERT_EQUAL(62,testToken->value);
}

void test_ShuntingYard_simple_expression_prefix_2(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  OperatorToken openToken = {TOKEN_OPERATOR_TYPE ,"(",&OPERATORS_TABLE[5] };
  OperatorToken closeToken = {TOKEN_OPERATOR_TYPE ,")",&OPERATORS_TABLE[6] };
  IntegerToken intToken6 = {TOKEN_INTEGER_TYPE ,"6",6 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken intToken10 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"3",3 };
  IntegerToken intToken4 = {TOKEN_INTEGER_TYPE ,"4",4 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "(2+10*4)+6";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&openToken);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken10);
  getToken_ExpectAndReturn(tokenizer , (Token *)&mulToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken4);
  getToken_ExpectAndReturn(tokenizer , (Token *)&closeToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken6);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  //printf("Token returned from SY : %d\n", testToken->value);
  TEST_ASSERT_EQUAL(48,testToken->value);
}

void test_ShuntingYard_simple_expression_prefix_3(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  OperatorToken openToken = {TOKEN_OPERATOR_TYPE ,"(",&OPERATORS_TABLE[5] };
  OperatorToken closeToken = {TOKEN_OPERATOR_TYPE ,")",&OPERATORS_TABLE[6] };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken intToken10 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "(2+10)";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&openToken);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken10);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&closeToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  //printf("Token returned from SY : %d\n", testToken->value);
  TEST_ASSERT_EQUAL(12,testToken->value);
}

/*void test_evaluatePrefix_temp(void)
{
  Stack *operator = initStack();
  Stack *operand = initStack();
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken minusToken = {TOKEN_OPERATOR_TYPE ,"-",&OPERATORS_TABLE[1] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  OperatorToken openToken = {TOKEN_OPERATOR_TYPE ,"(",&OPERATORS_TABLE[5] };
  OperatorToken closeToken = {TOKEN_OPERATOR_TYPE ,")",&OPERATORS_TABLE[6] };
  IntegerToken intToken4 = {TOKEN_INTEGER_TYPE ,"4",4 };
  IntegerToken intToken10 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken intToken6 = {TOKEN_INTEGER_TYPE ,"6",6 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};

  push(&operand,&intToken2);
  push(&operand,&intToken2);
  push(&operand,&intToken2);
  push(&operand,&intToken2);
  push(&operator,&openToken);
  push(&operator,&plusToken);
  push(&operator,&mulToken);
  push(&operator,&plusToken);
  //push(&operator,&closeToken);
  //push(&operator,&plusToken);

    evaluatePrefix(&operator,&operand,&closeToken);
    IntegerToken *result;
  	result = (IntegerToken *)pop(&operand);
    TEST_ASSERT_EQUAL(8, result->value);

}*/
