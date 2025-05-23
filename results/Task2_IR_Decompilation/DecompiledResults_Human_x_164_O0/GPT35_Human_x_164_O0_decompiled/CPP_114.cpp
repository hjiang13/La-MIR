```C++
#include <vector>

long long minSubArraySum(std::vector<long>& vec) {
    long long minSum = vec[0];
    long long currentSum = vec[0];
    int index = 1;

    while (index < vec.size()) {
        if (currentSum < 0) {
            currentSum = vec[index];
        } else {
            currentSum += vec[index];
        }

        if (currentSum < minSum) {
            minSum = currentSum;
        }

        index++;
    }

    return minSum;
}
```