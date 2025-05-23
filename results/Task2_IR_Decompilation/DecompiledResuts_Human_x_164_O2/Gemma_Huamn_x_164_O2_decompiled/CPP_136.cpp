```c
#include <stdlib.h>

void largest_smallest_integers(int* result, int* input, size_t input_size) {
  int smallest = 0;
  int largest = 0;
  for (size_t i = 0; i < input_size; ++i) {
    if (input[i] < 0) {
      if (smallest == 0 || input[i] > smallest) {
        smallest = input[i];
      }
    } else if (input[i] > 0) {
      if (largest == 0 || input[i] < largest) {
        largest = input[i];
      }
    }
  }
  result[0] = smallest;
  result[1] = largest;
}

```