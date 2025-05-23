Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int closest_integer(const char *str) {
    double num = atof(str);
    return (int)round(num);
}

int main() {
    const char *str = "123.456";
    int result = closest_integer(str);
    printf("%d\n", result);
    return 0;
}
```

Note that I've added a `main` function to make the code compilable and executable. The `closest_integer` function is the equivalent of the `_Z15closest_integerNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE` function in the IR code.