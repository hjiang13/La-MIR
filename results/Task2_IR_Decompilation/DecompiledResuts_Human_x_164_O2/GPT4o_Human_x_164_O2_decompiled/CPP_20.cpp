```cpp
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    float aux[2];
    size_t n = input.size();
    size_t result_size = 0;

    if (n > SIZE_MAX / sizeof(float)) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }

    // Initialize result vector
    result.clear();
    result.resize(2);

    for (size_t i = 0; i < n - 1; i++) {
        float first = input[i];
        float second = input[i + 1];
        aux[0] = first;
        aux[1] = second;

        if (fabs(aux[0] - aux[1]) < 0.0001) {
            result[result_size++] = first;
            result[result_size++] = second;
        }
    }

    result.resize(result_size);
}

int main() {
    std::vector<float> input = {1.0f, 2.0f, 1.00005f, 2.0f, 3.0f};
    std::vector<float> result;

    find_closest_elements(result, input);

    for (float val : result) {
        std::cout << val << " ";
    }

    return 0;
}
```