```cpp
#include <vector>
#include <string>
#include <iostream>
#include <cstring>

void select_words(std::vector<std::string>& vec, const std::string& input, int length) {
    // Initialize temporary strings and variables
    std::string temp1, temp2, temp3;
    size_t input_length = input.size();
    
    if (input_length > 15) {
        temp1 = input.substr(0, length);
    } else {
        temp1 = input;
    }
    
    vec.push_back(temp1);
    
    if (length > 0) {
        for (size_t i = 0; i < input_length; ++i) {
            if (input[i] == '\0') break;
            temp2 += input[i];
        }
    }
    
    vec.push_back(temp2);
    
    // Final string processing
    temp3 = input + "_processed";
    vec.push_back(temp3);
}

int main() {
    std::vector<std::string> words;
    std::string input = "aeiouAEIOU";
    int length = input.size();
    
    select_words(words, input, length);
    
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }
    
    return 0;
}
```