```cpp
#include <string>
#include <stdexcept>

bool is_palindrome(const std::string& str) {
    std::string reversed(str.rbegin(), str.rend());
    return reversed == str;
}
```