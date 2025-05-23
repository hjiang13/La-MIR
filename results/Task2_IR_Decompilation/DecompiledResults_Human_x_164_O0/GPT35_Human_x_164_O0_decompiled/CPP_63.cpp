```c
#include <stdio.h>

int fib(int n) {
    int fibArr[100];
    fibArr[0] = 0;
    fibArr[1] = 0;
    fibArr[2] = 1;
    int i = 3;
    while (i <= n) {
        fibArr[i] = fibArr[i - 1] + fibArr[i - 2] + fibArr[i - 3];
        i++;
    }
    return fibArr[n];
}

int main() {
    int num = 10; // Change this to the desired Fibonacci number
    int result = fib(num);
    printf("Fibonacci number at position %d is %d\n", num, result);
    return 0;
}
```