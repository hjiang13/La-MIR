Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
int f(int n) {
  int a[1000];
  a[0] = 0;
  a[1] = 1;
  int i = 2;
  while (i <= n) {
    a[i] = a[i - 1] + a[i - 2];
    i++;
  }
  return a[n];
}
```