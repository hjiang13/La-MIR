```cpp
#include <iostream>
#include <vector>
#include <string>

void words_string(std::vector<std::string>& vec, const std::string& str) {
    std::string temp;
    vec.clear();
    size_t length = str.length();
    if (length == 0) return;

    size_t start = 0;
    while (start < length) {
        size_t end = str.find_first_of(' ', start);
        if (end == std::string::npos) end = length;
        temp = str.substr(start, end - start);
        vec.push_back(temp);
        start = end + 1;
    }
}

int main() {
    std::vector<std::string> words;
    std::string input = "This is a test string";
    words_string(words, input);

    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
```