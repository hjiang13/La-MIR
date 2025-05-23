```cpp
#include <string>
#include <vector>

std::string int_to_mini_romank(std::string& result, int num) {
    struct Roman {
        char symbol;
        int value;
    };
    
    std::vector<Roman> romanNumerals = {
        {'M', 1000}, {'CM', 900}, {'D', 500}, {'CD', 400},
        {'C', 100}, {'XC', 90}, {'L', 50}, {'XL', 40},
        {'X', 10}, {'IX', 9}, {'V', 5}, {'IV', 4}, {'I', 1}
    };

    for (const auto& r : romanNumerals) {
        while (num >= r.value) {
            result += r.symbol;
            num -= r.value;
        }
    }
    return result;
}
```