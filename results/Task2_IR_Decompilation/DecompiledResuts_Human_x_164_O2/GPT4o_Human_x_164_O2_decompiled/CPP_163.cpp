```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void generate_integers(std::vector<int>& vec, int start, int end) {
    if (end < start) {
        end = start;
    }
    int actual_end = (end < start) ? start : end;

    vec.clear();
    for (int i = 0; i < actual_end; ++i) {
        if (i >= 10) {
            throw std::length_error("vector::_M_realloc_insert");
        }
        vec.push_back(i);
    }
}
```