#include <vector>
#include <algorithm>
#include <iostream>

void strange_sort_list(std::vector<int>& a, std::vector<int>& b) {
    std::vector<int> temp;
    for (auto it = b.begin(); it != b.end(); ++it) {
        temp.push_back(*it);
    }
    std::sort(temp.begin(), temp.end());
    
    for (size_t i = 0; i < temp.size(); ++i) {
        a.push_back(temp[i]);
    }
}

int main() {
    std::vector<int> a;
    std::vector<int> b = {5, 2, 9, 1, 5, 6};
    
    strange_sort_list(a, b);
    
    for (const int& val : a) {
        std::cout << val << " ";
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
