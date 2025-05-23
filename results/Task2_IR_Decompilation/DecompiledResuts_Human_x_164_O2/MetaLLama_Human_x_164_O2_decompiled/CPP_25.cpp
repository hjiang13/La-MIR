#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct VectorImplData {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} VectorImplData;

typedef struct VectorBase {
    VectorImplData _M_impl;
} VectorBase;

typedef struct Vector {
    VectorBase _M_base;
} Vector;

void __throw_length_error(const char* msg);

void* _Znwm(size_t size);

void _ZdlPv(void* ptr);

void* memmove(void* dest, const void* src, size_t len);

void memset(void* dest, int value, size_t len);

void factorize(Vector* v, int n) {
    if (n < 4) {
        v->_M_base._M_impl._M_start = NULL;
        v->_M_base._M_impl._M_finish = NULL;
        v->_M_base._M_impl._M_end_of_storage = NULL;
        return;
    }

    int* start = v->_M_base._M_impl._M_start;
    int* finish = v->_M_base._M_impl._M_finish;
    int* end_of_storage = v->_M_base._M_impl._M_end_of_storage;

    while (n > 1) {
        int i = 2;
        while (i * i <= n) {
            if (n % i == 0) {
                int* new_start;
                int* new_finish;
                int* new_end_of_storage;

                if (finish == start) {
                    new_start = (int*)_Znwm(sizeof(int));
                    new_finish = new_start;
                    new_end_of_storage = (int*)((char*)new_start + sizeof(int));
                } else {
                    size_t size = (size_t)(finish - start);
                    new_start = (int*)_Znwm(size * sizeof(int));
                    new_finish = (int*)((char*)new_start + size * sizeof(int));
                    new_end_of_storage = (int*)((char*)new_start + size * sizeof(int) + sizeof(int));

                    memmove(new_start, start, size * sizeof(int));
                }

                *new_finish = i;
                v->_M_base._M_impl._M_start = new_start;
                v->_M_base._M_impl._M_finish = new_finish;
                v->_M_base._M_impl._M_end_of_storage = new_end_of_storage;

                if (start != NULL) {
                    _ZdlPv((void*)start);
                }

                n /= i;
                i = 2;
            } else {
                i++;
            }
        }

        if (n > 1) {
            int* new_start;
            int* new_finish;
            int* new_end_of_storage;

            if (finish == start) {
                new_start = (int*)_Znwm(sizeof(int));
                new_finish = new_start;
                new_end_of_storage = (int*)((char*)new_start + sizeof(int));
            } else {
                size_t size = (size_t)(finish - start);
                new_start = (int*)_Znwm(size * sizeof(int));
                new_finish = (int*)((char*)new_start + size * sizeof(int));
                new_end_of_storage = (int*)((char*)new_start + size * sizeof(int) + sizeof(int));

                memmove(new_start, start, size * sizeof(int));
            }

            *new_finish = n;
            v->_M_base._M_impl._M_start = new_start;
            v->_M_base._M_impl._M_finish = new_finish;
            v->_M_base._M_impl._M_end_of_storage = new_end_of_storage;

            if (start != NULL) {
                _ZdlPv((void*)start);
            }

            break;
        }
    }
}

int main() {
    // Example usage:
    Vector v;
    factorize(&v, 100);
    return 0;
}
