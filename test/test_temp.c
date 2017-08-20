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

void test_ShuntingYard_simple_expression_add(void)
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
}
