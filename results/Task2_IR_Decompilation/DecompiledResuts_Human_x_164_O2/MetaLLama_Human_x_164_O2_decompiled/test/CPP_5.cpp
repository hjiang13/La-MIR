#include <stdlib.h>
#include <string.h>

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
} vector;

void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(vector* this, int* __position, int* __x) {
    int* __old_start = this->_M_base._M_impl._M_start;
    int* __old_finish = this->_M_base._M_impl._M_finish;
    int __old_size = __old_finish - __old_start;
    int __new_size = __old_size + 1;
    int* __new_start = (int*)malloc(__new_size * sizeof(int));
    int* __new_finish = __new_start + __new_size;
    if (__old_size > 0) {
        memmove(__new_start, __old_start, __old_size * sizeof(int));
    }
    if (__position != __old_finish) {
        memmove(__new_start + (__position - __old_start) + 1, __position, (__old_finish - __position) * sizeof(int));
    }
    *(__new_start + (__position - __old_start)) = *__x;
    if (__old_start != NULL) {
        free(__old_start);
    }
    this->_M_base._M_impl._M_start = __new_start;
    this->_M_base._M_impl._M_finish = __new_finish;
    this->_M_base._M_impl._M_end_of_storage = __new_finish;
}

void _Z11intersperseSt6vectorIiSaIiEEi(vector* __result, vector* __input, int __value) {
    __result->_M_base._M_impl._M_start = NULL;
    __result->_M_base._M_impl._M_finish = NULL;
    __result->_M_base._M_impl._M_end_of_storage = NULL;
    int* __input_start = __input->_M_base._M_impl._M_start;
    int* __input_finish = __input->_M_base._M_impl._M_finish;
    if (__input_start == __input_finish) {
        return;
    }
    _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(__result, NULL, __input_start);
    int* __result_start = __result->_M_base._M_impl._M_start;
    int* __result_finish = __result->_M_base._M_impl._M_finish;
    int* __input_ptr = __input_start + 1;
    while (__input_ptr != __input_finish) {
        _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(__result, __result_finish, __input_ptr);
        __result_finish = __result->_M_base._M_impl._M_finish;
        __input_ptr++;
    }
    int __n = __result_finish - __result_start;
    if (__n > 1) {
        int* __new_start = (int*)malloc(__n * sizeof(int));
        int* __new_finish = __new_start + __n;
        int __i = 1;
        int* __result_ptr = __result_start + 1;
        while (__result_ptr != __result_finish) {
            if (__i == 1) {
                *__new_start = __value;
            } else {
                *(__new_start + __i - 1) = *__result_ptr;
            }
            __i++;
            __result_ptr++;
        }
        if (__result_start != NULL) {
            free(__result_start);
        }
        __result->_M_base._M_impl._M_start = __new_start;
        __result->_M_base._M_impl._M_finish = __new_finish;
        __result->_M_base._M_impl._M_end_of_storage = __new_finish;
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<int> a,vector<int>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=b[i]) return false;
    }
    return true;
}
int main(){
    assert (issame(intersperse({}, 7), {}));
    
    assert (issame(intersperse({5, 6, 3, 2}, 8),{5, 8, 6, 8, 3, 8, 2}));
    assert (issame(intersperse({2, 2, 2}, 2),{2, 2, 2, 2, 2}));
}