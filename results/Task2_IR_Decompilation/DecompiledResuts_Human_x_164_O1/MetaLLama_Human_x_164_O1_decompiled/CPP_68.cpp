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

void __throw_length_error(const char* msg) {
    printf("%s\n", msg);
    exit(1);
}

void* _Znwm(unsigned long size) {
    return malloc(size);
}

void _ZdlPv(void* ptr) {
    free(ptr);
}

void __gxx_personality_v0() {}

void _ZNSt6vectorIiSaIiEE13_M_assign_auxIPKiEEvT_S5_St20forward_iterator_tag(vector* this, int* first, int* last) {
    unsigned long size = (unsigned long)last - (unsigned long)first;
    if (size > 2305843009213693951) {
        __throw_length_error("cannot create std::vector larger than max_size()");
    }
    int* new_data = _Znwm(size * sizeof(int));
    if (size) {
        memcpy(new_data, first, size * sizeof(int));
    }
    int* old_data = this->_M_base._M_impl._M_start;
    if (old_data) {
        _ZdlPv(old_data);
    }
    this->_M_base._M_impl._M_start = new_data;
    this->_M_base._M_impl._M_finish = new_data + size;
    this->_M_base._M_impl._M_end_of_storage = new_data + size;
}

void pluck(vector* v1, vector* v2) {
    int* first = v2->_M_base._M_impl._M_start;
    int* last = v2->_M_base._M_impl._M_finish;
    int* data = v1->_M_base._M_impl._M_start;
    if (first == last) return;
    unsigned long size = (unsigned long)last - (unsigned long)first;
    if (v1->_M_base._M_impl._M_start == v1->_M_base._M_impl._M_finish) {
        _ZNSt6vectorIiSaIiEE13_M_assign_auxIPKiEEvT_S5_St20forward_iterator_tag(v1, first, last);
    } else {
        unsigned long old_size = (unsigned long)v1->_M_base._M_impl._M_finish - (unsigned long)v1->_M_base._M_impl._M_start;
        if (old_size < size) {
            int* new_data = _Znwm(size * sizeof(int));
            if (old_size) {
                memmove(new_data, v1->_M_base._M_impl._M_start, old_size * sizeof(int));
            }
            int* old_data = v1->_M_base._M_impl._M_start;
            if (old_data) {
                _ZdlPv(old_data);
            }
            v1->_M_base._M_impl._M_start = new_data;
            v1->_M_base._M_impl._M_finish = new_data + size;
            v1->_M_base._M_impl._M_end_of_storage = new_data + size;
        } else {
            memmove(v1->_M_base._M_impl._M_start, first, size * sizeof(int));
            v1->_M_base._M_impl._M_finish = v1->_M_base._M_impl._M_start + size;
        }
    }
}
