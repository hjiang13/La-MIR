```c++
#include <vector>

void find_closest_elements(std::vector<float>& output, const std::vector<float>& input) {
    std::vector<float> temp(2);
    size_t i = 0;
    size_t j = 0;
    
    while (i < input.size() - 1) {
        if (input[i] > input[i + 1]) {
            temp[0] = input[i];
            temp[1] = input[i + 1];
            output = temp;
        }
        i++;
    }
}
```