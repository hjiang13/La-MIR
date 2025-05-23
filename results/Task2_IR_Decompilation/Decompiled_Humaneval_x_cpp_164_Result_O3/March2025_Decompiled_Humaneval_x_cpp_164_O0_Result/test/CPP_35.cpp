#include <vector>
#include <limits>

float max_element(const std::vector<float>& vec) {
    float max_val = -10000.0f;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (max_val < vec[i]) {
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
