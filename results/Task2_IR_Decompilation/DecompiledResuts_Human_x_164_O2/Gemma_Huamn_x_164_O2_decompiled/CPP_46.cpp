```c
#include <stdio.h>

int fib4(int n) {
  int fib[100];
  fib[0] = 0;
  fib[1] = 0;
  fib[2] = 2;
  fib[3] = 0;
  if (n < 4) {
    return fib[n];
  }
  fib[4] = 2;
  if (n == 5) {
    return fib[n - 1];
  }
  for (int i = 6; i <= n; i++) {
    fib[i] = fib[i - 3] + fib[i - 1] + fib[i - 2];
  }
  return fib[n - 1];
}

int main() {
  int n = 10;
  int result = fib4(n);
  printf("fib4(%d) = %d\n", n, result);
  return 0;
}
```