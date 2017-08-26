#include <stdlib.h>
#include <stdio.h>
#include "computeExpression.h"
#include "Token.h"
#include "Tokenizer.h"
#include "Stack.h"

Token *createNumberToken(int number)
{
	IntegerToken *newToken = malloc (sizeof(IntegerToken));
	newToken->type = TOKEN_INTEGER_TYPE;
	newToken->value=number;

	return (Token*)newToken;
}

void computeExpression(Stack **operand , OperatorToken *operator)
{
	//printf("value operand in before  compute: %d\n",operand);
  int answer;
  IntegerToken *number, *number2;
  //Token *newResult;
  number =(IntegerToken *)pop(operand);
  number2 =(IntegerToken *)pop(operand);

  answer = calculate(operator,number,number2);
  IntegerToken *newResult =(IntegerToken *)createNumberToken(answer);
	//printf("address of new result: %d\n",&newResult);
	printf("newResult : %d\n",newResult->value);
  push(operand , &newResult);
	IntegerToken *result = (IntegerToken *)pop(operand);
	printf("result: %d\n",result->value);
  //printf("Answer : %d\n",answer);
//	printf("value operand after compute: %d\n",*operand);
}

int calculate(OperatorToken *operator, IntegerToken *number,IntegerToken *number2)
{
  int y = number->value;
  int x = number2->value;
  char z= *(operator->str);

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
  return x;
}
