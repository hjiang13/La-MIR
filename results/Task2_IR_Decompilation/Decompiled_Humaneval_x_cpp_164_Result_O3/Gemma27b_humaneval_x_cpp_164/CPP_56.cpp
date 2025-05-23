```c
#include <stdint.h>
#include <stddef.h>

int correct_bracketing(const char* str, size_t len) {
  if (len == 0) {
    return 1;
  }

  int balance = 0;
  for (size_t i = 0; i < len; ++i) {
    if (str[i] == '(') {
      ++balance;
    } else if (str[i] == ')') {
      --balance;
    }

    if (balance < 0) {
      return 0;
    }
  }

  return balance == 0;
}
```