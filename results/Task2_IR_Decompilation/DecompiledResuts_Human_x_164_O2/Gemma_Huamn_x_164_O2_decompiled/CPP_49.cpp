```c
int _Z4modpii(int a, int b) {
  if (a > 0) {
    int c = a - 1;
    int d = a & 3;
    if (c < 3) {
      int e = 1;
      int f = 1;
      if (d == 0) {
        return 1;
      } else {
        do {
          int g = e << 1;
          e = g % b;
          d--;
        } while (d != 0);
        return e;
      }
    } else {
      int h = a & -4;
      int e = 1;
      for (;;) {
        int g = e << 1;
        e = g % b;
        g = e << 1;
        e = g % b;
        g = e << 1;
        e = g % b;
        g = e << 1;
        e = g % b;
        h = h - 4;
        if (h == 0) {
          break;
        }
      }
      int f = e;
      int d = 1;
      if (d == 0) {
        return f;
      } else {
        do {
          int g = d << 1;
          d = g % b;
          d--;
        } while (d != 0);
        return d;
      }
    }
  }
  return 1;
}
```