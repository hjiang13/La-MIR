int prime_fib(int);

int prime_fib(int n) {
  int i = 1;
  int j = 2;
  int k = 0;
  while (k < n) {
    j = j + i;
    if (j < 4) {
      i = 1;
      j = 2;
      k = 0;
      continue;
    }
    for (int l = 2; l * l <= j; l++) {
      if (j % l == 0) {
        break;
      }
    }
    i = 1;
    j = 2;
    k++;
  }
  return j;
}
```
<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (prime_fib(1) == 2);
    assert (prime_fib(2) == 3);
    assert (prime_fib(3) == 5);
    assert (prime_fib(4) == 13);
    assert (prime_fib(5) == 89);
    assert (prime_fib(6) == 233);
    assert (prime_fib(7) == 1597);
    assert (prime_fib(8) == 28657);
    assert (prime_fib(9) == 514229);
    assert (prime_fib(10) == 433494437);
}
