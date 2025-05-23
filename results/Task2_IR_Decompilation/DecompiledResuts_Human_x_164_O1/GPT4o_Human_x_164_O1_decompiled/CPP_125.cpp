```cpp
#include <vector>
#include <string>
#include <iostream>
#include <cstdarg>
#include <stdexcept>

void split_words(std::vector<std::string>& words, const std::string& str) {
    size_t length = str.length();
    if (length == 0) return;

    std::string current_word;
    for (size_t i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            if (!current_word.empty()) {
                words.push_back(current_word);
                current_word.clear();
            }
        } else {
            current_word += str[i];
        }
    }
    if (!current_word.empty()) {
        words.push_back(current_word);
    }
}

int main() {
    std::vector<std::string> words;
    std::string input = "This is a test string";
    split_words(words, input);

    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
```