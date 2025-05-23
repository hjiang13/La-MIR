#include <vector>
#include <algorithm>

using namespace std;

bool triples_sum_to_zero(const vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
        return false;
    }
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; ++i) {
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                return true;
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }
    
    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (triples_sum_to_zero({1, 3, 5, 0}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -1}) == false);
    assert (triples_sum_to_zero({1, 3, -2, 1}) == true);
    assert (triples_sum_to_zero({1, 2, 3, 7}) == false);
    assert (triples_sum_to_zero({1, 2, 5, 7}) == false);
    assert (triples_sum_to_zero({2, 4, -5, 3, 9, 7}) == true);
    assert (triples_sum_to_zero({1}) == false);
    assert (triples_sum_to_zero({1, 3, 5, -100}) == false);
    assert (triples_sum_to_zero({100, 3, 5, -100}) == false);
}
