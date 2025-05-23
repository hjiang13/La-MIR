#include <vector>
#include <algorithm>

float max_element(std::vector<float>& vec) {
    float max_value = -10000.0f;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] > max_value) {
            max_value = vec[i];
        }
    }
    return max_value;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}
