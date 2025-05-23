Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int* end;
    int* capacity;
} vector;

int vector_size(vector* v) {
    return (v->end - v->data) / sizeof(int);
}

int* vector_get(vector* v, int index) {
    return v->data + index;
}

int add(vector* v) {
    int result = 0;
    for (int i = 0; i < vector_size(v); i++) {
        int num = *vector_get(v, i);
        if (num % 2 == 0) {
            result += num;
        }
    }
    return result;
}
```

Please note that this is a direct translation of the IR code and may not be the most optimized or readable C code. Additionally, the `vector` struct and its functions are simplified representations of the original C++ `std::vector` class.