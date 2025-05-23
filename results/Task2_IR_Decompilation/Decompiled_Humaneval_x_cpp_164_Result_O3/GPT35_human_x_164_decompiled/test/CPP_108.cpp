#include <vector>

int count_nums(std::vector<int> &vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > 0) {
            int num = vec[i];
            while (num < -9) {
                int digit = num % 10;
                sum += digit;
                num /= 10;
                if (num > 99) {
                    continue;
                }
            }
            if (sum > 0) {
                sum++;
            }
        }
    }
    return sum;
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
