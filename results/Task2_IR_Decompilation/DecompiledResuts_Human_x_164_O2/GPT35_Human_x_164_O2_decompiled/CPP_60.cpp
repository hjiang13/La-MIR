```c
#include <stdio.h>

int sum_to_n(int n) {
    int result = (n + 1) * n / 2;
    return result;
}

int main() {
    int n = 10; // Example input value
    int sum = sum_to_n(n);
    printf("Sum of numbers from 1 to %d is %d\n", n, sum);
    
    return 0;
}
```