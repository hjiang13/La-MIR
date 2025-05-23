```cpp
#include <vector>

bool is_sorted(const std::vector<int>& vec) {
    if (vec.size() <= 1) {
        return true;
    }
    
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}
```