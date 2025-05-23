```cpp
#include <vector>
#include <cstddef>
#include <cstdint>
#include <algorithm>

extern "C" {
    inline int64_t umax(int64_t a, int64_t b) {
        return (a > b) ? a : b;
    }

    bool below_threshold(std::vector<int> *vec, int threshold) {
        auto data = vec->data();
        auto size = vec->size();
        
        if (size == 0) return true;

        int64_t step = std::max(int64_t(1), (size >> 2));
        if (data[0] < threshold) return false;

        for (int64_t i = 1; i < umax(step, int64_t(1)); ++i) {
            if (data[i] < threshold) return false;
        }

        return step <= size;
    }
}
```