```cpp
#include <vector>
#include <algorithm>

int max_fill(std::vector<std::vector<int>> vec, int val) {
    int max_count = 0;
    for (const auto& inner_vec : vec) {
        int count = std::count(inner_vec.begin(), inner_vec.end(), val);
        if (count > max_count) {
            max_count = count;
        }
    }
    return max_count;
}
```