```cpp
#include <vector>
#include <cstdint>
#include <limits>

long long minSubArraySum(std::vector<long long> &v) {
    long long* data = v.data();
    long long size = v.size();
    if (size <= 1) return 0;

    long long min_sum = std::numeric_limits<long long>::max();
    long long current_sum = 0;

    for (long long i = 0; i < size; ++i) {
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