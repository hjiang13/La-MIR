```cpp
#include <string>

int digitSum(const std::string& str) {
    int sum = 0;
    size_t index = 0;

    while (index < str.length()) {
        char ch = str[index];
        if (ch >= 'A' && ch <= 'Z') {
            sum += static_cast<int>(ch);
        }
        if (ch <= 'z' && ch >= 'a') {
            sum += static_cast<int>(ch);
        }
        index++;
    }
    return sum;
}
```