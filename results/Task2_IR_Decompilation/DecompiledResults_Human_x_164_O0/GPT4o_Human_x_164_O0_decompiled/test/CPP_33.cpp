#include <vector>
#include <algorithm>
#include <stdexcept>

void sort_third(std::vector<int>& vec1, std::vector<int>& vec2) {
    std::vector<int> temp;

    for (size_t i = 0; i < vec1.size(); i += 3) {
        if (i + 2 < vec1.size()) {
            temp.push_back(vec1[i]);
            temp.push_back(vec1[i + 1]);
            temp.push_back(vec1[i + 2]);
        } else if (i + 1 < vec1.size()) {
            temp.push_back(vec1[i]);
            temp.push_back(vec1[i + 1]);
        } else if (i < vec1.size()) {
            temp.push_back(vec1[i]);
        }
    }

    std::sort(temp.begin(), temp.end());

    for (size_t i = 0; i < temp.size(); ++i) {
        vec2.push_back(temp[i]);
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
    assert (issame(sort_third({1, 2, 3}) , sort_third({1, 2, 3})));
    assert (issame(sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}) , sort_third({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10})));
    assert (issame(sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}) , sort_third({5, 8, -12, 4, 23, 2, 3, 11, 12, -10})));
    assert (issame(sort_third({5, 6, 3, 4, 8, 9, 2}) , {2, 6, 3, 4, 8, 9, 5}));
    assert (issame(sort_third({5, 8, 3, 4, 6, 9, 2}) , {2, 8, 3, 4, 6, 9, 5}));
    assert (issame(sort_third({5, 6, 9, 4, 8, 3, 2}) , {2, 6, 9, 4, 8, 3, 5}));
    assert (issame(sort_third({5, 6, 3, 4, 8, 9, 2, 1}) , {2, 6, 3, 4, 8, 9, 5, 1}));
}
