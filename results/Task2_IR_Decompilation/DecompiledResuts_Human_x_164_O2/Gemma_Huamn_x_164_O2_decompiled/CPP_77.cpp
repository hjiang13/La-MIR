```c
int _Z7iscuberi(int a0) {
  int i2 = llvm_abs(a0, 1);
  int i4 = 0;
  while (i4 * i4 * i4 < i2) {
    i4++;
  }
  return i4 * i4 * i4 <= i2;
}

int llvm_abs(int a0, int a1) {
  return a0 < 0 ? -a0 : a0;
}
```