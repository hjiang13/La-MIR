```c
int _Z20largest_prime_factori(int);

int _Z20largest_prime_factori(int a1) {
  if (a1 < 4) {
    return a1;
  }
  int a2 = 2;
  int a3 = a1;
  while (1) {
    int a4 = a3 % a2;
    if (a4 == 0 && a3 > a2) {
      while (1) {
        int a5 = a3 / a2;
        int a6 = a5 % a2;
        if (a6 == 0 && a5 > a2) {
          a3 = a5;
        } else {
          break;
        }
      }
    }
    a2++;
    int a7 = a2 * a2;
    if (a7 > a3) {
      return a3;
    }
  }
}
```