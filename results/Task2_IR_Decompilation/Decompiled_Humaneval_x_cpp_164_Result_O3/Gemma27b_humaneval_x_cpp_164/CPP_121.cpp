```c
int solutions(int* a, int len) {
  if (len == 0) {
    return 0;
  }
  int sum = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] % 2 == 1) {
      sum += a[i];
    }
  }
  return sum;
}
```