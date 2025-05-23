#include <vector>
#include <cstdlib> // for std::abs

void compare(std::vector<int>& result, const std::vector<int>& a, const std::vector<int>& b) {
    result.clear();
    
    if (a.size() != b.size()) {
        // Handle size mismatch if necessary
        return;
    }

    size_t size = a.size();
    result.reserve(size);

    for (size_t i = 0; i < size; ++i) {
        int diff = std::abs(a[i] - b[i]);
        result.push_back(diff);
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
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,5,0,0,0,4},{4,1,1,0,0,-2}),{4,4,1,0,0,6}));
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,0,0,0,0,0},{0,0,0,0,0,0}),{0,0,0,0,0,0}));
    assert (issame(compare({1,2,3},{-1,-2,-3}),{2,4,6}));
    assert (issame(compare({1,2,3,5},{-1,2,3,4}),{2,0,0,1}));
}
