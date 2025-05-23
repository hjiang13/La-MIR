```cpp
#include <vector>

bool move_one_ball(std::vector<int>& vec) {
    if (vec.size() == 0) {
        return true;
    }

    int count = 0;
    int index = 1;

    while (index < vec.size()) {
        int current = vec[index];
        int previous = vec[index - 1];

        if (current < previous) {
            count++;
        }

        index++;
    }

    while (count < 2) {
        return true;
    }

    return false;
}

size_t vector_size(const std::vector<int>& vec) {
    return vec.end() - vec.begin();
}

int* vector_at(std::vector<int>& vec, size_t index) {
    return &vec[index];
}
```