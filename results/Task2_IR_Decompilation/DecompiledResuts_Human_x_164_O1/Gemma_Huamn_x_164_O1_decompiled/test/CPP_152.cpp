#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} vector;

void _Z7compareSt6vectorIiSaIiEES1_(vector* __result, const vector* __v1, const vector* __v2) {
    memset(__result, 0, sizeof(vector));
    int* __v1_start = __v1->_M_start;
    int* __v1_finish = __v1->_M_finish;
    int* __v2_start = __v2->_M_start;
    int* __result_finish = __result->_M_finish;
    int* __result_end = __result->_M_end_of_storage;
    if (__v1_start == __v1_finish) {
        return;
    }
    int i = 0;
    while (i < (__v1_finish - __v1_start)) {
        int diff = abs(__v1_start[i] - __v2_start[i]);
        if (__result_finish == __result_end) {
            size_t new_capacity = (__result_finish - __result->_M_start) * 2;
            int* new_storage = malloc(new_capacity * sizeof(int));
            memcpy(new_storage, __result->_M_start, (__result_finish - __result->_M_start) * sizeof(int));
            free(__result->_M_start);
            __result->_M_start = new_storage;
            __result_finish = __result->_M_start + new_capacity;
            __result_end = __result_finish;
        }
        *__result_finish = diff;
        __result_finish++;
        i++;
    }
}



void _ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_(vector* __this, int* __position, int* __value) {
    int* __old_finish = __this->_M_finish;
    int* __old_start = __this->_M_start;
    int* __old_end = __this->_M_end_of_storage;
    ptrdiff_t __old_size = __old_finish - __old_start;
    if (__old_size == 9223372036854775804) {
        
    }
    // reallocation logic omitted for brevity

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
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,5,0,0,0,4},{4,1,1,0,0,-2}),{4,4,1,0,0,6}));
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,0,0,0,0,0},{0,0,0,0,0,0}),{0,0,0,0,0,0}));
    assert (issame(compare({1,2,3},{-1,-2,-3}),{2,4,6}));
    assert (issame(compare({1,2,3,5},{-1,2,3,4}),{2,0,0,1}));
}
