#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float* _M_impl;
} _Vector_base;

typedef struct {
    float* _M_start;
    float* _M_finish;
    float* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base_float;

typedef struct {
    _Vector_base _M_base;
} vector;

void get_positive(vector* __result, vector* __first) {
    float* __first_start = __first->_M_base._M_impl._M_start;
    float* __first_finish = __first->_M_base._M_impl._M_finish;
    float* __result_start = __result->_M_base._M_impl._M_start;
    float* __result_finish = __result->_M_base._M_impl._M_finish;
    memset(__result, 0, sizeof(vector));

    if (__first_start == __first_finish) {
        return;
    }

    int __i = 0;
    float* __tmp = __first_start;

    while (1) {
        float __x = *__tmp;
        if (__x > 0.0f) {
            if (__result_start == __result_finish) {
                _M_realloc_insert(__result, __tmp, &__x);
            } else {
                *__result_start = __x;
                ++__result_start;
            }
        }
        ++__tmp;
        ++__i;
        if (__i >= (__first_finish - __first_start)) {
            break;
        }
    }
    __result->_M_base._M_impl._M_finish = __result_start;
}

void _M_realloc_insert(vector* __this, float* __position, float* __x) {
    float* __new_start = NULL;
    float* __new_finish = NULL;
    int __len = __this->_M_base._M_impl._M_finish - __this->_M_base._M_impl._M_start;
    int __new_capacity = __len + 1;
    if (__new_capacity > 2305843009213693951) {
        __throw_bad_alloc();
    }
    __new_start = (float*)malloc(__new_capacity * sizeof(float));
    __new_finish = __new_start + __new_capacity;
    if (__this->_M_base._M_impl._M_start != NULL) {
        memmove(__new_start, __this->_M_base._M_impl._M_start, __len * sizeof(float));
    }
    *__new_start = *__x;
    if (__position != __this->_M_base._M_impl._M_finish) {
        memmove(__new_start + 1, __position, (__this->_M_base._M_impl._M_finish - __position) * sizeof(float));
    }
    if (__this->_M_base._M_impl._M_start != NULL) {
        free(__this->_M_base._M_impl._M_start);
    }
    __this->_M_base._M_impl._M_start = __new_start;
    __this->_M_base._M_impl._M_finish = __new_finish;
}

void __throw_length_error(const char* __msg) {
    printf("%s\n", __msg);
    exit(1);
}

void __throw_bad_alloc() {
    printf("bad alloc\n");
    exit(1);
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(get_positive({-1, -2, 4, 5, 6}) , {4, 5, 6} ));
    assert (issame(get_positive({5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}) , {5, 3, 2, 3, 3, 9, 123, 1}));
     assert (issame(get_positive({-1, -2}) , {} ));
     assert (issame(get_positive({}) , {}));
}
