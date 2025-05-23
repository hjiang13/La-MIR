```cpp
#include <iostream>
#include <string>

int hex_key(std::basic_string<char> str) {
    const char* key = "2357BD";
    
    if (str.size() == 0) {
        return 0;
    }
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != key[i % 6]) {
            return i;
        }
    }
    
    return 0;
}

int main() {
    std::string input = "2357BD";
    int result = hex_key(input);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
```