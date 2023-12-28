#ifndef GENERAL_H_
#define GENERAL_H_

#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SYNTAX_ERROR_LINE "Syntax error!"
#define INVALID_DATA_LINE "Invalid data!"
#define SIZE_NAME_FUNC 3

typedef enum ErrorsCode { OK, SYNTAX_ERROR, MEMORY_ERROR } ErrorsCode;

/// @brief Структура лексемы
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

/// @brief Статусы лексем
typedef enum status {
  NUMBER_STATUS,
  SPECIAL_NUMBER_STATUS,
  OPERATOR_STATUS,
  FUNCTION_STATUS
} status;

/// @brief Приоритеты операций
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

typedef struct stack_tokens {
  token token_object;
  struct stack_tokens *prev_token;
  int size;
} stack_tokens;

void init_token(token *token_object, int status, double value, char *name);
int get_priority(char symbol);
stack_tokens *init_stack();
stack_tokens *create_new_element_stack(token token_object);
stack_tokens *push_token(stack_tokens *head, token token_object);
token pop_token(stack_tokens **head);
void free_stack(stack_tokens *head);

#endif  // GENERAL_H_
