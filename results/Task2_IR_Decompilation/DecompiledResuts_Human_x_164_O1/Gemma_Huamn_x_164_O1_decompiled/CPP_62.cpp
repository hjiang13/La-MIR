```c
#include <stdlib.h>

void derivative(float* restrict result, const float* restrict input) {
  float* result_end = result;
  const float* input_end = input;

  for (; input < input_end; ++input) {
    *result = *input * (float)(input - input_end);
    ++result;
  }
}