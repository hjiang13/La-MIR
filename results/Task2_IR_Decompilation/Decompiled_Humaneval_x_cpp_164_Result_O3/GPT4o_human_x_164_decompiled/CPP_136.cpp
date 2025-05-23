```cpp
#include <vector>
#include <cstring>
#include <cstdint>
#include <cstdlib>

void largest_smallest_integers(std::vector<int>* result, const std::vector<int>* input) {
    int* input_data = input->_Vector_base::_Vector_impl._Vector_impl_data;
    int* result_data = static_cast<int*>(std::malloc(2 * sizeof(int)));
    
    if (input_data == nullptr) {
        std::memset(result_data, 0, 2 * sizeof(int));
        result->_Vector_base::_Vector_impl._Vector_impl_data = result_data;
        return;
    }
    
    int largest = 0;
    int smallest = 0;
    size_t size = (reinterpret_cast<uintptr_t>(input_data[1]) - reinterpret_cast<uintptr_t>(input_data[0])) / sizeof(int);
    
    for (size_t i = 0; i < size; ++i) {
        int value = input_data[i];
        if (i == 0 || value > largest) {
            largest = value;
        }
        if (i == 0 || value < smallest) {
            smallest = value;
        }
    }
    
    result_data[0] = smallest;
    result_data[1] = largest;
    result->_Vector_base::_Vector_impl._Vector_impl_data = result_data;
}
```