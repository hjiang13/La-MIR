```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int valid_date(const char* s) {
  if (strlen(s) != 10) {
    return 0;
  }

  if (s[4] != '-' || s[7] != '-') {
    return 0;
  }

  char year[5];
  strncpy(year, s, 4);
  year[4] = '\0';
  int y = atoi(year);
  if (y < 1 || y > 9999) {
    return 0;
  }

  char month[3];
  strncpy(month, s + 5, 2);
  month[2] = '\0';
  int m = atoi(month);
  if (m < 1 || m > 12) {
    return 0;
  }

  char day[3];
  strncpy(day, s + 8, 2);
  day[2] = '\0';
  int d = atoi(day);
  if (d < 1 || d > 31) {
    return 0;
  }

  if (m == 4 || m == 6 || m == 9 || m == 11) {
    if (d > 30) {
      return 0;
    }
  }

  if (m == 2) {
    if (y % 4 != 0) {
      if (d > 28) {
        return 0;
      }
    } else if (y % 100 == 0 && y % 400 != 0) {
      if (d > 28) {
        return 0;
      }
    } else {
      if (d > 29) {
        return 0;
      }
    }
  }
  return 1;
}

```