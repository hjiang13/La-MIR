#include <vector>
#include <stdexcept>
#include <algorithm>

void intersperse(std::vector<int>& result, const std::vector<int>& input, int value) {
    result.clear();
    if (!input.empty()) {
        result.push_back(input[0]);
    }
    for (size_t i = 1; i < input.size(); ++i) {
        result.push_back(value);
        result.push_back(input[i]);
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
    assert (issame(intersperse({}, 7), {}));
    
    assert (issame(intersperse({5, 6, 3, 2}, 8),{5, 8, 6, 8, 3, 8, 2}));
    assert (issame(intersperse({2, 2, 2}, 2),{2, 2, 2, 2, 2}));
}