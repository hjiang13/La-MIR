```c
#include <stdint.h>

int prime_length(const char* s) {
  int64_t len = strlen(s);
  int32_t l = len;
  if (l < 2) return 0;
  if (l < 4) return 1;
  int32_t i = 2;
  while (1) {
    int32_t r = l % i;
    if (r == 0) {
      if (i * i > l) return 1;
    }
    i++;
  }
}

```