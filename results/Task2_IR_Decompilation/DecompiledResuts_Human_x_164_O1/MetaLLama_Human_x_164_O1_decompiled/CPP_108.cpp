#include <stdint.h>

int count_nums(int* arr, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > 0) {
            int num = arr[i];
            if (num > 9) {
                int sum = 0;
                while (num > 99) {
                    sum += num % 10;
                    num /= 10;
                }
                sum += num % 10;
                num /= 10;
                count += (sum > num) ? 1 : 0;
            } else {
                count += 1;
            }
        }
    }
    return count;
}
