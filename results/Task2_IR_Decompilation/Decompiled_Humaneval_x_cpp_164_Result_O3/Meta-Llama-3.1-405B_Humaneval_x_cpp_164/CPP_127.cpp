#include <stdio.h>
#include <string.h>

void intersection(char* result, int* arr1, int* arr2) {
    int len1 = *arr1;
    int len2 = *arr2;
    int min_len = len1 < len2 ? len1 : len2;
    int diff = min_len - 2;

    if (diff < 2) {
        result[0] = 'Y';
        result[1] = 'E';
        result[2] = 'S';
        result[3] = '\0';
    } else {
        int i = 2;
        while (1) {
            int square = i * i;
            if (square > diff) {
                result[0] = 'Y';
                result[1] = 'E';
                result[2] = 'S';
                result[3] = '\0';
                break;
            }
            if (diff % i == 0) {
                result[0] = 'Y';
                result[1] = 'E';
                result[2] = 'S';
                result[3] = '\0';
                break;
            }
            i++;
        }
    }
}

int main() {
    int arr1[] = {4, 1, 2, 3};
    int arr2[] = {4, 1, 2, 3};
    char result[4];

    intersection(result, arr1, arr2);

    printf("%s\n", result);

    return 0;
}
