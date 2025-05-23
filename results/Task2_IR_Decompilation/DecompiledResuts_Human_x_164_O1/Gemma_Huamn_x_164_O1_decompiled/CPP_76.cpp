```c
int _Z15is_simple_powerii(int a1, int a2) {
  if (a1 <= 0) {
    return a1 > 0;
  }
  int v4 = 0;
  int v5 = 1;
  while (v5 * a2 <= a1 && v4 < 99) {
    v5 = v5 * a2;
    ++v4;
  }
  return v5 == a1 || (v5 * a2 > a1 && v4 < 99);
}
```
<|im_end|>