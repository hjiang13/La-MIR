Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
int greatest_common_divisor(int a, int b) {
  int c;
  int d;
  int e;
  int f;
  c = a;
  d = b;
  while (1) {
    if (c < d) {
      f = c;
      c = d;
      d = f;
    }
    c = c % d;
    if (c == 0) {
      return d;
    }
  }
}
```

Please note that I've kept the variable names as simple as possible (a, b, c, d, e, f) since the IR code doesn't provide meaningful names. Also, the generated C code might not be optimal or human-readable, as it's a direct translation from the LLVM IR code.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (greatest_common_divisor(3, 7) == 1);
     assert (greatest_common_divisor(10, 15) == 5);
      assert (greatest_common_divisor(49, 14) == 7);
     assert (greatest_common_divisor(144, 60) == 12);
}
