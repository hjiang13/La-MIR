```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_date(char* s) {
  if (strlen(s) != 10) {
    return 0;
  }
  char *p = s;
  int year = atoi(p);
  p += 4;
  int month = atoi(p);
  p += 2;
  int day = atoi(p);

  if (day < 1 || day > 31) {
    return 0;
  }
  if (month < 1 || month > 12) {
    return 0;
  }

  if (year < 1 || year > 3000) {
    return 0;
  }
  return 1;
}

int main() {
  char s[] = "2023-10-27";
  int res = valid_date(s);
  printf("Valid Date: %d\n", res);

  return 0;
}
```