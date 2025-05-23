#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Vector_base {
    int* _M_impl;
} _Vector_base;

typedef struct _Vector_impl_data {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct vector {
    _Vector_base _M_base;
} vector;

void* _Znwm(size_t);
void _ZdlPv(void*);
void _ZSt20__throw_length_error(const char*);

void count_up_to(vector* v, int n) {
    _Vector_impl_data* data = (_Vector_impl_data*)v->_M_base._M_impl;
    int* start = data->_M_start;
    int* finish = data->_M_finish;
    int* end_of_storage = data->_M_end_of_storage;

    if (n > 2) {
        memset(v, 0, 24);

        int* new_start = NULL;
        int* new_finish = NULL;
        int* new_end_of_storage = NULL;
        int i = 2;

        while (1) {
            int* tmp = start + (finish - start);
            if (tmp == start) {
                if (start == new_start) {
                    new_start = (int*)_Znwm((finish - start + 1) * 4);
                    new_finish = new_start + (finish - start);
                    new_end_of_storage = new_finish + 1;
                    *new_finish = i;
                    data->_M_start = new_start;
                    data->_M_finish = new_finish;
                    data->_M_end_of_storage = new_end_of_storage;
                }
            } else {
                int j = 0;
                while (1) {
                    int val = *tmp;
                    if (val * val > i) break;
                    tmp++;
                    j++;
                }
                if (j == 0) break;
                if (start == new_start) {
                    start = (int*)_Znwm((finish - start + j + 1) * 4);
                    finish = start + (finish - start) + j;
                    end_of_storage = finish + 1;
                    *finish = i;
                    data->_M_start = start;
                    data->_M_finish = finish;
                    data->_M_end_of_storage = end_of_storage;
                } else {
                    if (finish == new_finish) {
                        new_finish = (int*)_Znwm((finish - start + j + 1) * 4);
                        new_end_of_storage = new_finish + (finish - start) + j + 1;
                        memcpy(new_finish, start, (finish - start) * 4);
                        new_start = new_finish - (finish - start);
                        data->_M_start = new_start;
                        data->_M_finish = new_finish;
                        data->_M_end_of_storage = new_end_of_storage;
                    } else {
                        if (new_finish - new_start == 9223372036854775804) {
                            _ZSt20__throw_length_error("vector::_M_realloc_insert");
                        }
                        size_t new_size = (new_finish - new_start) * 2;
                        if (new_size < (finish - start) + j + 1) new_size = (finish - start) + j + 1;
                        new_start = (int*)_Znwm(new_size * 4);
                        new_finish = new_start + (finish - start) + j;
                        new_end_of_storage = new_start + new_size;
                        if (new_finish - new_start > 0) {
                            memmove(new_start, start, (new_finish - new_start) * 4);
                        }
                        _ZdlPv((void*)start);
                        data->_M_start = new_start;
                        data->_M_finish = new_finish;
                        data->_M_end_of_storage = new_end_of_storage;
                    }
                }
            }
            i++;
            if (i == n) break;
        }
    }
}

int main() {
    vector v;
    count_up_to(&v, 10);
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
    assert (issame(count_up_to(5) , {2,3}));
    assert (issame(count_up_to(6) , {2,3,5}));
    assert (issame(count_up_to(7) , {2,3,5}));
    assert (issame(count_up_to(10) , {2,3,5,7}));
    assert (issame(count_up_to(0) , {}));
    assert (issame(count_up_to(22) , {2,3,5,7,11,13,17,19}));
    assert (issame(count_up_to(1) , {}));
    assert (issame(count_up_to(18) , {2,3,5,7,11,13,17}));
    assert (issame(count_up_to(47) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}));
    assert (issame(count_up_to(101) , {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}));
}
