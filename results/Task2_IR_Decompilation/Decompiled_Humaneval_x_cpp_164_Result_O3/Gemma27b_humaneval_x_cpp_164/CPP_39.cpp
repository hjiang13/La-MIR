```c
int prime_fib(int n) {
  int i = 1;
  int j = 2;
  int prime_count = 0;
  while (prime_count < n) {
    int k = 2;
    while (k < j) {
      if (j % k == 0) {
        break;
      }
      k++;
    }
    if (k == j) {
      prime_count++;
    }
    int temp = i;
    i = j;
    j = temp + j;
  }
  return i;
}
```