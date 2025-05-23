```cpp
#include <string>
#include <iostream>

void file_name_check(std::string& output, const std::string& input) {
    if (input.size() < 5) {
        output = std::string(2, '\0');
        output[0] = 0x6e; // 'n'
        output[1] = 0x6f; // 'o'
        return;
    }

    char firstChar = input[0];
    if (firstChar < 65) {
        switch (firstChar) {
            case 127:
            case 126:
            case 125:
            case 124:
            case 123:
            case 96:
            case 95:
            case 94:
            case 93:
            case 92:
            case 91:
                output = std::string(2, '\0');
                output[0] = 0x6e; // 'n'
                output[1] = 0x6f; // 'o'
                return;
        }
    }

    std::string target;
    target.reserve(32);
    target.assign(input, 0, input.size() - 4);

    if (target.compare(".txt") == 0) {
        output.assign("No", 2);
        return;
    } else if (target.compare(".exe") == 0) {
        output.assign("No", 2);
        return;
    } else if (target.compare(".dll") == 0) {
        output.assign("No", 2);
        return;
    }

    output.assign("Yes", 3);
}

int main() {
    std::string result;
    std::string fileName = "example.txt"; // Example filename for testing
    file_name_check(result, fileName);
    std::cout << result << std::endl;
    return 0;
}
```