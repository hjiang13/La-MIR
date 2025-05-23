#include <stdint.h>

typedef struct {
    int* _M_impl;
} std_Vector_base;

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} std_Vector_base_impl_data;

typedef struct {
    std_Vector_base_impl_data _M_impl;
} std_Vector_base_impl;

typedef struct {
    std_Vector_base_impl _M_impl;
} std_Vector_base;

typedef struct {
    std_Vector_base _M_base;
} std_Vector;

int is_sorted(std_Vector* v) {
    int* start = v->_M_base._M_impl._M_impl._M_start;
    int* finish = v->_M_base._M_impl._M_impl._M_finish;
    uint64_t size = (uint64_t)finish - (uint64_t)start;
    size >>= 2;
    if (size <= 1) return 1;

    int prev = *start;
    for (uint64_t i = 1; i < size; i++) {
        int curr = *(start + i);
        if (curr < prev) return 0;
        if (i > 1 && curr == prev) {
            uint64_t idx = i - 1;
            int* ptr = start + idx;
            if (*ptr != prev) return 0;
        }
        prev = curr;
    }
    return 1;
}
