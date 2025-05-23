```c
#include <stdio.h>

int choose_num(int num1, int num2) {
    if (num2 < num1) {
        return -1;
    } else {
        if (num2 % 2 == 1 && num2 == num1) {
            return -1;
        } else {
            int addition = num2 % 2;
            int result = addition + num2;
            return result;
        }
    }
}

int main() {
    int num1 = 10;
    int num2 = 7;
    int result = choose_num(num1, num2);
    printf("%d\n", result);
    return 0;
}
```