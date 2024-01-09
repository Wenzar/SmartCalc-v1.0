#include "general.h"
#include <math.h>

#ifndef CALCULATION_H_
#define CALCULATION_H_

#define AMOUNT_MATH_FUNCTIONS 9
#define NAMES_MATH_FUNCTIONS cos, tan, sin, sqrt, log, log10, acos, asin, atan
#define NAMES_TOKEN_FUNCTIONS \
  { "c", "t", "si", "sq", "ln", "lg", "ac", "as", "at" }
#define AMOUNT_OPERATORS_FUNCTIONS 6
#define NAMES_OPERATORS_FUNCTIONS addition, subtraction, multiplication, division, pow, fmod
#define NAMES_TOKEN_OPERATORS \
  { "+", "-", "*", "/", "^", "m" }

int calculation(token *reverse_polish_notation_array, const int amount_tokens,
                double *result);
stack_tokens *functions_workspace(const token token_object,
                                  stack_tokens *stack_value);
double functions_selector(const char *name_function, const double value);
stack_tokens *operators_workspace(const token token_object,
                                  stack_tokens *stack_value);
double operators_selector(const char *name_function, const double value_1,
                          const double value_2);
double addition(double value_1, double value_2);
double subtraction(double value_1, double value_2);
double multiplication(double value_1, double value_2);
double division(double value_1, double value_2);

#endif  // CALCULATION_H_