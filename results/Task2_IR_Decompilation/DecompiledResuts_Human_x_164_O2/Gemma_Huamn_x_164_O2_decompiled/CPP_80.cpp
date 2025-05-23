```c
#include <stdint.h>

bool is_happy(const char* str, size_t len) {
  if (len < 3) {
    return false;
  }

  char first = str[1];
  char second = str[2];
  if (second == first) {
    return true;
  }

  for (size_t i = 2; i < len; ++i) {
    if (str[i] == first && i > 2) {
      return true;
    }
    if (str[i] == second && i > 2) {
      return false;
    }
  }
  return true;
}
```