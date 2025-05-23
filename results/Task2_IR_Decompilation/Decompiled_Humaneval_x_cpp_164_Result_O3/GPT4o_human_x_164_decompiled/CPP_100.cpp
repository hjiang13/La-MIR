```cpp
#include <vector>
#include <stdexcept>

void make_a_pile(std::vector<int>& vec, int size) {
    if (size <= 1) {
        return;
    }

    int* new_data = new int[size];
    int* old_data = vec.data();

    if (old_data) {
        std::move(old_data, old_data + vec.size(), new_data);
        delete[] old_data;
    }

    vec.assign(new_data, new_data + size);
    vec[size - 1] = 0; // Just an example to initialize the last element
    delete[] new_data;
}
```