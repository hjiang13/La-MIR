Here is the C source code generated from the provided LLVM IR code:

```c
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int* _M_impl;
} std_vector;

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} vector_impl_data;

typedef struct {
    vector_impl_data _M_impl;
} vector_base;

int abs(int a) {
    return (a > 0) ? a : -a;
}

int* vector_ix(std_vector* v, int64_t i) {
    vector_base* vb = (vector_base*)v;
    vector_impl_data* vid = &vb->_M_impl;
    return vid->_M_start + i;
}

int64_t vector_size(std_vector* v) {
    vector_base* vb = (vector_base*)v;
    vector_impl_data* vid = &vb->_M_impl;
    return (int64_t)(vid->_M_finish - vid->_M_start);
}

int count_nums(std_vector* v) {
    int result = 0;
    int i = 0;
    while (i < vector_size(v)) {
        int elem = *vector_ix(v, i);
        if (elem > 0) {
            result++;
        } else {
            int abs_elem = abs(elem);
            int sum = 0;
            while (abs_elem >= 10) {
                sum += abs_elem % 10;
                abs_elem /= 10;
            }
            sum -= abs_elem;
            if (sum > 0) {
                result++;
            }
        }
        i++;
    }
    return result;
}
```
Please note that this code assumes that the input `std_vector` object has been properly initialized and has enough capacity to hold the required elements. Also, the generated code might not be optimal or idiomatic C code, as it is a direct translation of the LLVM IR code.