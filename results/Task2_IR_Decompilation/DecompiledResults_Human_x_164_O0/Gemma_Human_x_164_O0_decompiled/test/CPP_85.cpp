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
#undef NDEBUG
#include<assert.h>
int main(){
    assert (add({4, 88}) == 88);
    assert (add({4, 5, 6, 7, 2, 122}) == 122);
    assert (add({4, 0, 6, 7}) == 0);
    assert (add({4, 4, 6, 8}) == 12);
}
