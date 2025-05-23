#include <iostream>

int greatest_common_divisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x = 48;
    int y = 18;
    std::cout << "GCD of " << x << " and " << y << " is " << greatest_common_divisor(x, y) << std::endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (greatest_common_divisor(3, 7) == 1);
     assert (greatest_common_divisor(10, 15) == 5);
      assert (greatest_common_divisor(49, 14) == 7);
     assert (greatest_common_divisor(144, 60) == 12);
}
