```cpp
#include <vector>
#include <iostream>
#include <stdexcept>

void get_positive(std::vector<float>& vec, const std::vector<float>& input) {
    vec.clear();
    for (size_t i = 0; i < input.size(); ++i) {
        float value = input[i];
        if (value > 0.0f) {
            vec.push_back(value);
        }
    }
}

void _M_realloc_insert(std::vector<float>& vec, float* position, float* value) {
    if (vec.size() >= vec.capacity()) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    size_t index = position - vec.data();
    vec.resize(vec.size() + 1);
    for (size_t i = vec.size() - 1; i > index; --i) {
        vec[i] = vec[i - 1];
    }
    vec[index] = *value;
}

int main() {
    std::vector<float> input = { -1.0f, 2.0f, -3.0f, 4.0f };
    std::vector<float> positives;

    try {
        get_positive(positives, input);
        for (float val : positives) {
            std::cout << val << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
```