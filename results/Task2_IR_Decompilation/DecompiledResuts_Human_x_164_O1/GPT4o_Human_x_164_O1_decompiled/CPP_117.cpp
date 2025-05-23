```cpp
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

void select_words(std::vector<std::string>& words, const std::string& input, int length) {
    words.clear();
    if (input.size() > 15) {
        std::string word;
        for (size_t i = 0; i < input.size(); ++i) {
            if (input[i] == ' ') {
                if (!word.empty() && word.size() <= length) {
                    words.push_back(word);
                }
                word.clear();
            } else {
                word += input[i];
            }
        }
        if (!word.empty() && word.size() <= length) {
            words.push_back(word);
        }
    }
}

int main() {
    std::vector<std::string> words;
    std::string input = "This is a sample input string for testing.";
    int length = 10;
    
    select_words(words, input, length);
    
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }
    
    return 0;
}
```