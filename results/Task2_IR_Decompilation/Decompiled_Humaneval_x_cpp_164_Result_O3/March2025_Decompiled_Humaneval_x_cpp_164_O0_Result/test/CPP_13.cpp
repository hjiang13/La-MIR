#include <iostream>

int greatest_common_divisor(int a, int b) {
    while (a != 0) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        a = a % b;
    }
    return b;
}

int main() {
    int a = 48; // Example input
    int b = 18; // Example input
    std::cout << "GCD of " << a << " and " << b << " is " << greatest_common_divisor(a, b) << std::endl;
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
