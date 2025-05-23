#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

std::vector<int> common(std::vector<int> a, std::vector<int> b) {
    std::vector<int> result;
    for (size_t i = 0; i < a.size(); ++i) {
        if (std::find(result.begin(), result.end(), a[i]) == result.end()) {
            if (std::find(b.begin(), b.end(), a[i]) != b.end()) {
                result.push_back(a[i]);
            }
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
    assert (issame(common({1, 4, 3, 34, 653, 2, 5}, {5, 7, 1, 5, 9, 653, 121}) , {1, 5, 653}));
    assert (issame(common({5, 3, 2, 8}, {3, 2}) , {2, 3}));
    assert (issame(common({4, 3, 2, 8}, {3, 2, 4}) , {2, 3, 4}));
    assert (issame(common({4, 3, 2, 8}, {}) , {}));
}
