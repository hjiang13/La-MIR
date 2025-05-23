```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    if (input.empty()) return;

    int max_value = input[0];
    result.push_back(max_value);

    for (size_t i = 1; i < input.size(); ++i) {
        if (input[i] > max_value) {
            max_value = input[i];
        }
        result.push_back(max_value);
    }
}

int main() {
    std::vector<int> input = {1, 3, 2, 5, 4};
    std::vector<int> result;

    rolling_max(result, input);

    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```