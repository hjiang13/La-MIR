```c
#include <string.h>

int vowels_count(const char* str) {
  char vowels[10] = "aeiouAEIOU";

  int count = 0;
  size_t len = strlen(str);
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 0; j < 10; j++) {
      if (str[i] == vowels[j]) {
        count++;
        break;
      }
    }
  }

  return count;
}
```