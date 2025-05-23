```c++
#include <string>

void encode_shift(std::string& result, std::string* input) {
    result.clear();
    int index = 0;
    while (index < input->length()) {
        char currentChar = (*input)[index];
        int shiftedValue = ((currentChar - 'a' + 5) % 26) + 'a';
        result.push_back(static_cast<char>(shiftedValue));
        index++;
    }
}

void decode_shift(std::string& result, std::string* input) {
    result.clear();
    int index = 0;
    while (index < input->length()) {
        char currentChar = (*input)[index];
        int shiftedValue = ((currentChar - 'a' + 21) % 26) + 'a';
        result.push_back(static_cast<char>(shiftedValue));
        index++;
    }
}
```