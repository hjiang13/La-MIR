#include <vector>
#include <algorithm>

float max_element(std::vector<float> &vec) {
    if (vec.empty()) {
        return -1e4; // Return a sentinel value for empty vector
    }

    float max_val = -1e4;
    for (size_t i = 0; i < vec.size(); ++i) {
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
