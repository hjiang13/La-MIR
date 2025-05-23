```cpp
#include <string>

int digitSum(const std::string& str) {
    int sum = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            sum += c;
        }
    }
    return sum;
}
```