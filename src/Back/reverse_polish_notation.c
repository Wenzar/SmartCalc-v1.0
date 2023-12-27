#include "reverse_polish_notation.h"

/// @brief Преобразует входную строку в обратную польскую нотацию
/// @param input_array - входная строка char *
/// @param amount_tokens - указатель на int
/// @return массив лексем
token *reverse_polish_notation(char *input_array, int *amount_tokens) {
  token *reverse_polish_notation_array = NULL;
  if (input_array != NULL && amount_tokens != NULL) {
    *amount_tokens = 0;
    token *token_array = get_token_array(input_array, amount_tokens);
    if (token_array != NULL) {
      int result = check_token_array(token_array, *amount_tokens);
      if (result == OK) {
        reverse_polish_notation_array =
            get_reverse_polish_notation_array(token_array, amount_tokens);
      }
      free(token_array);
      token_array = NULL;
    }
  }
  return reverse_polish_notation_array;
}