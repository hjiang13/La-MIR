```c
long long int special_factorial(int a0) {
  if (a0 < 1) {
    return 1LL;
  } else {
    long long int i1 = 1LL;
    long long int i2 = 1LL;
    long long int i3 = 1LL;
    for (int i = 1; i <= a0 + 1; ++i) {
      i1 = i1 * i2 * i3;
      i2 = i3;
      i3 = i1;
    }
    return i1;
  }
}
```