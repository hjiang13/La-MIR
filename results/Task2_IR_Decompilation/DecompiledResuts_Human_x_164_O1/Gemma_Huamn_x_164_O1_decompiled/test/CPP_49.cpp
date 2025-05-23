int mod(int a, int b) {
  if (a <= 0) {
    return 1;
  }
  int i = 0;
  int r = 1;
  while (i < a) {
    r = (r << 1) % b;
    i++;
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
