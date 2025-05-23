#include <vector>
using namespace std;

int count_nums(vector<int> vec) {
    if (vec.empty()) {
        return 0;
    }

    int len = (vec.end() - vec.begin()) >> 1;
    len = len < 1 ? 1 : len;

    int count = 0;
    for (int i = 0; i < len; ++i) {
        int num = vec[i];
        if (num > 0) {
            count++;
        } else {
            int temp = -num;
            int digit_sum = 0;
            while (temp > 99) {
                digit_sum += temp % 10;
                temp /= 10;
            }
            count += digit_sum;
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
