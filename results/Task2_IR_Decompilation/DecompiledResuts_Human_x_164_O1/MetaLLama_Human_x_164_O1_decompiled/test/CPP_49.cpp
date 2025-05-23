int modp(int a, int b) {
  if (a > 0) {
    int x = 0;
    int y = 1;
    do {
      y = (y << 1) % b;
      x++;
    } while (x != a);
    return y;
  } else {
    return 1;
  }
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
