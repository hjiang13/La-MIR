```cpp
#include <stdbool.h>

bool is_equal_to_sum_even(int x) {
    bool result;
    if (x % 2 == 0) {
        if (x >= 8) {
            result = true;
        } else {
            result = false;
        }
    } else {
        result = false;
    }
    return result;
}
```