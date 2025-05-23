```c
#include <stdbool.h>

bool is_equal_to_sum_even(int num) {
    int temp = num & 1;
    bool is_even = temp == 0;
    bool is_greater_than_7 = num > 7;
    bool result = is_greater_than_7 && is_even;
    return result;
}
```