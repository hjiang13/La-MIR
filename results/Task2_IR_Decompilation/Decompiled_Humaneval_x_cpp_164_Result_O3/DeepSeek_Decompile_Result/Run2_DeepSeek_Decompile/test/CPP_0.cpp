#include <vector>
#include <cmath>

using namespace std;

bool has_close_elements(const vector<float>& vec, float threshold) {
    if (vec.empty()) {
        return false;
    }

    float* data = vec.data();
    size_t size = vec.size();

    if (size == 0) {
        return false;
    }

    float* end = data + size;

    size_t num_elements = end - data;
    num_elements = num_elements > 0 ? num_elements : 1;

    for (size_t i = 0; i < num_elements - 1; ++i) {
        float current = data[i];
        float next = data[i + 1];
        float diff = fabs(current - next);
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
