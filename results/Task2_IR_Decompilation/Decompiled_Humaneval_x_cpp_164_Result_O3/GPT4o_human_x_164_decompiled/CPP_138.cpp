```cpp
#include <iostream>

bool is_equal_to_sum(int x) {
    return ((x & 1) == 0) && (x > 7);
}

int main() {
    int value;
    std::cout << "Enter an integer: ";
    std::cin >> value;
    if (is_equal_to_sum(value)) {
        std::cout << "The condition is true." << std::endl;
    } else {
        std::cout << "The condition is false." << std::endl;
    }
    return 0;
}
```