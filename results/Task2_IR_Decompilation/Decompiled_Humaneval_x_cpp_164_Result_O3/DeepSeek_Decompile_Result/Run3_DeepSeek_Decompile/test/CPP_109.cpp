#include <vector>
#include <immintrin.h>  // For SIMD operations

using namespace std;

bool move_one_ball(vector<int>* v) {
    bool result = true;

    if (v->size() == 0)
        return true;

    int val = v->front();
    int n = v->size();

    // SIMD-optimized loop
    int i = 0;
    int remainder = n % 8;
    int aligned = n - remainder;

    for (; i < aligned; i += 8) {
        __m128i* ptr = (__m128i*)(v->data() + i);
        __m128i val_vec = _mm_set1_epi32(val);
        __m128i current = *ptr;

        __m128i comparison = _mm_cmpgt_epi32(current, val_vec);
        int mask = _mm_cvtsi128_si256(comparison).m128i[0];
        if (mask != 0) {
            result = false;
            break;
        }
    }

    // Handle remaining elements
    for (; i < n; ++i) {
        if (v->at(i) > val) {
            result = false;
            break;
        }
    }

    return result;
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
