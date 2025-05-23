```c
#include <stdio.h>

int starts_one_endsi(int x) {
    if (x < 1) {
        return 0;
    } else if (x == 1) {
        return 1;
    } else if (x > 2) {
        int a = 2;
        int b = 18;
        while (1) {
            b = b * 10;
            a = a + 1;
            if (a == x) {
                return b;
            }
        }
    }
    return 18;
}

int main() {
    int result = starts_one_endsi(10);
    printf("%d\n", result);
    return 0;
}
```