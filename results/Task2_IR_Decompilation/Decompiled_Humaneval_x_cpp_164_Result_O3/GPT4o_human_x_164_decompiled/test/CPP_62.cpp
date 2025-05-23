#include <vector>
#include <stdexcept>
#include <cstring>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    size_t input_size = input.size();
    if (input_size <= 1) return;

    result.resize(input_size);
    float scale = static_cast<float>(input_size - 1);
    
    for (size_t i = 0; i < input_size - 1; ++i) {
        result[i] = input[i] * (i / scale);
    }

    result[input_size - 1] = input[input_size - 1];
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
