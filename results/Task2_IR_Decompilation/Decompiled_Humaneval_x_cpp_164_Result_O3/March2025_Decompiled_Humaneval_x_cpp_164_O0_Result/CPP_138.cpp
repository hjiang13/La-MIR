```cpp
#include <iostream>

bool is_equal_to_sum_even(int input) {
    if (input % 2 == 0) {
        if (input >= 8) {
            return true;
        }
    }
    return false;
}

int main() {
    int input;
    std::cin >> input;
    bool result = is_equal_to_sum_even(input);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
}
```