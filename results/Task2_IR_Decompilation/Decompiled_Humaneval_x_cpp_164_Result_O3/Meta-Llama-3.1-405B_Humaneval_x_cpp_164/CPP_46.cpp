#include <stdio.h>

int fib(int n) {
    int arr[100];
    if (n < 4) {
        return arr[n];
    } else {
        arr[4] = 2;
        if (n == 5) {
            return arr[5];
        } else {
            int i, j;
            for (i = 5, j = 4; j < n; i += 2, j += 2) {
                arr[i] = arr[i - 3] + arr[i - 1] + 2;
                arr[i + 1] = arr[i - 2] + arr[i] + arr[i - 1] + arr[i - 3];
            }
            if (n % 2 == 0) {
                return arr[n];
            } else {
                return arr[n - 3] + arr[n - 1] + arr[n];
            }
        }
    }
}
