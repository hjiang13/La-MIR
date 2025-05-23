```cpp
#include <vector>
#include <algorithm>
#include <iostream>

void sort_array(std::vector<int>& output, std::vector<int>& input) {
    size_t size = input.size();
    output.resize(size);

    std::copy(input.begin(), input.end(), output.begin());
    std::sort(output.begin(), output.end());
}

int main() {
    std::vector<int> input = {5, 3, 8, 1, 2, 9, 4, 7, 6};
    std::vector<int> output;

    sort_array(output, input);

    for (int num : output) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```