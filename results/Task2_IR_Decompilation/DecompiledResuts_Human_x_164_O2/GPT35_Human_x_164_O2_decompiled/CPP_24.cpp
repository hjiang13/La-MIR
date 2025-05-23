```c
#include <stdio.h>

int largest_divisor(int num) {
    if (num < 4) {
        return 1;
    }

    int divisor = 2;
    while (1) {
        int remainder = num % divisor;
        int quotient = num / divisor;
        if (remainder == 0) {
            return quotient;
        } else {
            divisor++;
            int new_num = divisor * divisor;
            if (new_num > num) {
                return 1;
            }
        }
    }
}

int main() {
    int num = 24;
    int result = largest_divisor(num);
    printf("Largest divisor of %d is: %d\n", num, result);
    
    return 0;
}
```