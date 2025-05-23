```c
#include <string>

void encrypt(std::string& s, std::string& input) {
    int index = 0;
    while (index < input.length()) {
        char currentChar = input[index];
        int charValue = currentChar + 4;
        int newValue = (charValue - 97) % 26 + 97;
        s += static_cast<char>(newValue);
        index++;
    }
}

int main() {
    std::string input = "your_input_string_here";
    std::string encryptedString;
    encrypt(encryptedString, input);
    
    return 0;
}
```