#include <iostream>

bool is_simple_power(int base, int power) {
    if (base <= 0) {
        return false;
    }
    int result = 1;
    for (int i = 1; i <= 99; ++i) {
        result = result * power;
        if (result == base) {
            return true;
        }
        if (result > base) {
            break;
        }
    }
    return false;
}

int main() {
    // Example usage:
    std::cout << std::boolalpha; // Print 'true' or 'false' instead of 1 or 0
    std::cout << is_simple_power(4, 2) << std::endl;  // Output: true
    std::cout << is_simple_power(8, 2) << std::endl;  // Output: true
    std::cout << is_simple_power(9, 3) << std::endl;  // Output: true
    std::cout << is_simple_power(5, 2) << std::endl;  // Output: false
    std::cout << is_simple_power(1, 1) << std::endl;  // Output: true
    std::cout << is_simple_power(1, 2) << std::endl;  // Output: false
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_simple_power(1, 4)== true);
    assert (is_simple_power(2, 2)==true);
    assert (is_simple_power(8, 2)==true);
    assert (is_simple_power(3, 2)==false);
    assert (is_simple_power(3, 1)==false);
    assert (is_simple_power(5, 3)==false);
    assert (is_simple_power(16, 2)== true);
    assert (is_simple_power(143214, 16)== false);
    assert (is_simple_power(4, 2)==true);
    assert (is_simple_power(9, 3)==true);
    assert (is_simple_power(16, 4)==true);
    assert (is_simple_power(24, 2)==false);
    assert (is_simple_power(128, 4)==false);
    assert (is_simple_power(12, 6)==false);
    assert (is_simple_power(1, 1)==true);
    assert (is_simple_power(1, 12)==true);
}
