#include <vector>
#include <stdexcept>

using namespace std;

void rolling_max(vector<int>& result, const vector<int>& input) {
    result.reserve(input.size()); // Pre-allocate space for efficiency

    int current_max = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        current_max = max(current_max, input[i]);
        result.push_back(current_max);
    }
}

int main() {
    vector<int> input = {1, 3, 2, 5, 4};
    vector<int> result;
    rolling_max(result, input);
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
     assert (issame(rolling_max({}),{}));
    assert (issame(rolling_max({1, 2, 3, 4}) , {1, 2, 3, 4}));
     assert (issame(rolling_max({4, 3, 2, 1}),{4, 4, 4, 4}));
      assert (issame(rolling_max({3, 2, 3, 100, 3}) ,{3, 3, 3, 100, 100}));
}