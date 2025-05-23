```c
#include <stdint.h>

int is_nested(const char* str, size_t len) {
  if (len == 0) {
    return 0;
  }

  int nesting_level = 0;
  int max_nesting_level = 0;
  for (size_t i = 0; i < len; ++i) {
    if (str[i] == '{') {
      nesting_level++;
    } else if (str[i] == '}') {
      nesting_level--;
    }
    max_nesting_level = (nesting_level > max_nesting_level) ? nesting_level : max_nesting_level;
  }
  return len > 0 && max_nesting_level > 0;
}
```