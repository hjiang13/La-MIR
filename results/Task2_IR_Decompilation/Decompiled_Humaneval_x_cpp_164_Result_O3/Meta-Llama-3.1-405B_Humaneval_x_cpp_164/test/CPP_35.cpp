#include <stdio.h>

float max_element(float* data, int size) {
    float max_val = -10000.0f;

    if (size == 0) {
        return max_val;
    }

    int unroll_factor = (size >> 2) + 1;
    int remainder = size & 3;

    if (unroll_factor < 4) {
        for (int i = 0; i < size; i++) {
            float val = data[i];
            if (val > max_val) {
                max_val = val;
            }
        }
    } else {
        int i = 0;
        for (; i < size - remainder; i += 4) {
            float val1 = data[i];
            float val2 = data[i + 1];
            float val3 = data[i + 2];
            float val4 = data[i + 3];

            max_val = (val1 > max_val) ? val1 : max_val;
            max_val = (val2 > max_val) ? val2 : max_val;
            max_val = (val3 > max_val) ? val3 : max_val;
            max_val = (val4 > max_val) ? val4 : max_val;
        }

        for (; i < size; i++) {
            float val = data[i];
            if (val > max_val) {
                max_val = val;
            }
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
