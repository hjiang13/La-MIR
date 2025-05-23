```c
int _Z9prime_fibi(int);

int _Z9prime_fibi(int a1) {
  int v2;
  int v3;
  int v4;
  int v5;
  int v6;
  v2 = 1;
  v3 = 2;
  v4 = 0;
  while (v4 < a1) {
    v5 = v2 + v3;
    if (v3 < 4 || (v3 & 1) == 0) {
      v2 = v3;
      v3 = v5;
      v4 = v4 + 1;
    } else {
      int v7 = 3;
      while (v7 * v7 <= v3) {
        if (v3 % v7 == 0) {
          v2 = v3;
          v3 = v5;
          v4 = v4 + 1;
          break;
        }
        v7 = v7 + 1;
      }
      if (v7 * v7 > v3) {
        v2 = v3;
        v3 = v5;
        v4 = v4 + 1;
      }
    }
  }
  return v3;
}
```