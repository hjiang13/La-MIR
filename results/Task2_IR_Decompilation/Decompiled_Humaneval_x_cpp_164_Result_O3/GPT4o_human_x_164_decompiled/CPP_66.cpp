```cpp
#include <string>

int digitSum(const std::string& str) {
    size_t length = str.size();
    if (length == 0) return 0;

    int sum = 0;
    for (size_t i = 0; i < length; i += 4) {
        for (size_t j = 0; j < 4 && (i + j) < length; ++j) {
            char c = str[i + j];
            if (c >= '0' && c <= '9') {
                sum += c - '0';
            }
        }
    }
    return sum;
}
```