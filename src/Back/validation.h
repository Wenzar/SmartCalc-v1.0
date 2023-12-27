#include "general.h"

#ifndef VALIDATION_H_
#define VALIDATION_H_

#define AMOUNT_CHECK_FUNCTIONS 2
#define NAMES_CHECK_FUNCTIONS check_pair_braces, check_points

int input_array_validation(char *input_array);
int check_pair_braces(char *input_array);
int check_points(char *input_array);
int find_point(char *symbol, char **start, char **point, char **end);
int check_pointers(char *symbol, char **start, char **point, char **end);

#endif  // VALIDATION_H_
