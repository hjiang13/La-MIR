#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_impl;
} std__Vector_base;

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} std__Vector_base__Vector_impl_data;

void _Z3eatiii(std__Vector_base* __result, int __n, int __x, int __y) {
    if (__y < __x) {
        int* __begin = (int*)malloc(8);
        *__begin = __y + __n;
        __result->_M_impl->_M_start = __begin;
        __result->_M_impl->_M_finish = __begin;
        __result->_M_impl->_M_end_of_storage = (int*)(((char*)__begin) + 8);
    } else {
        int* __begin = (int*)malloc(8);
        *__begin = __x + __n;
        __result->_M_impl->_M_start = __begin;
        __result->_M_impl->_M_finish = (int*)(((char*)__begin) + 4);
        __result->_M_impl->_M_end_of_storage = (int*)(((char*)__begin) + 8);
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
    assert (issame(eat(5, 6, 10) , {11, 4}));
    assert (issame(eat(4, 8, 9) , {12, 1}));
    assert (issame(eat(1, 10, 10) , {11, 0}));
    assert (issame(eat(2, 11, 5) , {7, 0}));
    
    assert (issame(eat(4, 5, 7) , {9, 2}));
    assert (issame(eat(4, 5, 1) , {5, 0}));
}
