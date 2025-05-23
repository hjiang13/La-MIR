#include <vector>
#include <algorithm>  // For std::max

using namespace std;

void rolling_max(vector<int>& result, const vector<int>& input) {
    result._M_realloc_insert(result.end(), input.begin(), input.end());
    int current_max = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        current_max = max(current_max, input[i]);
        result.push_back(current_max);
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