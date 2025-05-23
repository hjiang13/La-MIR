#include <vector>
#include <algorithm>
#include <stdexcept>

void common(std::vector<int> &vec0, const std::vector<int> &vec1, const std::vector<int> &vec2) {
    size_t size0 = vec0.size();
    size_t size1 = vec1.size();
    size_t size2 = vec2.size();
    
    for (size_t i = 0; i < size0; ++i) {
        int *element = &vec0[i];
        auto it1 = std::find(vec1.begin(), vec1.end(), *element);
        auto it2 = std::find(vec2.begin(), vec2.end(), *element);
        
        if (it1 != vec1.end() && it2 != vec2.end()) {
            vec0.push_back(*element);
        }
    }
    std::sort(vec0.begin(), vec0.end());
}

int main() {
    std::vector<int> vec0;
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {3, 4, 5};
    
    common(vec0, vec1, vec2);
    
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
    assert (issame(common({1, 4, 3, 34, 653, 2, 5}, {5, 7, 1, 5, 9, 653, 121}) , {1, 5, 653}));
    assert (issame(common({5, 3, 2, 8}, {3, 2}) , {2, 3}));
    assert (issame(common({4, 3, 2, 8}, {3, 2, 4}) , {2, 3, 4}));
    assert (issame(common({4, 3, 2, 8}, {}) , {}));
}
