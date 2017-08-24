#ifndef _SHUNTINGYARD_H
#define _SHUNTINGYARD_H
#include "Token.h"
#include "Tokenizer.h"
#include "Stack.h"

Token *createNumberToken(int number);
Token* shuntingYard(char *expression, double *result);
void evaluateOperatorToken(Stack **operator ,OperatorToken *newToken);

//double computeExpression(Stack *operand , Stack *operators);

#endif // _SHUNTINGYARD_H
