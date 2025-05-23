int x_or_y(int a, int b, int c) {
  int d;
  if (a > 1) d = 1; else d = 0;
  if (a < 4) {
    while (1) {
      if (d & 1) {
        return b;
      } else {
        return c;
      }
      int e = 2;
      while (1) {
        int f = a % e;
        if (f == 0) d = 0; else d = 1;
        e = e + 1;
        int g = e * e;
        if (g > a) break;
      }
    }
  }
}
