```cpp
#include <string>
#include <stdexcept>

void encode_cyclic(std::string &result, const std::string &input) {
    size_t input_size = input.size();
    if (input_size <= 0) {
        result = "";
        return;
    }

    result.resize(input_size);
    for (size_t i = 0; i < input_size; ++i) {
        result[i] = input[i];
    }
}

void decode_cyclic(std::string &result, const std::string &input) {
    size_t input_size = input.size();
    if (input_size <= 0) {
        result = "";
        return;
    }

    result.resize(input_size);
    for (size_t i = 0; i < input_size; ++i) {
        result[i] = input[i];
    }
}
```