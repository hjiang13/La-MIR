```c
int _Z8is_primex(long long int);

int _Z8is_primex(long long int a1) {
  if (a1 < 2LL) {
    return 0;
  }
  if (a1 < 4LL) {
    return a1 & 1LL;
  }
  for (long long int i2 = 3LL; i2 * i2 <= a1; i2 += 1LL) {
    if (a1 % i2 == 0LL) {
      return 0;
    }
  }
  return 1;
}
```