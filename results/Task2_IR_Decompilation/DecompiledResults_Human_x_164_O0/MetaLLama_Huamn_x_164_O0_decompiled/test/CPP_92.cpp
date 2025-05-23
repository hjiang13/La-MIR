Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <math.h>

int any_int(float a, float b, float c) {
    float temp_a = roundf(a);
    float temp_b = roundf(b);
    float temp_c = roundf(c);

    if (temp_a != a) {
        return 0;
    }

    if (temp_b != b) {
        return 0;
    }

    if (temp_c != c) {
        return 0;
    }

    if (a + b == c) {
        return 1;
    }

    if (a + c == b) {
        return 1;
    }

    if (b + c == a) {
        return 1;
    }

    return 0;
}
```

Please note that the generated C code only includes the `any_int` function, as it is the only function defined in the provided LLVM IR code. The `roundf` function is assumed to be available, as it is declared in the IR code as an external function. In C, this function is part of the math library, so I included the `math.h` header to make it available.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (any_int(2, 3, 1)==true);
    assert (any_int(2.5, 2, 3)==false);
    assert (any_int(1.5, 5, 3.5)==false);
    assert (any_int(2, 6, 2)==false);
    assert (any_int(4, 2, 2)==true);
    assert (any_int(2.2, 2.2, 2.2)==false);
    assert (any_int(-4, 6, 2)==true);
    assert (any_int(2,1,1)==true);
    assert (any_int(3,4,7)==true);
    assert (any_int(3.01,4,7)==false);
}
