```c
#include <stdio.h>

int sum_to_n(int num) {
    int temp = num;
    temp = temp * (temp + 1) / 2;
    return temp;
}

int main() {
    int num = 10;
    int result = sum_to_n(num);
    printf("Sum of numbers from 1 to %d is: %d\n", num, result);
    return 0;
}
```