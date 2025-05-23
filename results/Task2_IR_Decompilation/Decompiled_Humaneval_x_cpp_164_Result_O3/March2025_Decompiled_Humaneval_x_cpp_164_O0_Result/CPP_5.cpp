```cpp
#include <vector>
#include <stdexcept>
#include <algorithm>

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    result.clear();
    if (!input.empty()) {
        result.push_back(input[0]);
    }
    for (size_t i = 1; i < input.size(); ++i) {
        result.push_back(value);
        result.push_back(input[i]);
    }
}
```