#include <vector>
#include <cstdlib>

int count_nums(std::vector<int> &vec) {
    int count = 0;
    int index = 0;
    int remainder = 0;
    int abs_val = 0;

    for (index = 0; index < vec.size(); ++index) {
        if (vec[index] > 0) {
            count++;
        } else {
            abs_val = std::abs(vec[index]);
            if (abs_val >= 10) {
                remainder += abs_val % 10;
                count += remainder;
                remainder = abs_val / 10;
            } else {
                remainder = abs_val;
            }
        }
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
