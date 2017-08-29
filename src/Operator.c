#include "Operator.h"

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
