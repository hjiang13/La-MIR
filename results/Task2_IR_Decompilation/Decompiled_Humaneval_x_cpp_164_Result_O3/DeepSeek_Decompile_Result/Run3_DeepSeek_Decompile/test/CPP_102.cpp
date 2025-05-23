#include <iostream>

int choose_num(int a, int b) {
    if (b < a) {
        return -1;
    } else if (b == a) {
        if (b % 2 == 1) {
            return -1;
        } else {
            return b;
        }
    } else { // b > a
        if (b % 2 == 1) {
            return b + 1;
        } else {
            return b;
        }
    }
}

int main() {
    // Example usage:
    std::cout << choose_num(5, 3) << std::endl;  // Output: -1
    std::cout << choose_num(4, 4) << std::endl;  // Output: -1 (since 4 is even, wait no: 4 is even, so this should return 4?
    // Wait, in the code above, when b == a and even, it returns b.
    // So choose_num(4,4) should return 4, not -1.
    // Let me check the code again.

    // Correcting the example:
    std::cout << choose_num(5, 5) << std::endl;  // 5 is odd, so returns -1
    std::cout << choose_num(4, 4) << std::endl;  // 4 is even, returns 4
    std::cout << choose_num(5, 6) << std::endl;  // 6 is even, returns 6
    std::cout << choose_num(5, 7) << std::endl;  // 7 is odd, returns 8
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (choose_num(12, 15) == 14);
    assert (choose_num(13, 12) == -1);
    assert (choose_num(33, 12354) == 12354);
    assert (choose_num(5234, 5233) == -1);
    assert (choose_num(6, 29) == 28);
    assert (choose_num(27, 10) == -1);
    assert (choose_num(7, 7) == -1);
    assert (choose_num(546, 546) == 546);
}
