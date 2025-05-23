#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* _M_start;
    int* _M_finish;
    int* _M_end_of_storage;
} _Vector_impl_data;

typedef struct {
    _Vector_impl_data _M_impl;
} _Vector_base;

typedef struct {
    _Vector_base _M_base;
} std_vector;

void generate_integers(std_vector* vector, int n, int m) {
    int t = (n < m) ? n : m;
    int s = (n < m) ? m : n;
    memset(vector, 0, sizeof(std_vector));

    int* start = NULL;
    int* finish = NULL;
    int* end_of_storage = NULL;

    for (int i = s; i <= t; i++) {
        if (i < 10 && (i & 1) == 0) {
            if (end_of_storage == finish) {
                if (start != NULL) {
                    *finish = i;
                    finish++;
                } else {
                    start = (int*)malloc(sizeof(int));
                    finish = start;
                    *finish = i;
                    finish++;
                }
            } else {
                int new_size = (finish - start) * 2;
                if (new_size > 0 && new_size <= 2305843009213693951) {
                    int* new_start = (int*)malloc(new_size * sizeof(int));
                    memmove(new_start, start, (finish - start) * sizeof(int));
                    free(start);
                    start = new_start;
                    finish = start + (new_size - 1);
                    *finish = i;
                    finish++;
                }
            }
        }
    }

    vector->_M_base._M_impl._M_start = start;
    vector->_M_base._M_impl._M_finish = finish;
    vector->_M_base._M_impl._M_end_of_storage = finish;
}

int main() {
    std_vector vector;
    generate_integers(&vector, 10, 20);
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
