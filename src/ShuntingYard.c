#include <stdio.h>
#include <stdlib.h>
#include "ShuntingYard.h"
#include "Token.h"
#include "Stack.h"
#include "Tokenizer.h"
#include "Token.h"
#include "CException.h"

#define sameToken 1

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

void shuntingYard(char *expression, double *result)
{
  Stack *operand = NULL ,*operator = NULL;
  Tokenizer *tokenizer = initTokenizer(expression);
  IntegerToken *inttoken;
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
                           , sameToken));
    }
  }
  //return result = 44;
//  *result = test->value;
  //printf("Value of token : %d", test->value);
}

double computeExpression(Stack *operand , Stack *operators)
{
  IntegerToken *number, *number2;
  OperatorToken *op;
//  number =pop(&operand);
//  number2 = pop(&operand);
//  op = pop(&operators);

  int x = number->value;
  int y = number2->value;
  char operator = op->str;

  switch(operator){
  case '+':
  x= x + y;
  break;
  default:
  return 0;
  }
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
