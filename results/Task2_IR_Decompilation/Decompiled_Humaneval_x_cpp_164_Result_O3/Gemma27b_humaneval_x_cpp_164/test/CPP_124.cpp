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


#undef NDEBUG
#include<assert.h>
int main(){
    assert (valid_date("03-11-2000") == true);
    assert (valid_date("15-01-2012") == false);
    assert (valid_date("04-0-2040") == false);
    assert (valid_date("06-04-2020") == true);
    assert (valid_date("01-01-2007") == true);
    assert (valid_date("03-32-2011") == false);
    assert (valid_date("") == false);
    assert (valid_date("04-31-3000") == false);
    assert (valid_date("06-06-2005") == true);
    assert (valid_date("21-31-2000") == false);
    assert (valid_date("04-12-2003") == true);
    assert (valid_date("04122003") == false);
    assert (valid_date("20030412") == false);
    assert (valid_date("2003-04") == false);
    assert (valid_date("2003-04-12") == false);
    assert (valid_date("04-2003") == false);
}
