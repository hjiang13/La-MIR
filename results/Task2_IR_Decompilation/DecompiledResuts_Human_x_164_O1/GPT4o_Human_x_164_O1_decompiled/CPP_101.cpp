```cpp
#include <vector>
#include <string>
#include <iostream>

void words_string(std::vector<std::string>& vec, const std::string& str) {
    vec.clear();
    if (str.empty()) return;

    std::string word;
    size_t start = 0, end = 0;

    while ((end = str.find_first_of(" ", start)) != std::string::npos) {
        word = str.substr(start, end - start);
        vec.push_back(word);
        start = end + 1;
    }
    vec.push_back(str.substr(start));
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