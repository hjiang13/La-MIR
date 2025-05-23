```c
#include <stdio.h>

int largest_divisor(int num) {
    if (num < 4) {
        return 1;
    }

    for (int i = 2; i <= num; i++) {
        if (num % i == 0) {
            return num / i;
        }
    }

    return 1;
}

int main() {
    int num = 24;
    int result = largest_divisor(num);
    printf("Largest divisor of %d is: %d\n", num, result);
    return 0;
}
```