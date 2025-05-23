```c
int largest_divisori(int a0) {
  if (a0 < 4) {
    return 1;
  }
  int a4 = 2;
  int a5 = a0 % a4;
  int a6 = a0 / a4;
  if (a5 == 0) {
    return a6;
  }
  int a9 = a4 + 1;
  int a10 = a9 * a9;
  while (a10 <= a0) {
    a4 = a9;
    a5 = a0 % a4;
    a6 = a0 / a4;
    if (a5 == 0) {
      return a6;
    }
    a9 = a4 + 1;
    a10 = a9 * a9;
  }
  return 1;
}
```