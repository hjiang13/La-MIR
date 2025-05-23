```c
int _Z7iscuberi(int);

int _Z7iscuberi(int x) {
  int x1 = abs(x);
  int i = 0;
  while (i*i*i < x1) {
    i = i + 1;
  }
  return i*i*i <= x1;
}
```