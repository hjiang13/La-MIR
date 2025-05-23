```cpp
#include <vector>

bool pairs_sum_to_zero(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[i] + vec[j] == 0) {
                return true;
            }
        }
    }
    return false;
}
```