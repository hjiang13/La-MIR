```c
#include <stdint.h>

int correct_bracketing(const char* str, size_t len) {
  if (len == 0) {
    return 1;
  }
  int count = 0;
  for (size_t i = 0; i < len; ++i) {
    if (str[i] == '(') {
      ++count;
    } else if (str[i] == ')') {
      --count;
    }
    if (count < 0) {
      return 0;
    }
  }
  return count == 0;
}
```