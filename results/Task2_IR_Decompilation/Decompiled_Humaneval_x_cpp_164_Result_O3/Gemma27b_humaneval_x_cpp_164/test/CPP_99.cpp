#include <stdlib.h>

int closest_integer(const char* str) {
  double d = strtod(str, NULL);
  return (int)round(d);
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
