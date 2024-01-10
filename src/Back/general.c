#include "general.h"

/// @brief Создает указатель на массив символов
/// @param length - длина массива const int
/// @return указатель на массив символов
char *init_char_array(const int length) {
  return (char *)calloc(length, sizeof(char));
}

/// @brief Изменяет размер массива символов
/// @param char_array - массив символов char *
/// @param prev_length - указатель на исходный размер массива int *
/// @return измененный массив символов
char *realloc_char_array(char *char_array, int *prev_length) {
  *prev_length *= 2;
  char_array = (char *)realloc(char_array, *prev_length * sizeof(char));
  return char_array;
}

/// @brief Заполняет поля лексемы
/// @param trait_object - указатель на лексему trait *
/// @param status - статус лексемы int
/// @param value - значение вещественного числа double
/// @param name - имя оператора(функции) char *
void init_trait(trait *trait_object, int status, double value, char *name) {
  if (trait_object != NULL) {
    trait_object->status = status;
    trait_object->value = value;
    strcpy(trait_object->name, name);
    trait_object->priority = get_priority(name[0]);
  }
}

/// @brief Возвращает приоритет операции
/// @param  symbol - первый символ оператора(функции)
/// @return приоритет операции int
int get_priority(char symbol) {
  int priority = 0;
  switch (symbol) {
    case '+':
    case '-':
      priority = e_sum_priority;
      break;
    case '*':
    case '/':
      priority = e_mul_priority;
      break;
    case '^':
      priority = e_pow_priority;
      break;
    case 'm':
      priority = e_mod_priority;
      break;
    case ')':
      priority = e_right_bracket_priority;
      break;
    case '(':
      priority = e_left_bracket_priority;
      break;
  }
  return priority;
}

/// @brief Инициализация стека лексем
/// @param  trait_object- добавляемая лексема
/// @return указатель на верхний элемент
stack_traits *init_stack() {
  stack_traits *head = (stack_traits *)malloc(sizeof(stack_traits));
  if (head != NULL) {
    head->prev_trait = NULL;
    head->size = 0;
  }
  return head;
}

/// @brief Создание указателя на новый элемент стека
/// @param trait_object- добавляемая лексема trait
/// @return указатель на новый элемент
stack_traits *create_new_element_stack(trait trait_object) {
  stack_traits *head = (stack_traits *)malloc(sizeof(stack_traits));
  if (head != NULL) {
    head->trait_object = trait_object;
    head->prev_trait = NULL;
    head->size = 0;
  }
  return head;
}

/// @brief Добавление новой лексемы в стек
/// @param head - указатель на верхний элемент
/// @param trait_object - добавляемая лексема
/// @return указатель на верхний элемент
stack_traits *push_trait(stack_traits *head, trait trait_object) {
  stack_traits *output = head;
  if (head != NULL && head->size == 0) {
    head->trait_object = trait_object;
    ++(head->size);
  } else if (head != NULL && head->size != 0) {
    stack_traits *new_trait = create_new_element_stack(trait_object);
    if (new_trait != NULL) {
      output = new_trait;
      new_trait->prev_trait = head;
      new_trait->size = head->size + 1;
    }
  }
  return output;
}

/// @brief Выталкивание верхней лексемы из стека
/// @param  head - указатель на верхний элемент
/// @return верхняя лексема
trait pop_trait(stack_traits **head) {
  trait output = (*head)->trait_object;
  if ((*head)->size == 1) {
    (*head)->size = 0;
  } else {
    stack_traits *tmp = (*head);
    (*head) = (*head)->prev_trait;
    free(tmp);
  }
  return output;
}

/// @brief Очистка стека
/// @param head - указатель на верхний элемент
void free_stack(stack_traits *head) {
  if (head != NULL) {
    while (head->prev_trait != NULL) {
      pop_trait(&head);
    }
    free(head);
    head = NULL;
  }
}
