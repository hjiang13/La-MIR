```cpp
#include <string>
#include <cstring>

bool is_palindrome(const std::string &s) {
    size_t n = s.size();
    if (n > 15) {
        std::string reversed(n, ' ');
        for (size_t i = 0; i < n; ++i) {
            reversed[n - 1 - i] = s[i];
        }
        return s == reversed;
    } else {
        for (size_t i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }
}

std::string make_palindrome(const std::string &s) {
    std::string result = s;
    size_t n = s.size();
    for (size_t i = 0; i < n; ++i) {
        result.push_back(s[n - 1 - i]);
    }
    return result;
}
```