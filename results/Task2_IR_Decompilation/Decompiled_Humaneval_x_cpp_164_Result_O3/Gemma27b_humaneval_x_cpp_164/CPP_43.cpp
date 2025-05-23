```c
#include <stdint.h>

int32_t* pairs_sum_to_zero(int32_t* vec, int32_t len) {
  int32_t* end = vec + len;
  int32_t* i = vec + 1;
  int32_t* j = vec;
  for (; i < end; ++i) {
    for (j = vec; j < i; ++j) {
      if (*i + *j == 0) {
        return 1;
      }
    }
  }
  return 0;
}
```