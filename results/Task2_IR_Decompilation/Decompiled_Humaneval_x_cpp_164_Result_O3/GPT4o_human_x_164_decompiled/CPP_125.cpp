```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <cstring>

void split_words(std::vector<std::string>& result, const std::string& str) {
    size_t len = str.length();
    const char* data = str.c_str();
    size_t start = 0;

    for (size_t i = 0; i < len; ++i) {
        if (data[i] == ' ') {
            if (i > start) {
                result.emplace_back(str.substr(start, i - start));
            }
            start = i + 1;
        }
    }
    if (start < len) {
        result.emplace_back(str.substr(start, len - start));
    }
}

int main() {
    std::vector<std::string> words;
    std::string str = "This is a test string";
    split_words(words, str);

    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
```