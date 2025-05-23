Based on the provided LLVM IR code, here is the equivalent C source code:

```c
int multiply(int a, int b) {
    int temp_a = abs(a) % 10;
    int temp_b = abs(b) % 10;
    return temp_a * temp_b;
}
```

Note that the `abs` function is assumed to be defined elsewhere, as it is declared but not defined in the provided IR code. If you want to include the `abs` function definition, it would be:

```c
int abs(int x) {
    return x < 0 ? -x : x;
}

int multiply(int a, int b) {
    int temp_a = abs(a) % 10;
    int temp_b = abs(b) % 10;
    return temp_a * temp_b;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (multiply(148, 412) == 16                   );
    assert (multiply(19, 28) == 72       );
    assert (multiply(2020, 1851) == 0);
    assert (multiply(14,-15) == 20   );
    assert (multiply(76, 67) == 42    );
    assert (multiply(17, 27) == 49    );
    assert (multiply(0, 1) == 0);
    assert (multiply(0, 0) == 0);
}
