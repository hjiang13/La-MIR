int largest_prime_factor(int n) {
  if (n < 4) return n;
  int i = 2;
  while (1) {
    if (n % i == 0 && n > i) {
      while (n % i == 0) n /= i;
    }
    i++;
    if (i * i > n) break;
  }
  return n;
}
