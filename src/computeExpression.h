#ifndef _COMPUTEEXPRESSION_H
#define _COMPUTEEXPRESSION_H
#include "Token.h"
#include "Tokenizer.h"
#include "Stack.h"

Token *createNumberToken(int number);
void computeExpression(Stack **operand , OperatorToken *operators);
void computeInfix(Stack **operand , OperatorToken *operators);
void computePrefix(Stack **operand , OperatorToken *operators);
int calculate(OperatorToken *operator ,IntegerToken *firstNumber,IntegerToken *secondNumber);
int calculatePrefix(OperatorToken *operator ,IntegerToken *firstNumber);

#endif // _COMPUTEEXPRESSION_H
