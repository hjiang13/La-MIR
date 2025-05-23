#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int specialFilter(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 10) {
            char str[16];
            sprintf(str, "%d", arr[i]);
            int len = strlen(str);
            if (len % 2 == 1) {
                if (str[len - 1] % 2 == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    // example usage
    int arr[] = {1, 12, 3, 14, 5, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = specialFilter(arr, size);
    printf("%d\n", result);
    return 0;
}
