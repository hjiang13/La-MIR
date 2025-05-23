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
```