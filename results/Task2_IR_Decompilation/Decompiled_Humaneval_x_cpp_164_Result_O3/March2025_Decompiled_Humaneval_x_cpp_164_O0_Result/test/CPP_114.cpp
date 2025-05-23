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

#undef NDEBUG
#include<assert.h>
int main(){
    assert (minSubArraySum({2, 3, 4, 1, 2, 4}) == 1);
    assert (minSubArraySum({-1, -2, -3}) == -6);
    assert (minSubArraySum({-1, -2, -3, 2, -10}) == -14);
    assert (minSubArraySum({-9999999999999999}) == -9999999999999999);
    assert (minSubArraySum({0, 10, 20, 1000000}) == 0);
    assert (minSubArraySum({-1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({100, -1, -2, -3, 10, -5}) == -6);
    assert (minSubArraySum({10, 11, 13, 8, 3, 4}) == 3);
    assert (minSubArraySum({100, -33, 32, -1, 0, -2}) == -33);
    assert (minSubArraySum({-10}) == -10);
    assert (minSubArraySum({7}) == 7);
    assert (minSubArraySum({1, -1}) == -1);
}
