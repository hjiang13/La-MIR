```cpp
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>

std::string int_to_mini_roman(int num) {
    std::vector<std::string> roman_literals = {"m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};
    std::vector<int> roman_values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    std::string result;
    for (size_t i = 0; i < roman_values.size(); ++i) {
        while (num >= roman_values[i]) {
            result += roman_literals[i];
            num -= roman_values[i];
        }
    }
    return result;
}
```