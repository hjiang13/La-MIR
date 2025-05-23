#include <iostream>
#include <vector>

using namespace std;

int count_nums(vector<int> nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << count_nums(nums) << endl;
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (count_nums({}) == 0);
    assert (count_nums({-1, -2, 0}) == 0);
    assert (count_nums({1, 1, 2, -2, 3, 4, 5}) == 6);
    assert (count_nums({1, 6, 9, -6, 0, 1, 5}) == 5);
    assert (count_nums({1, 100, 98, -7, 1, -1}) == 4);
    assert (count_nums({12, 23, 34, -45, -56, 0}) == 5);
    assert (count_nums({-0, 1}) == 1);
    assert (count_nums({1}) == 1);
}
