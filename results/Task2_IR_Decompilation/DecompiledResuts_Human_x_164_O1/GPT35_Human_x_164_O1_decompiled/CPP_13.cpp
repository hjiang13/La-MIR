```c
#include <stdio.h>

int greatest_common_divisor(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main() {
    int num1 = 15;
    int num2 = 25;
    int result = greatest_common_divisor(num1, num2);
    printf("Greatest common divisor of %d and %d is %d\n", num1, num2, result);
    return 0;
}
```