```c
#include <stdint.h>
#include <stddef.h>

int same_chars(const char* s1, const char* s2) {
  if (s1[0] == 0) {
    return s2[0] == 0;
  }
  size_t s1_len = strlen(s1);
  if (s1_len != strlen(s2)) {
    return 0;
  }
  
  for (size_t i = 0; i < s1_len; i++) {
    if (s1[i] != s2[i]) {
      return 0;
    }
  }
  
  return 1;
}
```