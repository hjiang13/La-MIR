#include <stdbool.h>

bool move_one_ball(int* arr, int len) {
    int count = 0;
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < max) {
            count++;
        }
    }
    return count < 2;
}
