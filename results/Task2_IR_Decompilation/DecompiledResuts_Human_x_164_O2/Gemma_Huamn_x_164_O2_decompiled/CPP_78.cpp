```c
#include <stdint.h>

int hex_key(const char* str) {
  char key[32] = "2357BD";
  int len = 6;
  int i;
  int match = 0;

  if (strlen(str) == 0) {
    return 0;
  }

  for (i = 0; i < len; i++) {
    if (key[i] != str[i]) {
      return 0;
    }
  }

  return 1;
}
```