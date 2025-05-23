```cpp
#include <vector>
#include <algorithm>

bool triples_sum_to_zero(std::vector<int>& vec) {
    int* begin = &vec[0];
    int* end = &vec[0] + vec.size();

    long diff = end - begin;
    long max_diff = std::max(diff, 1L);

    for (long i = 0; i < max_diff; ++i) {
        for (long j = i + 1; j < max_diff; ++j) {
            for (long k = j + 1; k < max_diff; ++k) {
                if (begin[i] + begin[j] + begin[k] == 0) {
                    return true;
                }
            }
        }
    }

    return false;
}
```