```cpp
#include <vector>
#include <stdexcept>

void realloc_insert(std::vector<int>& vec, int value) {
    if (vec.size() < 1) {
        vec.resize(1);
        vec[0] = value;
        return;
    }

    int* old_data = vec.data();
    int new_size = vec.size() + 1;

    if (new_size > vec.capacity()) {
        int* new_data = new int[new_size];
        std::memcpy(new_data, old_data, vec.size() * sizeof(int));
        delete[] old_data;
        vec.data() = new_data;
    }

    vec[new_size - 1] = value;
}
```