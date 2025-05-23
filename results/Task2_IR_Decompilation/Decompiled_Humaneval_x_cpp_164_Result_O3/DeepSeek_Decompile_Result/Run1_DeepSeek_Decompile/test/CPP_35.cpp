#include <vector>
#include <algorithm>

using namespace std;

float max_element(const vector<float>& vec) {
    if (vec.empty()) {
        return -10000.0f;
    }

    float max_val = vec[0];
    size_t size = vec.size();
    size_t i = 0;

    // Handle larger chunks
    while (i + 4 <= size) {
        float a = max(max(vec[i], vec[i+1]), max(vec[i+2], vec[i+3]));
        max_val = max(max_val, a);
        i += 4;
    }

    // Handle remaining elements
    while (i < size) {
        max_val = max(max_val, vec[i]);
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
