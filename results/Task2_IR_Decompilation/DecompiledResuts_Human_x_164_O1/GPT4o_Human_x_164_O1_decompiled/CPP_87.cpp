```cpp
#include <vector>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>

void get_row(std::vector<int>* result, const std::vector<int>* vec, int index) {
    if (index < 0 || index >= vec->size()) {
        throw std::out_of_range("Index out of range");
    }

    result->clear();
    size_t start = index * 3;
    size_t end = start + 3;

    for (size_t i = start; i < end && i < vec->size(); ++i) {
        result->push_back((*vec)[i]);
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> row;

    get_row(&row, &data, 1);

    for (int val : row) {
        std::cout << val << " ";
    }
    
    return 0;
}
```