#include <stdio.h>
#include <stdlib.h>
#include "ShuntingYard.h"
#include "Token.h"
#include "Stack.h"
#include "Tokenizer.h"
#include "Token.h"

void shuntingYard(char *expression, double *result)
{
  Stack *operand = NULL ,*operator = NULL;
  Tokenizer *tokenizer = initTokenizer(expression);
  Token *token = getToken(tokenizer);
  IntegerToken *inttoken;
  OperatorToken *optoken;

  if(token->type == TOKEN_INTEGER_TYPE)
  {
    inttoken = (IntegerToken *)token;
    push_double(&operand,inttoken->value);
    printf("Enter here %d \n" , inttoken->value);
  }
  else if(token->type == TOKEN_OPERATOR_TYPE)
  {
    optoken = (OperatorToken *)token;
    push(&operator,(int *)optoken->str);
  }
  *result = pop_double(&operand);
  printf("Value of result : %d" , *result);

}


/*typedef enum {
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
};*/

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
