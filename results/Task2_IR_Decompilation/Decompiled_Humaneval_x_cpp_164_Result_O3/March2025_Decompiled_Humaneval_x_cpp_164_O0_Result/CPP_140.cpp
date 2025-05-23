```cpp
#include <string>

std::string fix_spaces(const std::string& input) {
    std::string result;
    int space_count = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char current_char = input[i];
        if (current_char == ' ') {
            ++space_count;
        } else {
            if (space_count == 1) {
                result += '_';
            } else if (space_count == 2) {
                result += "__";
            } else if (space_count > 2) {
                result += "-";
            }
            result += current_char;
            space_count = 0;
        }
    }

    if (space_count == 1) {
        result += '_';
    } else if (space_count == 2) {
        result += "__";
    } else if (space_count > 2) {
        result += "-";
    }

    return result;
}
```