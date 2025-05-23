int _Z6x_or_yiii(int a1, int a2, int a3) {
  if (a1 > 1) {
    if (a1 < 4) {
      if (((a1 > 1) ? 1 : 0) & 1) {
        return a3;
      }
      return a2;
    }
    int i = 2;
    unsigned char v1 = (a1 > 1) ? 1 : 0;
    while (true) {
      int v2 = a1 % i;
      if (v2 == 0) {
        v1 = 0;
      }
      int v3 = i + 1;
      int v4 = v3 * v3;
      if (v4 > a1) {
        if ((v1 & 1) == 0) {
          return a2;
        }
        return a3;
      }
      i = v3;
    }
  }
  if (((a1 > 1) ? 1 : 0) & 1) {
    return a3;
  }
  return a2;
}
```<|im_end|>
#undef NDEBUG
#include<assert.h>
int main(){
    assert (x_or_y(7, 34, 12) == 34);
    assert (x_or_y(15, 8, 5) == 5);
    assert (x_or_y(3, 33, 5212) == 33);
    assert (x_or_y(1259, 3, 52) == 3);
    assert (x_or_y(7919, -1, 12) == -1);
    assert (x_or_y(3609, 1245, 583) == 583);
    assert (x_or_y(91, 56, 129) == 129);
    assert (x_or_y(6, 34, 1234) == 1234);
    assert (x_or_y(1, 2, 0) == 0);
    assert (x_or_y(2, 2, 0) == 2);
}
