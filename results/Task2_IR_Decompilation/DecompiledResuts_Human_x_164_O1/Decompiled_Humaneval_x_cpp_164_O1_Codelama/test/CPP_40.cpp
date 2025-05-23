bool triples_sum_to_zero(vector<int> nums) {
    int n = nums.size();
    if (n < 3) {
        return false;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    if (sum % 3 != 0) {
        return false;
    }

    int target = sum / 3;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == target) {
            count++;
        }
    }

    if (count < 3) {
        return false;
    }

    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (nums[i] + nums[j] == target) {
            count--;
            i++;
            j--;
        } else if (nums[i] + nums[j] < target) {
            i++;
        } else {
            j--;
        }
    }

    return count == 0;
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
