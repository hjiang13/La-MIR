Based on the provided LLVM IR code, here is the equivalent C source code:
```c
int largest_divisor(int n) {
  int i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return n / i;
    }
    i++;
  }
  return 1;
}
```
Note that I've only extracted the relevant function definition from the IR code and converted it to C syntax.