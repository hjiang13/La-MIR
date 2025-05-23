```cpp
#include <vector>
#include <algorithm>

int max_fill(std::vector<std::vector<int>>& vec, int divisor) {
    auto vec_data = vec.data();
    auto vec_begin = vec_data[0];
    auto vec_end = vec_data[1];

    if (vec_begin == vec_end) {
        return 0;
    }

    int count = (reinterpret_cast<uint64_t>(vec_begin) - reinterpret_cast<uint64_t>(vec_end)) / 24;
    count = std::max(count, 1LL);

    int total = 0;
    for (int i = 0; i < count; ++i) {
        total += vec_end[i];
    }

    int result = (total - 1) / divisor + 1;
    return result;
}
```