```cpp
#include <vector>
#include <iostream>
#include <cstdlib>

void introsort_loop(int* first, int* last, long depthLimit);
void final_insertion_sort(int* first, int* last);
void realloc_insert(std::vector<int>& vec, int* position, int* element);

void sort_array(std::vector<int>& vec) {
    if (vec.empty()) {
        vec.clear();
        return;
    }

    int* data = vec.data();
    int size = vec.size();

    if (size < 2) {
        return;
    }

    introsort_loop(data, data + size, 2 * log(size));
    final_insertion_sort(data, data + size);
}

void introsort_loop(int* first, int* last, long depthLimit) {
    // Implementation of introsort loop algorithm
    // ...
}

void final_insertion_sort(int* first, int* last) {
    // Implementation of final insertion sort algorithm
    // ...
}

void realloc_insert(std::vector<int>& vec, int* position, int* element) {
    // Implementation of realloc insert logic
    // ...
}

int main() {
    std::vector<int> vec = {4, 3, 2, 1};
    sort_array(vec);

    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```