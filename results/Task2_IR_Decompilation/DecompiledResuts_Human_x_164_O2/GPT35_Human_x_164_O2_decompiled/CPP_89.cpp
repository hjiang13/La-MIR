```c++
#include <string>

void encrypt(std::string& s, const std::string& input) {
    s = "";
    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        int offset = c - 93;
        int new_char = (offset % 26) + 97;
        s += new_char;
    }
}

int main() {
    std::string input = "your_input_string_here";
    std::string encrypted;
    encrypt(encrypted, input);
    return 0;
}
```