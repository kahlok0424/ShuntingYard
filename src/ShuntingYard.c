#include <stdio.h>
#include <stdlib.h>
#include "ShuntingYard.h"
#include "Token.h"
#include "Stack.h"
#include "Tokenizer.h"
#include "Token.h"
#include "CException.h"

#define SAMETOKEN 1
#define NULLTOKEN 2

typedef enum {
    OPERATOR_OTHER,
    OPERATOR_UNARY,
    OPERATOR_BINARY
} OperatorArity;

typedef enum {
    OPERATOR_NONE,
    OPERATOR_LEFT,
    OPERATOR_RIGHT
} OperatorAssociativity;

typedef struct {
    char symbol;
    int precedence;
    OperatorArity arity;
    OperatorAssociativity associativity;
} Operator;

static const Operator OPERATORS[] = {
//  {'!', 1, OPERATOR_UNARY,  OPERATOR_LEFT},
//    {'^', 2, OPERATOR_BINARY, OPERATOR_RIGHT},
//    {'+', 3, OPERATOR_UNARY,  OPERATOR_RIGHT},
//    {'-', 3, OPERATOR_UNARY,  OPERATOR_RIGHT},
    {'*', 4, OPERATOR_BINARY, OPERATOR_LEFT},
    {'/', 4, OPERATOR_BINARY, OPERATOR_LEFT},
    {'%', 4, OPERATOR_BINARY, OPERATOR_LEFT},
    {'+', 5, OPERATOR_BINARY, OPERATOR_LEFT},
//    {'-', 5, OPERATOR_BINARY, OPERATOR_LEFT},
//    {'(', 6, OPERATOR_OTHER,  OPERATOR_NONE}
};

Token* shuntingYard(char *expression, double *result)
{
  Stack *operand = NULL ,*operator = NULL;
  Tokenizer *tokenizer = initTokenizer(expression);
  IntegerToken *inttoken, *testToken;
  OperatorToken *optoken;
  Token *currentToken = peepToken(tokenizer);
  Token *token ;

  while(currentToken->type != TOKEN_NULL_TYPE)
  {
    currentToken = peepToken(tokenizer);
    if(currentToken->type != token->type)
    {
      token = getToken(tokenizer);
      if(token->type == TOKEN_INTEGER_TYPE)
      {
        inttoken = (IntegerToken *)token;
        push(&operand,(const void *)inttoken);
        printf("Integer Token Value = %d \n" , inttoken->value);
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

  int testresult = computeExpression(&operand,&operator);
  result = &testresult;
  printf("result :%d \n",*result);
  testToken =(IntegerToken *)pop(&operand);
  printf("Test Token value = %d\n",testToken->value);
  return testToken;

  if(currentToken->type == TOKEN_NULL_TYPE){
    Throw(createException("NULL Token detected! End of expression." \
                       , NULLTOKEN)); }
}

double computeExpression(Stack *operand , Stack *operators)
{
  IntegerToken *number, *number2, *result;
  OperatorToken *op;
  number =(IntegerToken *)pop(operand);
  number2 =(IntegerToken *)pop(operand);
  op =(OperatorToken *)pop(operators);

  int y = number->value;
  int x = number2->value;
  char z= *(op->str);
  //char *operator = &z;

  printf("X = %d\n",x);
  printf("y = %d\n",y);
  printf("op = %c\n",z);

  switch(z){
  case '+':
  x= x + y;
  break;

  case '-':
  x = x - y;
  break;

  case '*':
  x = x * y;
  break;

  case '/':
  x = x/y;
  break;

  default:
  return 0;
  }
  IntegerToken backResult = {TOKEN_INTEGER_TYPE,0,0,"x", 88 };
  push(operand , &backResult);
  printf("Back result address : %d\n",backResult);
  return x;
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
