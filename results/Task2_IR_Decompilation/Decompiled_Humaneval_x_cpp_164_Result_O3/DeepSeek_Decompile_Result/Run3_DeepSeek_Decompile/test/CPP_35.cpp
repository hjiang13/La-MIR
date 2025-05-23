#include <vector>
#include <algorithm>

using namespace std;

float max_element(const vector<float>& v) {
    if (v.empty()) {
        return -10000.0f;
    }
    const float* data = v.data();
    float max_val = data[0];
    size_t n = v.size();
    size_t i = 1;

    // Process chunks of four elements
    while (i + 3 < n) {
        max_val = max(max_val, data[i]);
        max_val = max(max_val, data[i + 1]);
        max_val = max(max_val, data[i + 2]);
        max_val = max(max_val, data[i + 3]);
        i += 4;
    }

    // Process remaining elements
    while (i < n) {
        max_val = max(max_val, data[i]);
        i++;
    }

    return max_val;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (abs(max_element({1, 2, 3})- 3)<1e-4);
    assert (abs(max_element({5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10})- 124)<1e-4);
}
