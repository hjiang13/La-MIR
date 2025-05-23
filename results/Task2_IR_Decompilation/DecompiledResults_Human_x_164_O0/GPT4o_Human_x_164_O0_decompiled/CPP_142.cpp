```cpp
#include <vector>

long vector_size(const std::vector<int>& vec) {
    return vec.size();
}

int& vector_at(std::vector<int>& vec, size_t index) {
    return vec[index];
}

int sum_squares(std::vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vector_size(vec); i++) {
        if (i % 3 == 0) {
            sum += vector_at(vec, i) * vector_at(vec, i);
        } else if (i % 4 == 0) {
            sum += vector_at(vec, i) * vector_at(vec, i) * vector_at(vec, i);
        } else {
            sum += vector_at(vec, i);
        }
    }
    return sum;
}
```