#include <stdint.h>

int solution(int* arr, int size) {
    int sum = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 1) {
            sum += arr[i];
        }
    }
    return sum;
}
