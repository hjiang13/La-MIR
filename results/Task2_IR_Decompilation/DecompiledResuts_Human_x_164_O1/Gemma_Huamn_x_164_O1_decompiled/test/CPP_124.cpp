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
