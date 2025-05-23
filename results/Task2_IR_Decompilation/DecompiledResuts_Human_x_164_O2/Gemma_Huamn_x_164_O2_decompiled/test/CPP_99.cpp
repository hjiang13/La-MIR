#include <stdio.h>

double strtod(const char* str, char** endptr);

int closest_integer(const std::string& str) {
  const char* cstr = str.c_str();
  double d = strtod(cstr, nullptr);
  double rounded = round(d);
  return (int)rounded;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (closest_integer("10") == 10);
    assert (closest_integer("14.5") == 15);
    assert (closest_integer("-15.5") == -16);
    assert (closest_integer("15.3") == 15);
    assert (closest_integer("0") == 0);
}
