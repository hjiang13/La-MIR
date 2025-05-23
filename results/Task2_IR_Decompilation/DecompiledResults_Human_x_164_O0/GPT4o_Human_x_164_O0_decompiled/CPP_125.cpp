```cpp
#include <vector>
#include <string>
#include <stdexcept>

void split_words(std::vector<std::string>& words, const std::string& str) {
    size_t start = 0;
    size_t end = 0;
    while (end != std::string::npos) {
        end = str.find(' ', start);
        std::string word = str.substr(start, end - start);
        if (!word.empty()) {
            words.push_back(word);
        }
        start = end + 1;
    }
}

int main() {
    std::vector<std::string> words;
    std::string str = "This is a sample string";
    split_words(words, str);
    return 0;
}
```