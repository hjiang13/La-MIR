#include <vector>
#include <cmath>

using namespace std;

bool has_close_elements(const vector<float>& vec, float threshold) {
    if (vec.empty()) {
        return false;
    }

    float* data_ptr = vec.data();
    size_t size = vec.size() / sizeof(float);

    for (size_t i = 0; i < size; ++i) {
        float current = data_ptr[i];
        for (size_t j = i + 1; j < size; ++j) {
            float other = data_ptr[j];
            if (fabs(current - other) < threshold) {
                return true;
            }
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
