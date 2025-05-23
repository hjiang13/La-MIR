#include <vector>
using namespace std;

int add(vector<int> *vec) {
    int sum = 0;
    int *data = vec->data();
    int *end = data + vec->size();

    // Vectorized loop
    while ((end - data) >= 4) {
        __m128i vec_data;
        vec_data = _mm_loadu_si128((__m128i *)data);
        
        __m128i mask = _mm_and_si128(vec_data, _mm_set1_epi32(1));
        __m128i zeros = _mm_set1_epi32(0);
        __m128i valid = _mm_cmpeq_epi32(mask, zeros);
        vec_data = _mm_andnot_si128(valid, vec_data);
        
        int result = _mm_reduce_add(vec_data);
        sum += result;
        
        data += 4;
    }

    // Scalar loop
    while (data < end) {
        if (*data & 1)
            sum += *data;
        data++;
    }

    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (add({4, 88}) == 88);
    assert (add({4, 5, 6, 7, 2, 122}) == 122);
    assert (add({4, 0, 6, 7}) == 0);
    assert (add({4, 4, 6, 8}) == 12);
}
