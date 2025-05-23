#include <stdint.h>

uint32_t sum_squares(const uint32_t* data, uint32_t size) {
    uint32_t sum = 0;
    for (uint32_t i = 0; i < size; i++) {
        uint32_t value = data[i];
        uint32_t squared = value * value;
        sum += squared;
    }
    return sum;
}
