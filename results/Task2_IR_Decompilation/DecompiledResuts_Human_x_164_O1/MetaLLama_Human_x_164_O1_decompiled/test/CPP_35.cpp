#include <stdio.h>

float max_element(float* arr, int len) {
    float max_val = -10000.0f;
    for (int i = 0; i < len; i++) {
        float val = arr[i];
        if (max_val < val) {
            max_val = val;
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
