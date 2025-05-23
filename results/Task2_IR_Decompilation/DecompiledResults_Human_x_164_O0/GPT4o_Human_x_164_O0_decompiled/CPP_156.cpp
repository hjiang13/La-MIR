```cpp
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> int_to_mini_romank(int num) {
    std::vector<std::string> romanNumerals = {
        "m", "cm", "cd", "d", "xc", "xl", "x", "ix", "v", "iv", "i"
    };

    std::vector<int> values = {
        1000, 900, 400, 500, 90, 40, 10, 9, 5, 4, 1
    };

    std::string result;
    for (size_t i = 0; i < values.size(); ++i) {
        while (num >= values[i]) {
            result += romanNumerals[i];
            num -= values[i];
        }
    }
    return result;
}

int main() {
    int number = 1994;
    std::string roman = int_to_mini_romank(number);
    std::cout << "Roman numeral: " << roman << std::endl;
    return 0;
}
```