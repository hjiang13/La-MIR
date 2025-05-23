```cpp
#include <vector>

void incr_list(std::vector<int>& out, std::vector<int>& in) {
    int* out_data = out.data();
    int* in_data = in.data();
    
    int size_diff = out_data - in_data;
    
    if (size_diff == 0) {
        return;
    }
    
    int num_elements = size_diff >> 2;
    int max_elements = __llvm_umax_i64(num_elements, 1);
    
    if (max_elements < 8) {
        return;
    }
    
    int aligned_elements = max_elements & -8;
    int num_chunks = (aligned_elements - 8) >> 3;
    
    if (num_chunks == 0) {
        return;
    }
    
    for (int i = 0; i < num_chunks; ++i) {
        int* chunk_ptr = in_data + (i * 8);
        __m128i* chunk_data = reinterpret_cast<__m128i*>(chunk_ptr);
        
        __m128i chunk_1 = chunk_data[0];
        __m128i chunk_2 = chunk_data[1];
        
        chunk_data[0] = _mm_add_epi32(chunk_1, _mm_set1_epi32(1));
        chunk_data[1] = _mm_add_epi32(chunk_2, _mm_set1_epi32(1));
    }
    
    int remaining_elements = aligned_elements + 8;
    int* remaining_chunk_ptr = in_data + remaining_elements;
    __m128i* remaining_chunk_data = reinterpret_cast<__m128i*>(remaining_chunk_ptr);
    
    __m128i remaining_chunk_1 = remaining_chunk_data[0];
    __m128i remaining_chunk_2 = remaining_chunk_data[1];
    
    remaining_chunk_data[0] = _mm_add_epi32(remaining_chunk_1, _mm_set1_epi32(1));
    remaining_chunk_data[1] = _mm_add_epi32(remaining_chunk_2, _mm_set1_epi32(1));
    
    for (int i = remaining_elements; i < num_elements; ++i) {
        in_data[i] += 1;
    }
}
```