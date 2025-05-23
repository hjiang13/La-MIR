```cpp
#include <vector>

void find_closest_elements(std::vector<float>& result, const std::vector<float>& input) {
    result.clear();

    if (input.size() <= 1) {
        return;
    }

    for (size_t i = 0; i < input.size() - 1; ++i) {
        if (input[i] > input[i + 1]) {
            result.push_back(input[i]);
            result.push_back(input[i + 1]);
        }
    }
}

int main() {
    std::vector<float> input = {3.14, 2.71, 1.618, 0.0};
    std::vector<float> result;

    find_closest_elements(result, input);

    return 0;
}
```