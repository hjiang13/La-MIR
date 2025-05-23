int fizz_buzzi(int x) {
  if (x > 0) {
    int i = 0;
    int sum = 0;
    while (1) {
      int r1 = i % 11;
      int r2 = i % 13;
      if ((r1 != 0) && (r2 != 0) || i == 0) {
        if (i == 0) {
          sum = sum;
        } else {
          while (i > 0) {
            int r = i % 10;
            if (r == 7) {
              sum++;
            }
            i = i / 10;
          }
        }
      }
      i++;
      if (i == x) {
        break;
      }
    }
    return sum;
  }
  return 0;
}


#undef NDEBUG
#include<assert.h>
int main(){
    assert (fizz_buzz(50) == 0);
    assert (fizz_buzz(78) == 2);
    assert (fizz_buzz(79) == 3);
    assert (fizz_buzz(100) == 3);
    assert (fizz_buzz(200) == 6);
    assert (fizz_buzz(4000) == 192);
    assert (fizz_buzz(10000) == 639);
    assert (fizz_buzz(100000) == 8026);
}
