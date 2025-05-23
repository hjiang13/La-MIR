#include <stdint.h>

uint32_t count_nums(const uint32_t* arr, uint64_t size) {
    uint32_t count = 0;
    for (uint64_t i = 0; i < size; i++) {
        if (arr[i] > 0) {
            uint32_t num = arr[i];
            uint32_t sum = 0;
            while (num > 99) {
                sum += num % 10;
                num /= 10;
            }
            sum += num;
            if (sum > num) {
                count++;
            }
        }
    }
    return count;
}
