```cpp
#include <vector>

bool is_sorted(const std::vector<int>& vec) {
    if (vec.size() < 2) {
        return true;
    }
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            return false;
        }
    }
    return true;
}
```