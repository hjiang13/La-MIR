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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (any_int(2, 3, 1)==true);
    assert (any_int(2.5, 2, 3)==false);
    assert (any_int(1.5, 5, 3.5)==false);
    assert (any_int(2, 6, 2)==false);
    assert (any_int(4, 2, 2)==true);
    assert (any_int(2.2, 2.2, 2.2)==false);
    assert (any_int(-4, 6, 2)==true);
    assert (any_int(2,1,1)==true);
    assert (any_int(3,4,7)==true);
    assert (any_int(3.01,4,7)==false);
}
