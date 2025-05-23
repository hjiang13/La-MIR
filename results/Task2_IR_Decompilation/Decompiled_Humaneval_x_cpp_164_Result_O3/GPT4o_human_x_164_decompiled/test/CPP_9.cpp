#include <vector>
#include <stdexcept>
#include <cstring>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    size_t input_size = input.size();
    
    if (input_size == 0) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    int max_val = input[0];
    result.push_back(max_val);
    
    for (size_t i = 1; i < input_size; ++i) {
        max_val = std::max(max_val, input[i]);
        result.push_back(max_val);
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