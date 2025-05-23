int _Z8multiplyii(int a, int b) {
  int a1 = abs(a);
  int a2 = a1 % 10;
  int b1 = abs(b);
  int b2 = b1 % 10;
  int result = a2 * b2;
  return result;
}
```<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (multiply(148, 412) == 16                   );
    assert (multiply(19, 28) == 72       );
    assert (multiply(2020, 1851) == 0);
    assert (multiply(14,-15) == 20   );
    assert (multiply(76, 67) == 42    );
    assert (multiply(17, 27) == 49    );
    assert (multiply(0, 1) == 0);
    assert (multiply(0, 0) == 0);
}
