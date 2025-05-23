#include <stdlib.h>
#include <string.h>

typedef struct _Vector_base {
    int * _M_start;
    int * _M_finish;
    int * _M_end_of_storage;
} _Vector_base;

typedef struct _Vector_impl {
    _Vector_base _M_impl;
} _Vector_impl;

typedef _Vector_impl _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_data;
} vector;

void intersperse(vector *result, const vector *v, int value) {
    result->_M_data._M_impl._M_start = NULL;
    result->_M_data._M_impl._M_finish = NULL;
    result->_M_data._M_impl._M_end_of_storage = NULL;

    if (v->_M_data._M_impl._M_start == v->_M_data._M_impl._M_finish) {
        return;
    }

    result->_M_data._M_impl._M_start = malloc(4);
    result->_M_data._M_impl._M_finish = result->_M_data._M_impl._M_start;
    *result->_M_data._M_impl._M_start = *v->_M_data._M_impl._M_start;
    result->_M_data._M_impl._M_end_of_storage = result->_M_data._M_impl._M_start + 1;

    int *iter = v->_M_data._M_impl._M_start + 1;
    int *end = v->_M_data._M_impl._M_finish;

    while (iter != end) {
        int *new_start = realloc(result->_M_data._M_impl._M_start,
                                (result->_M_data._M_impl._M_finish - result->_M_data._M_impl._M_start + 2) * sizeof(int));
        if (new_start == NULL) {
            free(result->_M_data._M_impl._M_start);
            result->_M_data._M_impl._M_start = NULL;
            result->_M_data._M_impl._M_finish = NULL;
            result->_M_data._M_impl._M_end_of_storage = NULL;
            return;
        }
        result->_M_data._M_impl._M_start = new_start;
        result->_M_data._M_impl._M_finish++;
        *result->_M_data._M_impl._M_finish = value;
        result->_M_data._M_impl._M_finish++;
        *result->_M_data._M_impl._M_finish = *iter;
        result->_M_data._M_impl._M_end_of_storage = result->_M_data._M_impl._M_finish + 1;

        iter++;
    }
}
```
<|im_end|>
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
    assert (issame(intersperse({}, 7), {}));
    
    assert (issame(intersperse({5, 6, 3, 2}, 8),{5, 8, 6, 8, 3, 8, 2}));
    assert (issame(intersperse({2, 2, 2}, 2),{2, 2, 2, 2, 2}));
}