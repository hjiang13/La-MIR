```c
#include <stdint.h>

int vowels_count(const char* s) {
  char vowels[] = "aeiouAEIOU";
  int count = 0;
  for (size_t i = 0; i < strlen(s); i++) {
    for (size_t j = 0; j < 10; j++) {
      if (s[i] == vowels[j]) {
        count++;
        break;
      }
    }
  }
  return count;
}
```