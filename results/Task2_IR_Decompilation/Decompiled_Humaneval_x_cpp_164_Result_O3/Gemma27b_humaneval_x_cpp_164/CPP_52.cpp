```c
#include <stdint.h>

int32_t below_threshold(int32_t* vec, int32_t threshold) {
  int32_t* end = vec + (sizeof(vec) / sizeof(vec[0]));
  int32_t size = end - vec;
  if (size == 0) {
    return 1;
  }
  int64_t max_index = size > 1 ? size : 1;
  if (vec[0] >= threshold) {
    return 0;
  }
  for (int64_t i = 1; i < max_index; ++i) {
    if (vec[i] >= threshold) {
      return 0;
    }
  }
  return 1;
}
```