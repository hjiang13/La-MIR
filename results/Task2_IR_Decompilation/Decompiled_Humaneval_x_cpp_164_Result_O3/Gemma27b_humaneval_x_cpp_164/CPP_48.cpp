```c
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(const char* s) {
  int len = strlen(s);
  char* rev = malloc(len + 1);
  if (rev == NULL) {
    return 0;
  }
  strcpy(rev, s);
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    char temp = rev[i];
    rev[i] = rev[j];
    rev[j] = temp;
  }
  int result = strcmp(s, rev) == 0;
  free(rev);
  return result;
}
```