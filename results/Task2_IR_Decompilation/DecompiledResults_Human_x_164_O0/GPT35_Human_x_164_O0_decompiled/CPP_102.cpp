```c
#include <stdio.h>

int choose_num(int num1, int num2) {
    int result = 0;
    
    if (num2 < num1) {
        result = -1;
    } else {
        if (num2 == num1) {
            if (num2 % 2 == 1) {
                result = -1;
            }
        } else {
            if (num2 % 2 == 1) {
                result = num2 - 1;
            } else {
                result = num2;
            }
        }
    }
    
    return result;
}

int main() {
    int num1 = 5;
    int num2 = 7;
    
    int result = choose_num(num1, num2);
    
    printf("Result: %d\n", result);
    
    return 0;
}
```