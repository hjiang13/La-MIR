Based on the provided LLVM IR code, here is the equivalent C source code:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int closest_integer(const char* str) {
    double num = atof(str);
    return (int)round(num);
}
```

Note that I've removed the unnecessary parts of the code, such as the `std::__cxx11::basic_string` class and the `llvm.round.f64` function, and replaced them with their equivalent C counterparts. The `closest_integer` function now takes a `const char*` as input and returns an `int` value. The `atof` function is used to convert the string to a double, and the `round` function is used to round the double to the nearest integer.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (closest_integer("10") == 10);
    assert (closest_integer("14.5") == 15);
    assert (closest_integer("-15.5") == -16);
    assert (closest_integer("15.3") == 15);
    assert (closest_integer("0") == 0);
}
