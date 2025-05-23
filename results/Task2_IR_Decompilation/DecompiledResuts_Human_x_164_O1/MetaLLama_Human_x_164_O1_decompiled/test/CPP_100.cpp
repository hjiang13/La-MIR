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

void make_a_pile(Vector* v, int n) {
    v->_M_base._M_impl._M_start = (int*) malloc(4);
    v->_M_base._M_impl._M_finish = v->_M_base._M_impl._M_start;
    v->_M_base._M_impl._M_end_of_storage = (int*) ((char*) v->_M_base._M_impl._M_start + 4);

    for (int i = 0; i < n; i++) {
        if (v->_M_base._M_impl._M_finish == v->_M_base._M_impl._M_end_of_storage) {
            int* new_start = (int*) malloc((v->_M_base._M_impl._M_end_of_storage - v->_M_base._M_impl._M_start) * 2);
            memcpy(new_start, v->_M_base._M_impl._M_start, (v->_M_base._M_impl._M_end_of_storage - v->_M_base._M_impl._M_start) * sizeof(int));
            free(v->_M_base._M_impl._M_start);
            v->_M_base._M_impl._M_start = new_start;
            v->_M_base._M_impl._M_finish = (int*) ((char*) new_start + (v->_M_base._M_impl._M_finish - v->_M_base._M_impl._M_start) * sizeof(int));
            v->_M_base._M_impl._M_end_of_storage = (int*) ((char*) new_start + ((v->_M_base._M_impl._M_end_of_storage - v->_M_base._M_impl._M_start) * 2) * sizeof(int));
        }
        *v->_M_base._M_impl._M_finish = i + 2;
        v->_M_base._M_impl._M_finish++;
    }
}

int main() {
    Vector v;
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
