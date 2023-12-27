#ifndef GENERAL_H_
#define GENERAL_H_

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SYNTAX_ERROR_LINE "Syntax error!"

typedef enum ErrorsCode { OK, SYNTAX_ERROR, MEMORY_ERROR } ErrorsCode;

/// @brief Структура лексемы
/// @param status - статус лексемы int
/// @param value - значение числа double
/// @param name - название оператора(функции) или спец.числа char *
/// @param priority - приоритет операторов(функции) int
typedef struct token {
  int status;
  double value;
//   char name[SIZE_NAME_FUNC];
  int priority;
} token;

#endif  // GENERAL_H_
