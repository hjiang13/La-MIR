```c
#include <stdbool.h>

bool is_simple_power(int x, int y) {
    int result = 1;
    int count = 0;
    
    while (result <= x) {
        if (count < 100) {
            if (result == x) {
                return true;
            } else {
                result *= y;
                count++;
            }
        } else {
            return false;
        }
    }
    
    return false;
}
```