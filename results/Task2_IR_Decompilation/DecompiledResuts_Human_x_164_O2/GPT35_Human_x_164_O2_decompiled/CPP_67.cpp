```cpp
#include <string>
#include <cstdlib>

int fruit_distribution(std::basic_string<char> &str, int num) {
    std::__cxx11::basic_string<char> str1;
    std::__cxx11::basic_string<char> str2;
    std::__cxx11::basic_string<char> str3;
    std::__cxx11::basic_string<char> str4;

    if (str1.empty()) {
        return num;
    }

    int val1 = std::strtol(&str[0], nullptr, 10);
    int val2 = std::strtol(&str[0], nullptr, 10);

    if (&str[0] == nullptr) {
        std::free(&str[0]);
    }

    if (str1.empty()) {
        std::free(&str1[0]);
    }

    int result = val1 + val2;
    int remaining = num - result;

    return remaining;
}
```