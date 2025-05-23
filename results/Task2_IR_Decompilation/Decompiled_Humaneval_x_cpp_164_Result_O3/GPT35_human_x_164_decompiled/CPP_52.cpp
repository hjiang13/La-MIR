```c
#include <vector>
#include <algorithm>

bool below_threshold(std::vector<int> &v, int threshold) {
    auto *begin = v.data();
    auto *end = begin + v.size();
    
    std::ptrdiff_t size = end - begin;
    std::ptrdiff_t max_size = std::max<size_t>(size >> 2, 1);
    
    if (size == 0) {
        return true;
    }
    
    for (std::ptrdiff_t i = 0; i < max_size; ++i) {
        if (v[i] < threshold) {
            return true;
        }
    }
    
    return false;
}
```