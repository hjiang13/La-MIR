#include <vector>
#include <algorithm>
#include <stdexcept>

void sort_array(std::vector<int>& result, const std::vector<int>& input) {
    if (input.size() == 0) {
        result = std::vector<int>();
        return;
    }

    int first = input[0];
    int last = input[input.size() - 1];
    int sum = first + last;
    bool isOdd = (sum % 2 == 1);

    if (isOdd) {
        std::vector<int> temp(input.begin(), input.end());
        std::sort(temp.begin(), temp.end());
        result = std::move(temp);
    } else {
        std::vector<int> temp;
        for (int i = input.size() - 1; i >= 0; --i) {
            temp.push_back(input[i]);
        }
        result = std::move(temp);
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
    assert (issame(sort_array({}) , {}));
    assert (issame(sort_array({5}) , {5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5}) , {0, 1, 2, 3, 4, 5}));
    assert (issame(sort_array({2, 4, 3, 0, 1, 5, 6}) , {6, 5, 4, 3, 2, 1, 0}));
    assert (issame(sort_array({2, 1}) , {1, 2}));
    assert (issame(sort_array({15, 42, 87, 32 ,11, 0}) , {0, 11, 15, 32, 42, 87}));
    assert (issame(sort_array({21, 14, 23, 11}) , {23, 21, 14, 11}));
}
