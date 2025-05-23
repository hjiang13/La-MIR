```cpp
#include <vector>
#include <cstdint>

bool pairs_sum_to_zero(const std::vector<int>& vec) {
    const int* data = vec.data();
    size_t size = vec.size();
    
    if (size == 0) return false;

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (data[i] + data[j] == 0) {
                return true;
            }
        }
    }
    return false;
}
```