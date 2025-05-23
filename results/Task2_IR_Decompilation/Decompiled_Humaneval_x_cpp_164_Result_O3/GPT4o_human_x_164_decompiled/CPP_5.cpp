```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    if (input.empty()) {
        return;
    }

    result.clear();
    result.reserve(input.size() * 2 - 1);

    result.push_back(input[0]);

    for (size_t i = 1; i < input.size(); ++i) {
        result.push_back(value);
        result.push_back(input[i]);
    }
}
```