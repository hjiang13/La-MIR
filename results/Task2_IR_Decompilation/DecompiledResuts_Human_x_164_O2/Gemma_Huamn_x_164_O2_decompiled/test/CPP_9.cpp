#include <stdlib.h>

// Define structure for std::vector
typedef struct {
    int *data;
    int *begin;
    int *end;
} vector;

void rolling_max(vector *result, const vector *input) {

    // Initialize result vector
    result->data = NULL;
    result->begin = NULL;
    result->end = NULL;

    int *input_begin = input->begin;
    int *input_end = input->end;

    int *current_max = NULL;
    int *result_begin = result->begin;
    int *result_end = result->end;

    while (input_begin != input_end) {
        int current_value = *input_begin;
        if (current_max == NULL || current_value > *current_max) {
            current_max = input_begin;
        }

        if (result_begin == result_end) {
            int new_size = (result_end - result_begin) * 2 + 1;
            int *new_data = (int *)malloc(new_size * sizeof(int));
            if (result_begin != NULL) {
                for (int i = 0; i < result_end - result_begin; i++) {
                    new_data[i] = result_begin[i];
                }
                free(result_begin);
            }
            result_begin = new_data;
            result_end = new_data + new_size;
        }

        *result_begin = *current_max;
        result_begin++;
        input_begin++;
    }
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
     assert (issame(rolling_max({}),{}));
    assert (issame(rolling_max({1, 2, 3, 4}) , {1, 2, 3, 4}));
     assert (issame(rolling_max({4, 3, 2, 1}),{4, 4, 4, 4}));
      assert (issame(rolling_max({3, 2, 3, 100, 3}) ,{3, 3, 3, 100, 100}));
}