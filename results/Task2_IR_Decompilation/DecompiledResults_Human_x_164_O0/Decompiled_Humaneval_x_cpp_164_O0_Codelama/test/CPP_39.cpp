int prime_fib(int n) {
  int prime[n];
  int i, j;
  int count = 0;

  for (i = 2; i <= n; i++) {
    for (j = 2; j <= i / j; j++) {
      if (i % j == 0) {
        break;
      }
    }
    if (j > i / j) {
      prime[count] = i;
      count++;
    }
  }

  return prime[count - 1];
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
