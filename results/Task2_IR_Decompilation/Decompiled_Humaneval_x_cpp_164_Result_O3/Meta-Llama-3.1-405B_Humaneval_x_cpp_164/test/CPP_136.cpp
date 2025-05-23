#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_impl;
} std_vector;

void largest_smallest_integers(std_vector* __result, std_vector* __v) {
    int* _M_start = __v->_M_impl;
    int* _M_finish = __v->_M_impl + (__v->_M_impl[1] - __v->_M_impl[0]);

    if (_M_start == _M_finish) {
        __result->_M_impl = (int*)calloc(2, sizeof(int));
        __result->_M_impl[0] = 0;
        __result->_M_impl[1] = 0;
        return;
    }

    int __min = 0;
    int __max = 0;
    int* __p = _M_start;
    for (int __n = _M_finish - _M_start; __n > 0; --__n) {
        int __x = *__p++;
        if (__x < 0) {
            if (__min == 0 || __x > __min) {
                __min = __x;
            }
        } else if (__x > 0) {
            if (__max == 0 || __x < __max) {
                __max = __x;
            }
        }
    }

    __result->_M_impl = (int*)calloc(2, sizeof(int));
    __result->_M_impl[0] = __min;
    __result->_M_impl[1] = __max;
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
    assert (issame(largest_smallest_integers({2, 4, 1, 3, 5, 7}) , {0, 1}));
    assert (issame(largest_smallest_integers({2, 4, 1, 3, 5, 7, 0}) , {0, 1}));
    assert (issame(largest_smallest_integers({1, 3, 2, 4, 5, 6, -2}) , {-2, 1}));
    assert (issame(largest_smallest_integers({4, 5, 3, 6, 2, 7, -7}) , {-7, 2}));
    assert (issame(largest_smallest_integers({7, 3, 8, 4, 9, 2, 5, -9}) , {-9, 2}));
    assert (issame(largest_smallest_integers({}) , {0, 0}));
    assert (issame(largest_smallest_integers({0}) , {0, 0}));
    assert (issame(largest_smallest_integers({-1, -3, -5, -6}) , {-1, 0}));
    assert (issame(largest_smallest_integers({-1, -3, -5, -6, 0}) , {-1, 0}));
    assert (issame(largest_smallest_integers({-6, -4, -4, -3, 1}) , {-3, 1}));
    assert (issame(largest_smallest_integers({-6, -4, -4, -3, -100, 1}) , {-3, 1}));

}
