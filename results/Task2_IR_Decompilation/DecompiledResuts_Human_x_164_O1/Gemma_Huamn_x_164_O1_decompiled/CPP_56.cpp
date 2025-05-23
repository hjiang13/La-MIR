```c
#include <stdint.h>

int correct_bracketing(const char* str) {
  size_t len = strlen(str);
  if (len == 0) {
    return 0;
  }

  int balance = 0;

  if (str[0] == '[') {
    balance = 1;
  } else if (str[0] == ']') {
    balance = -1;
  }

  if (balance < 0) {
    return 0;
  }

  for (size_t i = 1; i < len; i++) {
    if (str[i] == '[') {
      balance++;
    } else if (str[i] == ']') {
      balance--;
    }

    if (balance < 0) {
      return 0;
    }
  }
  return balance == 0;
}
```