```c
#include <stdint.h>

int is_happy(const char *s) {
  if (strlen(s) < 3) {
    return 0;
  }
  if (s[2] == s[1]) {
    return 1;
  }
  for (size_t i = 2; i < strlen(s); i++) {
    if (s[i] == s[i - 2]) {
      return 1;
    }
  }
  return 0;
}
```