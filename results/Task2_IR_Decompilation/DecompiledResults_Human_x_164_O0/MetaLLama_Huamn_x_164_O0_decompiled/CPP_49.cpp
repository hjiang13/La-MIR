Based on the provided LLVM IR code, I will generate the corresponding C source code. Here it is:

```c
int modp(int a, int b) {
    int c = 1;
    int d = 0;
    while (d < a) {
        c = (c * 2) % b;
        d++;
    }
    return c;
}
```

Note that I've removed the unnecessary variables and simplified the code to match the original functionality. The generated C code should produce the same results as the original IR code.