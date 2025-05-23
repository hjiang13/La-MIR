```c
int choose_num(int a, int b) {
  if (b < a) {
    return -1;
  }
  if (b == a) {
    if (b % 2 == 1) {
      return -1;
    }
  }
  if (b % 2 == 1) {
    return b + 1;
  }
  return -1;
}
```