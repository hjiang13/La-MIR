#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

std::vector<int> compare(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::vector<int> result;
    size_t size1 = v1.size();
    size_t size2 = v2.size();
    size_t minSize = std::min(size1, size2);

    for (size_t i = 0; i < minSize; ++i) {
        int diff = std::abs(v1[i] - v2[i]);
        result.push_back(diff);
    }

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
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,5,0,0,0,4},{4,1,1,0,0,-2}),{4,4,1,0,0,6}));
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,0,0,0,0,0},{0,0,0,0,0,0}),{0,0,0,0,0,0}));
    assert (issame(compare({1,2,3},{-1,-2,-3}),{2,4,6}));
    assert (issame(compare({1,2,3,5},{-1,2,3,4}),{2,0,0,1}));
}
