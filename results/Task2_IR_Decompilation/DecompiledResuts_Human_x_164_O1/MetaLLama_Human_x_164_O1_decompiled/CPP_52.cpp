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
