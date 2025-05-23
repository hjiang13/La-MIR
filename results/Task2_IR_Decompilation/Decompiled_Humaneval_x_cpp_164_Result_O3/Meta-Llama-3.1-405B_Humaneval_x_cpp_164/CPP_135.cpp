#include <stdint.h>

int can_arrange(int* arr, int n) {
    int i, j, k, l, m, x, y, z;
    int* p;
    int res = -1;

    if (n == 0) {
        return -1;
    }

    i = n >> 2;
    i = (i == 0) ? 1 : i;
    j = i - 1;
    k = i & 3;
    p = arr;

    if (j < 3) {
        while (k != 0) {
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            k--;
        }
    } else {
        i &= -4;
        while (i != 0) {
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            i -= 4;
        }
        while (k != 0) {
            x = *p;
            y = p - arr;
            res = (y < x) ? res : y;
            p++;
            k--;
        }
    }

    return res;
}
