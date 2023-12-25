#include "validation.h"

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
