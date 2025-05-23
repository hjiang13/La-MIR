```cpp
#include <vector>
#include <algorithm>

void common(std::vector<int>& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    result.clear();
    
    if (vec1.empty() || vec2.empty()) {
        return;
    }
    
    std::vector<int>::iterator it1 = vec1.begin();
    std::vector<int>::iterator it2 = vec2.begin();
    
    while (it1 != vec1.end() && it2 != vec2.end()) {
        if (*it1 < *it2) {
            result.push_back(*it1);
            ++it1;
        } else {
            result.push_back(*it2);
            ++it2;
        }
    }
    
    while (it1 != vec1.end()) {
        result.push_back(*it1);
        ++it1;
    }
    
    while (it2 != vec2.end()) {
        result.push_back(*it2);
        ++it2;
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
    assert (issame(common({1, 4, 3, 34, 653, 2, 5}, {5, 7, 1, 5, 9, 653, 121}) , {1, 5, 653}));
    assert (issame(common({5, 3, 2, 8}, {3, 2}) , {2, 3}));
    assert (issame(common({4, 3, 2, 8}, {3, 2, 4}) , {2, 3, 4}));
    assert (issame(common({4, 3, 2, 8}, {}) , {}));
}
