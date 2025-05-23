Based on the provided LLVM IR code, I will generate the equivalent C source code. Here is the C code:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int* end;
    int* capacity;
} vector_base;

typedef struct {
    vector_base base;
} vector;

int* vector_ix(vector* v, long idx) {
    return v->base.data + idx;
}

int add_elements(vector* v, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (*(vector_ix(v, i)) >= -99 && *(vector_ix(v, i)) <= 99) {
            sum += *(vector_ix(v, i));
        }
    }
    return sum;
}
```

Please note that I've made some assumptions about the missing parts of the code (e.g., the `std::vector` class implementation) and simplified the code to match the provided IR. The generated C code might not be identical to the original C++ code but should be functionally equivalent.
#undef NDEBUG
#include<assert.h>
int main(){
    assert (add_elements({1,-2,-3,41,57,76,87,88,99}, 3) == -4);
    assert (add_elements({111,121,3,4000,5,6}, 2) == 0);
    assert (add_elements({11,21,3,90,5,6,7,8,9}, 4) == 125);
    assert (add_elements({111,21,3,4000,5,6,7,8,9}, 4) == 24);
    assert (add_elements({1}, 1) == 1);
}
