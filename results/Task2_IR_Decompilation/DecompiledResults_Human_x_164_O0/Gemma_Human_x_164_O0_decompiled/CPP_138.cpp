Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
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