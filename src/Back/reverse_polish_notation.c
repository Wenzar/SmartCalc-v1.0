#include "reverse_polish_notation.h"

/// @brief Преобразует входную строку в обратную польскую нотацию
/// @param input_string - входная строка char *
/// @param amount_traits - указатель на int
/// @return массив лексем
trait *reverse_polish_notation(char *input_string, int *amount_traits) {
  trait *r_p_n_array = NULL;
  if (input_string != NULL && amount_traits != NULL) {
    *amount_traits = 0;
    trait *trait_array = get_trait_array(input_string, amount_traits);
    if (trait_array != NULL) {
      int result = check_trait_array(trait_array, *amount_traits);
      if (result == OK) {
        r_p_n_array = get_r_p_n_array(trait_array, amount_traits);
      }
      free(trait_array);
      trait_array = NULL;
    }
  }
  return r_p_n_array;
}

/// @brief Преобразует входную строку в массив лексем
/// @param  input_string - входная строка char *
/// @return массив лексем trait *
trait *get_trait_array(char *input_string, int *amount_traits) {
  trait *trait_array = NULL;
  if (input_string != NULL && amount_traits != NULL) {
    *amount_traits = 0;
    char *pointer = input_string;
    double value = 0.0;
    int size_trait_array = 5;
    trait_array = init_trait_array(size_trait_array);
    char *name_operator = init_char_array(SIZE_NAME_FUNC);
    int status = -1;
    while (*pointer != '\0') {
      if (*amount_traits == size_trait_array - 1) {
        trait_array = realloc_trait_array(trait_array, &size_trait_array);
      }
      if (isdigit(*pointer)) {
        value = get_value(&pointer);
        init_trait(&trait_array[*amount_traits], e_simple_number_status, value,
                   name_operator);
        ++(*amount_traits);
      } else if (isalpha(*pointer)) {
        get_name_operators(&pointer, name_operator);
        status = get_status(name_operator[0]);
        init_trait(&trait_array[*amount_traits], status, value, name_operator);
        ++(*amount_traits);
      } else {
        name_operator[0] = *pointer;
        ++pointer;
        init_trait(&trait_array[*amount_traits], e_operator_status, value,
                   name_operator);
        ++(*amount_traits);
      }
      value = 0.0;
      status = -1;
      memset(name_operator, '\0', SIZE_NAME_FUNC);
    }
    if (!(*amount_traits)) {
      free(trait_array);
      trait_array = NULL;
    }
    free(name_operator);
    name_operator = NULL;
  }
  return trait_array;
}

/// @brief Создает указатель на массив лексем
/// @param amount_traits - размер массива const int
/// @return
/// указатель на  массив лексем
trait *init_trait_array(const int amount_traits) {
  return (trait *)calloc(amount_traits, sizeof(trait));
}

/// @brief Изменяет размер массива лексем
/// @param trait_array - массив лексем trait *
/// @param prev_size - указатель на исходный размер массива int *
/// @return
/// измененный массив лексем
trait *realloc_trait_array(trait *trait_array, int *prev_size) {
  *prev_size *= 2;
  trait_array = (trait *)realloc(trait_array, *prev_size * sizeof(trait));
  return trait_array;
}

/// @brief Получает вещественное число из входной строки
/// @param  pointer - указатель на входную строку char *
/// @return
/// число double
double get_value(char **pointer) {
  double value = 0.0;
  if (pointer != NULL) {
    int start_length = 5;
    char *number = init_char_array(start_length);
    int i = 0;
    while (isdigit(**pointer) || **pointer == '.') {
      if (i == start_length - 1) {
        number = realloc_char_array(number, &start_length);
      }
      number[i++] = **pointer;
      ++(*pointer);
    }
    number[i] = '\0';
    setlocale(LC_NUMERIC, "C");
    value = strtod(number, NULL);
    free(number);
    number = NULL;
  }
  return value;
}

/// @brief Получает имена операторов(функций) из входной строки
/// @param  pointer - указатель на входную строку char *
/// @param name_operator - указатель на строку char *
void get_name_operators(char **pointer, char *name_operator) {
  if (pointer != NULL && name_operator != NULL) {
    if (**pointer == 'm' || **pointer == 'c' || **pointer == 't') {
      name_operator[0] = **pointer;
      *pointer += 3;
    } else if (**pointer == 'p') {
      name_operator[0] = **pointer;
      *pointer += 2;
    } else if (**pointer == 's') {
      strncpy(name_operator, *pointer, 2);
      ++(*pointer);
      if (**pointer == 'i') {
        *pointer += 2;
      } else {
        *pointer += 3;
      }
    } else if (**pointer == 'a') {
      strncpy(name_operator, *pointer, 2);
      *pointer += 4;
    } else if (**pointer == 'l') {
      name_operator[0] = **pointer;
      ++(*pointer);
      if (**pointer == 'n') {
        name_operator[1] = **pointer;
        ++(*pointer);
      } else {
        name_operator[1] = 'g';
        *pointer += 2;
      }
    } else {
      name_operator[0] = **pointer;
      ++(*pointer);
    }
  }
}

/// @brief | Возвращает статус лексемы |
/// @param  symbol - первый символ оператора(функции)
/// @return статус лексемы int
int get_status(char symbol) {
  int status = -1;
  if (symbol == 'p' || symbol == 'x' || symbol == 'e') {
    status = e_special_number_status;
  } else if (symbol == 'm') {
    status = e_operator_status;
  } else {
    status = e_function_status;
  }
  return status;
}

/// @brief Преобразование массива лексем в обратную польскую нотацию
/// @param trait_array - массив лексем trait *
/// @param amount_traits - количество лексем
/// @return преобразованная строка лексем
trait *get_r_p_n_array(trait *trait_array, int *amount_traits) {
  trait *r_p_n_array = NULL;
  if (trait_array != NULL) {
    r_p_n_array = init_trait_array(*amount_traits);
    stack_traits *stack_operators = init_stack();
    int count = 0;
    for (int i = 0; i < *amount_traits; ++i) {
      if (trait_array[i].status == e_simple_number_status ||
          trait_array[i].status == e_special_number_status) {
        r_p_n_array[count++] = trait_array[i];
      } else if (trait_array[i].status == e_function_status) {
        stack_operators = push_trait(stack_operators, trait_array[i]);
      } else {
        if (trait_array[i].priority == e_right_bracket_priority) {
          stack_operators =
              operator_is_right_bracket(r_p_n_array, stack_operators, &count);
          if (stack_operators == NULL) {
            break;
          }
        } else if (trait_array[i].priority == e_left_bracket_priority ||
                   stack_operators->size == EMPTY ||
                   trait_array[i].priority >
                       stack_operators->trait_object.priority) {
          stack_operators = push_trait(stack_operators, trait_array[i]);
        } else if (trait_array[i].priority <=
                   stack_operators->trait_object.priority) {
          stack_operators = priority_is_less(trait_array[i], r_p_n_array,
                                             stack_operators, &count);
        }
      }
    }
    cleaning_stack_operators(r_p_n_array, stack_operators, &count);
    *amount_traits = count;
  }
  return r_p_n_array;
}

/// @brief | Обр.польская нотация: лексема - правая скобка |
/// @param r_p_n_array - преобразованный массив лексем trait *
/// @param stack_operators - стек операторов stack_traits *
/// @param count - указатель на количество элементов в массиве лексем
/// @return указатель на стек операторов
stack_traits *operator_is_right_bracket(trait *r_p_n_array,
                                        stack_traits *stack_operators,
                                        int *count) {
  if (r_p_n_array != NULL && stack_operators != NULL && count != NULL) {
    while (stack_operators->size != EMPTY &&
           stack_operators->trait_object.priority != e_left_bracket_priority) {
      r_p_n_array[(*count)++] = pop_trait(&stack_operators);
    }
    if (stack_operators->trait_object.priority == e_left_bracket_priority) {
      pop_trait(&stack_operators);
    } else {
      free_stack(stack_operators);
      free(r_p_n_array);
      r_p_n_array = NULL;
      *count = 0;
    }
    if (stack_operators->trait_object.status == e_function_status) {
      r_p_n_array[(*count)++] = pop_trait(&stack_operators);
    }
  }
  return stack_operators;
}

/// @brief Обр.польская нотация : приоритет оператора меньше, чем
/// у верхнего оператора в стеке
/// @param trait_object - проверяемая лексема
/// @param r_p_n_array - преобразованный массив лексем trait *
/// @param stack_operators - стек операторов stack_traits *
/// @param count - указатель на количество элементов в массиве лексем
///@return указатель на стек операторов
stack_traits *priority_is_less(const trait trait_object, trait *r_p_n_array,
                               stack_traits *stack_operators, int *count) {
  if (r_p_n_array != NULL && stack_operators != NULL && count != NULL) {
    while (stack_operators->size != EMPTY &&
           trait_object.priority <= stack_operators->trait_object.priority) {
      r_p_n_array[(*count)++] = pop_trait(&stack_operators);
    }
    stack_operators = push_trait(stack_operators, trait_object);
  }
  return stack_operators;
}

/// @brief Обр.польская нотация: очистка стека операторов после цикла
/// @param r_p_n_array - преобразованный массив лексем trait *
/// @param stack_operators - стек операторов stack_traits *
/// @param count - указатель на количество элементов в массиве лексем
void cleaning_stack_operators(trait *r_p_n_array, stack_traits *stack_operators,
                              int *count) {
  if (r_p_n_array != NULL && stack_operators != NULL && count != NULL) {
    while (stack_operators->size != EMPTY) {
      r_p_n_array[(*count)++] = pop_trait(&stack_operators);
    }
    free_stack(stack_operators);
  }
}

/// @brief | Дополнительная обработка ошибок массива лексем |
/// @param trait_array - массив лексем trait *
/// @param amount_traits - количество лексем int
/// @return
/// 0 - OK;
/// 1 - синтаксическая ошибка
/// 2 - ошибка памяти
int check_trait_array(trait *trait_array, const int amount_traits) {
  int output = OK;
  if (trait_array == NULL) {
    output = MEMORY_ERROR;
  } else {
    int (*functions[NUM_CHECK_FUNCTIONS])(trait *,
                                          const int) = {NAMES_FUNCTIONS};
    for (int i = 0; i < NUM_CHECK_FUNCTIONS && output == OK; ++i) {
      output = functions[i](trait_array, amount_traits);
    }
  }
  return output;
}

/// @brief | Находит унарные плюсы и минусы |
/// @param trait_array - массив лексем trait *
/// @param amount_traits - количество лексем int
/// @return
/// 0 - OK;
/// 2 - ошибка памяти
int find_unar_operators(trait *trait_array, const int amount_traits) {
  int output = OK;
  if (trait_array == NULL) {
    output = MEMORY_ERROR;
  } else {
    for (int i = 0; i < amount_traits; ++i) {
      if (trait_array[i].status == e_operator_status &&
          trait_array[i].priority == e_sum_priority) {
        if ((i == 0 ||
             (i != 0 && trait_array[i - 1].status == e_operator_status &&
              trait_array[i - 1].priority == e_left_bracket_priority)) &&
            i != amount_traits - 1 &&
            (trait_array[i + 1].status == e_function_status ||
             trait_array[i + 1].status == e_simple_number_status ||
             trait_array[i + 1].status == e_special_number_status)) {
          if (trait_array[i].name[0] == '+') {
            trait_array[i].priority = e_unar_sum_priority;
          } else {
            trait_array[i].priority = e_unar_sub_priority;
          }
        }
      }
    }
  }
  return output;
}

/// @brief | Определяет пустые скобки вида () |
/// @param trait_array - массив лексем trait *
/// @param amount_traits - количество лексем int
/// @return
/// 0 - OK;
/// 1 - синтаксическая ошибка
/// 2 - ошибка памяти
int find_empty_brackets(trait *trait_array, const int amount_traits) {
  int output = OK;
  if (trait_array == NULL) {
    output = MEMORY_ERROR;
  } else {
    for (int i = 0; i < amount_traits && output == OK; ++i) {
      if (trait_array[i].status == e_operator_status &&
          trait_array[i].priority == e_left_bracket_priority &&
          trait_array[i + 1].status == e_operator_status &&
          trait_array[i + 1].priority == e_right_bracket_priority) {
        output = SYNTAX_ERROR;
      }
    }
  }
  return output;
}

/// @brief | Определяет есть ли между функциями операторы |
/// ошибки вида: sin(x)cos(x)
/// @param trait_array - массив лексем trait *
/// @param amount_traits - количество лексем int
/// @return
/// 0 - OK;
/// 1 - синтаксическая ошибка
/// 2 - ошибка памяти
int check_functions(trait *trait_array, const int amount_traits) {
  int output = OK;
  if (trait_array == NULL) {
    output = MEMORY_ERROR;
  } else {
    for (int i = 0; i < amount_traits && output == OK; ++i) {
      if (trait_array[i].status == e_function_status && i != 0 &&
          trait_array[i - 1].status == e_operator_status &&
          (trait_array[i - 1].priority == e_right_bracket_priority ||
           trait_array[i - 1].priority == e_mod_priority)) {
        output = SYNTAX_ERROR;
      }
    }
  }
  return output;
}
