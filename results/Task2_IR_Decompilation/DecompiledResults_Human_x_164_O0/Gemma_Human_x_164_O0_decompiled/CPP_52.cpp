Based on the provided LLVM IR code, here is the equivalent C source code:

```c
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int* _M_impl;
} _Vector_base;

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base_int;

typedef struct {
    _Vector_base _M_base;
} std_vector;

extern int __attribute__((always_inline)) 
std_vector_size(std_vector* v) {
    _Vector_base_int* base = (_Vector_base_int*)&v->_M_base;
    return base->_M_impl._M_finish - base->_M_impl._M_start;
}

extern int* __attribute__((always_inline)) 
std_vector_at(std_vector* v, int index) {
    _Vector_base_int* base = (_Vector_base_int*)&v->_M_base;
    return base->_M_impl._M_start + index;
}

bool below_threshold(std_vector* v, int threshold) {
    bool result;
    int i = 0;
    while (i < std_vector_size(v)) {
        if (*(std_vector_at(v, i)) >= threshold) {
            result = false;
            goto end;
        }
        i++;
    }
    result = true;
    end:
    return result;
}
```

Please note that this C source code is not exactly equivalent to the provided LLVM IR code, as some parts of the IR code are specific to the LLVM compiler infrastructure and do not have direct equivalents in C. However, this code should provide the same functionality as the IR code. Also, some types and function names have been changed to match the C naming conventions.