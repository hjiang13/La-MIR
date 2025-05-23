```cpp
#include <string>

int digitSum(std::__cxx11::basic_string<char> str) {
    int sum = 0;
    for (size_t i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            sum += c - 'A' + 1;
        }
    }
    return sum;
}
```