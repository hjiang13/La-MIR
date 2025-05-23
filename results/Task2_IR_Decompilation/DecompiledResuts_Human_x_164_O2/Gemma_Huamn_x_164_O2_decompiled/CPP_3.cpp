```c
#include <stdint.h>

int below_zero(int* vector, int size) {
  if (size == 0) {
    return 0;
  }
  int64_t sum = 0;
  for (int i = 0; i < size; i++) {
    sum += vector[i];
    if (sum < 0) {
      return 1;
    }
  }
  return 0;
}

```