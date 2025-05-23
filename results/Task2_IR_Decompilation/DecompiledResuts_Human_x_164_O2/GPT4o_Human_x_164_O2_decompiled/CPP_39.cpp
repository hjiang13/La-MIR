```cpp
#include <stdbool.h>

extern "C" int prime_fibi(int n) {
    int a = 1;
    int b = 2;
    int count = 0;

    while (count < n) {
        for (int i = 2; i * i <= b; i++) {
            if (b % i == 0) {
                break;
            }
            if (i * i > b) {
                count++;
                break;
            }
        }
        if (count < n) {
            a = b;
            b++;
        }
    }
    return a;
}
```