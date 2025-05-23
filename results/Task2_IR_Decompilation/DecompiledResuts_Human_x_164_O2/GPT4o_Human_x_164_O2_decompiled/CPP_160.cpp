```cpp
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

int do_algebra(std::vector<std::string> v1, std::vector<int> v2) {
    if (v1.empty() || v2.empty()) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int result = 0;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] == "**") {
            result++;
        } else if (v1[i] == "*") {
            result *= v2[i];
        } else if (v1[i] == "//") {
            result /= v2[i];
        } else if (v1[i] == "+") {
            result += v2[i];
        } else if (v1[i] == "-") {
            result -= v2[i];
        }
    }

    return result;
}
```