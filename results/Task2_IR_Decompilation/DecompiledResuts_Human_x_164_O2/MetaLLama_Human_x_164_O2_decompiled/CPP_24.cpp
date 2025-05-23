int largest_divisor(int n) {
  if (n < 4) {
    return 1;
  }
  int i = 2;
  while (1) {
    int r = n % i;
    int q = n / i;
    if (r == 0) {
      return q;
    }
    i = i + 1;
    int i2 = i * i;
    if (i2 > n) {
      return 1;
    }
  }
}
