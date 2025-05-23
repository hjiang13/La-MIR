#include <vector>
#include <cmath>

int count_nums(std::vector<int> vec) {
    int count = 0;
    int i = 0;
    while (i < vec.size()) {
        if (vec[i] > 0) {
            count++;
        } else {
            int sum = 0;
            int abs_val = std::abs(vec[i]);
            while (abs_val >= 10) {
                sum += abs_val % 10;
                abs_val /= 10;
            }
            sum -= abs_val;
            if (sum > 0) {
                count++;
            }
        }
        i++;
    }
    return count;
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
