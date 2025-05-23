```cpp
#include <vector>
#include <algorithm>

int next_smallest(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] != vec[i - 1]) {
            return vec[i];
        }
    }
    return -1;
}
```