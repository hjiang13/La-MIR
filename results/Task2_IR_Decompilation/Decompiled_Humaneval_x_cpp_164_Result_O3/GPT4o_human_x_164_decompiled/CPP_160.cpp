```cpp
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

int do_algebra(std::vector<std::string> vecStr, std::vector<int> vecInt) {
    if (vecStr.empty() || vecInt.empty()) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int size = vecInt.size();
    int result = 0;

    for (size_t i = 0; i < size; ++i) {
        if (vecStr[i] == "**") {
            result += static_cast<int>(pow(vecInt[i], 2));
        } else if (vecStr[i] == "*") {
            result *= vecInt[i];
        } else if (vecStr[i] == "//") {
            result /= vecInt[i];
        } else if (vecStr[i] == "+") {
            result += vecInt[i];
        } else if (vecStr[i] == "-") {
            result -= vecInt[i];
        }
    }
    
    return result;
}
```