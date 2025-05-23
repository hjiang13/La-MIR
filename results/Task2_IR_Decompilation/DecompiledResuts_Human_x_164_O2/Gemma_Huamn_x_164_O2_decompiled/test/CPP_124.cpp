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
