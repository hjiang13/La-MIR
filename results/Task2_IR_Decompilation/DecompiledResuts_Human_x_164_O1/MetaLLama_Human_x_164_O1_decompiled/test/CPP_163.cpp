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
} Vector_base;

typedef struct {
    Vector_base _M_base;
} vector;

void _M_realloc_insert(vector* this, int* __position, int* __x) {
    int* __new_start = NULL;
    int __len = __position - this->_M_base._M_impl._M_start;
    if (__len == 0) {
        __new_start = (int*)malloc(4);
    } else {
        __new_start = (int*)malloc(__len * 4);
        memmove(__new_start, this->_M_base._M_impl._M_start, __len * 4);
    }
    *(__new_start + __len) = *__x;
    if (__position != this->_M_base._M_impl._M_finish) {
        memmove(__new_start + __len + 1, __position, (this->_M_base._M_impl._M_finish - __position) * 4);
    }
    if (this->_M_base._M_impl._M_start != NULL) {
        free(this->_M_base._M_impl._M_start);
    }
    this->_M_base._M_impl._M_start = __new_start;
    this->_M_base._M_impl._M_finish = __new_start + __len + 1;
    this->_M_base._M_impl._M_end_of_storage = __new_start + __len + 1;
}

void generate_integers(vector* this, int n, int m) {
    this->_M_base._M_impl._M_start = NULL;
    this->_M_base._M_impl._M_finish = NULL;
    this->_M_base._M_impl._M_end_of_storage = NULL;
    int __n = (n < m) ? n : m;
    int __m = (n > m) ? n : m;
    for (int i = 0; i < __n; i++) {
        if (i < 10) {
            if (i % 2 == 0) {
                if (this->_M_base._M_impl._M_start == this->_M_base._M_impl._M_finish) {
                    _M_realloc_insert(this, this->_M_base._M_impl._M_finish, &i);
                } else {
                    *(this->_M_base._M_impl._M_start + i) = i;
                }
            }
        }
    }
}

int main() {
    vector v;
    generate_integers(&v, 10, 20);
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
    assert (issame(generate_integers(2, 10) , {2, 4, 6, 8}));
    assert (issame(generate_integers(10, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(132, 2) , {2, 4, 6, 8}));
    assert (issame(generate_integers(17,89) , {}));
}
