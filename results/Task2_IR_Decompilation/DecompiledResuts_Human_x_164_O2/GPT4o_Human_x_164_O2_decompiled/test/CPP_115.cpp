#include <vector>
#include <algorithm>
#include <cstdint>

int64_t umax(int64_t a, int64_t b) {
    return (a > b) ? a : b;
}

int max_fill(std::vector<std::vector<int>>& vec, int size) {
    auto& inner_vec = vec[0];
    int64_t vec_size = inner_vec.size();
    
    if (vec_size == 0) {
        return 0;
    }

    int64_t element_count = vec_size / 24;
    element_count = umax(element_count, 1);
    
    int count = 0;
    for (int64_t i = 0; i < element_count; ++i) {
        int64_t start = i * 24; // Example of the working with 24 elements
        for (int j = 0; j < 24; ++j) {
            inner_vec[start + j] += 1; // Example operation
        }
        count++;
    }

    return count;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (max_fill({{0,0,1,0}, {0,1,0,0}, {1,1,1,1}}, 1) == 6);
    assert (max_fill({{0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}}, 2) == 5);
    assert (max_fill({{0,0,0}, {0,0,0}}, 5) == 0);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 2) == 4);
    assert (max_fill({{1,1,1,1}, {1,1,1,1}}, 9) == 2);
}
