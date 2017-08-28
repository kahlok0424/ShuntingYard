#ifndef Token_H
#define Token_H

#include <stdint.h>
#include "Common.h"

typedef enum {
  TOKEN_UNKNOWN_TYPE,
  TOKEN_INTEGER_TYPE,
  TOKEN_OPERATOR_TYPE,
  TOKEN_FLOAT_TYPE,
  TOKEN_STRING_TYPE,
  TOKEN_IDENTIFIER_TYPE,
  TOKEN_NULL_TYPE,
} TokenType;

typedef enum {
  NO_AFFIX,
  PREFIX,
  INFIX,
  POSTFIX,
} Affix;

typedef enum {
  NO_ASSOCIATIVITY,
  LEFT_TO_RIGHT,
  RIGHT_TO_LEFT,
} Associativity;

typedef struct {
    char symbol;
    int precedence;
    Affix affix;
    Associativity assoc;
} Operator_info;

Operator_info OPERATORS_TABLE[] = {
//  {'!', 1, OPERATOR_UNARY,  OPERATOR_LEFT},
//    {'^', 2, OPERATOR_BINARY, OPERATOR_RIGHT},
    {'+', 3, INFIX, LEFT_TO_RIGHT},
    {'-', 3, INFIX, LEFT_TO_RIGHT},
    {'*', 4, INFIX, LEFT_TO_RIGHT},
    {'/', 4, INFIX, LEFT_TO_RIGHT},
    {'%', 4, INFIX, LEFT_TO_RIGHT},
  //  {'+', 4, INFIX, LEFT_TO_RIGHT},
//    {'-', 5, OPERATOR_BINARY, OPERATOR_LEFT},
//    {'(', 6, OPERATOR_OTHER,  OPERATOR_NONE}
};

typedef struct {
  TokenType type;
//  uint32_t startColumn;
//  uint32_t length;
  char *str;
} Token;

typedef struct {
  TokenType type;
  //uint32_t startColumn;   //commend out because it's not used in this project
  //uint32_t length;      //to avoid problem caused by this
  char *str;
  int value;
} IntegerToken;

typedef struct {
  TokenType type;
  //uint32_t startColumn; \
  uint32_t length;
  char *str;
  double value;
} FloatToken;

typedef struct {
  TokenType type;
  //uint32_t startColumn;  \
  uint32_t length;
  char *str;
} IdentifierToken, StringToken, CharConstToken;

typedef struct {
  TokenType type;
//uint32_t startColumn;\
  uint32_t length;
  char *str;
  Operator_info *info;
} OperatorToken;

typedef struct {
  Token *currentToken;
} Tokenizer;

#endif // Token_H
