```cpp
#include <vector>
#include <algorithm>

void sort_third(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    result.reserve(input.size());

    for (size_t i = 0; i < input.size(); ++i) {
        size_t index = i * 3;
        if (index < input.size()) {
            result.push_back(input[index]);
        }
    }

    std::sort(result.begin(), result.end());
}

int main() {
    std::vector<int> input = {5, 1, 7, 3, 9, 2, 6};
    std::vector<int> result;

    sort_third(result, input);

    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

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
    assert (issame(sort_third({1, 2, 3}) , sort_third({1, 2, 3})));
    assert (issame(sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}) , sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10})));
    assert (issame(sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}) , sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10})));
    assert (issame(sort_third({5, 6, 3, 4, 8, 9, 2}) , {2, 6, 3, 4, 8, 9, 5}));
    assert (issame(sort_third({5, 8, 3, 4, 6, 9, 2}) , {2, 8, 3, 4, 6, 9, 5}));
    assert (issame(sort_third({5, 6, 9, 4, 8, 3, 2}) , {2, 6, 9, 4, 8, 3, 5}));
    assert (issame(sort_third({5, 6, 3, 4, 8, 9, 2, 1}) , {2, 6, 3, 4, 8, 9, 5, 1}));
}
