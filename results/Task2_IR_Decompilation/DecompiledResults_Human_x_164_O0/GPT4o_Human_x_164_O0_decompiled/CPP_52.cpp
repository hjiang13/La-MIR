```cpp
#include <vector>

bool below_threshold(const std::vector<int>& vec, int threshold) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] >= threshold) {
            return false;
        }
    }
    return true;
}
```