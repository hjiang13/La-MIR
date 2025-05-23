```cpp
#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> largest_smallest_integers(const std::vector<int>& input) {
    if (input.empty()) {
        return std::vector<int>();
    }

    int largest = 0;
    int smallest = 0;
    bool largest_set = false;
    bool smallest_set = false;

    for (int value : input) {
        if (value < 0) {
            if (!largest_set || value > largest) {
                largest = value;
                largest_set = true;
            }
        } else if (value > 0) {
            if (!smallest_set || value < smallest) {
                smallest = value;
                smallest_set = true;
            }
        }
    }

    std::vector<int> result;
    if (largest_set) {
        result.push_back(largest);
    }
    if (smallest_set) {
        result.push_back(smallest);
    }

    return result;
}
```