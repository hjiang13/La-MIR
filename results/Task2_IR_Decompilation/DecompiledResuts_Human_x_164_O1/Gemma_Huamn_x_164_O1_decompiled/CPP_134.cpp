```c
#include <stddef.h>

int check_if_last_char_is_a_letter(const char* s) {
  size_t len = strlen(s);
  if (len == 0) {
    return 0;
  }
  char c = s[len - 1];
  if (c < 'A' || c > 'Z') {
    if (c < 'a' || c > 'z') {
      return 0;
    }
  }
  return 1;
}
```