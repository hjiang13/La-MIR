```cpp
#include <string>
#include <cstring>

bool is_palindrome(std::string s) {
    size_t length = s.size();
    if (length > 15) {
        std::string buffer(length, '\0');
        std::memcpy(&buffer[0], s.data(), length);
        buffer[length] = '\0';

        size_t half = length / 2;
        for (size_t i = 0; i < half; ++i) {
            if (buffer[i] != buffer[length - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    return length == 0;
}
```