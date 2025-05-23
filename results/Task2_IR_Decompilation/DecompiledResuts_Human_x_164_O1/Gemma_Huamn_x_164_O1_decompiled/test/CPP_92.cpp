float any_int(float a, float b, float c) {
  if (llvm.round.f32(a) != a || llvm.round.f32(b) != b || llvm.round.f32(c) != c) {
    return 1;
  }
  if (a + b == c || a + c == b || b + c == a) {
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
