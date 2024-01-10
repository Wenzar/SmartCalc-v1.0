#include "validation.h"

/// @brief Валидация вводимой строки 
int input_string_validation(char *input_string) {
  int output = OK;
  if (input_string == NULL) {
    output = MEMORY_ERROR;
  } else {
    int (*functions[NUMBER_OF_FUNCTIONS])(char *) = {NAMES_OF_FUNCTIONS};
    for (int i = 0; i < NUMBER_OF_FUNCTIONS && output == OK; i++) {
      output = functions[i](input_string);
    }
  }
  return output;
}

/// @brief Проверка парности скобок
int check_number_of_braces(char *input_string) {
  int output = OK;
  if (input_string == NULL) {
    output = MEMORY_ERROR;
  } else {
    size_t length = strlen(input_string);
    int count_braces = 0;
    for (size_t i = 0; i < length && count_braces >= 0; i++) {
      if (input_string[i] == '(') {
        count_braces++;
      } else if (input_string[i] == ')') {
        count_braces--;
      }
    }
    if (count_braces != 0) {
      output = SYNTAX_ERROR;
    }
  }
  return output;
}

/// @brief Проверка названий тригонаметрических функций
int check_name_operators(char *input_string) {
  int output = OK;
  if (input_string == NULL) {
    output = MEMORY_ERROR;
  } else {
    size_t length = strlen(input_string);
    char *start = NULL;
    char *end = NULL;
    for (size_t i = 0; i < length && output == OK; i++) {
      if (isalpha(input_string[i]) && start == NULL) {
        start = &input_string[i];
        end = &input_string[i];
      } else if (isalpha(input_string[i]) && start != NULL) {
        end = &input_string[i];
      }
      if ((!(isalpha(input_string[i])) || input_string[i + 1] == '\0') &&
          start != NULL) {
        size_t size = end - start + 1;
        if (start[0] == 'a' || start[0] == 'c' || start[0] == 's' ||
            start[0] == 't' || start[0] == 'l') {
          size += 1;
        }
        char *potential_function = init_char_array(size + 1);
        if (potential_function == NULL) {
          output = MEMORY_ERROR;
        } else {
          potential_function = strncpy(potential_function, start, size);
          output = compare_function_name(potential_function);
          free(potential_function);
          potential_function = NULL;
          start = NULL;
          end = NULL;
        }
      }
    }
  }
  return output;
}

/// @brief Сравнивает входную строку с исходным названием
int compare_function_name(char *potential_function) {
  int output = OK;
  if (potential_function == NULL) {
    output = MEMORY_ERROR;
  } else {
    int match = 1;
    const char trigonometry_name[AMOUNT_TRIGONOMETRY_FUNCTIONS][10] = NAMES_TRIGONOMETRY_FUNCTIONS;
    for (int i = 0; i < AMOUNT_TRIGONOMETRY_FUNCTIONS && match; i++) {
      match = strcmp(potential_function, trigonometry_name[i]);
    }
    if (match) {
      output = SYNTAX_ERROR;
    }
  }
  return output;
}

/// @brief Проверяет корректность ввода точек вещественных чисел
int check_points(char *input_string) {
  int output = OK;
  if (input_string == NULL) {
    output = MEMORY_ERROR;
  } else {
    size_t length = strlen(input_string);
    char *start = NULL;
    char *end = NULL;
    char *point = NULL;
    for (size_t i = 0; i < length && output == OK; i++) {
      output = find_point(&input_string[i], &start, &point, &end);
      if (output == OK) {
        output = check_pointers(&input_string[i], &start, &point, &end);
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
/// @param symbol - указатель на символ
/// @param start - указатель на цифру перед точкой
/// @param point - указатель на точку
/// @param end - указатель на цифру после точки
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
