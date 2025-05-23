Based on the provided LLVM IR code, here is the corresponding C source code:

```c
int largest_divisor(int n) {
  int result;
  int i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      result = n / i;
      return result;
    } else {
      i += 1;
    }
  }
  result = 1;
  return result;
}
```