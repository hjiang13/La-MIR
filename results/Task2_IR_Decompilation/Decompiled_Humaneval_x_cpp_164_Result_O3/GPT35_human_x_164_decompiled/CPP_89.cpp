```cpp
#include <iostream>
#include <string>

void encrypt(std::string& output, const std::string& input) {
    output = "";
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        int offset = c - 93;
        int encrypted = (offset % 26) + 97;
        output += static_cast<char>(encrypted);
    }
}

int main() {
    std::string input = "Hello, World!";
    std::string output;
    
    encrypt(output, input);
    
    std::cout << "Encrypted string: " << output << std::endl;
    
    return 0;
}
```