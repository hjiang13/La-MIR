Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
int choose_num(int x, int y) {
    int result;

    if (y < x) {
        result = -1;
    } else if (y == x) {
        if (y % 2 == 1) {
            result = -1;
        } else {
            if (y % 2 == 1) {
                result = y - 1;
            } else {
                result = y;
            }
        }
    } else {
        if (y % 2 == 1) {
            result = y - 1;
        } else {
            result = y;
        }
    }

    return result;
}
```

Please note that the generated C code is a direct translation of the provided LLVM IR code and may not be optimized or idiomatic C code.