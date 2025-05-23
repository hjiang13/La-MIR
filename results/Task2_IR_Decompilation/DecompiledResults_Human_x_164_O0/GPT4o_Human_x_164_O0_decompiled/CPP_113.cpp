```cpp
#include <iostream>
#include <vector>
#include <string>

void odd_count(std::vector<std::string>& result, const std::vector<std::string>& input) {
    int odd_count = 0;

    for (const auto& str : input) {
        for (size_t i = 0; i < str.length(); ++i) {
            if ((str[i] >= '0' && str[i] <= '9') && (str[i] - '0') % 2 != 0) {
                odd_count++;
            }
        }
    }

    result.push_back(std::to_string(odd_count));
}

int main() {
    std::vector<std::string> input = {"hello123", "world456", "test789"};
    std::vector<std::string> result;

    odd_count(result, input);

    std::cout << "The number of odd elements in the input: " << result[0] << std::endl;

    return 0;
}
```