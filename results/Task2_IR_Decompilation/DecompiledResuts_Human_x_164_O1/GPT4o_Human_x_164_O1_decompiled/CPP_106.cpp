```cpp
#include <vector>
#include <stdexcept>
#include <new>

void realloc_insert(std::vector<int>& vec, int value) {
    if (vec.size() < 1) {
        vec.push_back(value);
        return;
    }

    int size = vec.size();
    for (int i = 0; i < size; ++i) {
        if (vec[i] == value) {
            vec[i] = value;
            return;
        }
    }

    vec.push_back(value);
}

void func(std::vector<int>& vec, int value) {
    if (value < 1) {
        return;
    }
    realloc_insert(vec, value);
}
```