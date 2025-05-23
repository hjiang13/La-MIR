```cpp
#include <stdbool.h>

bool is_simple_power(int a, int b) {
    if (a <= 0) return false;
    if (a == 1) return (b == 0);

    int count = 0;
    int value = 1;
    
    while (value <= a && count < 99) {
        value *= b;
        count++;
        if (value == a) return true;
    }
    
    return false;
}
```