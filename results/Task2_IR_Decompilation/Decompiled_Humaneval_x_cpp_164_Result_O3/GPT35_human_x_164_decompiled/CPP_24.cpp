```c
#include <stdio.h>

int largest_divisor(int num) {
    if (num < 4) {
        return 2;
    }

    for (int divisor = 2; divisor < num; divisor++) {
        if (num % divisor == 0) {
            return num / divisor;
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