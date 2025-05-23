int _Z15is_simple_powerii(int a1, int a2) {
  if (a1 <= 0) {
    return a1 > 0;
  }
  int v4 = 0;
  int v5 = 1;
  while (v5 * a2 <= a1 && v4 < 99) {
    v5 = v5 * a2;
    ++v4;
  }
  return v5 == a1 || (v5 * a2 > a1 && v4 < 99);
}
```
<|im_end|>
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
