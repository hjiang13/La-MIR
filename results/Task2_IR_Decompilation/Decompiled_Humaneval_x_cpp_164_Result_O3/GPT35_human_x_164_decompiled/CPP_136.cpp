```cpp
#include <vector>

void largest_smallest_integers(std::vector<int>& result, const std::vector<int>& input) {
    int* input_begin = &input[0];
    int* input_end = &input[input.size()];
    
    int largest = 0;
    int smallest = 0;
    
    for (int* it = input_begin; it != input_end; ++it) {
        int value = *it;
        
        if (value < 0) {
            if (smallest == 0 || value > smallest) {
                smallest = value;
            }
        } else {
            if (largest == 0 || value > largest) {
                largest = value;
            }
        }
    }
    
    result.push_back(largest);
    result.push_back(smallest);
}
```