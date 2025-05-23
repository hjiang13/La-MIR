#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    float* data;
    float* end;
    float* capacity;
} vector_data;

typedef struct {
    vector_data impl;
} vector_base;

typedef struct {
    vector_base base;
} vector;

void rescale_to_unit(vector* out, vector* in) {
    float* in_data = in->base.impl.data;
    float* in_end = in->base.impl.end;
    int64_t length = (int64_t)(in_end - in_data);
    int64_t is_empty = length == 0;

    float min_val = -1e5;
    float max_val = 1e5;

    if (length < 4) {
        for (int64_t i = 0; i < length; i++) {
            float val = in_data[i];
            if (val < min_val) min_val = val;
            if (val > max_val) max_val = val;
        }
    } else {
        int64_t vec_length = length & ~(4 - 1);
        float vec_min_val = min_val;
        float vec_max_val = max_val;

        for (int64_t i = 0; i < vec_length; i += 4) {
            float* vec_ptr = (float*)(in_data + i);
            __m128 vec = _mm_loadu_ps(vec_ptr);
            __m128 min_vec = _mm_set1_ps(vec_min_val);
            __m128 max_vec = _mm_set1_ps(vec_max_val);

            __m128 cmp_min = _mm_cmplt_ps(vec, min_vec);
            __m128 cmp_max = _mm_cmpgt_ps(vec, max_vec);

            vec_min_val = _mm_min_ps(vec, min_vec)[0];
            vec_max_val = _mm_max_ps(vec, max_vec)[0];
        }

        for (int64_t i = vec_length; i < length; i++) {
            float val = in_data[i];
            if (val < min_val) min_val = val;
            if (val > max_val) max_val = val;
        }
    }

    float scale = 1.0f / (max_val - min_val);

    if (length < 4) {
        for (int64_t i = 0; i < length; i++) {
            in_data[i] = (in_data[i] - min_val) * scale;
        }
    } else {
        int64_t vec_length = length & ~(4 - 1);
        for (int64_t i = 0; i < vec_length; i += 4) {
            float* vec_ptr = (float*)(in_data + i);
            __m128 vec = _mm_loadu_ps(vec_ptr);
            __m128 min_vec = _mm_set1_ps(min_val);
            __m128 scale_vec = _mm_set1_ps(scale);

            vec = _mm_sub_ps(vec, min_vec);
            vec = _mm_mul_ps(vec, scale_vec);
            _mm_storeu_ps(vec_ptr, vec);
        }

        for (int64_t i = vec_length; i < length; i++) {
            in_data[i] = (in_data[i] - min_val) * scale;
        }
    }

    out->base.impl.data = in_data;
    out->base.impl.end = in_end;
    out->base.impl.capacity = in->base.impl.capacity;
    memset(in, 0, sizeof(vector));
}
