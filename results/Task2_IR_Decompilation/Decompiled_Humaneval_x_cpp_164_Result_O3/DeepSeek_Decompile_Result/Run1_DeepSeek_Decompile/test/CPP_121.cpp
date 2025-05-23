#include <vector>

using namespace std;

int solution(const vector<int>& input) {
    int sum = 0;
    
    if (!input.empty()) {
        size_t size = input.size();
        size_t chunk_size = 16;  // Based on the loop unrolling and vectorization
        size_t remaining = size;

        // Process chunks of 16 elements
        for (size_t i = 0; remaining > 0; i += chunk_size) {
            size_t current_chunk = min(chunk_size, remaining);
            
            // Process 4-element SIMD blocks
            for (size_t j = 0; j < current_chunk; j += 4) {
                int a = input[i + j];
                int b = input[i + j + 1];
                int c = input[i + j + 2];
                int d = input[i + j + 3];
                
                // Check if numbers are odd and add to sum
                sum += (a % 2 == 1) ? a : 0;
                sum += (b % 2 == 1) ? b : 0;
                sum += (c % 2 == 1) ? c : 0;
                sum += (d % 2 == 1) ? d : 0;
            }

            remaining -= current_chunk;
        }
    }

    return sum;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (solutions({5, 8, 7, 1})    == 12);
    assert (solutions({3, 3, 3, 3, 3}) == 9);
    assert (solutions({30, 13, 24, 321}) == 0);
    assert (solutions({5, 9}) == 5);
    assert (solutions({2, 4, 8}) == 0);
    assert (solutions({30, 13, 23, 32}) == 23);
    assert (solutions({3, 13, 2, 9}) == 3);
}
