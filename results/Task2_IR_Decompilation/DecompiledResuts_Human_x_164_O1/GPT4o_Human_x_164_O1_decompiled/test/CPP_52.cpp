#include <vector>
#include <cstdint>

extern "C" {
    uint64_t llvm_umax_i64(uint64_t a, uint64_t b);
}

bool below_threshold(std::vector<int> &vec, int threshold) {
    int* start = vec.data();
    int* end = start + vec.size();
    int64_t distance = reinterpret_cast<int64_t>(end) - reinterpret_cast<int64_t>(start);
    distance >>= 2;
    if (distance != 0) {
        int64_t max_distance = llvm_umax_i64(distance, 1);
        int first_value = *start;
        if (first_value < threshold) {
            int64_t count = 1;
            while (count < max_distance) {
                int value = *(start + count);
                if (value < threshold) {
                    count++;
                } else {
                    break;
                }
            }
            return count < max_distance;
        }
    }
    return false;
}

#undef NDEBUG
#include<assert.h>
int main(){
    assert (below_threshold({1, 2, 4, 10}, 100));
    assert (not(below_threshold({1, 20, 4, 10}, 5)));
    assert (below_threshold({1, 20, 4, 10}, 21));
    assert (below_threshold({1, 20, 4, 10}, 22));
    assert (below_threshold({1, 8, 4, 10}, 11));
    assert (not(below_threshold({1, 8, 4, 10}, 10)));
}
