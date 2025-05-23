```c
int _Z7iscuberi(int a0) {
  int b2 = abs(a0);
  int b4 = 0;
  while (b4 * b4 * b4 < b2) {
    b4++;
  }
  return b4 * b4 * b4 <= b2;
}
```