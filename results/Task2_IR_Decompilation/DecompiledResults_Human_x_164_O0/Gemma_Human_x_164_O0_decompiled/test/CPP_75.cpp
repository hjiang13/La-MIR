Based on the provided LLVM IR code, here is the equivalent C source code:

```c
#include <stdbool.h>

bool is_multiply_prime(int n) {
    int i = 0;
    int j = 2;
    while (j * j <= n) {
        if (n % j == 0) {
            n /= j;
            i++;
        } else {
            j++;
        }
    }
    return i == 2;
}
```

Note that I've used the `stdbool.h` header to use the `bool` type, which is equivalent to the `i1` type in the LLVM IR code. Also, I've used the same variable names as in the IR code to maintain consistency.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_multiply_prime(5) == false);
    assert (is_multiply_prime(30) == true);
    assert (is_multiply_prime(8) == true);
    assert (is_multiply_prime(10) == false);
    assert (is_multiply_prime(125) == true);
    assert (is_multiply_prime(3 * 5 * 7) == true);
    assert (is_multiply_prime(3 * 6 * 7) == false);
    assert (is_multiply_prime(9 * 9 * 9) == false);
    assert (is_multiply_prime(11 * 9 * 9) == false);
    assert (is_multiply_prime(11 * 13 * 7) == true);
}
