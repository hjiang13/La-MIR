```cpp
#include <vector>
#include <stdexcept>
#include <new>

void derivative(std::vector<float>& result, const std::vector<float>& input) {
    float temp;
    result.clear();
    result.resize(input.size());

    for (size_t i = 1; i < input.size(); ++i) {
        float factor = static_cast<float>(i);
        temp = input[i] * factor;
        result[i - 1] = temp;
    }
    
    if (input.size() > 0) {
        result[input.size() - 1] = input[input.size() - 1] * static_cast<float>(input.size());
    }
}

void realloc_insert(std::vector<float>& vec, float* ptr) {
    if (ptr == nullptr) {
        throw std::length_error("vector::_M_realloc_insert");
    }
    
    size_t old_size = vec.size();
    vec.resize(old_size + 1);
    vec[old_size] = *ptr;
}

int main() {
    std::vector<float> input = {1.0f, 2.0f, 3.0f};
    std::vector<float> output;
    derivative(output, input);
    return 0;
}
```