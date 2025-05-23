#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

void sort_even(std::vector<float>& vec) {
    if (vec.empty()) return;

    std::vector<float> even_elements;
    for (size_t i = 0; i < vec.size(); i += 2) {
        even_elements.push_back(vec[i]);
    }

    std::sort(even_elements.begin(), even_elements.end());

    for (size_t i = 0; i < even_elements.size(); ++i) {
        vec[i * 2] = even_elements[i];
    }
}

int main() {
    std::vector<float> vec = {5.0f, 3.0f, 8.0f, 1.0f, 4.0f, 9.0f};
    sort_even(vec);

    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

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
