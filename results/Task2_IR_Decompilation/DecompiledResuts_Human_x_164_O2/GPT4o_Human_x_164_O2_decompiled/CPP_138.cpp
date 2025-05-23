```cpp
#include <iostream>

bool is_equal_to_sum(int value) {
    return ((value & 1) == 0) && (value > 7);
}

int main() {
    int input;
    std::cout << "Enter a number: ";
    std::cin >> input;
    if (is_equal_to_sum(input)) {
        std::cout << "The condition is met." << std::endl;
    } else {
        std::cout << "The condition is not met." << std::endl;
    }
    return 0;
}
```