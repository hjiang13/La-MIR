```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> select_words(const std::string &input, int max_words) {
    std::vector<std::string> result;
    std::string vowels = "aeiouAEIOU";
    std::string current_word;
    bool word_started = false;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c == ' ') {
            if (word_started) {
                if (result.size() == max_words) {
                    result.push_back(current_word);
                }
                current_word.clear();
                word_started = false;
            }
        } else {
            if (!word_started) {
                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                    word_started = true;
                }
            }
            if (word_started) {
                current_word += c;
            }
        }
    }

    if (word_started && result.size() < max_words) {
        result.push_back(current_word);
    }

    return result;
}

int main() {
    std::string input = "Your input string here";
    int max_words = 10;
    std::vector<std::string> words = select_words(input, max_words);

    for (const auto &word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
```