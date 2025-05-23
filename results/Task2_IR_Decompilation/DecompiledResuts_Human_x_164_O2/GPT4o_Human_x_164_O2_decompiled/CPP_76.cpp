```cpp
#include <stdbool.h>

bool is_simple_power(int a, int b) {
    if (a <= 0) return false;
    if (a == 1) return b == 1;

    int count = 0;
    int power = 1;

    while (count < 99 && power <= a) {
        if (power == a) return true;
        power *= b;
        count++;
    }
    return false;
}
```