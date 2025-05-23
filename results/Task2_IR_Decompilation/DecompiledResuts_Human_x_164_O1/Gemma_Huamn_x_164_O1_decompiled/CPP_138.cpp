```c
int _Z20is_equal_to_sum_eveni(int a0) {
  int a2 = a0 & 1;
  int a3 = a2 == 0;
  int a4 = a0 > 7;
  int a5 = a4 & a3;
  return a5;
}
```