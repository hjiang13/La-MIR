```cpp
#include <vector>
#include <algorithm>

std::vector<int> sort_third(const std::vector<int>& input) {
    std::vector<int> result;
    for (size_t i = 0; i * 3 < input.size(); ++i) {
        result.push_back(input[i * 3]);
    }
    std::sort(result.begin(), result.end());
    std::vector<int> output;
    for (size_t i = 0; i < input.size(); ++i) {
        if (i % 3 == 0) {
            output.push_back(result[i / 3]);
        } else {
            output.push_back(input[i]);
        }
    }
    return output;
}
```