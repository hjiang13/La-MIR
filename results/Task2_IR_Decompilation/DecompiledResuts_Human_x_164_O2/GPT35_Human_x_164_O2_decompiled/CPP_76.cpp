```c
#include <stdbool.h>

bool is_simple_power(int a, int b) {
    if (a > 0 && a > 1) {
        int c = 0;
        int d = 1;
        while (d * b <= a && c < 99) {
            if (d * b == a) {
                return true;
            }
            c++;
            d++;
        }
    }
    return false;
}
```