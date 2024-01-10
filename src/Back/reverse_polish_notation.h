#include <locale.h>

#include "general.h"

#ifndef REVERSE_POLISH_NOTATION_H_
#define REVERSE_POLISH_NOTATION_H_

#define NUM_CHECK_FUNCTIONS 3
#define NAMES_FUNCTIONS \
  find_unar_operators, find_empty_brackets, check_functions

trait *reverse_polish_notation(char *input_string, int *amount_traits);
trait *get_trait_array(char *input_string, int *amount_traits);

double get_value(char **pointer);
void get_name_operators(char **pointer, char *name_operator);
int get_status(char symbol);
trait *get_r_p_n_array(trait *trait_array, int *amount_traits);
stack_traits *operator_is_right_bracket(trait *r_p_n_array,
                                        stack_traits *stack_operators,
                                        int *count);
stack_traits *priority_is_less(const trait trait_object, trait *r_p_n_array,
                               stack_traits *stack_operators, int *count);
void cleaning_stack_operators(trait *r_p_n_array, stack_traits *stack_operators,
                              int *count);
int check_trait_array(trait *trait_array, const int amount_traits);
int find_unar_operators(trait *trait_array, const int amount_traits);
int find_empty_brackets(trait *trait_array, const int amount_traits);
int check_functions(trait *trait_array, const int amount_traits);
trait *init_trait_array(const int amount_traits);
trait *realloc_trait_array(trait *trait_array, int *prev_size);

#endif  // REVERSE_POLISH_NOTATION_H_