Based on the provided LLVM IR code, the equivalent C source code is:

```c
#include <stdio.h>

int is_simple_power(int a, int b) {
    int i = 1;
    int j = 0;
    while (i <= a) {
        if (j < 100) {
            if (i == a) {
                return 1;
            }
            i *= b;
            j++;
        } else {
            return 0;
        }
    }
    return 0;
}
```

Note that I've removed the unnecessary `store` and `load` operations, as well as the `alloca` instructions, as they are not needed in C code. I've also replaced the `br` instructions with equivalent control flow statements in C.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (is_simple_power(1, 4)== true);
    assert (is_simple_power(2, 2)==true);
    assert (is_simple_power(8, 2)==true);
    assert (is_simple_power(3, 2)==false);
    assert (is_simple_power(3, 1)==false);
    assert (is_simple_power(5, 3)==false);
    assert (is_simple_power(16, 2)== true);
    assert (is_simple_power(143214, 16)== false);
    assert (is_simple_power(4, 2)==true);
    assert (is_simple_power(9, 3)==true);
    assert (is_simple_power(16, 4)==true);
    assert (is_simple_power(24, 2)==false);
    assert (is_simple_power(128, 4)==false);
    assert (is_simple_power(12, 6)==false);
    assert (is_simple_power(1, 1)==true);
    assert (is_simple_power(1, 12)==true);
}
