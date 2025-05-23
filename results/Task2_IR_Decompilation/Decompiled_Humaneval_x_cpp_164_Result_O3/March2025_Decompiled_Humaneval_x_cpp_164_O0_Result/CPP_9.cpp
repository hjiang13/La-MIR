```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> rolling_max(const std::vector<int>& input) {
    std::vector<int> result;
    int current_max = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        if (i == 0 || input[i] > current_max) {
            current_max = input[i];
        }
        result.push_back(current_max);
    }
    return result;
}
```