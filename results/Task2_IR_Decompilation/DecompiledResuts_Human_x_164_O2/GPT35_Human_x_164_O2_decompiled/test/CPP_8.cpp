```cpp
#include <vector>

void sum_product(std::vector<int>& result, const std::vector<int>& input) {
    int size = input.size();
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[j] += input[i * 4 + j];
        }
    }
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> result(4, 0);
    
    sum_product(result, input);
    
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
    assert (issame(sum_product({}) ,{0, 1}));
    assert (issame(sum_product({1, 1, 1}), {3, 1}));
    assert (issame(sum_product({100, 0}),{100, 0}));
     assert (issame(sum_product({3, 5, 7}) , {3 + 5 + 7, 3 * 5 * 7}));
      assert (issame(sum_product({10}) ,{10, 10}));
}


