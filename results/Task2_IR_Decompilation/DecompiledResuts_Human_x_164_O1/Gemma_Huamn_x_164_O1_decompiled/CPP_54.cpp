```c
#include <stdint.h>

int same_chars(const char* s1, const char* s2) {
  if (*((uint64_t*)s1) == 0) {
    return * ((uint64_t*)s2) == 0;
  }

  const char* p1 = *((const char**)s1 + 1);
  const char* p2 = *((const char**)s2 + 1);
  size_t len1 = *((uint64_t*)s1);
  size_t len2 = *((uint64_t*)s2);

  if (len1 > 3) {
    for (size_t i = 0; i < len1 / 4; i++) {
      if (*(uint32_t*)(p1 + i * 4) != *(uint32_t*)(p2 + i * 4)) {
        return 0;
      }
    }
    p1 += len1 / 4 * 4;
    p2 += len1 / 4 * 4;
    len1 %= 4;
  }

  if (len1 > 0) {
    for (size_t i = 0; i < len1; i++) {
      if (p1[i] != p2[i]) {
        return 0;
      }
    }
  }
  return 1;
}
```