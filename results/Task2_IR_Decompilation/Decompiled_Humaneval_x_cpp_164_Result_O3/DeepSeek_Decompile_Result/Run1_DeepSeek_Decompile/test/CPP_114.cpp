#include <vector>
#include <climits>

using namespace std;

long long minSubArraySum(const vector<long long>& arr) {
    long long* dataPtr = arr.data();
    long long minSum = dataPtr[0];
    long long size = arr.size();

    if (size <= 1) {
        return minSum;
    }

    long long i = 1;
    long long currentSum = dataPtr[1];
    if (currentSum < minSum) {
        minSum = currentSum;
    }

    i = 2;
    currentSum = dataPtr[2];
    if (currentSum < minSum) {
        minSum = currentSum;
    }

    for (; i < size; i++) {
        long long temp = dataPtr[i];
        currentSum = (temp < currentSum + temp) ? temp : currentSum + temp;
        minSum = (temp < minSum) ? temp : minSum;
        minSum = (currentSum < minSum) ? currentSum : minSum;
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
