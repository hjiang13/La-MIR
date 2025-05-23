#include <vector>
#include <cstdlib>
#include <cmath>

void compare(std::vector<int>& v1, std::vector<int>& v2, std::vector<int>& result) {
    result.clear();
    for (size_t i = 0; i < v1.size(); ++i) {
        if (i < v2.size()) {
            int diff = std::abs(v1[i] - v2[i]);
            result.push_back(diff);
        }
    }
}

int main() {
    std::vector<int> vector1 = {1, 2, 3, 4};
    std::vector<int> vector2 = {4, 3, 2, 1};
    std::vector<int> result;

    compare(vector1, vector2, result);
    
    for (int val : result) {
        std::cout << val << " ";
    }
    
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
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,5,0,0,0,4},{4,1,1,0,0,-2}),{4,4,1,0,0,6}));
    assert (issame(compare({1,2,3,4,5,1},{1,2,3,4,2,-2}),{0,0,0,0,3,3}));
    assert (issame(compare({0,0,0,0,0,0},{0,0,0,0,0,0}),{0,0,0,0,0,0}));
    assert (issame(compare({1,2,3},{-1,-2,-3}),{2,4,6}));
    assert (issame(compare({1,2,3,5},{-1,2,3,4}),{2,0,0,1}));
}
