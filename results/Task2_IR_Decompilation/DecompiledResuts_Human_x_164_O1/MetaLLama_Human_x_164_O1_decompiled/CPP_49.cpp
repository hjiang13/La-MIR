int modp(int a, int b) {
  if (a > 0) {
    int x = 0;
    int y = 1;
    do {
      y = (y << 1) % b;
      x++;
    } while (x != a);
    return y;
  } else {
    return 1;
  }
}
