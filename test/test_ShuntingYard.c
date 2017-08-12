#include "unity.h"
#include "ShuntingYard.h"
#include "Token.h"
#include "mock_Tokenizer.h"
#include "Stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_get_integerToken(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,11 ,4 , "44", 44};
  Token *token;

  getToken_ExpectAndReturn(tokenizer , (Token *)&inttoken);

  token = getToken(tokenizer);
  TEST_ASSERT_EQUAL_STRING("44" ,token->str);
}

void test_get_integer_and_put_in_intToken(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,11 ,4 , "44", 44};
  Token *token;
  IntegerToken *intToken1;

  getToken_ExpectAndReturn(tokenizer , (Token *)&inttoken);

  token = getToken(tokenizer);
  intToken1 = (IntegerToken *)token;
  TEST_ASSERT_EQUAL(44, intToken1->value);
}

void test_get_operator_and_put_in_opToken(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE ,11 ,4 , "+", };
  Token *token;
  OperatorToken *opToken1;

  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken);

  token = getToken(tokenizer);
  opToken1 = (OperatorToken *)token;
  TEST_ASSERT_EQUAL_STRING("+" ,opToken1->str);
}

void test_ShuntingYard_get_integer_token(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,11 ,4 , "44" , 44};
  Token *token;
  char *expression = " 44 ";

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);

  double *result;
  shuntingYard(expression , &result);
  TEST_ASSERT_EQUAL(44 , *result);
}

void test_ShuntingYard_get_operator_token(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken2 = {TOKEN_OPERATOR_TYPE ,11 ,4 , "*" };
  Token *token;
  char *expression = "* ";

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken2);

  double *result;
  shuntingYard(expression , &result);
  TEST_ASSERT_EQUAL("*" , result);
}

/*void xtest_ShuntingYard_get_integer_token(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE ,11 ,4 , "+", };
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,11 ,4 , "44",44};
  Token *token;
  IntegerToken *intToken1;
  OperatorToken *opToken1;

  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken);

  token = getToken(tokenizer);
  opToken1 = (OperatorToken *)token;
  intToken1 =(IntegerToken *)token;
  TEST_ASSERT_EQUAL_STRING(opToken1->str,"+");
  TEST_ASSERT_EQUAL(intToken1->value,44);
}*/

 void xtest_ShuntingYard(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,11 ,4 , "22",22};
  IntegerToken inttoken1 = {TOKEN_INTEGER_TYPE ,15 ,4 , "44",44};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE ,13 , 2 , "+" , };

  initTokenizer_ExpectAndReturn("22+44",tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&inttoken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&optoken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&inttoken1);

}
