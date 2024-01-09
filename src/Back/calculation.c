#include "calculation.h"

/// @brief Вычисление введенного выражения
/// @param reverse_polish_notation_array - входная строка token *
/// @param amount_tokens - количество лексем const int
/// @param result - указатель на результат double *
/// @return
int calculation(token *reverse_polish_notation_array, const int amount_tokens, double *result) {
  int output = OK;
  if (reverse_polish_notation_array == NULL || result == NULL) {
    output = MEMORY_ERROR;
  } else {
    *result = 0.0;
    stack_tokens *stack_value = init_stack();
    for (int i = 0; i < amount_tokens && stack_value != NULL; ++i) {
      if (reverse_polish_notation_array[i].status == e_simple_number_status) {
        stack_value = push_token(stack_value, reverse_polish_notation_array[i]);
      } else if (reverse_polish_notation_array[i].status == e_function_status) {
        stack_value =
            functions_workspace(reverse_polish_notation_array[i], stack_value);
      } else if (reverse_polish_notation_array[i].status == e_operator_status) {
        stack_value =
            operators_workspace(reverse_polish_notation_array[i], stack_value);
      }
    }
    if (stack_value != NULL && stack_value->size == 1) {
      *result = stack_value->token_object.value;
      free_stack(stack_value);
    } else if (stack_value != NULL && stack_value->size != 1) {
      output = SYNTAX_ERROR;
      free_stack(stack_value);
    } else {
      output = SYNTAX_ERROR;
    }
  }
  return output;
}

/// @brief Обработка лексем-функций
/// @param token_object - рассматриваемая лексема token
/// @param stack_value - стек чисел token *
/// @return указатель на стек чисел
stack_tokens *functions_workspace(const token token_object,
                                  stack_tokens *stack_value) {
  if (stack_value != NULL) {
    if (stack_value->size != EMPTY) {
      double value = stack_value->token_object.value;
      pop_token(&stack_value);
      double result = functions_selector(token_object.name, value);
      token *new_token = (token *)calloc(1, sizeof(token));
      init_token(new_token, e_simple_number_status, result, "\0");
      stack_value = push_token(stack_value, *new_token);
      free(new_token);
      new_token = NULL;
    } else {
      free_stack(stack_value);
      stack_value = NULL;
    }
  }
  return stack_value;
}

/// @brief Вызывает нужные математические функции
/// @param name_function - название функции char *
/// @param value - вычисляемое значение double
/// @return вычисленное значение double
double functions_selector(const char *name_function, const double value) {
  double result = 0.0;
  if (name_function != NULL) {
    double (*functions[AMOUNT_MATH_FUNCTIONS])(double) = {NAMES_MATH_FUNCTIONS};
    const char names_token_functions[AMOUNT_MATH_FUNCTIONS][3] =
        NAMES_TOKEN_FUNCTIONS;
    int i = 0;
    for (int match = 1; i < AMOUNT_MATH_FUNCTIONS && match; ++i) {
      match = strcmp(name_function, names_token_functions[i]);
    }
    result = functions[i - 1](value);
  }
  return result;
}

/// @brief Обработка лексем-операторов
/// @param token_object - рассматриваемая лексема token
/// @param stack_value - стек чисел token *
/// @return указатель на стек чисел
stack_tokens *operators_workspace(const token token_object,
                                  stack_tokens *stack_value) {
  if (stack_value != NULL) {
    if (stack_value->size != EMPTY) {
      if (token_object.priority == e_unar_sub_priority &&
          token_object.name[0] == '-') {
        stack_value->token_object.value *= -1;
      } else if (token_object.priority != e_unar_sub_priority &&
                 stack_value->size >= 2) {
        double value_2 = stack_value->token_object.value;
        pop_token(&stack_value);
        double value_1 = stack_value->token_object.value;
        pop_token(&stack_value);
        double result = operators_selector(token_object.name, value_1, value_2);
        token *new_token = (token *)calloc(1, sizeof(token));
        init_token(new_token, e_simple_number_status, result, "\0");
        stack_value = push_token(stack_value, *new_token);
        free(new_token);
        new_token = NULL;
      } else if (token_object.priority != e_unar_sum_priority) {
        free_stack(stack_value);
        stack_value = NULL;
      }
    }
  } else {
    free_stack(stack_value);
    stack_value = NULL;
  }
  return stack_value;
}

/// @brief Вызывает нужные функции-операторы (+-*/^mod)
/// @param name_function - название функции char *
/// @param value - вычисляемое значение double
/// @return вычисленное значение double
double operators_selector(const char *name_function, const double value_1,
                          const double value_2) {
  double result = 0.0;
  if (name_function != NULL) {
    double (*functions[AMOUNT_OPERATORS_FUNCTIONS])(
        double, double) = {NAMES_OPERATORS_FUNCTIONS};
    const char names_token_operators[AMOUNT_OPERATORS_FUNCTIONS][3] =
        NAMES_TOKEN_OPERATORS;
    int i = 0;
    for (int match = 1; i < AMOUNT_OPERATORS_FUNCTIONS && match; ++i) {
      match = strcmp(name_function, names_token_operators[i]);
    }
    result = functions[i - 1](value_1, value_2);
  }
  return result;
}

/// @brief Сложение вещественных чисел
double addition(double value_1, double value_2) { return value_1 + value_2; }

/// @brief Вычитание вещественных чисел
double subtraction(double value_1, double value_2) { return value_1 - value_2; }

/// @brief Умножение вещественных чисел
double multiplication(double value_1, double value_2) { return value_1 * value_2; }

/// @brief Деление вещественных чисел
double division(double value_1, double value_2) { return value_1 / value_2; }
