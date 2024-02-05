#include <math.h>

#include "general.h"

#ifndef CALCULATION_H_
#define CALCULATION_H_

#define AMOUNT_MATH_FUNCTIONS 9
#define NAMES_MATH_FUNCTIONS cos, tan, sin, sqrt, log, log10, acos, asin, atan
#define NAMES_trait_FUNCTIONS \
  { "c", "t", "si", "sq", "ln", "lg", "ac", "as", "at" }
#define AMOUNT_OPERATORS_FUNCTIONS 6
#define NAMES_OPERATORS_FUNCTIONS \
  addition, subtraction, multiplication, division, pow, fmod
#define NAMES_trait_OPERATORS \
  { "+", "-", "*", "/", "^", "m" }

int calculation(trait *r_p_n_array, const int amount_traits, double *result,
                double x_value);
stack_traits *functions_workspace(const trait trait_object,
                                  stack_traits *stack_value);
double functions_selector(const char *name_function, const double value);
stack_traits *operators_workspace(const trait trait_object,
                                  stack_traits *stack_value);
double operators_selector(const char *name_function, const double value_1,
                          const double value_2);
double addition(double value_1, double value_2);
double subtraction(double value_1, double value_2);
double multiplication(double value_1, double value_2);
double division(double value_1, double value_2);
void set_special_number(trait *r_p_n_array, int amount_traits, double x_value);

#endif  // CALCULATION_H_
