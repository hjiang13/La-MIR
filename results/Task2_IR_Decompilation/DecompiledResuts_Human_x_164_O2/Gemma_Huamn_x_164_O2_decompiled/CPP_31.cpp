```c
#include <stdint.h>

int32_t is_prime(int64_t x) {
  if (x < 2) {
    return 0;
  }
  if (x < 4) {
    return 1;
  }
  for (int64_t i = 2; (i * i) <= x; i++) {
    if ((x % i) == 0) {
      return 0;
    }
  }
  return 1;
}
```