```c
#include <stdint.h>

int hex_key(const char* s) {
  char t[7] = "2357BD";
  size_t l = 6;
  int i = 0;
  while (i < l) {
    if (s[i] == t[i]) {
      return 1;
    }
    i++;
  }
  return 0;
}
```