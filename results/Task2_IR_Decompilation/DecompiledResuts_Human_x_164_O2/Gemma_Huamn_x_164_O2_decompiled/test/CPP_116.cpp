#include <stdlib.h>
#include <string.h>

typedef struct {
    int * _M_start;
    int * _M_finish;
    int * _M_end_of_storage;
} _Vector_base;

typedef struct {
    _Vector_base _M_impl;
} vector;

void sort_array(vector * dest, vector * src) {
    int * begin = src->_M_impl._M_start;
    int * end = src->_M_impl._M_finish;
    if (begin == end) {
        return;
    }
    int * iter = begin;
    int * last = end;
    while (iter != last) {
        int val = *iter;
        if (val == 0) {
            iter++;
        } else {
            last--;
            int tmp = *last;
            *last = val;
            *iter = tmp;
        }
    }
    int * p = dest->_M_impl._M_start;
    int * q = dest->_M_impl._M_finish;
    int * r = begin;

    while (p != q && r != end) {
        *p++ = *r++;
    }

    free(dest->_M_impl._M_start);
    dest->_M_impl._M_start = (int *)malloc(sizeof(int) * (end - begin));
    dest->_M_impl._M_finish = dest->_M_impl._M_start + (end - begin);
    dest->_M_impl._M_end_of_storage = dest->_M_impl._M_finish;

    memcpy(dest->_M_impl._M_start, begin, sizeof(int) * (end - begin));

    
    int i = 0;
    while (i < dest->_M_impl._M_finish - dest->_M_impl._M_start) {
        int j = i + 1;
        while (j < dest->_M_impl._M_finish - dest->_M_impl._M_start) {
            if (dest->_M_impl._M_start[i] > dest->_M_impl._M_start[j]) {
                int tmp = dest->_M_impl._M_start[i];
                dest->_M_impl._M_start[i] = dest->_M_impl._M_start[j];
                dest->_M_impl._M_start[j] = tmp;
            }
            j++;
        }
        i++;
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
    assert (issame(sort_array({1,5,2,3,4}) , {1, 2, 4, 3, 5}));
    assert (issame(sort_array({-2,-3,-4,-5,-6}) , {-4, -2, -6, -5, -3}));
    assert (issame(sort_array({1,0,2,3,4}) , {0, 1, 2, 4, 3}));
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({2,5,77,4,5,3,5,7,2,3,4}) , {2, 2, 4, 4, 3, 3, 5, 5, 5, 7, 77}));
    assert (issame(sort_array({3,6,44,12,32,5}) , {32, 3, 5, 6, 12, 44}));
    assert (issame(sort_array({2,4,8,16,32}) , {2, 4, 8, 16, 32}));
    assert (issame(sort_array({2,4,8,16,32}) , {2, 4, 8, 16, 32}));
}
