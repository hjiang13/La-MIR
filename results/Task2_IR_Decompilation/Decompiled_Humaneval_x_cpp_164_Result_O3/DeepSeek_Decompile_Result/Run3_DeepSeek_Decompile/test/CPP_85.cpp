#include <vector>

using namespace std;

int add(const vector<int>& vec) {
    int sum = 0;
    // Get pointers to the vector's data
    const int* data_start = vec.data();
    const int* data_end = data_start + vec.size();
    
    // SIMD-optimized loop for processing 4 elements at a time
    for (; data_start < data_end; data_start += 4) {
        // Use SIMD operations to process 4 elements
        __m128i vec1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(data_start));
        __m128i mask = _mm_and_si128(vec1, _mm_set1_epi32(1));
        __m128i is_odd = _mm_cmpeq_epi32(mask, _mm_set1_epi32(1));
        
        int temp;
        if (_mm_movemask_epi8(is_odd)) {
            temp = _mm_reduce_add_epi32(vec1);
            sum += temp;
        }
    }
    
    // Handle remaining elements that didn't fit in SIMD blocks
    for (; data_start < data_end; ++data_start) {
        if (*data_start & 1) {
            sum += *data_start;
        }
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
