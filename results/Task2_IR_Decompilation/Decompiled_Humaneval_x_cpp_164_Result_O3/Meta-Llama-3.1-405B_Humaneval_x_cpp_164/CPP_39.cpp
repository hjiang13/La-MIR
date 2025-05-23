int prime_fib(int n) {
  int a = 1;
  int b = 2;
  int i = 0;
  while (i < n) {
    int t = a + b;
    if (b < 4) {
      a = b;
      b = t;
      i++;
    } else {
      int d = 2;
      do {
        if (b % d == 0) break;
        d++;
        if (d * d > b) {
          a = b;
          b = t;
          i++;
          break;
        }
      } while (1);
    }
  }
  return b;
}
