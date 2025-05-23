```c
int mod(int a, int b) {
  if (a <= 0) {
    return 1;
  }
  int i = 0;
  int r = 1;
  while (i < a) {
    r = (r << 1) % b;
    i++;
  }
  return r;
}
```