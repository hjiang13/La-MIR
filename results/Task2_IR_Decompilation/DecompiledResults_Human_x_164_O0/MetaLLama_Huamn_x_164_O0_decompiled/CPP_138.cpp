Based on the provided LLVM IR code, here is the generated C source code:

```c
#include <stdbool.h>

bool is_equal_to_sum_even(int n) {
    bool result;
    if (n % 2 == 0) {
        if (n >= 8) {
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

Let me know if you need further assistance!