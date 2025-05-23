```cpp
#include <string>
#include <cstring>
#include <cstdlib>

bool is_palindrome(std::string str) {
    size_t length = str.size();
    if (length <= 15) {
        return length < 4 ? true : false;
    }
    
    char* buffer = (char*)malloc(length + 1);
    if (!buffer) return false;

    for (size_t i = 0; i < length; ++i) {
        buffer[i] = str[i];
    }
    buffer[length] = '\0';

    for (size_t i = 0; i < length / 2; ++i) {
        if (buffer[i] != buffer[length - 1 - i]) {
            free(buffer);
            return false;
        }
    }

    free(buffer);
    return true;
}

int main() {
    std::string test = "racecar";
    bool result = is_palindrome(test);
    return result ? 0 : 1;
}
```