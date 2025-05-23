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
