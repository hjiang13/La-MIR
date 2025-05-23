```cpp
#include <map>
#include <string>
#include <iostream>

void histogram(std::map<std::string, int>& m, const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        m[std::string(1, ch)]++;
    }
}

int main() {
    std::map<std::string, int> m;
    std::string input = "example string";
    histogram(m, input);

    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```