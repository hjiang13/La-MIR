```cpp
#include <vector>
#include <string>

void words_string(std::vector<std::string>& vec, const std::string& str) {
    vec.clear();
    auto length = str.length();
    for (size_t i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            continue;
        }
        std::string word;
        while (i < length && str[i] != ' ') {
            word += str[i++];
        }
        if (!word.empty()) {
            vec.push_back(word);
        }
    }
}
```