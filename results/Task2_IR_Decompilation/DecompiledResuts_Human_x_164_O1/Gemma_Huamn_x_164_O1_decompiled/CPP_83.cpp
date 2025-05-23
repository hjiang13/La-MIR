```c
int starts_one_endsi(int arg) {
  if (arg < 1) {
    return 0;
  }
  if (arg == 1) {
    return 1;
  }
  if (arg > 2) {
    int i = 2;
    int res = 18;
    while (i != arg) {
      res = res * 10;
      i = i + 1;
    }
    return res;
  }
  return 18;
}

```