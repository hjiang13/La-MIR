```c
#include <vector>
#include <algorithm>

void compare(std::vector<int>& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    result.clear();
    result.resize(vec1.size());

    for (size_t i = 0; i < vec1.size(); ++i) {
        int diff = std::abs(vec1[i] - vec2[i]);
        result[i] = diff;
    }
}
```