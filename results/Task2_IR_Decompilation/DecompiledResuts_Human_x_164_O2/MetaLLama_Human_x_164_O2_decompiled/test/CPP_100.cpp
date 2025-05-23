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

void make_a_pile(vector* v, int n) {
    memset(v, 0, sizeof(vector));
    int* ptr = (int*)malloc(4);
    v->_M_base._M_impl._M_start = ptr;
    v->_M_base._M_impl._M_finish = ptr;
    v->_M_base._M_impl._M_end_of_storage = ptr + 1;
    *ptr = n;

    if (n > 1) {
        int* start = v->_M_base._M_impl._M_start;
        int* finish = v->_M_base._M_impl._M_finish;
        int* end_of_storage = v->_M_base._M_impl._M_end_of_storage;
        int size = (end_of_storage - start) / 2;

        for (int i = 1; i < n; i++) {
            int new_size = size * 2;
            if (new_size < size || new_size > 2305843009213693951) {
                new_size = 2305843009213693951;
            }

            if (new_size == 0) {
                return;
            }

            int* new_ptr = (int*)malloc(new_size * 4);
            if (size > 0) {
                memmove(new_ptr, start, size * 4);
            }

            free(start);
            v->_M_base._M_impl._M_start = new_ptr;
            v->_M_base._M_impl._M_finish = new_ptr + i;
            v->_M_base._M_impl._M_end_of_storage = new_ptr + new_size;
            start = new_ptr;
            size = new_size;
        }
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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}
