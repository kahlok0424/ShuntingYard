#ifndef _SHUNTINGYARD_H
#define _SHUNTINGYARD_H
#include "Token.h"
#include "Tokenizer.h"
#include "Stack.h"

void shuntingYard(char *expression, double *result);

void push_double(Stack **operands , double x);

#endif // _SHUNTINGYARD_H
