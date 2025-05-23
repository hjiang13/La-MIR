#include <vector>
#include <cmath>
#include <cstddef>

bool has_close_elements(const std::vector<float>& vec, float threshold) {
    size_t size = vec.size();
    for (size_t i = 0; i < size - 1; ++i) {
        float diff = std::fabs(vec[i] - vec[i + 1]);
        if (diff < threshold) {
            return true;
        }
    }
    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    vector<float> a={1.0, 2.0, 3.9, 4.0, 5.0, 2.2};
    assert (has_close_elements(a, 0.3)==true);
    assert (has_close_elements(a, 0.05) == false);

    assert (has_close_elements({1.0, 2.0, 5.9, 4.0, 5.0}, 0.95) == true);
    assert (has_close_elements({1.0, 2.0, 5.9, 4.0, 5.0}, 0.8) ==false);
    assert (has_close_elements({1.0, 2.0, 3.0, 4.0, 5.0}, 2.0) == true);
    assert (has_close_elements({1.1, 2.2, 3.1, 4.1, 5.1}, 1.0) == true);
    assert (has_close_elements({1.1, 2.2, 3.1, 4.1, 5.1}, 0.5) == false);
    
}
