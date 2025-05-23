Here is the C source code generated from the provided LLVM IR code:

```c
int prime_fib(int n) {
  int a = 1;
  int b = 2;
  int i = 0;
  int fib = 0;
  int is_prime = 1;
  int divisor = 2;
  while (i < n) {
    fib = a + b;
    a = b;
    b = fib;
    is_prime = 1;
    divisor = 2;
    while (divisor * divisor <= fib) {
      if (fib % divisor == 0) {
        is_prime = 0;
        break;
      }
      divisor++;
    }
    if (is_prime) {
      i++;
    }
  }
  return fib;
}
```