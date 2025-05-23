#include <stdio.h>
#include <stdint.h>

int count_nums(int* arr, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > 0) {
            count++;
        } else {
            int num = -arr[i];
            int sum = 0;
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

int main() {
    // You can call the count_nums function from here
    return 0;
}
