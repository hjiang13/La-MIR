```c
#include <stdint.h>

int32_t prime_length(const char* str) {
  int32_t len = strlen(str);
  if (len < 2) {
    return 0;
  }
  if (len < 4) {
    return 1;
  }
  for (int32_t i = 2; ; i++) {
    if (len % i == 0) {
      if (i * i > len) {
        return 1;
      }
    } else {
      if (i * i > len) {
        return 0;
      }
    }
    i++;
  }
}
```
<|im_end|>