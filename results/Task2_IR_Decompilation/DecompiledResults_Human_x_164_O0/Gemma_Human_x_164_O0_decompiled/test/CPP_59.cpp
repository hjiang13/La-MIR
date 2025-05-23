Based on the provided LLVM IR code, here is the equivalent C source code:

```c
int largest_prime_factor(int n) {
    int p = 2;
    while (p * p <= n) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
        }
        p++;
    }
    return n;
}
```

Please note that this code is a direct translation of the provided LLVM IR code and does not include any additional error checking or handling that might be present in the original C++ code.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (largest_prime_factor(15) == 5);
    assert (largest_prime_factor(27) == 3);
    assert (largest_prime_factor(63) == 7);
    assert (largest_prime_factor(330) == 11);
    assert (largest_prime_factor(13195) == 29);
}
