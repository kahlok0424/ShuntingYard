#ifndef Token_H
#define Token_H

#include <stdint.h>
#include "Common.h"
#include "Operator.h"

typedef enum {
  TOKEN_UNKNOWN_TYPE,
  TOKEN_INTEGER_TYPE,
  TOKEN_OPERATOR_TYPE,
  TOKEN_FLOAT_TYPE,
  TOKEN_STRING_TYPE,
  TOKEN_IDENTIFIER_TYPE,
  TOKEN_NULL_TYPE,
} TokenType;

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
