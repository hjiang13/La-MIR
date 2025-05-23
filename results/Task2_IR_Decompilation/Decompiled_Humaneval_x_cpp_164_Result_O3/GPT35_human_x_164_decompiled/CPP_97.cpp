```c
#include <stdlib.h>

int multiply(int a, int b) {
    int abs_a = abs(a);
    int abs_b = abs(b);
    int rem_a = abs_a % 10;
    int rem_b = abs_b % 10;
    return rem_a * rem_b;
}
```