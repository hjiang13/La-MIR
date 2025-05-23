#include <iostream>

bool is_simple_power(int base, int exponent) {
    int result = 1;
    int count = 0;

    while (result <= base) {
        if (count < 100) {
            if (result == base) {
                return true;
            }
            result *= exponent;
            count++;
        } else {
            break;
        }
    }
    return false;
}

int main() {
    int base = 16; // Example base
    int exponent = 2; // Example exponent
    bool isPower = is_simple_power(base, exponent);
    std::cout << "Is " << base << " a power of " << exponent << "? " << (isPower ? "Yes" : "No") << std::endl;
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
