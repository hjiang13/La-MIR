#include <iostream>
#include <vector>
#include <algorithm>

void sort_even(std::vector<float> &vec1, std::vector<float> &vec2) {
    std::vector<float> temp;
    temp.reserve(vec1.size());
    for (size_t i = 0; i < vec1.size(); i += 2) {
        if (i < vec2.size()) {
            temp.push_back(vec2[i]);
        }
    }
    std::sort(temp.begin(), temp.end());
    for (size_t i = 0; i < temp.size(); ++i) {
        if (i < vec1.size()) {
            vec1[i] = temp[i];
        }
    }
}

int main() {
    std::vector<float> vec1 = {5.0, 3.0, 2.0, 4.0, 1.0};
    std::vector<float> vec2 = {10.0, 9.0, 8.0, 7.0, 6.0};

    sort_even(vec1, vec2);

    for (const auto &val : vec1) {
        std::cout << val << " ";
    }
    return 0;
}

#undef NDEBUG
#include<assert.h>
bool issame(vector<float> a,vector<float>b){
    if (a.size()!=b.size()) return false;
    for (int i=0;i<a.size();i++)
    {
        if (abs(a[i]-b[i])>1e-4) return false;
    }
    return true;
}
int main(){
    assert (issame(sort_even({1, 2, 3}), {1, 2, 3}));
    assert (issame(sort_even({5, 3, -5, 2, -3, 3, 9, 0, 123, 1, -10}) , {-10, 3, -5, 2, -3, 3, 5, 0, 9, 1, 123}));
    assert (issame(sort_even({5, 8, -12, 4, 23, 2, 3, 11, 12, -10}) , {-12, 8, 3, 4, 5, 2, 12, 11, 23, -10}));
}
