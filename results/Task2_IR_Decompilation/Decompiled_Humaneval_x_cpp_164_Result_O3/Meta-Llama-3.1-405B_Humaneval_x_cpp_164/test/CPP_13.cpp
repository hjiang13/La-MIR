int greatest_common_divisor(int a, int b) {
    while (1) {
        int c = a < b ? a : b;
        int d = a < b ? b : a;
        int e = d % c;
        if (e == 0) {
            return c;
        }
        a = c;
        b = e;
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
