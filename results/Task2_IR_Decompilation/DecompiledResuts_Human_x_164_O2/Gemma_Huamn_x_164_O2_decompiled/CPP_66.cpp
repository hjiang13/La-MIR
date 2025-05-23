```c
#include <stdint.h>

int digitSum(const char* str) {
  int32_t sum = 0;
  size_t len = strlen(str);
  for (size_t i = 0; i < len; ++i) {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      sum += c - '0';
    }
  }
  return sum;
}
```