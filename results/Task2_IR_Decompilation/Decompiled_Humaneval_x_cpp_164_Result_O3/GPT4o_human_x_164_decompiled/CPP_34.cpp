```cpp
#include <vector>
#include <stdexcept>
#include <algorithm>

void unique(std::vector<int>& v) {
    if (v.empty()) return;

    auto end = std::unique(v.begin(), v.end());
    v.erase(end, v.end());
}

void make_heap(std::vector<int>& v) {
    std::make_heap(v.begin(), v.end());
}

void insertion_sort(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
}

void sort_vector(std::vector<int>& v) {
    if (v.size() > 64) {
        make_heap(v);
        std::sort_heap(v.begin(), v.end());
    } else {
        insertion_sort(v);
    }
}

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    unique(vec);
    sort_vector(vec);
    return 0;
}
```