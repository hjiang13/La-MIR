```cpp
#include <string>
#include <stdexcept>

std::string file_name_check(const std::string& input) {
    if (input.length() < 5) {
        return "No";
    }

    char firstChar = input[0];
    if (!((firstChar >= 'A' && firstChar <= 'Z') || (firstChar >= 'a' && firstChar <= 'z'))) {
        return "No";
    }

    std::string extension = input.substr(input.length() - 4);
    if (extension != ".txt" && extension != ".exe" && extension != ".dll") {
        return "No";
    }

    int digitCount = 0;
    int dotCount = 0;
    for (char c : input) {
        if (c >= '0' && c <= '9') {
            digitCount++;
        }
        if (c == '.') {
            dotCount++;
        }
    }

    if (digitCount > 3 || dotCount != 1) {
        return "No";
    }

    return "Yes";
}
```