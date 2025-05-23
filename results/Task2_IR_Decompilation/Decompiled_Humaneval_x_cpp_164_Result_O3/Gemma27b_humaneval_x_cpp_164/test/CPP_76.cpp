#include <stdint.h>

int32_t is_simple_power(int32_t arg0, int32_t arg1) {
  if (arg0 <= 0) {
    return arg0 > 0;
  }
  int32_t i = 0;
  int32_t power = 1;
  while (power * arg1 <= arg0 && i < 99) {
    i++;
    power *= arg1;
    if (power == arg0) {
      return 1;
    }
  }
  return power * arg1 > arg0;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_simple_power(1, 4)== true);
    assert (is_simple_power(2, 2)==true);
    assert (is_simple_power(8, 2)==true);
    assert (is_simple_power(3, 2)==false);
    assert (is_simple_power(3, 1)==false);
    assert (is_simple_power(5, 3)==false);
    assert (is_simple_power(16, 2)== true);
    assert (is_simple_power(143214, 16)== false);
    assert (is_simple_power(4, 2)==true);
    assert (is_simple_power(9, 3)==true);
    assert (is_simple_power(16, 4)==true);
    assert (is_simple_power(24, 2)==false);
    assert (is_simple_power(128, 4)==false);
    assert (is_simple_power(12, 6)==false);
    assert (is_simple_power(1, 1)==true);
    assert (is_simple_power(1, 12)==true);
}
