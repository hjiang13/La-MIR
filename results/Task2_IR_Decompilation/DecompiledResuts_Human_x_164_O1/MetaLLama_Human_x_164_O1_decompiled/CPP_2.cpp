Based on the provided LLVM IR code, here is the equivalent C source code:
```
float truncate_number(float x) {
  int i = (int)x;
  float f = (float)i;
  return x - f;
}
```