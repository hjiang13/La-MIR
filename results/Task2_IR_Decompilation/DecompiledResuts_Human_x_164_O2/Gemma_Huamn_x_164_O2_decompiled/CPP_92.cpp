```c
float _Z7any_intfff(float a, float b, float c) {
  float d = llvm.round.f32(a);
  if (d != a) {
    return 1;
  }
  float e = llvm.round.f32(b);
  if (e != b) {
    return 1;
  }
  float f = llvm.round.f32(c);
  if (f != c) {
    return 1;
  }
  float g = a + b;
  if (g == c) {
    return 1;
  }
  float h = a + c;
  if (h == b) {
    return 1;
  }
  float i = b + c;
  if (i == a) {
    return 1;
  }
  return 0;
}
```