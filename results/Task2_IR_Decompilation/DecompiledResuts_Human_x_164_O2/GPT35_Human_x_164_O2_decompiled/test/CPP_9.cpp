```cpp
#include <vector>
#include <algorithm>

void rolling_max(std::vector<int>& output, const std::vector<int>& input) {
    output.clear();
    
    if (input.empty()) {
        return;
    }
    
    output.push_back(input[0]);
    
    for (size_t i = 1; i < input.size(); ++i) {
        int current = input[i];
        int max_so_far = std::max(output.back(), current);
        output.push_back(max_so_far);
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