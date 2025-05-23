```cpp
#include <string>
#include <cstring>

void words_in_sentence(std::string &result, const std::string &input) {
    size_t length = input.length();
    if (length > 15) {
        result.resize(length);
        std::memcpy(&result[0], input.c_str(), length);
    } else {
        result = input;
    }
}
```