```c
#include <stdlib.h>
#include <string.h>

int tolower(int c) {
  return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

int count_distinct_characters(const char* str) {
  char* s = (char*)str;
  size_t len = strlen(str);

  if (len == 0) {
    return 0;
  }

  for (size_t i = 0; i < len; ++i) {
    s[i] = tolower(s[i]);
  }

  char* seen = NULL;
  char* current = NULL;
  size_t count = 0;

  for (size_t i = 0; i < len; ++i) {
    char c = s[i];
    char* p = seen;

    while (p != current) {
      if (*p == c) {
        break;
      }
      p++;
    }

    if (p == current) {
      if (current == NULL) {
        seen = malloc(1);
        current = seen;
      } else {
        size_t old_size = current - seen;
        size_t new_size = old_size + 1;
        seen = realloc(seen, new_size);
        current = seen + new_size;
      }
      *current = c;
      count++;
    }
  }
  free(seen);

  return count;
}

```