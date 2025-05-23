#include <stdlib.h>

typedef struct {
    int * _M_start;
    int * _M_finish;
    int * _M_end_of_storage;
} _Vector_base;

typedef struct {
    _Vector_base _M_impl;
} vector;

void make_a_pile(vector * v, int n) {
    v->_M_impl._M_start = (int *)malloc(4);
    v->_M_impl._M_finish = v->_M_impl._M_start;
    v->_M_impl._M_end_of_storage = v->_M_impl._M_start + 1;

    *v->_M_impl._M_start = n;
    v->_M_impl._M_finish++;
    v->_M_impl._M_end_of_storage = v->_M_impl._M_finish;

    for (int i = 1; i < n; ++i) {
        int * temp = (int *)malloc(sizeof(int) * (v->_M_impl._M_finish - v->_M_impl._M_start + 1));
        int * temp_finish = temp + (v->_M_impl._M_finish - v->_M_impl._M_start);
        *temp_finish = i + 1;
        for (int j = 0; j < v->_M_impl._M_finish - v->_M_impl._M_start; ++j) {
            temp[j] = v->_M_impl._M_start[j];
        }
        free(v->_M_impl._M_start);
        v->_M_impl._M_start = temp;
        v->_M_impl._M_finish = temp_finish + 1;
        v->_M_impl._M_end_of_storage = v->_M_impl._M_finish;
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
