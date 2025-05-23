#include <vector>
#include <algorithm>

void remove_duplicates(std::vector<int>& vec) {
    std::vector<int> tmp;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (std::find(tmp.begin(), tmp.end(), vec[i]) == tmp.end()) {
            tmp.push_back(vec[i]);
        }
    }
    vec = std::move(tmp);
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
