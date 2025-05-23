#include <stdio.h>

int is_multiply_prime(int n) {
    if (n < 4) {
        return n == 2;
    }

    int i = 2;
    int j = 0;
    int k = n;

    while (1) {
        int remainder = k % i;
        if (remainder == 0 && k > i) {
            while (1) {
                k /= i;
                j++;
                remainder = k % i;
                if (remainder != 0 || k <= i) {
                    break;
                }
            }
        }

        if (i * i > k) {
            break;
        }

        i++;
    }

    return j == 2;
}
