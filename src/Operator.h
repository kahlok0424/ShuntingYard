#ifndef _OPERATOR_H
#define _OPERATOR_H

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

extern Operator_info OPERATORS_TABLE[];

#endif // _OPERATOR_H
