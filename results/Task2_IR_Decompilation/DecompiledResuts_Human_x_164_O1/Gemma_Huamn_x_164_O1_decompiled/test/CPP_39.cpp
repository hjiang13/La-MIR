int _Z9prime_fibi(int);

int _Z9prime_fibi(int a1) {
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  v2 = 1;
  v3 = 2;
  v4 = 0;
  while (v4 < a1) {
    v5 = v2 + v3;
    if (v3 < 4 || (v3 & 1) == 0) {
      v2 = v3;
      v3 = v5;
      v4 = v4 + 1;
    } else {
      int v7 = 3;
      while (v7 * v7 <= v3) {
        if (v3 % v7 == 0) {
          v2 = v3;
          v3 = v5;
          v4 = v4 + 1;
          break;
        }
        v7 = v7 + 1;
      }
      if (v7 * v7 > v3) {
        v2 = v3;
        v3 = v5;
        v4 = v4 + 1;
      }
    }
  }
  return v3;
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
