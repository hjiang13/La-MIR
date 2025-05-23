#include <stdio.h>
#include <string.h>

typedef struct {
    int* data;
    int* end;
    int* capacity;
} vector_base;

typedef struct {
    vector_base base;
} vector;

void incr_list(vector* result, vector* input) {
    int* data = input->base.data;
    int* end = input->base.end;

    size_t size = end - data;
    if (size == 0) {
        result->base.data = data;
        result->base.end = end;
        result->base.capacity = input->base.capacity;
        memset(input, 0, sizeof(vector));
        return;
    }

    size_t unroll_size = (size >> 2) << 2;
    size_t remainder = size - unroll_size;
    size_t loop_count = unroll_size >> 2;

    for (size_t i = 0; i < loop_count; i++) {
        int* ptr = data + (i << 2);
        ptr[0]++;
        ptr[1]++;
        ptr[2]++;
        ptr[3]++;
    }

    if (remainder > 0) {
        int* ptr = data + unroll_size;
        for (size_t i = 0; i < remainder; i++) {
            ptr[i]++;
        }
    }

    result->base.data = data;
    result->base.end = end;
    result->base.capacity = input->base.capacity;
    memset(input, 0, sizeof(vector));
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
    assert (issame(incr_list({}) , {}));
    assert (issame(incr_list({3, 2, 1}) , {4, 3, 2}));
    assert (issame(incr_list({5, 2, 5, 2, 3, 3, 9, 0, 123}) , {6, 3, 6, 3, 4, 4, 10, 1, 124}));
}
