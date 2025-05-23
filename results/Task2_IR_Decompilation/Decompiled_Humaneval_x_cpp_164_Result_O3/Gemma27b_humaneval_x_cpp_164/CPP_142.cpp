```c
#include <stdint.h>

int sum_squares(int* arr, int size) {
  if (size == 0) {
    return 0;
  }
  int64_t i = 0;
  int sum = 0;
  for (; i < size; i++) {
    int val = arr[i];
    sum += val * val;
  }
  return sum;
}

```