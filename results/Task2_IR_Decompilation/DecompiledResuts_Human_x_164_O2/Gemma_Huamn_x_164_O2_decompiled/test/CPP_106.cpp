#include <stdlib.h>
#include <string.h>

struct std_vector {
    struct _Vector_base base;
};

struct _Vector_base {
    struct _Vector_base_impl_data _M_impl;
};

struct _Vector_base_impl_data {
    int * _M_start;
    int * _M_finish;
    int * _M_end_of_storage;
};

void _Z1fi(struct std_vector * __return_buffer, int parameter_1) {

    int * _M_start = (int*)malloc(sizeof(int));

    int * _M_finish = (int*)malloc(sizeof(int));

    int * _M_end_of_storage = (int*)malloc(sizeof(int));

    * _M_start = 0;

    * _M_finish = 0;

    * _M_end_of_storage = 0;

    if (parameter_1 < 1) {
      
        __return_buffer->base._M_impl._M_start = _M_start;
        __return_buffer->base._M_impl._M_finish = _M_finish;
        __return_buffer->base._M_impl._M_end_of_storage = _M_end_of_storage;
        return;
    }

    int n = 1;

    int capacity = 1;

    int i = 1;

    while (i < parameter_1) {

        if (capacity == n) {

            int new_capacity = 2 * capacity;
            int * new_start = (int*)malloc(sizeof(int) * new_capacity);
            memcpy(new_start, _M_start, sizeof(int) * capacity);
            free(_M_start);
            _M_start = new_start;

            _M_finish = _M_start + n;

            _M_end_of_storage = _M_start + new_capacity;
            capacity = new_capacity;
        }

        *(_M_finish) = n * i;
        _M_finish++;
        n = n + 1;
        i++;
    }

    __return_buffer->base._M_impl._M_start = _M_start;
    __return_buffer->base._M_impl._M_finish = _M_finish;
    __return_buffer->base._M_impl._M_end_of_storage = _M_end_of_storage;
}

int main() {
    struct std_vector v;
    _Z1fi(&v, 5);
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
    assert (issame(f(5) , {1, 2, 6, 24, 15}));
    assert (issame(f(7) , {1, 2, 6, 24, 15, 720, 28}));
    assert (issame(f(1) , {1}));
    assert (issame(f(3) , {1, 2, 6}));
}
