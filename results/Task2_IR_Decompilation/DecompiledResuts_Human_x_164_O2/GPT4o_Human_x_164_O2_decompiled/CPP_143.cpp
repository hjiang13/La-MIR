```cpp
#include <string>
#include <cstring>

void words_in_sentence(std::string& output, const std::string& input) {
    size_t length = input.size();
    if (length > 15) {
        output.resize(length);
        std::memcpy(&output[0], input.c_str(), length);
        output[length] = '\0';
    } else {
        output = input;
    }
    
    size_t wordCount = 0;
    for (size_t i = 0; i < length; ++i) {
        if (input[i] == ' ') {
            wordCount++;
        }
    }
    
    if (wordCount > 0) {
        output.insert(0, "Words in sentence: ");
        output += std::to_string(wordCount);
    }
}
```