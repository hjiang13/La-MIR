#include <vector>
#include <algorithm>
#include <limits>

float max_element(std::vector<float> const& vec) {
    if (vec.empty()) return -10000.0f;
    
    float max_val = -10000.0f;
    size_t size = vec.size();

    for (size_t i = 0; i < size; ++i) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }
    
    return max_val;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}
