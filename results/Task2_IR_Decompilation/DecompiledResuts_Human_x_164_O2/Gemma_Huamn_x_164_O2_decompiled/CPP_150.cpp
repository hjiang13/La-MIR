```c
int x_or_y(int a, int b, int c) {
  if (a > 1) {
    if (a < 4) {
      if (((a > 1) ? 1 : 0) & 1 == 0) {
        return c;
      } else {
        return b;
      }
    }
    int d = 2;
    int e = (a > 1) ? 1 : 0;
    while (true) {
      int f = a % d;
      if (f == 0) {
        e = 0;
      }
      d = d + 1;
      int g = d * d;
      if (g > a) {
        if ((e & 1) == 0) {
          return c;
        } else {
          return b;
        }
      }
    }
  }
  if (((a > 1) ? 1 : 0) & 1 == 0) {
    return c;
  } else {
    return b;
  }
}
```