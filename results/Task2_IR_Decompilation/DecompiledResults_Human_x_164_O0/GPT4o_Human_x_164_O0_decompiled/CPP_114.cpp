```cpp
#include <vector>

long long minSubArraySum(std::vector<long long>& vec) {
    long long sum = vec[0];
    long long minSum = vec[0];
    int index = 1;

    while (index < vec.size()) {
        if (sum < 0) {
            sum += vec[index];
        } else {
            sum = vec[index];
        }
        if (sum < minSum) {
            minSum = sum;
        }
        index++;
    }

    return minSum;
}
```