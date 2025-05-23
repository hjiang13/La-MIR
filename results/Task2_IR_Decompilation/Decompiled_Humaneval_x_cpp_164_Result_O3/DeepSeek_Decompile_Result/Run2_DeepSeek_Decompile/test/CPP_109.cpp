#include <vector>
#include <immintrin.h> // For SIMD intrinsics

using namespace std;

bool move_one_ball(vector<int>& v) {
    int* data = v.data();
    size_t size = v.size();
    size_t adjusted_size = (size / 4) * 4;

    __m128i* vec_data = reinterpret_cast<__m128i*>(data);
    int count = 0;

    // SIMD processing of 4 elements at a time
    for (size_t i = 0; i < adjusted_size; i += 4) {
        __m128i chunk = vec_data[i / 4];
        __m128i ones = _mm_set1_epi32(1);
        __m128i zero = _mm_set1_epi32(0);

        __m128i mask = _mm_cmpgt_epi32(chunk, zero);
        int bitset;
        memcpy(&bitset, &mask, sizeof(bitset));
        count += __builtin_popcount(bitset);
    }

    // Handle remaining elements
    for (size_t i = adjusted_size; i < size; ++i) {
        if (data[i] > 0) {
            count++;
        }
    }

    return count < 2;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (move_one_ball({3, 4, 5, 1, 2})==true);
    assert (move_one_ball({3, 5, 10, 1, 2})==true);
    assert (move_one_ball({4, 3, 1, 2})==false);
    assert (move_one_ball({3, 5, 4, 1, 2})==false);
    assert (move_one_ball({})==true);
}
