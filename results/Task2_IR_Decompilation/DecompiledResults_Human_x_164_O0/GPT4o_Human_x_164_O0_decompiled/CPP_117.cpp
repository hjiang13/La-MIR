```cpp
#include <vector>
#include <string>
#include <cstring>
#include <stdexcept>

void select_words(std::vector<std::string>& output, const std::string& input, int length) {
    const char* vowels = "aeiouAEIOU";
    std::string buffer;

    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == ' ') {
            if (!buffer.empty() && buffer.length() == length) {
                output.push_back(buffer);
            }
            buffer.clear();
        } else {
            buffer += input[i];
        }
    }

    if (!buffer.empty() && buffer.length() == length) {
        output.push_back(buffer);
    }
}

int main() {
    std::vector<std::string> words;
    std::string input = "This is a sample input string";
    select_words(words, input, 2);
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }
    return 0;
}
```