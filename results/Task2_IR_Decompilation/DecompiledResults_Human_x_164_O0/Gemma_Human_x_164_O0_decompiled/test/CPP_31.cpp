Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>

int is_prime(long long x) {
    if (x < 2) {
        return 0;
    }

    long long i = 2;
    while (i * i <= x) {
        if (x % i == 0) {
            return 0;
        }
        i++;
    }

    return 1;
}
```

Please note that I've replaced the `zeroext i1` return type with `int` as C doesn't have a direct equivalent for the former. Also, I've used `long long` to represent the 64-bit integers used in the IR code. The generated C code maintains the same functionality as the original IR code.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_prime(6) == false);
    assert (is_prime(101) == true);
    assert (is_prime(11) == true);
    assert (is_prime(13441) == true);
    assert (is_prime(61) == true);
    assert (is_prime(4) == false);
    assert (is_prime(1) == false);
    assert (is_prime(5) == true);
    assert (is_prime(11) == true);
    assert (is_prime(17) == true);
    assert (is_prime(5 * 17) == false);
    assert (is_prime(11 * 7) == false);
    assert (is_prime(13441 * 19) == false);
}
