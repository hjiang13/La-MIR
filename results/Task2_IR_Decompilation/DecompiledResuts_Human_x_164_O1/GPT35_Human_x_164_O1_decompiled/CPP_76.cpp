```c
#include <stdbool.h>

bool is_simple_power(int a, int b) {
    if (a > 0 && a > 1) {
        int product = b;
        int power = 1;
        while (product <= a && power < 99) {
            if (product == a) {
                return true;
            }
            product *= b;
            power++;
        }
        return false;
    }
    return false;
}
```