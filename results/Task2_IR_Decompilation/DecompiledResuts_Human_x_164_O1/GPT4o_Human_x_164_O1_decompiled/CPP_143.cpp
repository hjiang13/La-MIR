```cpp
#include <string>

void words_in_sentence(std::string &result, const std::string &input) {
    size_t count = input.length();
    if (count > 15) {
        result.resize(count);
        switch (count) {
            case 1:
                result[0] = input[0];
                break;
            case 0:
                break;
            default:
                std::memcpy(&result[0], &input[0], count);
                break;
        }
    } else {
        switch (count) {
            case 1:
                result[0] = input[0];
                break;
            case 0:
                break;
            default:
                std::memcpy(&result[0], &input[0], count);
                break;
        }
    }
    
    result[count] = '\0';
}
```