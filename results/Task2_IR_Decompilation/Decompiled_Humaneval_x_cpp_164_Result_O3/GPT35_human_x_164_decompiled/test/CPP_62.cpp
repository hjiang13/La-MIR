#include <vector>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    
    if (input.size() > 1) {
        for (size_t i = 0; i < input.size(); ++i) {
            float val = input[i] * static_cast<float>(i);
            result.push_back(val);
        }
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
