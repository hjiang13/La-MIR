```c
#include <stdint.h>

extern int strtol(const char *nptr, char **endptr, int base);

int valid_date(const char *s) {
  if (strlen(s) != 10) {
    return 0;
  }
  const char *p = s;
  for (int i = 0; i < 10; ++i) {
    if (*p < '0' || *p > '9') {
      return 0;
    }
    ++p;
  }
  int year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
  int month = (s[0] - '0') * 10 + (s[1] - '0');
  int day = (s[3] - '0') * 10 + (s[4] - '0');
  if (month < 1 || month > 12) {
    return 0;
  }
  if (day < 1 || day > 31) {
    return 0;
  }
  if (year < 1 || year > 3000) {
    return 0;
  }
  return 1;
}
```<|im_end|>