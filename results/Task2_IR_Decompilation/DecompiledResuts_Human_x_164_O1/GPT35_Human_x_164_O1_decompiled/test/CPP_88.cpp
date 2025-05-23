```cpp
#include <vector>
#include <algorithm>

void sort_array(std::vector<int>& result, std::vector<int>& input) {
    auto first = input.begin();
    auto last = input.end();
    
    if (first == last) {
        result.clear();
        return;
    }
    
    int len = std::distance(first, last);
    int mid = len / 2;
    int pivot = *std::next(first, mid);
    
    std::sort(first, last);
    std::inplace_merge(first, std::next(first, mid), last);
    
    result.assign(first, last);
}

int main() {
    std::vector<int> input = {5, 2, 8, 1, 9, 3};
    std::vector<int> result;
    
    sort_array(result, input);
    
    for (int num : result) {
        std::cout << num << " ";
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
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({5}) , {5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5}) , {0, 1, 2, 3, 4, 5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5, 6}) , {6, 5, 4, 3, 2, 1, 0}));
    assert (issame(sort_array({2, 1}) , {1, 2}));
    assert (issame(sort_array({15, 42, 87, 32 ,11, 0}) , {0, 11, 15, 32, 42, 87}));
    assert (issame(sort_array({21, 14, 23, 11}) , {23, 21, 14, 11}));
}
