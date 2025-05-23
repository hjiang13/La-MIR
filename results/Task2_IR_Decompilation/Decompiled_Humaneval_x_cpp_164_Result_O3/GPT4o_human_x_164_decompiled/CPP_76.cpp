```cpp
#include <iostream>

bool is_simple_power(int a, int b) {
    if (a <= 0) return false;
    if (a == 1) return (b == 1);
    
    int count = 0;
    int power = 1;
    
    while (power <= a && count < 99) {
        power *= b;
        count++;
        if (power == a) return true;
    }
    
    return false;
}

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    if (is_simple_power(a, b)) {
        std::cout << a << " is a power of " << b << std::endl;
    } else {
        std::cout << a << " is not a power of " << b << std::endl;
    }
    return 0;
}
```