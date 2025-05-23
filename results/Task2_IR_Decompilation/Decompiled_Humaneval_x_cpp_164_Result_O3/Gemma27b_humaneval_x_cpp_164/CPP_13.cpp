```c
int greatest_common_divisor(int a, int b) {
  while (1) {
    int tmp = a;
    a = b;
    b = tmp % b;
    if (b == 0) {
      return a;
    }
  }
}
```