#include <vector>
#include <algorithm>

float max_element(std::vector<float> &vec) {
    float max_val = -1e4;
    size_t size = vec.size();
    
    if (size == 0) return max_val;

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
