```c
#include <stdint.h>

int32_t _Z8is_primex(int64_t x) {
  if (x < 2) {
    return 0;
  }
  if (x < 4) {
    return 1;
  }
  for (int64_t i = 2; ; i++) {
    int64_t j = x % i;
    if (j == 0) {
      return 0;
    }
    i++;
    int64_t k = i * i;
    if (k > x) {
      return 1;
    }
  }
}
```
<|im_end|>