#include <stdio.h>

int iscuber(int x) {
    int abs_x = (x < 0) ? -x : x;
    int i = 0;
    while (1) {
        long long cube = (long long)i * i * i;
        if (cube >= abs_x) break;
        i++;
    }
    return cube <= abs_x;
}
