```c
#include <stdlib.h>

int abs(int x);

int multiply(int a, int b) {
    int x = a;
    int y = b;
    x = abs(x);
    int mod_x = x % 10;
    y = abs(y);
    int mod_y = y % 10;
    return mod_x * mod_y;
}
```