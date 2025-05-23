```cpp
#include <iostream>
#include <string>
#include <iterator>

void solve(std::string& result, const std::string& input) {
    result.clear();
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c >= 'A' && c <= 'Z') {
            result += c + 32; // Convert to lowercase
        } else if (c >= 'a' && c <= 'z') {
            result += c - 32; // Convert to uppercase
        } else {
            result += c; // Keep other characters unchanged
        }
    }
}

int main() {
    std::string input = "Hello, World!";
    std::string result;
    solve(result, input);
    std::cout << result << std::endl;
    return 0;
}
```