```c
#include <stdint.h>

int32_t is_simple_power(int32_t arg0, int32_t arg1) {
  if (arg0 <= 0) {
    return arg0 > 0;
  }
  int32_t i = 0;
  int32_t power = 1;
  while (power * arg1 <= arg0 && i < 99) {
    i++;
    power *= arg1;
    if (power == arg0) {
      return 1;
    }
  }
  return power * arg1 > arg0;
}

```