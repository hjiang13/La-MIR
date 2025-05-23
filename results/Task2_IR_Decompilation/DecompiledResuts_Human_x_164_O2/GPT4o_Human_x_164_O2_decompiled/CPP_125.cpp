```cpp
#include <vector>
#include <string>
#include <iostream>
#include <cstdarg>

void split_words(std::vector<std::string>& words, const std::string& str) {
    std::size_t start = 0, end = 0;
    while ((end = str.find(' ', start)) != std::string::npos) {
        if (end > start) {
            words.emplace_back(str.substr(start, end - start));
        }
        start = end + 1;
    }
    if (start < str.length()) {
        words.emplace_back(str.substr(start));
    }
}

int main() {
    std::string input = "This is a test string";
    std::vector<std::string> words;
    split_words(words, input);

    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
```