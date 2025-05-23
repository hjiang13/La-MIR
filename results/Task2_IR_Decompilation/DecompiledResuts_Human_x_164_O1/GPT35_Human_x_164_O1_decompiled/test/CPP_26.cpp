```cpp
#include <vector>

void remove_duplicates(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    
    std::vector<int> temp;
    temp.clear();
    
    for (const auto& item : input) {
        if (std::find(result.begin(), result.end(), item) == result.end()) {
            result.push_back(item);
        }
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
    assert (issame(remove_duplicates({}) , {}));
     assert (issame(remove_duplicates({1, 2, 3, 4}) , {1, 2, 3, 4}));
      assert (issame(remove_duplicates({1, 2, 3, 2, 4, 3, 5}) , {1, 4, 5}));
}
