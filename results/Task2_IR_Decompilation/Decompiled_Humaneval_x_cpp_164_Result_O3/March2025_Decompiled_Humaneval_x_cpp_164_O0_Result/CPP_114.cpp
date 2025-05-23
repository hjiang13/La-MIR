```cpp
#include <vector>
#include <limits>

long long minSubArraySum(std::vector<long long>& vec) {
    if (vec.empty()) return 0;

    long long currentSum = vec[0];
    long long minSum = vec[0];

    for (size_t i = 1; i < vec.size(); ++i) {
        if (currentSum < 0) {
            currentSum += vec[i];
        } else {
            currentSum = vec[i];
        }
        if (currentSum < minSum) {
            minSum = currentSum;
        }
    }

    return minSum;
}
```