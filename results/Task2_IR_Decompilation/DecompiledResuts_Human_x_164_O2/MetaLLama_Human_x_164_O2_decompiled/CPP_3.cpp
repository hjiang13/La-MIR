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
