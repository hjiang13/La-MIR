```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    if (input.empty()) return;

    int current_max = input[0];
    result.push_back(current_max);
    
    for (size_t i = 1; i < input.size(); ++i) {
        current_max = std::max(current_max, input[i]);
        result.push_back(current_max);
    }
}

int main() {
    std::vector<int> input = {1, 3, 2, 5, 4};
    std::vector<int> result;
    
    rolling_max(result, input);

    for (int max : result) {
        std::cout << max << " ";
    }
    return 0;
}
```