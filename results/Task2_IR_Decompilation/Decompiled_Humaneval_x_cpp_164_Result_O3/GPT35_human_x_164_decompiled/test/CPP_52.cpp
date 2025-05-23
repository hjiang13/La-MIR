```c
#include <vector>
#include <algorithm>

bool below_threshold(std::vector<int> &v, int threshold) {
    auto *begin = v.data();
    auto *end = begin + v.size();
    
    std::ptrdiff_t size = end - begin;
    std::ptrdiff_t max_size = std::max<size_t>(size >> 2, 1);
    
    if (size == 0) {
        return true;
    }
    
    for (std::ptrdiff_t i = 0; i < max_size; ++i) {
        if (v[i] < threshold) {
            return true;
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
