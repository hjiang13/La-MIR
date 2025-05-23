Based on the provided LLVM IR code, here is the equivalent C source code:

```c
float truncate_number(float x) {
    float temp = x;
    int truncated = (int) temp;
    float result = temp - (float) truncated;
    return result;
}
```

Please note that this C code is a direct translation of the provided LLVM IR code and may not be the most efficient or optimal implementation.