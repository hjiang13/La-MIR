```c
#include <stdint.h>
#include <stddef.h>

int is_bored(const char* str) {
  size_t len = strlen(str);
  if (len == 0) {
    return 0;
  }
  int count = 0;
  int i = 0;
  int state = 1;
  for (; i < len; i++) {
    if (str[i] == ' ') {
      count += state;
    } else if (str[i] == 'I' && state) {
      count += 1;
      state = 0;
    } else {
      state = (str[i] == '.' || str[i] == '?' || str[i] == '!');
    }
  }
  return count;
}

```