```c
int _Z17is_multiply_primei(int a) {
  if (a < 4) {
    return a == 2;
  }
  int i = 2;
  int j = 0;
  int k = a;
  while (1) {
    int l = k % i;
    if ((k > i) && (l == 0)) {
      j++;
      k /= i;
      l = k % i;
      if ((k > i) && (l == 0)) {
        continue;
      }
    }
    i++;
    int m = i * i;
    if (m > k) {
      if (j == 2) {
        return 1;
      }
      return 0;
    }
  }
}
```