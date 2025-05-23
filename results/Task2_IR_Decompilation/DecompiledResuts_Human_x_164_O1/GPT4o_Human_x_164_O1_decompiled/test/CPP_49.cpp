#include <iostream>

int mod(int a, int b) {
    if (a > 0) {
        int count = 0;
        int remainder = 0;
        while (true) {
            if (count == a) {
                return 1;
            }
            remainder = (remainder << 1) % b;
            count++;
        }
    } else {
        return 1;
    }
}

int main() {
    int a = 10; // Example value
    int b = 3;  // Example value
    std::cout << mod(a, b) << std::endl;
    return 0;
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
