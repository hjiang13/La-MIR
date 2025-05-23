#include <vector>
#include <algorithm>
#include <iostream>

void remove_duplicates(std::vector<int> &vec) {
    if (vec.empty()) return;

    std::vector<int> unique;
    std::sort(vec.begin(), vec.end());
    unique.push_back(vec[0]);

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] != vec[i - 1]) {
            unique.push_back(vec[i]);
        }
    }

    vec = std::move(unique);
}

int main() {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 5};
    remove_duplicates(vec);

    for (int num : vec) {
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
    assert (issame(remove_duplicates({}) , {}));
     assert (issame(remove_duplicates({1, 2, 3, 4}) , {1, 2, 3, 4}));
      assert (issame(remove_duplicates({1, 2, 3, 2, 4, 3, 5}) , {1, 4, 5}));
}
