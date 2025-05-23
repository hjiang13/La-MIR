```c
#include <stdio.h>

int largest_prime_factor(int num) {
    int num_copy = num;
    int divisor = 2;

    while (1) {
        if (divisor * divisor > num_copy) {
            return num_copy;
        }
        
        if (num_copy % divisor == 0) {
            num_copy /= divisor;
        } else {
            divisor++;
        }
    }
}

int main() {
    int num = 13195; // Input number
    int result = largest_prime_factor(num);
    
    printf("Largest prime factor of %d is %d\n", num, result);
    
    return 0;
}
```