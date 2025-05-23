```c
bool is_simple_power(int a, int b) {
  if (a <= 0) {
    return a > 0;
  }
  int i = 0;
  int p = 1;
  while (p * b <= a && i < 99) {
    i++;
    p *= b;
    if (p == a) {
      return true;
    }
  }
  return false;
}
```