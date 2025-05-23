#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

std::vector<int> unique(std::vector<int> input) {
    std::vector<int> result;
    for (size_t i = 0; i < input.size(); ++i) {
        if (std::find(result.begin(), result.end(), input[i]) == result.end()) {
            result.push_back(input[i]);
        }
    }
    std::sort(result.begin(), result.end());
    return result;
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
    assert (issame(unique({5, 3, 5, 2, 3, 3, 9, 0, 123}) , {0, 2, 3, 5, 9, 123}));
}
