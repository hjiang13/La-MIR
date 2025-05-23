#include <vector>
#include <algorithm>
#include <stdexcept>

void strange_sort_list(std::vector<int>& result, const std::vector<int>& input) {
    std::vector<int> temp;
    temp.reserve(input.size());

    std::vector<int>::const_iterator begin = input.begin();
    std::vector<int>::const_iterator end = input.end();

    std::sort(begin, end);

    int i = 0;
    int j = input.size() - 1;

    while (i < j) {
        temp.push_back(input[i]);
        temp.push_back(input[j]);
        i++;
        j--;
    }

    if (i == j) {
        temp.push_back(input[i]);
    }

    result = std::move(temp);
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
