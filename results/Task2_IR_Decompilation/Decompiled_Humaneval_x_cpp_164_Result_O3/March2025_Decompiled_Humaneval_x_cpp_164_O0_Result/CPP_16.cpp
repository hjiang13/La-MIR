```cpp
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

int count_distinct_characters(const std::string& input) {
    std::vector<char> distinct_chars;
    std::string transformed_input(input.size(), '\0');
    std::transform(input.begin(), input.end(), transformed_input.begin(), ::tolower);

    for (size_t i = 0; i < transformed_input.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < distinct_chars.size(); ++j) {
            if (distinct_chars[j] == transformed_input[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            distinct_chars.push_back(transformed_input[i]);
        }
    }

    return distinct_chars.size();
}
```