```c
#include <stdint.h>

int below_zero(int* arr, int size) {
  if (size == 0) {
    return 0;
  }
  if (arr[0] < 0) {
    return 1;
  }
  for (int i = 1; i < size; i++) {
    if (arr[i] + arr[i - 1] < 0) {
      return 1;
    }
  }
  return 0;
}

```