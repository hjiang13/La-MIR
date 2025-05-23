```cpp
#include <string>

void file_name_check(std::string& output, const std::string& input) {
    if (input.length() < 5) {
        output = "No";
        return;
    }

    char first_char = input[0];
    if ((first_char < 'A' || first_char > 'Z') && (first_char < 'a' || first_char > 'z')) {
        output = "No";
        return;
    }

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c < '0' || c > '9') {
            if (c == '.') {
                // Check if it's an extension
                if (i == input.length() - 1) {
                    output = "No";
                    return;
                }
            } else if (c < 'A' || c > 'Z') {
                if (c < 'a' || c > 'z') {
                    output = "No";
                    return;
                }
            }
        }
    }

    if (input.find(".txt") != std::string::npos || 
        input.find(".exe") != std::string::npos || 
        input.find(".dll") != std::string::npos) {
        output = "Yes";
    } else {
        output = "No";
    }
}
```