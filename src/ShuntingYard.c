#include <stdio.h>
#include <stdlib.h>
#include "ShuntingYard.h"
#include "Token.h"
#include "Stack.h"
#include "Tokenizer.h"
#include "CException.h"
#include "computeExpression.h"

#define SAMETOKEN 1
#define NULLTOKEN 2


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
  return token;

  if(currentToken->type == TOKEN_NULL_TYPE){
    Throw(createException("NULL Token detected! End of expression." \
                       , NULLTOKEN)); }
}

void evaluateOperatorToken(Stack **operator ,Stack **operand,OperatorToken *newToken)
{
  OperatorToken *previousToken;
  previousToken = (OperatorToken *)pop(operator);

  if(previousToken == NULL){
    push(operator , newToken);
  }
  else{
   if(newToken->info->precedence > previousToken->info->precedence){
     printf("lol");
     }
  else{
    computeExpression(operand,previousToken);
    }
  }
}
