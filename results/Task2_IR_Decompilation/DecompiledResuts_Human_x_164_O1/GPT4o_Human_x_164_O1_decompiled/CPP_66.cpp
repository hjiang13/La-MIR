```cpp
#include <string>

int digitSum(const std::string& str) {
    if (str.size() == 0) {
        return 0;
    }

    int sum = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {
            sum += ch;
        }
    }
    return sum;
}
```