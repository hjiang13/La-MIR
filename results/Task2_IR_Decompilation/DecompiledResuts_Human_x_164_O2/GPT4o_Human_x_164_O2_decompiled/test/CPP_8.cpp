#include <vector>
#include <cstring>
#include <algorithm>

extern "C" void sum_product(std::vector<int>* result, const std::vector<int>* input) {
    int* input_data = input->data();
    int input_size = input->size();

    if (input_size == 0) {
        std::memset(result, 0, sizeof(std::vector<int>));
        return;
    }

    std::vector<int> intermediate_result(input_size);
    int product_sum = 0;

    for (int i = 0; i < input_size; i += 4) {
        int a[4] = {0, 0, 0, 0};
        int b[4] = {0, 0, 0, 0};
        
        for (int j = 0; j < 4 && (i + j) < input_size; ++j) {
            a[j] = input_data[i + j];
            b[j] = input_data[i + j] + 1; // Example operation
        }

        for (int j = 0; j < 4; ++j) {
            product_sum += a[j] * b[j];
        }
    }

    std::memset(result, 0, sizeof(std::vector<int>));
    result->resize(2);
    (*result)[0] = product_sum;
    (*result)[1] = product_sum * 2; // Example operation
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
    assert (issame(sum_product({}) ,{0, 1}));
    assert (issame(sum_product({1, 1, 1}), {3, 1}));
    assert (issame(sum_product({100, 0}),{100, 0}));
     assert (issame(sum_product({3, 5, 7}) , {3 + 5 + 7, 3 * 5 * 7}));
      assert (issame(sum_product({10}) ,{10, 10}));
}


