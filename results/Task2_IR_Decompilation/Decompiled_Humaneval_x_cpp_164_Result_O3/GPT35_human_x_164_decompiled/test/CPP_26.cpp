```c
#include <vector>
#include <algorithm>

void remove_duplicates(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    std::vector<int>::const_iterator it = input.begin();
    while (it != input.end()) {
        if (std::find(result.begin(), result.end(), *it) == result.end()) {
            result.push_back(*it);
        }
        ++it;
    }
}

int main() {
    std::vector<int> input = {1, 2, 2, 3, 4, 4, 5};
    std::vector<int> result;
    remove_duplicates(result, input);
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
    assert (issame(remove_duplicates({}) , {}));
     assert (issame(remove_duplicates({1, 2, 3, 4}) , {1, 2, 3, 4}));
      assert (issame(remove_duplicates({1, 2, 3, 2, 4, 3, 5}) , {1, 4, 5}));
}
