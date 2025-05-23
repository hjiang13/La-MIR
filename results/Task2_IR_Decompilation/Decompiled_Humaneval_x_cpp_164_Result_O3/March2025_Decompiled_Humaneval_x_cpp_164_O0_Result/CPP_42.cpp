```cpp
#include <vector>

std::vector<int> incr_list(const std::vector<int>& input) {
    std::vector<int> result(input);
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] += 1;
    }
    return result;
}
```