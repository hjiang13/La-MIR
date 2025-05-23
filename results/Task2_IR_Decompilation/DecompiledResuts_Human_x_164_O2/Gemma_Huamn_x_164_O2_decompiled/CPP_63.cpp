```c
int fib(int n) {
  int fib_array[100] = {0, 0, 1};
  if (n < 3) {
    return fib_array[n];
  }
  int i;
  for (i = 3; i <= n; i++) {
    fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
  }
  return fib_array[n];
}
```