int largest_divisor(int n) {
  if (n < 4) return 1;
  int d = 2;
  while (1) {
    int q = n / d;
    int r = n % d;
    if (r == 0) return q;
    d++;
    if (d * d > n) return 1;
  }
}
