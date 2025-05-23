#include <vector>
#include <algorithm>
#include <iterator>

void remove_duplicates(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> temp1;
    std::vector<int> temp2;

    for (size_t i = 0; i < input.size(); ++i) {
        if (std::find(temp1.begin(), temp1.end(), input[i]) == temp1.end()) {
            if (std::find(temp2.begin(), temp2.end(), input[i]) == temp2.end()) {
                temp2.push_back(input[i]);
            } else {
                temp1.push_back(input[i]);
            }
        }
    }

    for (size_t i = 0; i < input.size(); ++i) {
        if (std::find(temp2.begin(), temp2.end(), input[i]) == temp2.end()) {
            result.push_back(input[i]);
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
