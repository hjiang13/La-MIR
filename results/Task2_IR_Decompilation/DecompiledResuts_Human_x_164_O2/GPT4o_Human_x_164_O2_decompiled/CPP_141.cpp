```cpp
#include <string>
#include <cstring>

void file_name_check(std::string& output, const std::string& input) {
    if (input.size() < 5) {
        output = std::string(2, '\0');
        output[0] = (char)0x6F6E; // 'No'
        output[1] = '\0';
        return;
    }

    char first_char = input[0];
    if (first_char < 65) {
        output = std::string(2, '\0');
        output[0] = (char)0x6F6E; // 'No'
        output[1] = '\0';
        return;
    }

    if (first_char == 127 || first_char == 126 || first_char == 125 || first_char == 124 ||
        first_char == 123 || first_char == 96 || first_char == 95 || first_char == 94 ||
        first_char == 93 || first_char == 92 || first_char == 91) {
        output = std::string(2, '\0');
        output[0] = (char)0x6F6E; // 'No'
        output[1] = '\0';
        return;
    }

    std::string str1 = ".txt";
    std::string str2 = ".exe";
    std::string str3 = ".dll";

    if (input.compare(str1) == 0 || input.compare(str2) == 0 || input.compare(str3) == 0) {
        output = std::string(3, '\0');
        output[0] = 'Y';
        output[1] = 'e';
        output[2] = 's';
        output[3] = '\0';
    } else {
        output = std::string(2, '\0');
        output[0] = (char)0x6F6E; // 'No'
        output[1] = '\0';
    }
}
```