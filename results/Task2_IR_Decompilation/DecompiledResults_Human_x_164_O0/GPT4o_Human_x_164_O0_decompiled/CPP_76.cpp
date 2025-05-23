```cpp
#include <stdbool.h>

bool is_simple_power(int base, int exponent) {
    bool result = true;
    int power = 1;
    int count = 0;

    while (power <= base) {
        if (power == base) {
            return true;
        }
        if (count >= 100) {
            result = false;
            break;
        }
        power *= exponent;
        count++;
    }
    return result;
}
```