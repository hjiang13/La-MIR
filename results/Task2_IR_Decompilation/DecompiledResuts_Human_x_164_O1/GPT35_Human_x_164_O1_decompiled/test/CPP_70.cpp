```cpp
#include <vector>

void strange_sort_list(std::vector<int>& result, const std::vector<int>& input) {
    result.clear();
    if (input.empty()) {
        return;
    }

    const int* begin = &input[0];
    const int* end = &input[input.size() - 1];

    if (begin == end) {
        result.push_back(*begin);
        return;
    }

    int step = (end - begin) / 4;
    int pivot = *(begin + 2 * step);

    std::vector<int> less, equal, greater;

    for (const int* it = begin; it <= end; ++it) {
        if (*it < pivot) {
            less.push_back(*it);
        } else if (*it == pivot) {
            equal.push_back(*it);
        } else {
            greater.push_back(*it);
        }
    }

    strange_sort_list(result, less);
    result.insert(result.end(), equal.begin(), equal.end());
    strange_sort_list(result, greater);
}

int main() {
    std::vector<int> input = {5, 3, 10, 2, 8, 7};
    std::vector<int> result;
    
    strange_sort_list(result, input);

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
    assert (issame(strange_sort_list({1, 2, 3, 4}) , {1, 4, 2, 3}));
    assert (issame(strange_sort_list({5, 6, 7, 8, 9}) , {5, 9, 6, 8, 7}));
    assert (issame(strange_sort_list({1, 2, 3, 4, 5}) , {1, 5, 2, 4, 3}));
    assert (issame(strange_sort_list({5, 6, 7, 8, 9, 1}) , {1, 9, 5, 8, 6, 7}));
    assert (issame(strange_sort_list({5, 5, 5, 5}) , {5, 5, 5, 5}));
    assert (issame(strange_sort_list({}) , {}));
    assert (issame(strange_sort_list({1,2,3,4,5,6,7,8}) , {1, 8, 2, 7, 3, 6, 4, 5}));
    assert (issame(strange_sort_list({0,2,2,2,5,5,-5,-5}) , {-5, 5, -5, 5, 0, 2, 2, 2}));
    assert (issame(strange_sort_list({111111}) , {111111}));
}
