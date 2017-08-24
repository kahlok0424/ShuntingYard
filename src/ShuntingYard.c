#include <stdio.h>
#include <stdlib.h>
#include "ShuntingYard.h"
#include "Token.h"
#include "Stack.h"
#include "Tokenizer.h"
#include "Token.h"
#include "CException.h"
#include "computeExpression.h"

#define SAMETOKEN 1
#define NULLTOKEN 2

typedef struct {
    char symbol;
    int precedence;
    Affix affix;
    Associativity assoc;
} Operator;

static const Operator OPERATORS[] = {
//  {'!', 1, OPERATOR_UNARY,  OPERATOR_LEFT},
//    {'^', 2, OPERATOR_BINARY, OPERATOR_RIGHT},
//    {'+', 3, OPERATOR_UNARY,  OPERATOR_RIGHT},
//    {'-', 3, OPERATOR_UNARY,  OPERATOR_RIGHT},
    {'*', 4, INFIX, LEFT_TO_RIGHT},
    {'/', 4, INFIX, LEFT_TO_RIGHT},
    {'%', 4, INFIX, LEFT_TO_RIGHT},
    {'+', 5, INFIX, LEFT_TO_RIGHT},
//    {'-', 5, OPERATOR_BINARY, OPERATOR_LEFT},
//    {'(', 6, OPERATOR_OTHER,  OPERATOR_NONE}
};

Token* shuntingYard(char *expression, double *result)
{
  Stack *operand = NULL ,*operator = NULL;
  Tokenizer *tokenizer = initTokenizer(expression);
  IntegerToken *intToken, *testToken;
  OperatorToken *optoken;
  Token *currentToken = peepToken(tokenizer);
  Token *token;

  while(currentToken->type != TOKEN_NULL_TYPE)
  {
    currentToken = peepToken(tokenizer);
    if(currentToken->type != token->type)
    {
      token = getToken(tokenizer);
      if(token->type == TOKEN_INTEGER_TYPE)
      {
        intToken = (IntegerToken *)token;
        push(&operand,(const void *)intToken);
        //printf("Integer Token Value = %d \n" , intToken->value);
      }
      else if(token->type == TOKEN_OPERATOR_TYPE)
      {
        optoken = (OperatorToken *)token;
        push(&operator,(const void *)optoken);
      //  printf("Operator Token = %s\n",optoken->str);
      }
    }
    else
    {
      Throw(createException("Invalid Token ,token is the same type of previous!" \
                           , SAMETOKEN));
    }
  }

  //computeExpression(&operand,);
  //result = &testresult;
  //printf("result :%d \n",*result);
  testToken =(IntegerToken *)pop(&operand);
  //printf("Test Token value = %d\n",testToken->value);
  return testToken;

  if(currentToken->type == TOKEN_NULL_TYPE){
    Throw(createException("NULL Token detected! End of expression." \
                       , NULLTOKEN)); }
}

void evaluateOperatorToken(Stack **operator ,OperatorToken *newToken)
{
  OperatorToken *previousToken;
  previousToken = (OperatorToken *)pop(operator);

  if(previousToken == NULL){
    push(operator , newToken);
  }
  else{
    Throw(createException("error" \
                         , SAMETOKEN));
  }

}
