#include "unity.h"
#include "ShuntingYard.h"
#include "Token.h"
#include "mock_Tokenizer.h"
#include "Stack.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "computeExpression.h"
#include "Operator.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_get_integerToken(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE , "44", 44};
  Token *token;

  getToken_ExpectAndReturn(tokenizer , (Token *)&inttoken);

  token = getToken(tokenizer);
  //TEST_ASSERT_EQUAL_STRING("44" ,token->str);
}

void test_get_integer_and_put_in_intToken(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE , "44", 44};
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
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "+",&OPERATORS_TABLE[0] };
  Token *token;
  OperatorToken *opToken1;

  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken);

  token = getToken(tokenizer);
  opToken1 = (OperatorToken *)token;
  //TEST_ASSERT_EQUAL_STRING("+" ,opToken1->str);
}

/*void test_ShuntingYard_get_integer_token(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  IntegerToken intToken = {TOKEN_INTEGER_TYPE , "44" , 44};
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"44" , 44};
  Token *token;
  char *expression = " 44 ";
  IntegerToken *resultToken;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    resultToken = shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
//  TEST_ASSERT_EQUAL(44 , *result);
}

void test_ShuntingYard_get_operator_token(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE, "*",&OPERATORS_TABLE[2] };
  OperatorToken nullToken = {TOKEN_NULL_TYPE, "*" };
  Token *token;
  char *expression = "* ";
  IntegerToken *resultToken;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken);
  getToken_ExpectAndReturn(tokenizer ,(Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    resultToken = shuntingYard(expression);
  //  TEST_ASSERT_EQUAL("*" , result);
  }Catch(ex){
    dumpException(ex);
  }

}

void test_ShuntingYard_same_token_expect_Exception(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken1 = {TOKEN_OPERATOR_TYPE, "*",&OPERATORS_TABLE[2] };
  OperatorToken opToken2 = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };
  OperatorToken nullToken = {TOKEN_NULL_TYPE,""};
  Token *token;
  char *expression = "**";
  IntegerToken *resultToken;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  //getToken_ExpectAndReturn(tokenizer , (Token *)&opToken3);

  CEXCEPTION_T ex;
  Try{
    resultToken = shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  //TEST_ASSERT_EQUAL_STRING()
}

void test_ShuntingYard_NULL_token_expect_Exception(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken1 = {TOKEN_OPERATOR_TYPE, "*",&OPERATORS_TABLE[2] };
  OperatorToken opToken2 = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  char *expression = "**";
  IntegerToken *resultToken;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  getToken_ExpectAndReturn(tokenizer , (Token *)&opToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    resultToken = shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
}*/

void test_evaluateOperatorToken_give_operator_token(void)
{
  Stack *operator;
  Stack *operand;
  operator = initStack();
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"10",10 };

  push(&operand,&intToken);
  push(&operand,&intToken1);

  CEXCEPTION_T ex;
  Try{
    evaluateOperatorToken(&operator,&operand,&mulToken);
  }Catch(ex){
    dumpException(ex);
  }

}

void test_evaluateOperatorToken_give_lower_precedence_operator(void)
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
  }Catch(ex){
    dumpException(ex);
  }
}

void test_evaluateOperatorToken_give_higher_precedence_operator(void)
{
  Stack *operator;
  Stack *operand;
  operator = initStack();
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE , "*", &OPERATORS_TABLE[2] };
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "+", &OPERATORS_TABLE[0] };
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"10",10 };

  push(&operand,&intToken);
  push(&operand,&intToken1);
  push(&operator,&plusToken);

  CEXCEPTION_T ex;
  Try{
    evaluateOperatorToken(&operator,&operand,&mulToken);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_evaluateOperatorToken_with_compute_expression_10_mul_5(void)
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
}

void test_evaluateOperatorToken_with_compute_expression_2_add_5(void)
{
  Stack *operator;
  Stack *operand;
  operator = initStack();
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "+",&OPERATORS_TABLE[0] };
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };

  push(&operand,&intToken);
  push(&operand,&intToken1);
  push(&operator,&mulToken);

  CEXCEPTION_T ex;
  Try{
    evaluateOperatorToken(&operator,&operand,&plusToken);
    IntegerToken *result;
  	result = (IntegerToken *)pop(&operand);
    TEST_ASSERT_EQUAL(10, result->value);
  }Catch(ex){
    dumpException(ex);
  }
}

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
  //printf("Token returned from SY : %d\n", testToken->value);
  TEST_ASSERT_EQUAL(10,testToken->value);
}

void test_ShuntingYard_simple_expression_add_10(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
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
  //printf("Token returned from SY : %d\n", testToken->value);
  TEST_ASSERT_EQUAL(20,testToken->value);
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
  //printf("Token returned from SY : %d\n", testToken->value);
  TEST_ASSERT_EQUAL(55,testToken->value);
}

/*void xtest_ShuntingYard_get_integer_token(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken opToken = {TOKEN_OPERATOR_TYPE , "+", };
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"44",44};
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
  IntegerToken inttoken = {TOKEN_INTEGER_TYPE ,"22",22};
  IntegerToken inttoken1 = {TOKEN_INTEGER_TYPE ,"44",44};
  OperatorToken optoken = {TOKEN_OPERATOR_TYPE ,"+" , };

  initTokenizer_ExpectAndReturn("22+44",tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&inttoken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&optoken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&inttoken1);

}
