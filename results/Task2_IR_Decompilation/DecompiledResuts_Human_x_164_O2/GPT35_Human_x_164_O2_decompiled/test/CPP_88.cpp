```cpp
#include <vector>

void sort_array(std::vector<int>& result, std::vector<int>& input) {
    int* result_data = input.data();
    int* input_data = input.data();
    int result_size = result_data - input_data;
    int result_capacity = result_data - input_data;
    
    if (result_size == 0) {
        memset(&result, 0, sizeof(result));
        return;
    }
    
    int pivot = input[input.size() - 1];
    int* iter = input.data();
    while (*iter < pivot) {
        ++iter;
    }
    
    int* new_pivot = std::partition(input.begin(), input.end() - 1, [&](int x) {
        return x < pivot;
    });
    
    result.assign(input.begin(), new_pivot);
    result.push_back(pivot);
    std::copy(new_pivot + 1, input.end(), std::back_inserter(result));
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
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({5}) , {5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5}) , {0, 1, 2, 3, 4, 5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5, 6}) , {6, 5, 4, 3, 2, 1, 0}));
    assert (issame(sort_array({2, 1}) , {1, 2}));
    assert (issame(sort_array({15, 42, 87, 32 ,11, 0}) , {0, 11, 15, 32, 42, 87}));
    assert (issame(sort_array({21, 14, 23, 11}) , {23, 21, 14, 11}));
}
