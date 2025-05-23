int prime_fib(int n) {
  int a = 1;
  int b = 2;
  int i = 0;
  while (i < n) {
    int t = a + b;
    if (b < 4) {
      a = b;
      b = t;
      i++;
    } else {
      int d = 2;
      do {
        if (b % d == 0) break;
        d++;
        if (d * d > b) {
          a = b;
          b = t;
          i++;
          break;
        }
      } while (1);
    }
  }
  return b;
}

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
