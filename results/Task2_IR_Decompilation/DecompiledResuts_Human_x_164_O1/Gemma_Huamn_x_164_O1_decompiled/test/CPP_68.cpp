#include <stdint.h>

typedef struct std_vector {
    int32_t* _M_start;
    int32_t* _M_finish;
    int32_t* _M_end_of_storage;
} std_vector;

void pluck_std_vector(std_vector* output, const std_vector* input) {
    int32_t* input_finish = input->_M_finish;
    int32_t* input_start = input->_M_start;

    output->_M_start = NULL;
    output->_M_finish = output->_M_start;
    output->_M_end_of_storage = output->_M_start;

    if (input_start == input_finish)
        return;

    int32_t temp_array[2];
    int32_t* temp_ptr = temp_array;

    for (int32_t i = 0; input_start != input_finish; ++i, ++input_start) {
        if ((*input_start & 1) == 0) {
            *temp_ptr = *input_start;
            temp_ptr++;
        }
    }

    output->_M_start = temp_array;
    output->_M_finish = temp_ptr;
    output->_M_end_of_storage = temp_array + 2;
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
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
