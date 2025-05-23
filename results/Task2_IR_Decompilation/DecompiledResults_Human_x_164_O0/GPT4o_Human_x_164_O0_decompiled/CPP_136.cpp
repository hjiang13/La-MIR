```cpp
#include <iostream>
#include <vector>
#include <initializer_list>
#include <stdexcept>

void largest_smallest_integers(std::vector<int>& result, const std::vector<int>& vec) {
    int smallest = 0;
    int largest = 0;
    size_t size = vec.size();

    for (size_t i = 0; i < size; ++i) {
        int value = vec[i];
        if (i == 0 || value < smallest) {
            smallest = value;
        }
        if (i == 0 || value > largest) {
            largest = value;
        }
    }

    result.push_back(smallest);
    result.push_back(largest);
}

int main() {
    std::vector<int> input = {5, 3, 8, 1, 4};
    std::vector<int> output;

    largest_smallest_integers(output, input);

    std::cout << "Smallest: " << output[0] << ", Largest: " << output[1] << std::endl;

    return 0;
}
```