#include <vector>
#include <climits>

using namespace std;

long long minSubArraySum(const vector<long long>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    
    long long min_ending_here_even = arr[0];
    long long min_ending_here_odd = LLONG_MAX;
    long long min_so_far = arr[0];

    // First pass for even indices
    for (int i = 0; i < n; ++i) {
        min_ending_here_even += arr[i];
        if (min_ending_here_even < min_so_far) {
            min_so_far = min_ending_here_even;
        }
        if (min_ending_here_even < 0) {
            min_ending_here_even = 0;
        }
    }

    // Second pass for odd indices
    for (int i = 1; i < n; ++i) {
        min_ending_here_odd += arr[i];
        if (min_ending_here_odd < min_so_far) {
            min_so_far = min_ending_here_odd;
        }
        if (min_ending_here_odd < 0) {
            min_ending_here_odd = 0;
        }
    }

    return min_so_far;
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
