#include "unity.h"
#include "ShuntingYard.h"
#include "Token.h"
#include "mock_Tokenizer.h"
#include "Stack.h"
#include "Exception.h"

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
  //TEST_ASSERT_EQUAL_STRING("44" ,token->str);
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
  //TEST_ASSERT_EQUAL(44, intToken1->value);
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
  //TEST_ASSERT_EQUAL_STRING("+" ,opToken1->str);
}

void test_ShuntingYard_get_integer_token(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,11 ,4 , "44" , 44};
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,11 ,4 , "44" , 44};
  Token *token;
  char *expression = " 44 ";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&intToken);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken);
  peepToken_ExpectAndReturn(tokenizer,(Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    shuntingYard(expression , result);
  }Catch(ex){
    dumpException(ex);
  }
//  TEST_ASSERT_EQUAL(44 , *result);
}

void test_ShuntingYard_get_operator_token(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE ,11 ,4 , "*" };
  OperatorToken nullToken = {TOKEN_NULL_TYPE ,11 ,4 , "*" };
  Token *token;
  char *expression = "* ";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer ,(Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    shuntingYard(expression , result);
  //  TEST_ASSERT_EQUAL("*" , result);
  }Catch(ex){
    dumpException(ex);
  }

}

void test_ShuntingYard_same_token_expect_Exception(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken1 = {TOKEN_OPERATOR_TYPE ,11 ,4 , "*" };
  OperatorToken opToken2 = {TOKEN_OPERATOR_TYPE ,11 ,4 , "*" };
  OperatorToken opToken3 = {TOKEN_NULL_TYPE , 11,4,""};
  Token *token;
  char *expression = "**";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken2);
  //getToken_ExpectAndReturn(tokenizer , (Token *)&opToken3);

  CEXCEPTION_T ex;
  Try{
    shuntingYard(expression , result);
  }Catch(ex){
    dumpException(ex);
  }
  //TEST_ASSERT_EQUAL_STRING()
}

void test_ShuntingYard_NULL_token_expect_Exception(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken1 = {TOKEN_OPERATOR_TYPE ,11 ,4 , "*" };
  OperatorToken opToken2 = {TOKEN_OPERATOR_TYPE ,11 ,4 , "*" };
  IntegerToken nullToken = {TOKEN_NULL_TYPE , 11,4,"bla",0};
  Token *token;
  char *expression = "**";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    shuntingYard(expression , result);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_computeExpression_4_add_4_expect_8(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,11 ,4 , "4", 4};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE ,11 ,4 , "4", 4};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE , 0,0 , "+", };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &optoken);

  TEST_ASSERT_EQUAL(8,computeExpression(&operand ,&operator));
}

void test_computeExpression_10_minus_4_expect_6(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,11 ,4 , "10", 10};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE ,11 ,4 , "5", 5};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE , 0,0 , "-", };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &optoken);

  TEST_ASSERT_EQUAL(5,computeExpression(&operand ,&operator));
}

void test_computeExpression_3_multiply_3_expect_9(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,11 ,4 , "3", 3};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE ,11 ,4 , "3", 3};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE , 0,0 , "*", };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &optoken);

  TEST_ASSERT_EQUAL(9,computeExpression(&operand ,&operator));
}

void test_computeExpression_100_divide_5_expect_20(void)
{
  Stack *operand, *operator;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,11 ,4 , "100", 100};
  IntegerToken inttoken2 = {TOKEN_INTEGER_TYPE ,11 ,4 , "5", 5};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE , 0,0 , "/", };

  push(&operand,&inttoken);
  push(&operand, &inttoken2);
  push(&operator, &optoken);

  TEST_ASSERT_EQUAL(20,computeExpression(&operand ,&operator));
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
