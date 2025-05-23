Here is the C source code corresponding to the provided LLVM IR code:

```c
#include <stdio.h>

int is_prime(long long x) {
    if (x < 2) return 0;
    long long i = 2;
    while (i * i <= x) {
        if (x % i == 0) return 0;
        i = i + 1;
    }
    return 1;
}
```

Please note that I removed the unnecessary variables and used a more idiomatic C style. The function name was also changed to `is_prime` to follow conventional naming conventions. The logic remains the same as in the original IR code.
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
