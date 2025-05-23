int x_or_y(int a, int b, int c) {
  if (a > 1) {
    if (a < 4) {
      int d = a % 2;
      if (d == 0) {
        return c;
      } else {
        return b;
      }
    } else {
      int e = 2;
      int f = a % e;
      while (1) {
        if (f == 0) {
          return c;
        } else {
          e = e + 1;
          f = a % e;
          if (e * e > a) {
            break;
          }
        }
      }
      return b;
    }
  } else {
    return b;
  }
}
