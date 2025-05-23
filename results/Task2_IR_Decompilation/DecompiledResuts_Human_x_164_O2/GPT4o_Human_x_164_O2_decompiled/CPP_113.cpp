```cpp
#include <iostream>
#include <vector>
#include <string>

void odd_count(std::vector<std::string>& result, const std::vector<std::string>& input) {
    result.clear();
    for (const auto& str : input) {
        int count = 0;
        for (const char& c : str) {
            if ((c - '0') % 2 != 0) {
                count++;
            }
        }
        if (count > 0) {
            result.push_back("Odd count: " + std::to_string(count));
        }
    }
}

int main() {
    std::vector<std::string> input = {"123", "456", "789"};
    std::vector<std::string> result;
    odd_count(result, input);
    for (const auto& res : result) {
        std::cout << res << std::endl;
    }
    return 0;
}
```