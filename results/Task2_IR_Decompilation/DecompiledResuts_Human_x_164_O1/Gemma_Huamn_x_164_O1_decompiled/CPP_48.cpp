```c
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
 
_Bool is_palindrome(const char* str) {
  size_t len = strlen(str);
  char* reversed = malloc(len + 1);
  if (reversed == NULL) {
    return 0;
  }
  strcpy(reversed, str);
  for (size_t i = 0; i < len / 2; ++i) {
    char tmp = reversed[i];
    reversed[i] = reversed[len - i - 1];
    reversed[len - i - 1] = tmp;
  }
  _Bool result = strcmp(str, reversed) == 0;
  free(reversed);
  return result;
}
```