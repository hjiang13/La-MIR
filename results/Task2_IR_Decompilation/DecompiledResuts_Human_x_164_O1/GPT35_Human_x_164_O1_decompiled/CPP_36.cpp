```c
#include <stdio.h>

int fizz_buzzi(int num) {
    if (num > 0) {
        int res = 0;
        while (1) {
            if ((num % 11 == 0) || (num % 13 == 0) || (num % 10 == 7)) {
                res += num / 10;
            }
            if (num > 9) {
                num = num / 10;
            } else {
                break;
            }
        }
        return res;
    } else {
        return 0;
    }
}

int main() {
    int num = 12345; // Input number
    int result = fizz_buzzi(num);
    printf("Result: %d\n", result);
    return 0;
}
```