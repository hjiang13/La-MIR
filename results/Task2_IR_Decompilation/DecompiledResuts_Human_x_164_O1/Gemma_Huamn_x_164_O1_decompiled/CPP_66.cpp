```c
#include <stdint.h>

int digitSum(const char* str) {
  int len = strlen(str);
  if (len == 0) {
    return 0;
  }

  int sum = 0;
  for (int i = 0; i < len; i++) {
    char c = str[i];
    if (c >= '0' && c <= '9') {
      sum += c - '0';
    }
  }
  return sum;
}
```