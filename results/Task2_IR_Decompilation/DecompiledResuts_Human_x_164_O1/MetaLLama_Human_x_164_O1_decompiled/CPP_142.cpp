#include <stdint.h>

int sum_squares(int* data, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        int value = data[i];
        if (i % 3 == 0) {
            result += value * value;
        } else if (i % 4 == 0) {
            result += value * value * value;
        } else {
            result += value;
        }
    }
    return result;
}
