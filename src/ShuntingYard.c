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
        printf("Integer Token Value = %d \n" , intToken->value);
      }
      else if(token->type == TOKEN_OPERATOR_TYPE)
      {
        optoken = (OperatorToken *)token;
        push(&operator,(const void *)optoken);
        printf("Operator Token = %s\n",optoken->str);
      }
    }
    else
    {
      Throw(createException("Invalid Token ,token is the same type of previous!" \
                           , SAMETOKEN));
    }
  }

  computeExpression(&operand,);
  result = &testresult;
  printf("result :%d \n",*result);
  testToken =(IntegerToken *)pop(&operand);
  printf("Test Token value = %d\n",testToken->value);
  return testToken;

  if(currentToken->type == TOKEN_NULL_TYPE){
    Throw(createException("NULL Token detected! End of expression." \
                       , NULLTOKEN)); }
}

/*void push_operator(const Operator *operator, Stack **operands,
                     Stack **operators) {
    if (!operator)
        return ERROR_SYNTAX;

    while (*operators && status == OK) {
        const Operator *stack_operator = stack_top(*operators);
        if (operator->arity == OPERATOR_UNARY ||
                operator->precedence < stack_operator->precedence ||
                (operator->associativity == OPERATOR_RIGHT &&
                 operator->precedence == stack_operator->precedence))
            break;

        apply_operator(stack_pop(operators), operands);
    }
    stack_push(operators, operator);
    return result;
}


void push_number(const char *value, Stack **operands) {
    char *end_pointer = NULL;
    double x = strtod(value, &end_pointer);

    // If not all of the value is converted, the rest is invalid.
    if (value + strlen(value) != end_pointer)
        return ERROR_SYNTAX;
    push_double(x, operands);
    return OK;
}*/
