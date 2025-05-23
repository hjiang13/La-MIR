#include <vector>

void rolling_max(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    int max_val = 0;
    
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] > max_val) {
            max_val = input[i];
        }
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