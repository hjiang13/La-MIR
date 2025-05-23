#include <math.h>
int any_int(float x, float y, float z) {
  if (roundf(x) != x || roundf(y) != y || roundf(z) != z) {
    return 1;
  }
  if (x + y == z || x + z == y || y + z == x) {
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
