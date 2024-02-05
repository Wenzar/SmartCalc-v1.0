#include "general.h"

#ifndef VALIDATION_H_
#define VALIDATION_H_

#define NUMBER_OF_FUNCTIONS 3
#define NAMES_OF_FUNCTIONS \
  check_number_of_braces, check_name_operators, check_points
#define AMOUNT_TRIGONOMETRY_FUNCTIONS 11
#define NAMES_TRIGONOMETRY_FUNCTIONS                                          \
  {                                                                           \
    "mod", "cos(", "sin(", "tan(", "acos(", "asin(", "atan(", "sqrt(", "ln(", \
        "log(", "x"                                                           \
  }

int input_string_validation(char *input_string);
int check_number_of_braces(char *input_string);
int check_name_operators(char *input_string);
int compare_function_name(char *potential_function);
int check_points(char *input_string);
int find_point(char *symbol, char **start, char **point, char **end);
int check_pointers(char *symbol, char **start, char **point, char **end);

#endif  // VALIDATION_H_
