```c
#include <stdint.h>

int sum_squares(int* arr, int size) {
  if (size == 0) {
    return 0;
  }
  int64_t iterations = (size / 3) > 0 ? (size / 3) : 1;
  int sum = 0;
  for (int i = 0; i < iterations; i++) {
    int val = arr[i * 3];
    sum += val * val;
    if (i * 3 + 1 < size) {
      int val = arr[i * 3 + 1];
      sum += val * val;
    }
    if (i * 3 + 2 < size) {
      int val = arr[i * 3 + 2];
      sum += val * val;
    }
  }
  return sum;
}
```