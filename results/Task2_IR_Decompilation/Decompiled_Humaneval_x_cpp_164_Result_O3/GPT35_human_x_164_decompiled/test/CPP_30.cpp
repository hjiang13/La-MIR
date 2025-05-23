#include <vector>
#include <stdexcept>
#include <cstring>

void get_positive(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    result.reserve(input.size());

    for (const float& val : input) {
        if (val > 0.0f) {
            result.push_back(val);
        }
    }
}

int main() {
    std::vector<float> input = {1.0f, -2.0f, 3.0f, -4.0f, 5.0f};
    std::vector<float> result;
    
    get_positive(result, input);

    return 0;
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
    assert (issame(get_positive({-1, -2, 4, 5, 6}) , {4, 5, 6} ));
    assert (issame(get_positive({5, 3, -5, 2, 3, 3, 9, 0, 123, 1, -10}) , {5, 3, 2, 3, 3, 9, 123, 1}));
     assert (issame(get_positive({-1, -2}) , {} ));
     assert (issame(get_positive({}) , {}));
}
