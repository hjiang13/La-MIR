```cpp
#include <vector>

void sort_array(std::vector<int>& result, std::vector<int>& input) {
    int* result_data = input.data();
    int* input_data = input.data();
    int result_size = result_data - input_data;
    int result_capacity = result_data - input_data;
    
    if (result_size == 0) {
        memset(&result, 0, sizeof(result));
        return;
    }
    
    int pivot = input[input.size() - 1];
    int* iter = input.data();
    while (*iter < pivot) {
        ++iter;
    }
    
    int* new_pivot = std::partition(input.begin(), input.end() - 1, [&](int x) {
        return x < pivot;
    });
    
    result.assign(input.begin(), new_pivot);
    result.push_back(pivot);
    std::copy(new_pivot + 1, input.end(), std::back_inserter(result));
}
```