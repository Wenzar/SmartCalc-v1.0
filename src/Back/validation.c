#include "validation.h"

/// @brief Проверка входной строки на корректный ввод
/// @param input_array - входная строка char *
/// @return
int input_array_validation(char *input_array) {
  int output = OK;
  if (input_array == NULL) {
    output = MEMORY_ERROR;
  } else {
    int (*functions[AMOUNT_CHECK_FUNCTIONS])(char *) = {NAMES_CHECK_FUNCTIONS};
    for (int i = 0; i < AMOUNT_CHECK_FUNCTIONS && output == OK; i++) {
      output = functions[i](input_array);
    }
  }
  return output;
}

/// @brief Проверка количества скобок
/// @param input_array - входная строка char *
/// @return
int check_pair_braces(char *input_array) {
  int output = OK;
  if (input_array == NULL) {
    output = MEMORY_ERROR;
  } else {
    int count_braces = 0;
    for (int i = 0; i < strlen(input_array) && count_braces >= 0; i++) {
      if (input_array[i] == '(') {
        count_braces++;
      } else if (input_array[i] == ')') {
        count_braces--;
      }
    }
    if (count_braces != 0) {
      output = SYNTAX_ERROR;
    }
  }
  return output;
}

/// @brief Проверяет корректность ввода точек вещественных чисел
/// @param input_array - входная строка char *
/// @return
int check_points(char *input_array) {
  int output = OK;
  if (input_array == NULL) {
    output = MEMORY_ERROR;
  } else {
    size_t length = strlen(input_array);
    char *start = NULL;
    char *end = NULL;
    char *point = NULL;
    for (size_t i = 0; i < length && output == OK; i++) {
      output = find_point(&input_array[i], &start, &point, &end);
      if (output == OK) {
        output = check_pointers(&input_array[i], &start, &point, &end);
      }
      if (output == SYNTAX_ERROR) {
        start = NULL;
        end = NULL;
        point = NULL;
      }
    }
  }
  return output;
}

/// @brief Расстановка указателей на первую цифру, точку, последнюю цифру
/// @param symbol указатель на символ char *
/// @param start указатель на начало
/// @param point указатель на точку
/// @param end указатель на конец
/// @return
int find_point(char *symbol, char **start, char **point, char **end) {
  int output = OK;
  if (isdigit(*symbol) && *start == NULL) {
    *start = symbol;
  } else if (isdigit(*symbol) && *start != NULL) {
    *end = symbol;
  } else if (*symbol == '.' && *point == NULL) {
    *point = symbol;
  } else if (*symbol == '.' && *point != NULL) {
    output = SYNTAX_ERROR;
    *start = NULL;
    *end = NULL;
    *point = NULL;
  }
  return output;
}

/// @brief Проверка указателей на вещественное число
/// @param symbol - указатель на символ char *
/// @param start - указатель на начало
/// @param point - указатель на точку
/// @param end - указатель на конец
/// @return
int check_pointers(char *symbol, char **start, char **point, char **end) {
  int output = OK;
  if ((!(isdigit(*symbol)) && *symbol != '.') ||
      ((isdigit(*symbol) || *symbol == '.') && *(symbol + 1) == '\0')) {
    if (*point != NULL && *start != NULL && *end != NULL) {
      if (*point - *start > 0 && *end - *point > 0) {
        *start = NULL;
        *end = NULL;
        *point = NULL;
      } else {
        output = SYNTAX_ERROR;
      }
    } else if (*point != NULL && (*start == NULL || *end == NULL)) {
      output = SYNTAX_ERROR;
    } else if (*point == NULL) {
      *start = NULL;
      *end = NULL;
    }
  }
  return output;
}