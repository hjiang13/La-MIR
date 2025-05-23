#include <stdio.h>
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

void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(vector* this, int* __position, int* __x) {
    int* __new_start = NULL;
    int __new_size = 0;
    if (this->_M_base._M_impl._M_end_of_storage - this->_M_base._M_impl._M_start == 0) {
        __new_size = 1;
    } else {
        __new_size = (this->_M_base._M_impl._M_end_of_storage - this->_M_base._M_impl._M_start) * 2;
    }

    if (__new_size > 2305843009213693951) {
        __new_size = 2305843009213693951;
    }

    if (__new_size > 0) {
        __new_start = (int*)malloc(__new_size * sizeof(int));
        if (!__new_start) {
            exit(1);
        }
    }

    int* __new_finish = __new_start + (__position - this->_M_base._M_impl._M_start);
    *__new_finish = *__x;

    if (this->_M_base._M_impl._M_start != this->_M_base._M_impl._M_finish) {
        memmove(__new_start, this->_M_base._M_impl._M_start, (__position - this->_M_base._M_impl._M_start) * sizeof(int));
    }

    if (this->_M_base._M_impl._M_finish != __position) {
        memmove(__new_finish + 1, __position, (this->_M_base._M_impl._M_finish - __position) * sizeof(int));
    }

    if (this->_M_base._M_impl._M_start != NULL) {
        free(this->_M_base._M_impl._M_start);
    }

    this->_M_base._M_impl._M_start = __new_start;
    this->_M_base._M_impl._M_finish = __new_finish + 1;
    this->_M_base._M_impl._M_end_of_storage = __new_start + __new_size;
}

void compare(vector* this, vector* __x, vector* __y) {
    int __tmp = 0;
    memset(this, 0, sizeof(vector));

    int* __it = __x->_M_base._M_impl._M_start;
    int* __end = __x->_M_base._M_impl._M_finish;

    while (__it != __end) {
        int __a = *__it;
        int __b = *__y->_M_base._M_impl._M_start;
        int __diff = __a - __b;
        __diff = abs(__diff);
        __tmp = __diff;

        if (this->_M_base._M_impl._M_finish == this->_M_base._M_impl._M_end_of_storage) {
            _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(this, this->_M_base._M_impl._M_finish, &__tmp);
        } else {
            *this->_M_base._M_impl._M_finish = __tmp;
            ++this->_M_base._M_impl._M_finish;
        }

        ++__it;
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
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,5,0,0,0,4},{4,1,1,0,0,-2}),{4,4,1,0,0,6}));
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,0,0,0,0,0},{0,0,0,0,0,0}),{0,0,0,0,0,0}));
    assert (issame(compare({1,2,3},{-1,-2,-3}),{2,4,6}));
    assert (issame(compare({1,2,3,5},{-1,2,3,4}),{2,0,0,1}));
}
