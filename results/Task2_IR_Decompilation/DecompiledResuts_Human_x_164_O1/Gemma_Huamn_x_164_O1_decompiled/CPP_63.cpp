```c
int fib(int n) {
  int fib_array[100];
  fib_array[0] = 0;
  fib_array[1] = 0;
  fib_array[2] = 1;
  if (n < 3) {
    return fib_array[n];
  }
  for (int i = 3; i <= n; i++) {
    fib_array[i] = fib_array[i - 2] + fib_array[i - 1];
  }
  return fib_array[n];
}
```