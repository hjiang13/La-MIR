```cpp
#include <string>

int count_upper(const std::string& input) {
    std::string vowels = "AEIOU";
    int count = 0;
    int index = 0;

    while (index * 2 < input.length()) {
        char current_char = input[index * 2];
        if (vowels.find(current_char) != std::string::npos) {
            count++;
        }
        index++;
    }

    return count;
}
```