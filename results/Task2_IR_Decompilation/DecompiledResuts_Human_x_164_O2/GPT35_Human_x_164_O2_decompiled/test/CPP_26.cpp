```cpp
#include <vector>

void remove_duplicates(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    if (input.empty()) {
        return;
    }

    std::vector<int>::const_iterator it = input.begin();
    result.push_back(*it);

    for (++it; it != input.end(); ++it) {
        if (*it != result.back()) {
            result.push_back(*it);
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
