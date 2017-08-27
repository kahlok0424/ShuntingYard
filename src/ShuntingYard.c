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


Token* shuntingYard(char *expression)
{
  Stack *operand = initStack();
  Stack *operator = initStack();
  Tokenizer *tokenizer = initTokenizer(expression);
  IntegerToken *intToken, *resultToken;
  OperatorToken *opToken;
  //Token *currentToken = peepToken(tokenizer);
  Token *token = getToken(tokenizer);
  Token *previousToken;

  while(token->type != TOKEN_NULL_TYPE)
  {
    //previousToken = token;
    if(token->type != previousToken->type)
    {
      if(token->type == TOKEN_INTEGER_TYPE)
      {
        intToken = (IntegerToken *)token;
        push(&operand,(const void *)intToken);
      }
      else if(token->type == TOKEN_OPERATOR_TYPE)
      {
        opToken = (OperatorToken *)token;
        evaluateOperatorToken(&operator,&operand,opToken);
      }
    }
    else
    {
      Throw(createException("Invalid Token ,token is the same type of previous!" \
                           , SAMETOKEN));
    }
    token = getToken(tokenizer);
  }

  //computeExpression(&operand,);
  //result = &testresult;
  //printf("result :%d \n",*result);
  resultToken =(IntegerToken *)pop(&operand);
  //printf("Test Token value = %d\n",testToken->value);
  return token;

  if(token->type == TOKEN_NULL_TYPE){
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
     //printf("It goes to here");
     push(operator , newToken);
     }
  else{
    computeExpression(operand,previousToken);
    push(operator , newToken);
    }
  }
}
