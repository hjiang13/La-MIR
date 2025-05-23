```cpp
#include <string>
#include <cstring>

bool is_palindrome(const std::string& str) {
    size_t len = str.size();
    if (len <= 15) {
        return std::equal(str.begin(), str.begin() + len / 2, str.rbegin());
    }

    std::string reversed(len, '\0');
    for (size_t i = 0; i < len; ++i) {
        reversed[len - 1 - i] = str[i];
    }

    return str == reversed;
}

std::string make_palindrome(const std::string& str) {
    std::string result = str;
    if (!is_palindrome(str)) {
        result += std::string(str.rbegin(), str.rend());
    }
    return result;
}
```