```c
#include <stdio.h>

int starts_one_endsi(int x) {
    int a = x;
    int b = 0;
    int c = 0;
    int d = 0;

    if (a < 1) {
        b = 0;
        return b;
    } else if (a == 1) {
        b = 1;
        return b;
    } else {
        c = 18;
        d = 2;

        while (d < a) {
            c = c * 10;
            d++;
        }

        b = c;
        return b;
    }
}

int main() {
    int result = starts_one_endsi(5);
    printf("%d\n", result);
    return 0;
}
```