```c
#include <stdio.h>

double strtod(const char* str, char** endptr);

int closest_integer(const std::string& str) {
  const char* cstr = str.c_str();
  double d = strtod(cstr, nullptr);
  double rounded = round(d);
  return (int)rounded;
}
```