#include <stdint.h>

int digitSum(const char *str) {
    int sum = 0;
    uint64_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (uint64_t i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            sum += c;
        }
    }
    return sum;
}
