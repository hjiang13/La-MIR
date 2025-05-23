#include <stdbool.h>
#include <stdint.h>

bool below_zero(const int* data, int size) {
    int64_t start = (int64_t)data;
    int64_t end = (int64_t)data + size;
    int64_t length = (end - start) / 4;

    if (length == 0) {
        return false;
    }

    int64_t max = (length > 1) ? length : 1;
    int sum = data[0];

    for (int64_t i = 1; i < max; ++i) {
        sum += data[i];
        if (sum < 0) {
            return true;
        }
    }

    return length > max;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_zero({}) == false);
    assert (below_zero({1, 2, -3, 1, 2, -3}) == false);
    assert (below_zero({1, 2, -4, 5, 6}) == true);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -4}) == false);
    assert (below_zero({1, -1, 2, -2, 5, -5, 4, -5}) == true);
    assert (below_zero({1, -2, 2, -2, 5, -5, 4, -4}) == true);
}