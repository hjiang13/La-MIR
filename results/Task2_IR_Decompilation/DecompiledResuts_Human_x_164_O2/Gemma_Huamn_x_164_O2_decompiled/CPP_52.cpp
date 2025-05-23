```c
#include <stdint.h>

int32_t below_threshold(const int32_t *vec, int32_t threshold, size_t size) {
  if (size == 0) {
    return 1;
  }

  size_t i = 1;
  size_t max_index = size > 1 ? size : 1;

  if (vec[0] < threshold) {
    for (; i < max_index; ++i) {
      if (vec[i] >= threshold) {
        break;
      }
    }
  }

  return i >= max_index;
}
```