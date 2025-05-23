Based on the provided LLVM IR code, here is the equivalent C source code:
```c
int largest_divisor(int n) {
  int i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return n / i;
    }
    i++;
  }
  return 1;
}
```
Note that I've only extracted the relevant function definition from the IR code and converted it to C syntax.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_divisor(3) == 1);
    assert (largest_divisor(7) == 1);
    assert (largest_divisor(10) == 5);
    assert (largest_divisor(100) == 50);
    assert (largest_divisor(49) == 7);
}
