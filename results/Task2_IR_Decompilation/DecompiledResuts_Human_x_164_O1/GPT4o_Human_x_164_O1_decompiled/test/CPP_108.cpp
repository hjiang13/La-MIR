#include <vector>
#include <cstdlib>

int count_nums(std::vector<int> &vec) {
    int *data_ptr = vec.data();
    int *end_ptr = data_ptr + vec.size();
    if (data_ptr == end_ptr) {
        return 0;
    }

    int count = 0;
    for (int *ptr = data_ptr; ptr < end_ptr; ++ptr) {
        int value = *ptr;
        if (value > 0) {
            int abs_value = std::abs(value);
            if (abs_value > 9) {
                int sum = 0;
                while (abs_value > 99) {
                    sum += abs_value % 10;
                    abs_value /= 10;
                }
                sum += abs_value;
                count += (sum > value) ? 1 : 0;
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
