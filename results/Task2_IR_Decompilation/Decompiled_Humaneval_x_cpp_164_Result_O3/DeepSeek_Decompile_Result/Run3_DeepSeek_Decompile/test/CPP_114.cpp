#include <vector>
using namespace std;

long long minSubArraySum(const vector<long long>& arr) {
    if (arr.empty()) {
        return 0; // Assuming 0 for empty array, adjust if needed
    }

    long long min_sum = arr[0];
    long long current_sum = arr[0];
    
    for (size_t i = 1; i < arr.size(); ++i) {
        current_sum = min(arr[i], current_sum + arr[i]);
        min_sum = min(min_sum, current_sum);
    }

    return min_sum;
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
