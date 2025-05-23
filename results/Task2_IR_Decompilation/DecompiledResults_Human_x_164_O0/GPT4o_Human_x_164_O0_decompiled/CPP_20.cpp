```cpp
#include <vector>
#include <initializer_list>
#include <cmath>
#include <stdexcept>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();
    if (input.size() < 2) {
        throw std::length_error("cannot create std::vector larger than max_size()");
    }

    for (size_t i = 0; i < input.size() - 1; ++i) {
        float diff = input[i] - input[i + 1];
        float abs_diff = std::fabs(diff);
        if (result.empty() || abs_diff < std::fabs(result[0] - result[1])) {
            result = {input[i], input[i + 1]};
        }
    }
}

int main() {
    std::vector<float> vec = {1.0f, 2.5f, 3.0f, 4.0f};
    std::vector<float> closest;

    find_closest_elements(closest, vec);

    for (float num : closest) {
        printf("%f\n", num);
    }

    return 0;
}
```