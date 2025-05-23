```cpp
#include <vector>
#include <stdexcept>
#include <cstring>

void remove_duplicates(std::vector<int>& vec) {
    if (vec.size() > 9223372036854775804) {
        throw std::length_error("vector::_M_realloc_insert");
    }

    size_t original_size = vec.size();
    size_t new_size = 0;

    for (size_t i = 0; i < original_size; ++i) {
        bool is_duplicate = false;
        for (size_t j = 0; j < new_size; ++j) {
            if (vec[i] == vec[j]) {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate) {
            vec[new_size++] = vec[i];
        }
    }

    vec.resize(new_size);
}
```