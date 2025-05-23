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
    _Vector_base_int _M_base;
} std__vector;

void make_a_pile(std__vector* __result, int __n) {
    memset(__result, 0, sizeof(std__vector));
    int* __begin = (int*)malloc(4);
    int* __end = __begin;
    __result->_M_base._M_impl._M_start = __begin;
    __result->_M_base._M_impl._M_finish = __end;
    __result->_M_base._M_impl._M_end_of_storage = __end;
    int __size = 1;
    while (__size < __n) {
        int __capacity = (__end - __begin) * 2;
        if (__capacity > 2305843009213693951) {
            __capacity = 2305843009213693951;
        }
        int* __new_begin = (int*)malloc(__capacity * 4);
        memmove(__new_begin, __begin, (__end - __begin) * 4);
        free(__begin);
        __begin = __new_begin;
        __end = __begin + __size;
        __result->_M_base._M_impl._M_start = __begin;
        __result->_M_base._M_impl._M_finish = __end;
        __result->_M_base._M_impl._M_end_of_storage = __begin + __capacity;
        __size++;
    }
}

int main() {
    std__vector v;
    make_a_pile(&v, 10);
    return 0;
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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}
