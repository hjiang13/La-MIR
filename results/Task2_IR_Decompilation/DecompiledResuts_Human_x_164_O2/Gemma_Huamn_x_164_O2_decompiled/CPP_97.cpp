```c
int _Z8multiplyii(int a, int b) {
  int a1 = abs(a);
  int a2 = a1 % 10;
  int b1 = abs(b);
  int b2 = b1 % 10;
  int result = a2 * b2;
  return result;
}

```