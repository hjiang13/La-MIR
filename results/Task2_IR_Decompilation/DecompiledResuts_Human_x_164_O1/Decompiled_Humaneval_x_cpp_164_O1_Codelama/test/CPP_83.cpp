#include <iostream>

int starts_one_end(int x) {
  if (x < 1) {
    return 0;
  } else if (x == 1) {
    return 1;
  } else {
    int y = 2;
    while (y <= x) {
      y = y * 10 + 1;
    }
    return y;
  }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (starts_one_ends(1) == 1);
    assert (starts_one_ends(2) == 18);
    assert (starts_one_ends(3) == 180);
    assert (starts_one_ends(4) == 1800);
    assert (starts_one_ends(5) == 18000);
}
