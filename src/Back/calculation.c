#include "calculation.h"

/// @brief Вычисление введенного выражения
/// @param r_p_n_array - входная лексема trait *
/// @param amount_traits - количество лексем const int
/// @param result - указатель на результат double *
/// @return
int calculation(trait *r_p_n_array, const int amount_traits, double *result) {
  int output = OK;
  if (r_p_n_array == NULL || result == NULL) {
    output = MEMORY_ERROR;
  } else {
    *result = 0.0;
    stack_traits *stack_value = init_stack();
    for (int i = 0; i < amount_traits && stack_value != NULL; ++i) {
      if (r_p_n_array[i].status == e_simple_number_status) {
        stack_value = push_trait(stack_value, r_p_n_array[i]);
      } else if (r_p_n_array[i].status == e_function_status) {
        stack_value =
            functions_workspace(r_p_n_array[i], stack_value);
      } else if (r_p_n_array[i].status == e_operator_status) {
        stack_value =
            operators_workspace(r_p_n_array[i], stack_value);
      }
    }
    if (stack_value != NULL && stack_value->size == 1) {
      *result = stack_value->trait_object.value;
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
/// @param trait_object - рассматриваемая лексема trait
/// @param stack_value - стек чисел trait *
/// @return указатель на стек чисел
stack_traits *functions_workspace(const trait trait_object,
                                  stack_traits *stack_value) {
  if (stack_value != NULL) {
    if (stack_value->size != EMPTY) {
      double value = stack_value->trait_object.value;
      pop_trait(&stack_value);
      double result = functions_selector(trait_object.name, value);
      trait *new_trait = (trait *)calloc(1, sizeof(trait));
      init_trait(new_trait, e_simple_number_status, result, "\0");
      stack_value = push_trait(stack_value, *new_trait);
      free(new_trait);
      new_trait = NULL;
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
    const char names_trait_functions[AMOUNT_MATH_FUNCTIONS][3] =
        NAMES_trait_FUNCTIONS;
    int i = 0;
    for (int match = 1; i < AMOUNT_MATH_FUNCTIONS && match; ++i) {
      match = strcmp(name_function, names_trait_functions[i]);
    }
    result = functions[i - 1](value);
  }
  return result;
}

/// @brief Обработка лексем-операторов
/// @param trait_object - рассматриваемая лексема trait
/// @param stack_value - стек чисел trait *
/// @return указатель на стек чисел
stack_traits *operators_workspace(const trait trait_object,
                                  stack_traits *stack_value) {
  if (stack_value != NULL) {
    if (stack_value->size != EMPTY) {
      if (trait_object.priority == e_unar_sub_priority &&
          trait_object.name[0] == '-') {
        stack_value->trait_object.value *= -1;
      } else if (trait_object.priority != e_unar_sub_priority &&
                 stack_value->size >= 2) {
        double value_2 = stack_value->trait_object.value;
        pop_trait(&stack_value);
        double value_1 = stack_value->trait_object.value;
        pop_trait(&stack_value);
        double result = operators_selector(trait_object.name, value_1, value_2);
        trait *new_trait = (trait *)calloc(1, sizeof(trait));
        init_trait(new_trait, e_simple_number_status, result, "\0");
        stack_value = push_trait(stack_value, *new_trait);
        free(new_trait);
        new_trait = NULL;
      } else if (trait_object.priority != e_unar_sum_priority) {
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
    const char names_trait_operators[AMOUNT_OPERATORS_FUNCTIONS][3] =
        NAMES_trait_OPERATORS;
    int i = 0;
    for (int match = 1; i < AMOUNT_OPERATORS_FUNCTIONS && match; ++i) {
      match = strcmp(name_function, names_trait_operators[i]);
    }
    result = functions[i - 1](value_1, value_2);
  }
  return result;
}

/// @brief Сложение
double addition(double value_1, double value_2) { return value_1 + value_2; }

/// @brief Вычитание
double subtraction(double value_1, double value_2) { return value_1 - value_2; }

/// @brief Умножение
double multiplication(double value_1, double value_2) { return value_1 * value_2; }

/// @brief Деление
double division(double value_1, double value_2) { return value_1 / value_2; }
