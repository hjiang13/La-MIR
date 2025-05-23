#include <vector>
#include <stdexcept>
#include <cstring>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    size_t inputSize = input.size();
    
    if (inputSize <= 1) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    
    result.resize(inputSize);
    
    for (size_t i = 1; i < inputSize; ++i) {
        float delta = input[i] - input[i - 1];
        result[i - 1] = delta;
    }
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(derivative({3, 1, 2, 4, 5}) , {1, 4, 12, 20}));
    assert (issame(derivative({1, 2, 3}) , {2, 6}));
    assert (issame(derivative({3, 2, 1}) , {2, 2}));
    assert (issame(derivative({3, 2, 1, 0, 4}) , {2, 2, 0, 16}));
    assert (issame(derivative({1}) , {}));
}
