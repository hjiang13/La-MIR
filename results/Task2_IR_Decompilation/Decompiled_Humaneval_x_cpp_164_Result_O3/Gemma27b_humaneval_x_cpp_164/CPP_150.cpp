```c
int _Z6x_or_yiii(int a1, int a2, int a3) {
  if (a1 > 1) {
    if (a1 < 4) {
      if (((a1 > 1) ? 1 : 0) & 1) {
        return a3;
      }
      return a2;
    }
    int i = 2;
    unsigned char v1 = (a1 > 1) ? 1 : 0;
    while (true) {
      int v2 = a1 % i;
      if (v2 == 0) {
        v1 = 0;
      }
      int v3 = i + 1;
      int v4 = v3 * v3;
      if (v4 > a1) {
        if ((v1 & 1) == 0) {
          return a2;
        }
        return a3;
      }
      i = v3;
    }
  }
  if (((a1 > 1) ? 1 : 0) & 1) {
    return a3;
  }
  return a2;
}
```<|im_end|>