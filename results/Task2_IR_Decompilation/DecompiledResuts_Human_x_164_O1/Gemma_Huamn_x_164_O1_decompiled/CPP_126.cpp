```c
#include <stdint.h>

int _Z9is_sortedSt6vectorIiSaIiEE(const int* v, size_t size) {
  if (size <= 1) {
    return 1;
  }
  for (size_t i = 1; i < size; ++i) {
    if (v[i] < v[i - 1]) {
      return 0;
    }
  }
  return 1;
}
```