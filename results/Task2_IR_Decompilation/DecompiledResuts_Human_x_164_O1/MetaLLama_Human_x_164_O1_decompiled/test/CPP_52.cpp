#include <stdbool.h>
#include <stdint.h>

bool below_threshold(int* data, int size, int threshold) {
    int64_t length = (int64_t)(data + size) - (int64_t)data;
    length >>= 2;

    if (length == 0) {
        return true;
    }

    int64_t max = __builtin_umaxll(length, 1);
    int64_t i = 1;

    do {
        if (data[i - 1] >= threshold) {
            return false;
        }
        i++;
    } while (i <= max);

    return length > max;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_threshold({1, 2, 4, 10}, 100));
    assert (not(below_threshold({1, 20, 4, 10}, 5)));
    assert (below_threshold({1, 20, 4, 10}, 21));
    assert (below_threshold({1, 20, 4, 10}, 22));
    assert (below_threshold({1, 8, 4, 10}, 11));
    assert (not(below_threshold({1, 8, 4, 10}, 10)));
}
