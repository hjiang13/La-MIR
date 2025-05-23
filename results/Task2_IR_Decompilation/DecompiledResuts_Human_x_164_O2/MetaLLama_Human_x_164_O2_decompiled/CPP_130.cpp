#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_impl;
} _Vector_base;

typedef struct {
    _Vector_base _M_base;
} std__vector;

void _Z3trii(std__vector* __result, int __n) {
    int* __begin = (int*) malloc(8);
    int* __end = __begin + 1;
    *(__begin) = 1;
    *(__end) = 3;

    if (__n == 0) {
        memset(__result, 0, 24);
        int* __tmp = (int*) malloc(4);
        __result->_M_base._M_impl = __tmp;
        *__tmp = 1;
        free((void*) __begin);
        return;
    }

    int __size = __n;
    if (__size < 2) {
        __result->_M_base._M_impl = __begin;
        return;
    }

    int __capacity = __size + 1;
    if ((__capacity & 1) == 0) {
        __capacity >>= 1;
        ++__capacity;
        if (__begin == __end) {
            *__begin = __capacity;
        } else {
            int* __tmp = (int*) malloc(__capacity * 4);
            __tmp[__capacity - 1] = __capacity;
            memmove(__tmp, __begin, (__end - __begin) * 4);
            free((void*) __begin);
            __begin = __tmp;
            __end = __begin + __capacity;
        }
    } else {
        int __tmp1 = __end[-2];
        int __tmp2 = __end[-1];
        ++__size;
        __size >>= 1;
        ++__size;
        __size = __tmp1 + __size + __tmp2;
        if (__begin == __end) {
            *__begin = __size;
        } else {
            int* __tmp = (int*) malloc(__size * 4);
            __tmp[__size - 1] = __size;
            memmove(__tmp, __begin, (__end - __begin) * 4);
            free((void*) __begin);
            __begin = __tmp;
            __end = __begin + __size;
        }
    }

    while (__capacity < __n) {
        if ((__capacity & 1) == 0) {
            __capacity >>= 1;
            ++__capacity;
            if (__begin == __end) {
                *__begin = __capacity;
            } else {
                int* __tmp = (int*) malloc(__capacity * 4);
                __tmp[__capacity - 1] = __capacity;
                memmove(__tmp, __begin, (__end - __begin) * 4);
                free((void*) __begin);
                __begin = __tmp;
                __end = __begin + __capacity;
            }
        } else {
            int __tmp1 = __end[-2];
            int __tmp2 = __end[-1];
            ++__capacity;
            __capacity >>= 1;
            ++__capacity;
            __capacity = __tmp1 + __capacity + __tmp2;
            if (__begin == __end) {
                *__begin = __capacity;
            } else {
                int* __tmp = (int*) malloc(__capacity * 4);
                __tmp[__capacity - 1] = __capacity;
                memmove(__tmp, __begin, (__end - __begin) * 4);
                free((void*) __begin);
                __begin = __tmp;
                __end = __begin + __capacity;
            }
        }
        ++__capacity;
    }

    __result->_M_base._M_impl = __begin;
}

int main() {
    std__vector __vec;
    _Z3trii(&__vec, 5);
    return 0;
}
