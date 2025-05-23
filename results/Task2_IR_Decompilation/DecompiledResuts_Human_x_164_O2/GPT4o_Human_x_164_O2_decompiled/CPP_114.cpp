```cpp
#include <vector>
#include <cstdint>

long long minSubArraySum(std::vector<long long> &vec) {
    long long *data = vec.data();
    long long size = vec.size();
    if (size <= 1) {
        return 0; // Handle the edge case for empty or single element vector
    }
    
    long long minSum = data[0];
    for (long long i = 0; i < size; ++i) {
        long long currentSum = 0;
        for (long long j = i; j < size; ++j) {
            currentSum += data[j];
            if (currentSum < minSum) {
                minSum = currentSum;
            }
        }
    }
    
    return minSum;
}
```