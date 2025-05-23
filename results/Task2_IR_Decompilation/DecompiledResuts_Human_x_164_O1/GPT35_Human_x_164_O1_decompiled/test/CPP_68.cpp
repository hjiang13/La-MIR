```cpp
#include <vector>

void pluck(std::vector<int>& result, std::vector<int>& input) {
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] & 1 == 0) {
            if (result.size() == 0 || input[i] < result.back()) {
                result.push_back(input[i]);
            }
        }
    }
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> result;
    
    pluck(result, input);
    
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
    assert (issame(pluck({4,2,3}) , {2, 1}));
    assert (issame(pluck({1,2,3}) , {2, 1}));
    assert (issame(pluck({}) , {}));
    assert (issame(pluck({5, 0, 3, 0, 4, 2}) , {0, 1}));
    assert (issame(pluck({1, 2, 3, 0, 5, 3}) , {0, 3}));
    assert (issame(pluck({5, 4, 8, 4 ,8}) , {4, 1}));
    assert (issame(pluck({7, 6, 7, 1}) , {6, 1}));
    assert (issame(pluck({7, 9, 7, 1}) , {}));
}
