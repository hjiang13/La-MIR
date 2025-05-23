```c
#include <stdint.h>

int x_or_y(int arg0, int arg1, int arg2) {
    if (arg0 > 1) {
        if (arg0 < 4) {
            if ((arg0 % 2) == 0) {
                return arg2;
            } else {
                return arg1;
            }
        }
    } else {
        int i = 2;
        while (1) {
            if ((i * i) > arg0) {
                if ((arg0 % i) == 0) {
                    return arg1;
                } else {
                    return 0;
                }
            }
            i++;
        }
    }
}
```