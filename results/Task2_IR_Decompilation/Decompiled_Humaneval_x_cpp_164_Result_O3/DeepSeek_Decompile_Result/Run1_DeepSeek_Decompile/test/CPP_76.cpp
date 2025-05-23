#include <iostream>

bool is_simple_power(int power, int base) {
    if (power == 0) {
        return false;
    }
    if (power == 1) {
        return true;
    }

    int result = 1;
    int i = 0;

    while (i < 99) {
        result = result * base;

        if (result == power) {
            return true;
        }
        if (result > power) {
            break;
        }
        i++;
    }

    return false;
}

int main() {
    // Example usage:
    std::cout << std::boolalpha;
    std::cout << is_simple_power(8, 2) << std::endl;   // Output: true
    std::cout << is_simple_power(10, 3) << std::endl;  // Output: false
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
