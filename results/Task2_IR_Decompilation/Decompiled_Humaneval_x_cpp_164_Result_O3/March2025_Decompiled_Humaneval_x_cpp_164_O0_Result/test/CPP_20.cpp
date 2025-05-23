#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>

std::vector<float> find_closest_elements(const std::vector<float>& input) {
    std::vector<float> result;
    if (input.size() < 2) {
        return result;
    }

    float min_diff = std::abs(input[0] - input[1]);
    result = {input[0], input[1]};

    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = i + 1; j < input.size(); ++j) {
            float diff = std::abs(input[i] - input[j]);
            if (diff < min_diff) {
                min_diff = diff;
                result = {input[i], input[j]};
            }
        }
    }

    if (result[0] > result[1]) {
        std::swap(result[0], result[1]);
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
    assert (issame(find_closest_elements({1.0, 2.0, 3.9, 4.0, 5.0, 2.2}) , {3.9, 4.0}));
    assert (issame(find_closest_elements({1.0, 2.0, 5.9, 4.0, 5.0}) , {5.0, 5.9} ));
    assert (issame(find_closest_elements({1.0, 2.0, 3.0, 4.0, 5.0, 2.2}) ,{2.0, 2.2}));
     assert (issame(find_closest_elements({1.0, 2.0, 3.0, 4.0, 5.0, 2.0}) ,{2.0, 2.0}));
      assert (issame(find_closest_elements({1.1, 2.2, 3.1, 4.1, 5.1}) , {2.2, 3.1}));
}
