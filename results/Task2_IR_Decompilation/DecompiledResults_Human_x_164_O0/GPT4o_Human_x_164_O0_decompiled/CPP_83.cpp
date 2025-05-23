```cpp
#include <iostream>

extern "C" int starts_one_endsi(int arg) {
    int result;
    if (arg < 1) {
        result = 0;
    } else if (arg == 1) {
        result = 1;
    } else {
        int multiplier = 18;
        int count = 2;
        while (count < arg) {
            multiplier *= 10;
            count++;
        }
        result = multiplier;
    }
    return result;
}
```