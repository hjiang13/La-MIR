```cpp
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
```