int is_prime(long long n) {
  if (n < 2) return 0;
  if (n < 4 || (n & 1) == 0) return 0;
  long long i = 3;
  while (i * i <= n) {
    if (n % i == 0) return 0;
    i += 1;
  }
  return 1;
}
