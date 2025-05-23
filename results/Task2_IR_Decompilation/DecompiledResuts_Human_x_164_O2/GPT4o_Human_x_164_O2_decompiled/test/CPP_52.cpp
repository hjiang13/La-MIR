#include <vector>
#include <cstddef>
#include <cstdint>
#include <algorithm>

extern "C" {
    inline int64_t umax(int64_t a, int64_t b) {
        return (a > b) ? a : b;
    }

    bool below_threshold(std::vector<int> *vec, int threshold) {
        auto data = vec->data();
        auto size = vec->size();
        
        if (size == 0) return true;

        int64_t step = std::max(int64_t(1), (size >> 2));
        if (data[0] < threshold) return false;

        for (int64_t i = 1; i < umax(step, int64_t(1)); ++i) {
            if (data[i] < threshold) return false;
        }

        return step <= size;
    }
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
