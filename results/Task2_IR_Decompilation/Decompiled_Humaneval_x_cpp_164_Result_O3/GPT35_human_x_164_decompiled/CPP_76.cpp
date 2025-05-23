```cpp
#include <stdbool.h>

bool is_simple_power(int a, int b) {
    if (a > 1) {
        int result = 1;
        int power = 0;
        
        while (result <= a && power < 99) {
            result *= b;
            power++;
            
            if (result == a) {
                return true;
            }
        }
    }
    
    return false;
}
```