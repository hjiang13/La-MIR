```cpp
#include <vector>

void unique(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();

    if (input.empty()) {
        return;
    }

    result.push_back(input[0]);

    for (size_t i = 1; i < input.size(); ++i) {
        if (input[i] != input[i - 1]) {
            result.push_back(input[i]);
        }
    }
}
```