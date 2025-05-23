```cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

std::vector<std::string> split_words(const std::string &input) {
    std::vector<std::string> result;
    std::string current_word;
    for (char c : input) {
        if (c == ' ') {
            if (!current_word.empty()) {
                result.push_back(current_word);
                current_word.clear();
            }
        } else {
            current_word += c;
        }
    }
    if (!current_word.empty()) {
        result.push_back(current_word);
    }
    return result;
}

int main() {
    std::string input = "This is a test string";
    std::vector<std::string> words = split_words(input);
    for (const auto &word : words) {
        std::cout << word << std::endl;
    }
    return 0;
}
```