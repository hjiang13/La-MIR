```c
int fib(int n) {
  int arr[100] = {0};
  arr[0] = 0;
  arr[1] = 0;
  arr[2] = 1;
  if (n < 3) {
    return arr[n];
  }
  int i = n + 1;
  int j = 4;
  arr[3] = 1;
  if (n == 4) {
    return arr[n];
  }
  for (i = 4; i < n; i += 1) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }
  return arr[n];
}
```