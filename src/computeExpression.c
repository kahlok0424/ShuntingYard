#include <stdlib.h>
#include <stdio.h>
#include "computeExpression.h"
#include "Token.h"
//#include "Tokenizer.h"
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
  if(operator->info->affix == PREFIX)
	{
		computePrefix(operand,operator);
	}else{
		computeInfix(operand,operator);
	}
}

void computeInfix(Stack **operand,OperatorToken *operator)
{
	int answer;
  IntegerToken *number, *number2;
  number =(IntegerToken *)pop(operand);
  number2 =(IntegerToken *)pop(operand);

  answer = calculate(operator,number,number2);
  IntegerToken *newResult =(IntegerToken *)createNumberToken(answer);

  push(operand , newResult);
}


void computePrefix(Stack **operand,OperatorToken *operator)
{
	int answer;
  IntegerToken *number, *number2;
  number =(IntegerToken *)pop(operand);

  answer = calculatePrefix(operator,number);
  IntegerToken *newResult =(IntegerToken *)createNumberToken(answer);

  push(operand , newResult);
}

int calculate(OperatorToken *operator, IntegerToken *number,IntegerToken *number2)
{
  int y = number->value;
  int x = number2->value;
  char z= *(operator->str);

/*  printf(" %d",x);     //for development
	printf(" %c ",z);
  printf(" %d = \n",y);*/

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

	case '%':
	x = x%y;
	break;

  default:
  return 0;
  }
  return x;
}

int calculatePrefix(OperatorToken *operator, IntegerToken *number)
{
  int x = number->value;
  char z= *(operator->str);

//  printf("X = %d\n",x);    \
  printf("y = %d\n",y);    \
  printf("op = %c\n",z);   \

  switch(z){
  case '(':
	x = x;

  default:
  return 0;
  }
  return x;
}
