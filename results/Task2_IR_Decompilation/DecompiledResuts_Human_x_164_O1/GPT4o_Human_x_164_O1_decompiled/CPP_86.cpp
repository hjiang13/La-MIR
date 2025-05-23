```cpp
#include <string>
#include <cstring>

void anti_shuffle(std::string &result, const std::string &input) {
    size_t input_size = input.size();
    if (input_size > 15) {
        result.resize(input_size);
        memcpy(&result[0], input.data(), input_size);
    } else {
        result = input;
    }
    result.push_back('\0');
}
```