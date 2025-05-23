```c
#include <stdio.h>

int largest_divisor(int num) {
    if (num < 4) {
        return 2;
    }

    for (int divisor = 2; divisor < num; divisor++) {
        if (num % divisor == 0) {
            return num / divisor;
        }
    }

    return 1;
}

int main() {
    int num = 24;
    int result = largest_divisor(num);
    printf("Largest divisor of %d is: %d\n", num, result);
    
    return 0;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_divisor(3) == 1);
    assert (largest_divisor(7) == 1);
    assert (largest_divisor(10) == 5);
    assert (largest_divisor(100) == 50);
    assert (largest_divisor(49) == 7);
}
