```c
int _Z6x_or_yiii(int a, int b, int c) {
  if (a > 1) {
    if (a < 4) {
      return (a & 1) == 0 ? c : b;
    }
    int i = 2;
    int j = (a > 1) ? 1 : 0;
    while (i * i <= a) {
      if (a % i == 0) {
        j = 0;
      }
      i++;
      i *= i;
    }
    return j == 0 ? c : b;
  }
  return (a & 1) == 0 ? c : b;
}
```