```cpp
#include <vector>

bool has_close_elements(std::vector<float> *vec, float val) {
    float *data_end = vec->data() + vec->size();
    float *data_begin = vec->data();
    size_t size_diff = data_end - data_begin;
    size_t max_diff = std::max(size_diff, static_cast<size_t>(1));

    for (size_t i = 0; i < max_diff - 1; ++i) {
        float diff = std::abs(data_begin[i] - data_begin[i + 1]);
        if (diff < val) {
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
