```c++
#include <vector>
#include <cmath>

bool has_close_elements(std::vector<float> &vec, float threshold) {
    float *begin = vec.data();
    float *end = vec.data() + vec.size();

    if (end - begin == 0) {
        return false;
    }

    size_t max_iterations = std::max(end - begin, 1);

    for (size_t i = 1; i < max_iterations; ++i) {
        if (std::fabs(begin[i] - begin[i-1]) < threshold) {
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
