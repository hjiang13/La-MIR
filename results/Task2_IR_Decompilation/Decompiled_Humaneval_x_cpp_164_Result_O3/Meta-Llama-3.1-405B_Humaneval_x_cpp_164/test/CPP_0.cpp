#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float* data;
    float* end;
    float* capacity;
} vector_base;

typedef struct {
    vector_base base;
} vector;

int has_close_elements(vector* v, float threshold) {
    float* data = v->base.data;
    float* end = v->base.end;
    size_t size = (end - data) / sizeof(float);
    size_t i, j;

    if (size == 0) return 0;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            float diff = fabsf(data[i] - data[j]);
            if (diff < threshold) return 1;
        }
    }

    return 0;
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
