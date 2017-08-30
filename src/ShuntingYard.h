#ifndef _SHUNTINGYARD_H
#define _SHUNTINGYARD_H
#include "Token.h"
#include "Tokenizer.h"
#include "Stack.h"

Token *createNumberToken(int number);
Token* shuntingYard(char *expression);
void evaluateOperatorToken(Stack **operator ,Stack **operand,OperatorToken *newToken);
void evaluateStack(Stack **operator, Stack **operand);

#endif // _SHUNTINGYARD_H
