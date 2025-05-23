#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float* _M_start;
    float* _M_finish;
    float* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
    _Vector_base _M_base;
} std__vector;

void _Z10derivativeSt6vectorIfSaIfEE(std__vector* noalias sret, std__vector* readonly) {
    _Vector_impl_data* impl = &sret->_M_base._M_impl;
    _Vector_impl_data* readonly_impl = &readonly->_M_base._M_impl;
    float* start = readonly_impl->_M_start;
    float* finish = readonly_impl->_M_finish;
    float* _M_start = impl->_M_start;
    float* _M_finish = impl->_M_finish;
    float* _M_end_of_storage = impl->_M_end_of_storage;
    memset(impl, 0, sizeof(_Vector_impl_data));
    float* _M_start2 = start;
    float* _M_finish2 = finish;
    float* _M_end_of_storage2 = 0;
    float* _M_start3 = 0;
    float* _M_finish3 = 0;
    unsigned long _M_len = (unsigned long)(finish - start);
    unsigned long _M_capacity = _M_len >> 2;
    if (_M_capacity > 1) {
        unsigned long _M_idx = 1;
        float _M_val;
        while (1) {
            float f = *_M_start2;
            _M_val = f * _M_idx;
            if (_M_start3 == _M_finish3) {
                if (_M_capacity == 9223372036854775804) {
                    __throw_length_error("vector::_M_realloc_insert");
                }
                unsigned long _M_new_capacity = _M_capacity + (_M_capacity >> 1);
                if (_M_new_capacity < _M_capacity) {
                    _M_new_capacity = 2305843009213693951;
                }
                float* _M_new_start = (float*)malloc(_M_new_capacity * sizeof(float));
                *_M_new_start = _M_val;
                if (_M_start2 != _M_finish2) {
                    memmove(_M_new_start + 1, _M_start2, (_M_finish2 - _M_start2) * sizeof(float));
                }
                if (_M_start != 0) {
                    free(_M_start);
                }
                _M_start = _M_new_start;
                _M_finish = _M_new_start + _M_new_capacity;
                _M_end_of_storage = _M_new_start + _M_new_capacity;
                _M_start3 = _M_new_start;
                _M_finish3 = _M_new_start + 1;
            } else {
                *_M_start3 = _M_val;
                _M_start3++;
            }
            _M_start2++;
            _M_idx++;
            if (_M_start2 == _M_finish2) {
                break;
            }
        }
    }
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
    assert (issame(derivative({3, 1, 2, 4, 5}) , {1, 4, 12, 20}));
    assert (issame(derivative({1, 2, 3}) , {2, 6}));
    assert (issame(derivative({3, 2, 1}) , {2, 2}));
    assert (issame(derivative({3, 2, 1, 0, 4}) , {2, 2, 0, 16}));
    assert (issame(derivative({1}) , {}));
}
