int mod(int a, int b) {
  int r = 1;
  while (b != 0) {
    if (a < b) {
      r = 0;
      break;
    }
    a -= b;
    b /= 2;
  }
  return r;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (modp(3, 5) == 3);
    assert (modp(1101, 101) == 2);
    assert (modp(0, 101) == 1);
    assert (modp(3, 11) == 8);
    assert (modp(100, 101) == 1);
    assert (modp(30, 5) == 4);
    assert (modp(31, 5) == 3);
}
