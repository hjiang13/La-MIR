#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* _M_p;
} _Alloc_hider;

typedef struct {
    _Alloc_hider _M_dataplus;
    long long _M_string_length;
    char _M_local_buf[16];
} basic_string;

typedef struct {
    basic_string** _M_impl;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
    _Vector_base _M_base;
} vector;

void _Z7longestSt6vectorINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEESaIS5_EE(basic_string* sret, vector* vec) {
    basic_string* _3 = &sret->_M_dataplus;
    sret->_M_dataplus._M_p = (char*)_3;
    sret->_M_string_length = 0;
    *_3 = 0;

    basic_string** _7 = vec->_M_base._M_impl._M_impl;
    basic_string** _8 = vec->_M_base._M_impl._M_impl + 1;
    basic_string* _9 = *_7;
    basic_string* _10 = *_8;

    if (_9 == _10) {
        return;
    }

    basic_string* _13 = _10;
    basic_string* _14 = _9;
    long long _15 = 0;
    long long _16 = 0;

    while (1) {
        long long _18 = _13->_M_string_length;
        if (_18 > _15) {
            _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_(sret, _13);
            _9 = *_7;
            _10 = *_8;
        }

        long long _35 = _16 + 1;
        long long _36 = (long long)_14;
        long long _37 = (long long)_13;
        long long _38 = _36 - _37;
        long long _39 = _38 >> 5;
        if (_39 > _35) {
            _15 = sret->_M_string_length;
            _13 = _10;
            _14 = _9;
            _16 = 0;
        } else {
            break;
        }
    }

    return;
}

void _ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_(basic_string* ths, basic_string* str) {
    // implementation of _M_assign not provided
}

void _ZdlPv(void* ptr) {
    free(ptr);
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (longest({}) == "");
    assert (longest({"x", "y", "z"}) == "x");
    assert (longest({"x", "yyy", "zzzz", "www", "kkkk", "abc"}) == "zzzz");
}
