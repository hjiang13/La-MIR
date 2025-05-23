```c
#include <stdint.h>

int prod_signs(int* a, int size) {
  if (size == 0) {
    return -32768;
  }
  int64_t n = size >> 2;
  if (size < 2) {
    n = 1;
  }
  int sum = 0;
  int prod = 1;
  for (int64_t i = 0; i < n; ++i) {
    int val = a[i];
    sum += abs(val);
    prod = (val < 0) ? -prod : prod;
  }
  return prod * sum;
}

```