```c
float any_int(float a, float b, float c) {
  if (llvm.round.f32(a) != a || llvm.round.f32(b) != b || llvm.round.f32(c) != c) {
    return 1;
  }
  if (a + b == c || a + c == b || b + c == a) {
    return 1;
  }
  return 0;
}
```