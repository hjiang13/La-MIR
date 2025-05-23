```cpp
#include <vector>
#include <stdexcept>
#include <cstring>
#include <algorithm>

void sort_array(std::vector<int>& vec) {
    if (vec.empty()) {
        return;
    }

    int* data = vec.data();
    size_t size = vec.size();
    
    if (size <= 1) {
        return;
    }

    std::make_heap(data, data + size);
    std::sort_heap(data, data + size);
}

int main() {
    std::vector<int> vec = {5, 3, 8, 6, 2, 7, 4, 1};
    sort_array(vec);
    for (const int& val : vec) {
        std::cout << val << " ";
    }
    return 0;
}
```