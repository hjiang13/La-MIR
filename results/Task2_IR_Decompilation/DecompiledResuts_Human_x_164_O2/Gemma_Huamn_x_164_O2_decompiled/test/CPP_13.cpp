int greatest_common_divisor(int a, int b) {
  while (1) {
    int tmp = a;
    a = b;
    b = tmp % b;
    if (b == 0) {
      return a;
    }
  }
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (greatest_common_divisor(3, 7) == 1);
     assert (greatest_common_divisor(10, 15) == 5);
      assert (greatest_common_divisor(49, 14) == 7);
     assert (greatest_common_divisor(144, 60) == 12);
}
