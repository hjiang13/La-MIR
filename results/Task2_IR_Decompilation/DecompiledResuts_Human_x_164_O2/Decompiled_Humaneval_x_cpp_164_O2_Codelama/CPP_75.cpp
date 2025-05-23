```
#include <stdio.h>
#include <string>

using namespace std;

bool is_multiply_prime(int num) {
    if (num < 4) {
        return false;
    }
    int i = 2;
    while (i * i <= num) {
        if (num % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    int num = 17;
    if (is_multiply_prime(num)) {
        printf("The number %d is a multiply of prime numbers.\n", num);
    } else {
        printf("The number %d is not a multiply of prime numbers.\n", num);
    }
    return 0;
}
```

Note: The decompiled code is in C, not C++.