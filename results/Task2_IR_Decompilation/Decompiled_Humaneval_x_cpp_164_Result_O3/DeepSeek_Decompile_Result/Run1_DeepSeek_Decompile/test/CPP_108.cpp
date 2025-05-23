#include <vector>
using namespace std;

int count_nums(vector<int>* vec) {
    if (vec->empty()) return 0;

    int count = 0;
    size_t size = vec->size();
    size = (size + 1) >> 1; // Equivalent to size = max(size / 2, 1)

    for (size_t i = 0; i < size; ++i) {
        int num = (*vec)[i];
        if (num > 0) {
            // Process digits
            int sum = 0;
            int temp = num;
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum > num) {
                count++;
            }
        } else {
            // Handle negative numbers
            num = -num;
            int sum = 0;
            int temp = num;
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum > num) {
                count++;
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
