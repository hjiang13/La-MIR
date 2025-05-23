#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

void compare(std::vector<int>& result, const std::vector<int>& vec1, const std::vector<int>& vec2) {
    result.clear();

    if (vec1.empty() || vec2.empty()) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    size_t size = std::min(vec1.size(), vec2.size());
    for (size_t i = 0; i < size; ++i) {
        int diff = std::abs(vec1[i] - vec2[i]);
        result.push_back(diff);
    }

    if (result.size() > vec1.size()) {
        throw std::length_error("vector::_M_realloc_insert");
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
