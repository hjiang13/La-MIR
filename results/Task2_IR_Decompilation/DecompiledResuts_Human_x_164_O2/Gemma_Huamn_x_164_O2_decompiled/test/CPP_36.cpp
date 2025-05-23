int fizz_buzzi(int arg_0) {
  if (arg_0 > 0) {
    int arg_6 = 0;
    int arg_7 = 0;
    while (1) {
      int arg_8 = arg_6 % 11;
      int arg_9 = arg_8 != 0;
      int arg_10 = arg_6 % 13;
      int arg_11 = arg_10 != 0;
      int arg_12 = arg_9 && arg_11;
      int arg_13 = arg_6 == 0;
      int arg_14 = arg_12 ? 1 : arg_13;
      if (arg_14) {
        return arg_7;
      }
      int arg_16 = arg_6;
      int arg_17 = arg_7;
      while (1) {
        int arg_18 = arg_16 % 10;
        int arg_19 = arg_18 == 7;
        int arg_20 = arg_19 ? 1 : 0;
        int arg_21 = arg_17 + arg_20;
        int arg_22 = arg_16 / 10;
        int arg_23 = arg_16 < 10;
        if (arg_23) {
          break;
        }
        arg_16 = arg_22;
        arg_17 = arg_21;
      }
      arg_7 = arg_21;
      arg_6 = arg_6 + 1;
      if (arg_6 == arg_0) {
        return arg_7;
      }
    }
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
