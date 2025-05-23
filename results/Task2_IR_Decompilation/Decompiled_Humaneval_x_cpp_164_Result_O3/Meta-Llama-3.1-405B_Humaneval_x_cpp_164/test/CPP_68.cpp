Based on the provided LLVM IR code, I will generate the equivalent C source code. Here it is:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M
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
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
