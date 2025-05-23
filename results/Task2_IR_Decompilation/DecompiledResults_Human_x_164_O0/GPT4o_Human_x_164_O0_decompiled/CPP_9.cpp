```cpp
#include <vector>
#include <stdexcept>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    int max_value = INT_MIN;

    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] > max_value) {
            max_value = input[i];
        }
        result.push_back(max_value);
    }
}
```