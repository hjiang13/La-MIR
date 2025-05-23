```cpp
#include <vector>
#include <cstring>
#include <algorithm>

extern "C" void largest_smallest_integers(std::vector<int>* result, const std::vector<int>* input) {
    if (input->empty()) {
        memset(result, 0, sizeof(std::vector<int>));
        int* data = new int[2];
        result->data = data;
        return;
    }

    int min_val = input->at(0);
    int max_val = input->at(0);

    for (size_t i = 1; i < input->size(); ++i) {
        int val = input->at(i);
        if (val < min_val) {
            min_val = val;
        }
        if (val > max_val) {
            max_val = val;
        }
    }

    int* data = new int[2];
    data[0] = min_val;
    data[1] = max_val;

    result->data = data;
    result->size = 2;
    result->capacity = 2;
}
```