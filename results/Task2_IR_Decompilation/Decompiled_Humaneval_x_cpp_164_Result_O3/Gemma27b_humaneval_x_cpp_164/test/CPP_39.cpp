int prime_fib(int n) {
  int i = 1;
  int j = 2;
  int prime_count = 0;
  while (prime_count < n) {
    int k = 2;
    while (k < j) {
      if (j % k == 0) {
        break;
      }
      k++;
    }
    if (k == j) {
      prime_count++;
    }
    int temp = i;
    i = j;
    j = temp + j;
  }
  return i;
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
