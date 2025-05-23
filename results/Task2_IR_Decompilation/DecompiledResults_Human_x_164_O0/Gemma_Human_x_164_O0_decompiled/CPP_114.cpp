Here is the C source code generated from the provided LLVM IR code:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long* data;
    long long* end;
    long long* capacity;
} Vector;

long long vectorSize(Vector* v) {
    return (v->end - v->data) / 8;
}

long long* vectorGet(Vector* v, long long index) {
    return &v->data[index];
}

long long minSubArraySum(Vector* v) {
    long long sum = *vectorGet(v, 0);
    long long minSum = sum;
    for (int i = 1; i < vectorSize(v); i++) {
        long long current = *vectorGet(v, i);
        if (sum < 0) {
            sum += current;
        } else {
            sum = current;
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }
    return minSum;
}
```

Please note that the above C code is a direct translation of the provided LLVM IR code and may not be the most efficient or optimal implementation. It's also worth mentioning that the original IR code seems to be generated from C++ code, and the translated C code may not fully capture the original C++ code's semantics.