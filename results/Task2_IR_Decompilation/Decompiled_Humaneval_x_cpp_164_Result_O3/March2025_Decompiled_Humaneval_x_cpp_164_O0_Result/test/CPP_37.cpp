#include <vector>
#include <algorithm>

std::vector<float> sort_even(const std::vector<float>& input) {
    std::vector<float> even_elements;
    std::vector<float> result;

    for (size_t i = 0; i < input.size(); i += 2) {
        even_elements.push_back(input[i]);
    }

    std::sort(even_elements.begin(), even_elements.end());

    for (size_t i = 0; i < input.size(); ++i) {
        if (i % 2 == 0) {
            result.push_back(even_elements[i / 2]);
        } else {
            result.push_back(input[i]);
        }
    }

    return result;
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
