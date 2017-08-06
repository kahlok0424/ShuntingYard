#include "unity.h"
#include "ShuntingYard.h"
#include "Token.h"
#include "mock_Tokenizer.h"

void setUp(void)
{
}

void tearDown(void)
{
}

 void test_ShuntingYard_NeedToImplement(void)
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
