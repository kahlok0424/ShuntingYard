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

    evaluateOperatorToken(&operator,&operand,&mulToken);
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

    evaluateOperatorToken(&operator,&operand,&plusToken);
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

    evaluateOperatorToken(&operator,&operand,&mulToken);
}

void test_evaluateOperatorToken_with_computeExpression_10_mul_5(void)
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

    evaluateOperatorToken(&operator,&operand,&plusToken);
    IntegerToken *result;
  	result = (IntegerToken *)pop(&operand);
    TEST_ASSERT_EQUAL(50, result->value);
}

void test_evaluateOperatorToken_with_computeExpression_2_add_5(void)
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

    evaluateOperatorToken(&operator,&operand,&plusToken);
    IntegerToken *result;
  	result = (IntegerToken *)pop(&operand);
    TEST_ASSERT_EQUAL(10, result->value);
}

void test_evaluateStack_2_add_2_add_2_add_2_expect_8(void)
{
  Stack *operator = initStack();
  Stack *operand = initStack();
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE , "+",&OPERATORS_TABLE[0] };
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"2",2 };

  push(&operand,&intToken);
  push(&operand,&intToken);
  push(&operand,&intToken);
  push(&operand,&intToken);
  push(&operator,&plusToken);
  push(&operator,&plusToken);
  push(&operator,&plusToken);

    evaluateStack(&operator,&operand);
    IntegerToken *result;
  	result = (IntegerToken *)pop(&operand);
    TEST_ASSERT_EQUAL(8, result->value);

}

void test_evaluateStack_2_mul_2_mul_2_mul_2_expect_16(void)
{
  Stack *operator = initStack();
  Stack *operand = initStack();
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE , "*",&OPERATORS_TABLE[2] };
  IntegerToken intToken = {TOKEN_INTEGER_TYPE ,"2",2 };

  push(&operand,&intToken);
  push(&operand,&intToken);
  push(&operand,&intToken);
  push(&operand,&intToken);
  push(&operator,&mulToken);
  push(&operator,&mulToken);
  push(&operator,&mulToken);

    evaluateStack(&operator,&operand);
    IntegerToken *result;
  	result = (IntegerToken *)pop(&operand);
    TEST_ASSERT_EQUAL(16, result->value);

}

void test_ShuntingYard_add_expression1(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
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
  TEST_ASSERT_EQUAL(10,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_minus_expression1(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken minusToken = {TOKEN_OPERATOR_TYPE ,"-",&OPERATORS_TABLE[1] };
  IntegerToken intToken10 = {TOKEN_INTEGER_TYPE ,"10",10};
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2};
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "10-2";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken10);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&minusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL(8,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_multiply_expression1(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"3",3};
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "3*3";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken3);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&mulToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken3);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL(9,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_div_expression1(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  IntegerToken intToken99 = {TOKEN_INTEGER_TYPE ,"99",99};
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"3",3};
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "99/3";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken99);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&divToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken3);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL(33,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_mod_expression(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken molToken = {TOKEN_OPERATOR_TYPE ,"%",&OPERATORS_TABLE[4] };
  IntegerToken intToken10 = {TOKEN_INTEGER_TYPE ,"10",10};
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"3",3};
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "10%3";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken10);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&molToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken3);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL(1,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_simple_expression1(void)
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
  TEST_ASSERT_EQUAL(20,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_simple_expression2(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken minusToken = {TOKEN_OPERATOR_TYPE ,"-",&OPERATORS_TABLE[2] };
  IntegerToken intToken4 = {TOKEN_INTEGER_TYPE ,"4",4 };
  IntegerToken intToken8 = {TOKEN_INTEGER_TYPE ,"8",8 };
  IntegerToken intToken10 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "8+10-4";  //answer = 14
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken8);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken10);
  getToken_ExpectAndReturn(tokenizer , (Token *)&minusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken4);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL(14,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_simple_expression3(void)
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
  TEST_ASSERT_EQUAL(55,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_simple_expression4(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  FloatToken fToken = {TOKEN_FLOAT_TYPE,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "5+10/2";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&divToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken3);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL(10,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_simple_expression5(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  OperatorToken molToken = {TOKEN_OPERATOR_TYPE ,"%",&OPERATORS_TABLE[4] };
  IntegerToken intToken1 = {TOKEN_INTEGER_TYPE ,"5",5 };
  IntegerToken intToken9 = {TOKEN_INTEGER_TYPE ,"9",9 };
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  FloatToken fToken = {TOKEN_FLOAT_TYPE,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "5+9%2";  // answer = 9%2 = 1 = 5+1 = 6
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken1);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken9);
  getToken_ExpectAndReturn(tokenizer , (Token *)&molToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken3);
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL(6,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_simple_expression6(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken minusToken = {TOKEN_OPERATOR_TYPE ,"-",&OPERATORS_TABLE[1] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  IntegerToken intToken4 = {TOKEN_INTEGER_TYPE ,"4",4 };
  IntegerToken intToken10 = {TOKEN_INTEGER_TYPE ,"10",10 };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken intToken6 = {TOKEN_INTEGER_TYPE ,"6",6 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "4+10*2-6/2";   //answer should be 4 + (10*2) - (6/2) = 21
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken4);   // 4
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);  //
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);   // +
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken10);  // 10
  getToken_ExpectAndReturn(tokenizer , (Token *)&mulToken);    // *
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);   // 2
  getToken_ExpectAndReturn(tokenizer , (Token *)&minusToken);  // -
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken6);  // 6
  getToken_ExpectAndReturn(tokenizer , (Token *)&divToken);   // /
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);  // 2
  getToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);

  CEXCEPTION_T ex;
  Try{
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL(21,testToken->value);
  printf("%s= %d\n",expression, testToken->value);
}

void test_ShuntingYard_give_2_integer_token_expect_Cexception(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "2 2";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);

  CEXCEPTION_T ex;
  Try{
    printf("%s= ",expression);
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_ShuntingYard_give_2_operator_token_expect_Cexception(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "2+*";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&mulToken);

  CEXCEPTION_T ex;
  Try{
    printf("%s= ",expression);
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_ShuntingYard_give_2_operator_token_expect_Cexception_in_between_expression(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken plusToken = {TOKEN_OPERATOR_TYPE ,"+",&OPERATORS_TABLE[0] };
  OperatorToken minusToken = {TOKEN_OPERATOR_TYPE ,"-",&OPERATORS_TABLE[1] };
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "2+2+/3";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  getToken_ExpectAndReturn(tokenizer , (Token *)&plusToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&divToken);

  CEXCEPTION_T ex;
  Try{
    printf("%s= ",expression);
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_ShuntingYard_give_2_operator_token_expect_Cexception_in_between_expression2(void)
{
  Tokenizer *tokenizer = (Tokenizer *)0x0badface;
  OperatorToken mulToken = {TOKEN_OPERATOR_TYPE ,"*",&OPERATORS_TABLE[2] };
  OperatorToken divToken = {TOKEN_OPERATOR_TYPE ,"/",&OPERATORS_TABLE[3] };
  IntegerToken intToken2 = {TOKEN_INTEGER_TYPE ,"2",2 };
  IntegerToken intToken3 = {TOKEN_INTEGER_TYPE ,"3",3 };
  IntegerToken nullToken = {TOKEN_NULL_TYPE ,"bla",0};
  Token *token;
  IntegerToken *testToken;
  char *expression = "2*/3";
  double *result;

  initTokenizer_ExpectAndReturn( expression , tokenizer);
  getToken_ExpectAndReturn(tokenizer , (Token *)&intToken2);
  peepToken_ExpectAndReturn(tokenizer , (Token *)&nullToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&mulToken);
  getToken_ExpectAndReturn(tokenizer , (Token *)&divToken);
  //getToken_ExpectAndReturn(tokenizer , (Token *)&intToken3);

  CEXCEPTION_T ex;
  Try{
    printf("%s= ",expression);
    testToken = (IntegerToken *)shuntingYard(expression);
  }Catch(ex){
    dumpException(ex);
  }
}
