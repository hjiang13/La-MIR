```cpp
#include <vector>

void largest_smallest_integers(std::vector<int>& result, const std::vector<int>& input) {
    int largest = 0;
    int smallest = 0;

    // Find largest and smallest integers in the input vector
    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] < 0) {
            if (smallest == 0 || input[i] > smallest) {
                smallest = input[i];
            }
        } else {
            if (largest == 0 || input[i] < largest) {
                largest = input[i];
            }
        }
    }

    // Store the largest and smallest integers in the result vector
    result.clear();
    result.push_back(largest);
    result.push_back(smallest);
}
```