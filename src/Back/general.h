#ifndef GENERAL_H_
#define GENERAL_H_

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_NAME_FUNC 3
#define EMPTY 0
#define SYNTAX_ERROR_LINE "Syntax error!"
#define INVALID_DATA_LINE "Invalid data!"

typedef enum CodeErrors { OK, SYNTAX_ERROR, MEMORY_ERROR } CodeErrors;

/// @brief | Статусы лексем |
typedef enum status {
  e_simple_number_status,
  e_special_number_status,
  e_operator_status,
  e_function_status
} status;

/// @brief | Приоритеты операций |
typedef enum priority {
  e_left_bracket_priority,
  e_sum_priority,
  e_sub_priority = 1,
  e_mul_priority,
  e_div_priority = 2,
  e_pow_priority,
  e_mod_priority,
  e_unar_sum_priority,
  e_unar_sub_priority = 5,
  e_right_bracket_priority,
} priority;

/// @brief | Структура лексемы |
/// @param status - статус лексемы int
/// @param value - значение числа double
/// @param name - название оператора(функции) или спец.числа char *
/// @param priority - приоритет операторов(функции) int
typedef struct token {
  int status;
  double value;
  char name[SIZE_NAME_FUNC];
  int priority;
} token;

typedef struct stack_tokens {
  token token_object;
  struct stack_tokens *prev_token;
  int size;
} stack_tokens;

char *init_char_array(const int length);
char *realloc_char_array(char *char_array, int *prev_length);
void init_token(token *token, int status, double value, char *name);
int get_priority(char symbol);
stack_tokens *init_stack();
stack_tokens *create_new_element_stack(token token_object);
stack_tokens *push_token(stack_tokens *head, token token_object);
token pop_token(stack_tokens **head);
void free_stack(stack_tokens *head);

#endif  // GENERAL_H_
