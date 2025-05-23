```c
#include <stdio.h>

int greatest_common_divisor(int a, int b) {
    int x = a;
    int y = b;
    
    while (x != y) {
        if (x > y) {
            x = x - y;
        } else {
            y = y - x;
        }
    }
    
    return x;
}

int main() {
    int num1 = 24;
    int num2 = 36;
    
    int gcd = greatest_common_divisor(num1, num2);
    
    printf("Greatest Common Divisor of %d and %d is %d\n", num1, num2, gcd);
    
    return 0;
}
```