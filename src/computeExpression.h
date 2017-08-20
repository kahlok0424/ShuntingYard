#ifndef _COMPUTEEXPRESSION_H
#define _COMPUTEEXPRESSION_H
#include "Token.h"
#include "Tokenizer.h"
#include "Stack.h"

Token *createNumberToken(int number);
void computeExpression(Stack *operand , OperatorToken *operators);
int calculate(OperatorToken *operator ,IntegerToken *firstNumber,IntegerToken *secondNumber);

#endif // _COMPUTEEXPRESSION_H
