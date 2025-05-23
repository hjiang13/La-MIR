```cpp
#include <vector>

void largest_smallest_integers(std::vector<int>& result, std::vector<int>& input) {
    int largest = 0;
    int smallest = 0;

    for (int i = 0; i < input.size(); i++) {
        int num = input[i];

        if (num < 0) {
            if (smallest == 0 || num > smallest) {
                smallest = num;
            }
        } else {
            if (largest == 0 || num > largest) {
                largest = num;
            }
        }
    }

    result.push_back(smallest);
    result.push_back(largest);
}
```