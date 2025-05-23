#include <vector>

using namespace std;

vector<int> rolling_max(vector<int> output, const vector<int>& input) {
    if (input.empty()) {
        return output;
    }
    
    output.reserve(input.size());
    
    int current_max = input[0];
    output.push_back(current_max);
    
    for (size_t i = 1; i < input.size(); ++i) {
        if (input[i] > current_max) {
            current_max = input[i];
        }
        output.push_back(current_max);
    }
    
    return output;
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