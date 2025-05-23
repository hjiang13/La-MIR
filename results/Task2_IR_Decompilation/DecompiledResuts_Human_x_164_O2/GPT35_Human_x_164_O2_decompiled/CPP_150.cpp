```c
#include <stdio.h>

int x_or_y(int a, int b, int c) {
    if (a > 1) {
        if (a < 4) {
            if ((a % 2) == 0) {
                return b;
            } else {
                return c;
            }
        } else {
            return b;
        }
    } else {
        return c;
    }
}

int main() {
    int result = x_or_y(3, 5, 7);
    printf("Result: %d\n", result);
    return 0;
}
```