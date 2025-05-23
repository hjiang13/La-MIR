```c
#include <stdio.h>

int fizz_buzzi(int x) {
    if (x > 0) {
        int sum = 0;
        for (int i = 0; i < x; i++) {
            if (i % 11 != 0 && i % 13 != 0) {
                if (i % 10 == 7) {
                    sum += 1;
                }
            }
        }
        return sum;
    }
    return 0;
}

int main() {
    int result = fizz_buzzi(100);
    printf("Result: %d\n", result);
    return 0;
}
```