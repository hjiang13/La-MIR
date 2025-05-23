```c
#include <stdbool.h>

bool is_equal_to_sum_even(int num) {
    bool result;
    int num_copy = num;
    
    if (num_copy % 2 == 0) {
        if (num_copy >= 8) {
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