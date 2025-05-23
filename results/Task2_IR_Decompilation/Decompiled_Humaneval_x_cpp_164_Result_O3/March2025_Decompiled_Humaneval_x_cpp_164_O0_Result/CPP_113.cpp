```cpp
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> odd_count(const std::vector<std::string>& input) {
    std::vector<std::string> result;
    for (const auto& str : input) {
        int odd_count = 0;
        for (char ch : str) {
            if (ch >= '0' && ch <= '9' && (ch - '0') % 2 == 1) {
                ++odd_count;
            }
        }
        result.push_back(std::to_string(odd_count));
    }
    return result;
}

int main() {
    std::vector<std::string> input = {"123", "456", "789"};
    std::vector<std::string> result = odd_count(input);
    for (const auto& res : result) {
        std::cout << res << std::endl;
    }
    return 0;
}
```