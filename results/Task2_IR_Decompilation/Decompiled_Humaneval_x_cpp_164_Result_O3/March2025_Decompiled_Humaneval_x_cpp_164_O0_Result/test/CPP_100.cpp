#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

void make_a_pile(std::vector<int>& vec, int n) {
    std::vector<int> temp = {n};
    vec = std::vector<int>(temp.begin(), temp.end());
    for (int i = 1; i < n; ++i) {
        int last = vec.back();
        vec.push_back(last + 2);
    }
}

int main() {
    std::vector<int> vec;
    make_a_pile(vec, 10);
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
    assert (issame(make_a_pile(3) , {3, 5, 7}));
    assert (issame(make_a_pile(4) , {4,6,8,10}));
    assert (issame(make_a_pile(5) , {5, 7, 9, 11, 13}));
    assert (issame(make_a_pile(6) , {6, 8, 10, 12, 14, 16}));
    assert (issame(make_a_pile(8) , {8, 10, 12, 14, 16, 18, 20, 22}));
}
