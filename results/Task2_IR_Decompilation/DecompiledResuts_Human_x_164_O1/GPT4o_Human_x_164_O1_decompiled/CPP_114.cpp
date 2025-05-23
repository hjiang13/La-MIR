```cpp
#include <vector>
#include <cstdint>

int64_t minSubArraySum(std::vector<int64_t> &vec) {
    int64_t* data = vec.data();
    int64_t size = vec.size();
    if (size <= 1) return 0;

    int64_t min_sum = data[0];
    int64_t current_sum = 0;

    for (int64_t i = 0; i < size; ++i) {
        current_sum += data[i];
        if (current_sum < min_sum) {
            min_sum = current_sum;
        }
        if (current_sum > 0) {
            current_sum = 0;
        }
    }

    return min_sum;
}
```