```cpp
#include <iostream>

bool is_equal_to_sum_even(int x) {
    return ((x & 1) == 0) && (x > 7);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    if (is_equal_to_sum_even(num)) {
        std::cout << "The number is even and greater than 7." << std::endl;
    } else {
        std::cout << "The number does not meet the criteria." << std::endl;
    }
    return 0;
}
```